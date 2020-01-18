/* resume.c - resume */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * resume  --  unsuspend a process, making it ready; return the priority
 *------------------------------------------------------------------------
 */
extern long ctr1000;

SYSCALL resume(int pid)
{	
	update_syscall_count(currpid,9);
	unsigned long syscall_exec_start = ctr1000;

	STATWORD ps;    
	struct	pentry	*pptr;		/* pointer to proc. tab. entry	*/
	int	prio;			/* priority to return		*/

	disable(ps);
	if (isbadpid(pid) || (pptr= &proctab[pid])->pstate!=PRSUSP) {
		restore(ps);
		update_syscall_time(currpid,9,ctr1000 - syscall_exec_start);
		return(SYSERR);
	}
	prio = pptr->pprio;
	ready(pid, RESCHYES);
	restore(ps);
	update_syscall_time(currpid,9,ctr1000 - syscall_exec_start);
	return(prio);
}
