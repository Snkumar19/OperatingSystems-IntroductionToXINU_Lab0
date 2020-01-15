/* scount.c - scount */

#include <conf.h>
#include <kernel.h>
#include <sem.h>
#include <lab0.h>
#include <proc.h>

/*------------------------------------------------------------------------
 *  scount  --  return a semaphore count
 *------------------------------------------------------------------------
 */
extern long ctr1000;

SYSCALL scount(int sem)
{
update_syscall_count(currpid,10);
        unsigned long syscall_exec_start = ctr1000;
extern	struct	sentry	semaph[];

	if (isbadsem(sem) || semaph[sem].sstate==SFREE){
		update_syscall_time(currpid,10,ctr1000 - syscall_exec_start);
		return(SYSERR);
	}
	update_syscall_time(currpid,10,ctr1000 - syscall_exec_start);
	return(semaph[sem].semcnt);
}
