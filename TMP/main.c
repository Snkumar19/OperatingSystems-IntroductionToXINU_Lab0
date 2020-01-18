/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 *
 */
int prX;
void halt();
prch(c)
char c;
{
	int i;
	sleep(2);	
}
int main()
{
	kprintf("\n\nHello World, Xinu lives\n\n");
	long o = zfunction(0xaabbccdd);
	kprintf("\nzfunction: Input = 0xaabbccdd; Output = 0x%x",o);
	printsegaddress();
	printtos();
	printprocstks(10);
	syscallsummary_start();
	resume(prX = create(prch,2000,20,"proc X",1,'A'));
	//resume(prX = create(prch,1000,15,"proc Y",1,'B'));
	sleep(3);
	//sleep(3);
	syscallsummary_stop();
	printsyscallsummary();
	return 0;
}
