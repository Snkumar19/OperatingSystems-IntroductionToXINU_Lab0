/* send.c - send */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>
/*------------------------------------------------------------------------
 *  send  --  send a message to another process
 *------------------------------------------------------------------------
 */
extern long ctr1000;
SYSCALL	send(int pid, WORD msg)
{
	update_syscall_count(currpid,12);
        unsigned long syscall_exec_start = ctr1000;
	STATWORD ps;    
	struct	pentry	*pptr;

	disable(ps);
	if (isbadpid(pid) || ( (pptr= &proctab[pid])->pstate == PRFREE)
	   || pptr->phasmsg != 0) {
		restore(ps);
		update_syscall_time(currpid,12,ctr1000 - syscall_exec_start);
		return(SYSERR);
	}
	pptr->pmsg = msg;
	pptr->phasmsg = TRUE;
	if (pptr->pstate == PRRECV)	/* if receiver waits, start it	*/
		ready(pid, RESCHYES);
	else if (pptr->pstate == PRTRECV) {
		unsleep(pid);
		ready(pid, RESCHYES);
	}
	restore(ps);
	update_syscall_time(currpid,12,ctr1000 - syscall_exec_start);
	return(OK);
}
