/* gettime.c - gettime */

#include <conf.h>
#include <kernel.h>
#include <date.h>
#include <lab0.h>
#include <proc.h>

extern int getutim(unsigned long *);
extern long ctr1000;

/*------------------------------------------------------------------------
 *  gettime  -  get local time in seconds past Jan 1, 1970
 *------------------------------------------------------------------------
 */
SYSCALL	gettime(long *timvar)
{
    /* long	now; */

	/* FIXME -- no getutim */
	update_syscall_count(currpid,4);
        unsigned long syscall_exec_start = ctr1000;
	update_syscall_time(currpid,4,ctr1000 - syscall_exec_start);
	return OK;
}
