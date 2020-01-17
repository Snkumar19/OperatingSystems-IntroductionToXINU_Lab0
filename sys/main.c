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
	sleep(1);	
}
int main()
{
	kprintf("\n\nHello World, Xinu lives\n\n");
	long o = zfunction(0xaabbccdd);
	kprintf("\nTask 1: Input = 0xaabbccdd; Output = 0x%x",o);
	printsegaddress();
	printtos();
	printprocstks(10);
	syscallsummary_start();
	resume(prX = create(prch,2000,220,"proc X",1,'A'));
	sleep(2);
	sleep(3);
	syscallsummary_stop();
	printsyscallsummary();
	return 0;
}
