/* sleep1000.c - sleep1000 */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sleep.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * sleep1000 --  delay the caller for a time specified in 1/100 of seconds
 *------------------------------------------------------------------------
 */
extern long ctr1000;
SYSCALL sleep1000(int n)
{
	update_syscall_count(currpid,21);
        unsigned long syscall_exec_start = ctr1000;
	STATWORD ps;    

	if (n < 0  || clkruns==0){
		update_syscall_time(currpid,21,ctr1000 - syscall_exec_start);
	         return(SYSERR);
	}
	disable(ps);
	if (n == 0) {		/* sleep1000(0) -> end time slice */
	        ;
	} else {
		insertd(currpid,clockq,n);
		slnempty = TRUE;
		sltop = &q[q[clockq].qnext].qkey;
		proctab[currpid].pstate = PRSLEEP;
	}
	resched();
        restore(ps);
	update_syscall_time(currpid,21,ctr1000 - syscall_exec_start);
	return(OK);
}
