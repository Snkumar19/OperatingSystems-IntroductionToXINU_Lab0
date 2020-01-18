#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

static unsigned long *esp;
//static unsigned long *ebp;

void printprocstks(int priority)
{
	struct pentry *proc;
	int i;
	//unsigned long limit;
	//unsigned long *fp;
        unsigned long *sp;

//	kprintf("\n\n NPROC = %d, numproc = %d, nextproc= %d,currpid = %d ",NPROC, numproc,nextproc,currpid );
	kprintf("\n\nTask 4:");
	for(i =0; i < NPROC; i++)
	{
		proc = &proctab[i];
		
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
		kprintf("\n\tpid = %d", i);
		kprintf("\n\tpriority = %d", proc->pprio);
		kprintf("\n\tbase = 0x%08X", proc->pbase);
	        kprintf("\n\tlimit = 0x%08X", proc->plimit);
		kprintf("\n\tlen = %d", proc->pstklen);
		kprintf("\n\tpointer = 0x%08X", sp);

		
		}  
	}  

}

