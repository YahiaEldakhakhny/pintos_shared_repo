# list_priority_cmp ___Added___
```c
bool list_priority_cmp(const struct list_elem *a, const struct list_elem *b, void *aux UNUSED);
```
Function to compare the priority of 2 threads in the `ready_list`.

a is the list element associated with thread A.

b is the list element associated with thread B.

This function returns true if priority of A is less than priority of B and returns false otherwise.

---

# is_in_list ___Added___
```c
bool is_in_list(struct list *list, struct list_elem *target);
```
Function to find if target is in a list

if elem is in list, the function returns true

if elem is not found, the function returns false

---

# thread_set_priority ___Editted___

1. Get pointer to current thread.
1. store the current priority in the `old_priority` attribute of the thread.
1. store `new_priority` in the `priority` attribute of the thread.
1. check if the priority of the thread decreased, if so the thread should yield the processor.
## Notes

we don't need to disable the interrupts because this approach does not access any global variables.

---

# next_thread_to_run ___Editted___
I made the function select the next thread to run from the back of the ready_list instead of the front because I noticed that the function `list_insert_ordered` inserts the threads in ascending order (lowest priority at head and highest priority at tail).

---

# thread_block ___Editted___
```c
void
thread_block (void) 
```
1. get current running thread.
1. change its status to `THREAD_BLOCKED`
1. if the thread is in ready_list remove it.

---

# thread_unblock ___Editted___
```c
void
thread_unblock (struct thread *t) 
```
1. if thread is not in `ready_list`, add it.
1. change its state to `THREAD_READY`.

---
