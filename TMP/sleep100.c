/* sleep100.c - sleep100 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 * sleep100  --  delay the caller for a time specified in 1/100 of seconds
 *------------------------------------------------------------------------
 */
extern long ctr1000;
SYSCALL sleep100(int n)
{
	update_syscall_count(currpid,20);
        unsigned long syscall_exec_start = ctr1000;
	STATWORD ps;    

	if (n < 0  || clkruns==0){
		update_syscall_time(currpid,20,ctr1000 - syscall_exec_start);
	         return(SYSERR);
	}
	disable(ps);
	if (n == 0) {		/* sleep100(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n*10);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);
	update_syscall_time(currpid,20,ctr1000 - syscall_exec_start);
	return(OK);
}
