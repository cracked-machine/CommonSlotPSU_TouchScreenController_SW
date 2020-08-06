HPECommonSlot_BreakoutModule_SW


### TODO

#### Using Sempahores

This approach may interrupt DisplayTask in the middle of a display write!

##### System Definition:

  - Define tasks:
    - DisplayTask (Priority: Normal)
    - AdcTask     (Priority: Low)
    - PenIrqTask  (Priority: High)


  - Define binary semaphore IrqSem
  - Define binary semaphore MainSem

##### System Runtime:

  - DisplayTask:
      - Task (Infinite Loop):
        - Take MainSem (wait: 100ms)
        - Executes display code (use Touchscreen coordinates and ADC data)
        - Release MainSem
        - Suspend this task


  - AdcTask:
      - Task  (Infinite Loop):
        - Take MainSem (wait: 100ms)
        - Capture ADC data (global variable?)
        - Resume DisplayTask
        - Release MainSem




  - PenIrqTask:
    - ISR:
      - Update StateChart
      - Release IrqSem
    - Task (Infinite Loop):
      - Take IrqSem (wait: forever)
      - Toggle PSU output
      - Display touchscreen coordinates and ADC data






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
