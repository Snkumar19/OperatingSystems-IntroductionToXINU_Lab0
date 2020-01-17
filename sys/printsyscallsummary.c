#include<stdio.h>
#include<lab0.h>
#include <conf.h>
#include <kernel.h>
#include <proc.h>

extern long ctr1000;

char* syscall_name[27]={"syscall_freemem", "syscall_chprio", "syscall_getpid", "syscall_getprio", "syscall_gettime", "syscall_kill", "syscall_receive", "syscall_recvclr", "syscall_recvtim", "syscall_resume", "syscall_scount", "syscall_sdelete", "syscall_send", "syscall_setdev", "syscall_setnok", "syscall_screate", "syscall_signal", "syscall_signaln", "syscall_sleep", "syscall_sleep10", "syscall_sleep100", "syscall_sleep1000", "syscall_sreset", "syscall_stacktrace", "syscall_suspend", "syscall_unsleep", "syscall_wait"};

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
	
