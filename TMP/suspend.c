/* suspend.c - suspend */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  suspend  --  suspend a process, placing it in hibernation
 *------------------------------------------------------------------------
 */
extern long ctr1000;
SYSCALL	suspend(int pid)
{
	update_syscall_count(currpid,24);
        unsigned long syscall_exec_start = ctr1000;
	STATWORD ps;    
	struct	pentry	*pptr;		/* pointer to proc. tab. entry	*/
	int	prio;			/* priority returned		*/

	disable(ps);
	if (isbadpid(pid) || pid==NULLPROC ||
	 ((pptr= &proctab[pid])->pstate!=PRCURR && pptr->pstate!=PRREADY)) {
		restore(ps);
		update_syscall_time(currpid,24,ctr1000 - syscall_exec_start);
		return(SYSERR);
	}
	if (pptr->pstate == PRREADY) {
		pptr->pstate = PRSUSP;
		dequeue(pid);
	}
	else {
		pptr->pstate = PRSUSP;
		resched();
	}
	prio = pptr->pprio;
	restore(ps);
	update_syscall_time(currpid,24,ctr1000 - syscall_exec_start);
	return(prio);
}
