/* freemem.c - freemem */

#include <conf.h>
#include <kernel.h>
#include <mem.h>
#include <stdio.h>
#include <lab0.h>
#include <proc.h>

/*------------------------------------------------------------------------
 *  freemem  --  free a memory block, returning it to memlist
 *------------------------------------------------------------------------
 */

extern long ctr1000;

SYSCALL	freemem(struct mblock *block, unsigned size)
{	
	update_syscall_count(currpid,0);
	unsigned long syscall_exec_start = ctr1000;
	STATWORD ps;    
	struct	mblock	*p, *q;
	unsigned top;

	if (size==0 || (unsigned)block>(unsigned)maxaddr
	    || ((unsigned)block)<((unsigned) &end))
		{
		update_syscall_time(currpid,0,ctr1000 - syscall_exec_start);
		return(SYSERR);
		}
	size = (unsigned)roundmb(size);
	disable(ps);
	for( p=memlist.mnext,q= &memlist;
	     p != (struct mblock *) NULL && p < block ;
	     q=p,p=p->mnext )
		;
	if (((top=q->mlen+(unsigned)q)>(unsigned)block && q!= &memlist) ||
	    (p!=NULL && (size+(unsigned)block) > (unsigned)p )) {
		restore(ps);
		update_syscall_time(currpid,0,ctr1000 - syscall_exec_start);
		return(SYSERR);
	}
	if ( q!= &memlist && top == (unsigned)block )
			q->mlen += size;
	else {
		block->mlen = size;
		block->mnext = p;
		q->mnext = block;
		q = block;
	}
	if ( (unsigned)( q->mlen + (unsigned)q ) == (unsigned)p) {
		q->mlen += p->mlen;
		q->mnext = p->mnext;
	}
	restore(ps);
	update_syscall_time(currpid,0,ctr1000 - syscall_exec_start);
	return(OK);
}
