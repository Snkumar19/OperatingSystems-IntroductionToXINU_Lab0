/* sleep.c - sleep */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * sleep  --  delay the calling process n seconds
 *------------------------------------------------------------------------
 */
extern long ctr1000;

SYSCALL	sleep(int n)
{	
	update_syscall_count(currpid,18);
	unsigned long syscall_exec_start = ctr1000;
	STATWORD ps;    
	if (n<0 || clkruns==0){
		update_syscall_time(currpid,18,ctr1000 - syscall_exec_start);
		return(SYSERR);
	}
	if (n == 0) {
	        disable(ps);
		resched();
		restore(ps);
		update_syscall_time(currpid,18,ctr1000 - syscall_exec_start);
		return(OK);
	}
	while (n >= 1000) {
		sleep10(10000);
		n -= 1000;
	}
	if (n > 0)
		sleep10(10*n);
	update_syscall_time(currpid,18,ctr1000 - syscall_exec_start);
	kprintf ("\n\n\n Debug from sleep %lu", ctr1000 - syscall_exec_start); 
	return(OK);
}
