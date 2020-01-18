/* wait.c - wait */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * wait  --  make current process wait on a semaphore
 *------------------------------------------------------------------------
 */
extern long ctr1000;
SYSCALL	wait(int sem)
{
	STATWORD ps;    
	struct	sentry	*sptr;
	struct	pentry	*pptr;
	
	update_syscall_count(currpid,26);
        unsigned long syscall_exec_start = ctr1000;

	disable(ps);
	if (isbadsem(sem) || (sptr= &semaph[sem])->sstate==SFREE) {
		update_syscall_time(currpid,26,ctr1000 - syscall_exec_start);
		restore(ps);
		return(SYSERR);
	}
	
	if (--(sptr->semcnt) < 0) {
		(pptr = &proctab[currpid])->pstate = PRWAIT;
		pptr->psem = sem;
		enqueue(currpid,sptr->sqtail);
		pptr->pwaitret = OK;
		resched();
		restore(ps);
		update_syscall_time(currpid,26,ctr1000 - syscall_exec_start);
		return pptr->pwaitret;
	}
	restore(ps);
	update_syscall_time(currpid,26,ctr1000 - syscall_exec_start);
	return(OK);
}
