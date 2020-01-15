/* setdev.c - setdev */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 *  setdev  -  set the two device entries in the process table entry
 *------------------------------------------------------------------------
 */

extern long ctr1000;
SYSCALL	setdev(int pid, int dev1, int dev2)
{
	update_syscall_count(currpid,14);
        unsigned long syscall_exec_start = ctr1000;
	short	*nxtdev;

	if (isbadpid(pid)){
		update_syscall_time(currpid,14,ctr1000 - syscall_exec_start);
		return(SYSERR);
	}
	nxtdev = (short *) proctab[pid].pdevs;
	*nxtdev++ = dev1;
	*nxtdev = dev2;
	update_syscall_time(currpid,14,ctr1000 - syscall_exec_start);
	return(OK);
}
