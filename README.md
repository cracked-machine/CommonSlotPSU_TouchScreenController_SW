HPECommonSlot_BreakoutModule_SW


### TODO

#### Using Sempahores

This approach may interrupt DisplayTask in the middle of a display write!

##### System Definition:

  - Define tasks:
    - DisplayTask (Priority: Low)
    - PenIrqTask  (Priority: High)
    - AdcTask     (Priority: Normal)
  - Define Semaphore with 1 token

##### System Runtime:

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


  
#### Using (Event) Queue 

##### System Definition:

 - Define tasks:
  - DisplayTask (Priority: High)
  - PenIrqTask  (Priority: Medium)
  - AdcTask     (Priority: Low)
  
 - Define Queues:
  - Event queue with 1 item (Register DisplayTask as receiver)
  
##### System Runtime:

- DisplayTask (state machine):
   
  - Task (Infinite Loop):
    - Wait for message on event queue (Suspended)
    - Process Event (Blocking):   
      - ADC Event:
        - update display with ADC data
      - TouchScreen Event:
        - update display with Touchscreen coordinates

- PenIrqTask:

  - ISR:
    - Resume PenIrqTask
  
  - Task (Infinite Loop):
    - capture data from Touchscreen IC over SPI (global variable?)
    - Send PENIRQ message on event queue
    - Suspend PenIrqTask


- AdcTask:

  - ISR:
    - Resume AdcTask
  
  - Task (Infinite Loop):
    - Capture data from data from ADC peripheral (global variable?)
    - Send ADC message on event queue
    - Suspend AdcTask
  
