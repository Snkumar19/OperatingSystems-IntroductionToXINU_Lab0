#include<stdio.h>
#include<lab0.h>
#include <conf.h>
#include <kernel.h>
#include <proc.h>

extern long ctr1000;

char* syscall_name[27]={"sys_freemem", "sys_chprio", "sys_getpid", "sys_getprio", "sys_gettime", "sys_kill", "sys_receive", "sys_recvclr", "sys_recvtim", "sys_resume", "sys_scount", "sys_sdelete", "sys_send", "sys_setdev", "sys_setnok", "sys_screate", "sys_signal", "sys_signaln", "sys_sleep", "sys_sleep10", "sys_sleep100", "sys_sleep1000", "sys_sreset", "sys_stacktrace", "sys_suspend", "sys_unsleep", "sys_wait"};

void update_syscall_count(int pid, int syscall_index)
{
                extern struct  pentry  proctab[];
		if (syscall_flag ==1)
                	proctab[pid].syscall_count[syscall_index] += 1;
}

void update_syscall_time(int pid, int syscall_index,unsigned long diff_time)
{
                extern struct  pentry  proctab[];
		if (syscall_flag ==1)
               		 proctab[pid].syscall_exec_time[syscall_index] += diff_time;
}

void syscallsummary_start()
{
	syscall_flag = 1;
}
void syscallsummary_stop()
{
	syscall_flag = 0;
}

void printsyscallsummary()
{
	int i,j;
	extern struct  pentry  proctab[];
	kprintf("\n\nTask 5:");
	for (i = 0 ;i<NPROC; i++) 
	{
		if(proctab[i].pprio != 0){
			kprintf("\nProcess [pid = %d]", i);
			//kprintf("Process name : %s, %d", proctab[i].pname, proctab[i].pprio);
		for (j =0;j<27; j++)
		{
			if (proctab[i].syscall_count[j]>0)
			{
				//kprintf("\n -> Process [pid = %d]", i);
				kprintf("\n\tSyscall: %s,", syscall_name[j]);
                		kprintf("Count: %d, ",proctab[i].syscall_count[j]);
                		kprintf("Average Execution time: %lu (ms) ", (proctab[i].syscall_exec_time[j]/proctab[i].syscall_count[j]));
			}
		}
		//kprintf("\n------------------------------", i);
	}
	}
}
	
