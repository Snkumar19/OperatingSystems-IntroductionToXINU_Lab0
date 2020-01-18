/* lab0.h  */
unsigned int syscall_flag;
extern void update_syscall_count(int pid, int syscall_index);
extern void update_syscall_time(int pid, int syscall_index,unsigned long diff_time);
