#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>


void printprocstks(int priority)
{
  struct pentry	*proc;
int i;
  kprintf("\n\n NPROC = %d, numproc = %d, nextproc= %d,currpid = %d ",NPROC, numproc,nextproc,currpid );
for(i =0; i < NPROC; i++)
{
proc = &proctab[i];
kprintf("\nproc = %d", i);
kprintf("\nproc->pstate = %s", proc->pstate);
kprintf("\nproc->pbase = %X", proc->pbase);
kprintf("\nproc->pprio = %d", proc->pprio);
kprintf("\nproc->pstklen = %d\n", proc->pstklen);


}
  

}
