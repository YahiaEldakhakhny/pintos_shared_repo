# thread_set_priority (Editted)

1. Get pointer to current thread.
1. store the current priority in the `old_priority` attribute of the thread.
1. store `new_priority` in the `priority` attribute of the thread.
1. check if the priority of the thread decreased, if so the thread should yield the processor.
## Notes

1. we don't need to disable the interrupts because this approach does not access any global variables.