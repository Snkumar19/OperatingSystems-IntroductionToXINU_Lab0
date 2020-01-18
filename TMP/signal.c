/* signal.c - signal */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <q.h>
#include <sem.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * signal  --  signal a semaphore, releasing one waiting process
 *------------------------------------------------------------------------
 */
extern long ctr1000;
SYSCALL signal(int sem)
{
	update_syscall_count(currpid,16);
        unsigned long syscall_exec_start = ctr1000;
	STATWORD ps;    
	register struct	sentry	*sptr;

	disable(ps);
	if (isbadsem(sem) || (sptr= &semaph[sem])->sstate==SFREE) {
		restore(ps);
		update_syscall_time(currpid,16,ctr1000 - syscall_exec_start);
		return(SYSERR);
	}
	if ((sptr->semcnt++) < 0)
		ready(getfirst(sptr->sqhead), RESCHYES);
	restore(ps);
	update_syscall_time(currpid,16,ctr1000 - syscall_exec_start);
	return(OK);
}
