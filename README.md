HPECommonSlot_BreakoutModule_SW


#### TODO

- Enable HW Timer for systick
- Add separate tasks for Display, PENIRQ interrupt and ADC Interrupt/Polling

- Add Semaphore to block other PENIRQ/ADC tasks while Display task runs, release semaphore on PENIRQ or ADC interrupt.
- Add message queue to relay coordinates from PENIRQ task to Display task AND relay voltage data from ADC task to Display task.
