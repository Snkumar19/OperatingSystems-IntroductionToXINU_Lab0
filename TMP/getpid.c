/* getpid.c - getpid */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <lab0.h>

/*------------------------------------------------------------------------
 * getpid  --  get the process id of currently executing process
 *------------------------------------------------------------------------
 */
extern long ctr1000;

SYSCALL getpid()
{
	update_syscall_count(currpid,2);
        unsigned long syscall_exec_start = ctr1000;
	update_syscall_time(currpid,2,ctr1000 - syscall_exec_start);
	return(currpid);
}
