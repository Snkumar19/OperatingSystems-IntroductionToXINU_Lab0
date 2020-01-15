/* setnok.c - setnok */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  setnok  -  set next-of-kin (notified at death) for a given process
 *------------------------------------------------------------------------
 */
extern long ctr1000;
SYSCALL	setnok(int nok, int pid)
{
	update_syscall_count(currpid,15);
        unsigned long syscall_exec_start = ctr1000;
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid)) {
		restore(ps);
		update_syscall_time(currpid,15,ctr1000 - syscall_exec_start);
		return(SYSERR);
	}
	pptr = &proctab[pid];
	pptr->pnxtkin = nok;
	restore(ps);
	update_syscall_time(currpid,15,ctr1000 - syscall_exec_start);
	return(OK);
}
