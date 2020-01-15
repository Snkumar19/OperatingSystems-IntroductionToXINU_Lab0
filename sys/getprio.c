/* getprio.c - getprio */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * getprio -- return the scheduling priority of a given process
 *------------------------------------------------------------------------
 */
extern long ctr1000;

SYSCALL getprio(int pid)
{
	update_syscall_count(currpid,3);
        unsigned long syscall_exec_start = ctr1000;
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || (pptr = &proctab[pid])->pstate == PRFREE) {
		restore(ps);
		update_syscall_time(currpid,3,ctr1000 - syscall_exec_start);
		return(SYSERR);
	}
	restore(ps);
	update_syscall_time(currpid,3,ctr1000 - syscall_exec_start);
	return(pptr->pprio);
}
