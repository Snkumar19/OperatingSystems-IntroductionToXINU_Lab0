/* sleep10.c - sleep10 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * sleep10  --  delay the caller for a time specified in tenths of seconds
 *------------------------------------------------------------------------
 */
extern long ctr1000;
SYSCALL	sleep10(int n)
{
	update_syscall_count(currpid,19);
        unsigned long syscall_exec_start = ctr1000;
	STATWORD ps;    
	if (n < 0  || clkruns==0){
		update_syscall_time(currpid,19,ctr1000 - syscall_exec_start);
	         return(SYSERR);
	}
	disable(ps);
	if (n == 0) {		/* sleep10(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n*100);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);
	update_syscall_time(currpid,19,ctr1000 - syscall_exec_start);
	return(OK);
}
