#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

static unsigned long *esp;
static unsigned long *ebp;

void printprocstks(int priority)
{
	struct pentry *proc;
	int i;
	unsigned long limit;
        unsigned long *sp, *fp;

//	kprintf("\n\n NPROC = %d, numproc = %d, nextproc= %d,currpid = %d ",NPROC, numproc,nextproc,currpid );
	kprintf("\n\n Task 4:");
	for(i =0; i < NPROC; i++)
	{
		proc = &proctab[i];
		//kprintf("\nproc = %d", i);
		//kprintf("\nproc->pstate = %s", proc->pstate);
		//kprintf("\nproc->pbase = %X", proc->pbase);
		//kprintf("\nproc->pprio = %d", proc->pprio);
		//kprintf("\nproc->pstklen = %d\n", proc->pstklen);
		
		if (proc->pprio > priority && proc->pstate != PRFREE)
		{
			if (i == currpid) {
			   asm("movl %esp,esp");
			  // asm("movl %ebp,ebp");
			   sp = esp;
			   //fp = ebp;
			}
			else {
			  sp = (unsigned long *)proc->pesp;
		 	  //fp = (unsigned long *)proc->pbase;
		}
		kprintf("\nProcess [%s]",proc->pname);
		kprintf("\npid = %d", i);
		kprintf("\npriority = %d", proc->pprio);
		kprintf("\nbase = %X", proc->pbase);
	        kprintf("\nlimit = %X", proc->plimit);
		kprintf("\nlen = %d", proc->pstklen);
		kprintf("\npointer = %X", sp);

		
		}  
	}  

}

