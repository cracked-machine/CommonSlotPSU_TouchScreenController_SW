HPECommonSlot_BreakoutModule_SW


#### TODO

- Enable HW Timer for systick
- Add separate tasks for Display, PENIRQ interrupt and ADC Interrupt/Polling

- Add Semaphore to block other PENIRQ/ADC tasks while Display task runs, release semaphore on PENIRQ or ADC interrupt.
- Add message queue to relay coordinates from PENIRQ task to Display task AND relay voltage data from ADC task to Display task.

##### Using Sempahores

This approach may interrupt DisplayTask in the middle of a display write!

- Define tasks:
  - DisplayTask (Priority: Low)
  - PenIrqTask  (Priority: High)
  - AdcTask     (Priority: Normal)
- Define Semaphore with 1 token

- DisplayTask:
  - Task (Infinite Loop):
    - Take semaphore
    - Executes display code (use Touchscreen coordinates and ADC data)
    - Release Semaphore
    

- PenIrqTask:
  - ISR:
    - Release Semapore
    - Suspend DisplayTask, AdcTask (prevent race condition)
    - Take Semaphore
    - Resume PenIrqTask (this task)
  - Task (Infinite Loop):
    - Resume DisplayTask, AdcTask (still blocked by semaphore)
    - Capture Touch screen coordinates (global variable?)
    - Release Semaphore
    - Suspend PenIrqTask (this task)

- AdcTask:
  - ISR:
    - Release Semapore
    - Suspend DisplayTask, PenIrqTask (prevent race condition)
    - Take Semaphore
    - Resume AdcTask (this task)
  - Task:
    - Resume DisplayTask, PenIrqTask (still blocked by semaphore)
    - Capture ADC data (global variable?)
    - Release Semaphore
    - Suspend AdcTask (this task)
  

  
##### Using Sempahores wth (event) queue

