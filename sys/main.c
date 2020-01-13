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
prch(c)
char c;
{
	int i;
	sleep(5);	
}
int main()
{
	kprintf("\n\nHello World, Xinu lives\n\n");
	long o = zfunction(0xaabbccdd);
	kprintf("\n Task 1: Input = 0xaabbccdd; Output = 0x%x",o);
	printsegaddress();
	printprocstks(1);
        printtos();
	syscallsummary_start();
	resume(prX = create(prch,2000,20,"proc X",1,'A'));
	sleep(20);
	syscallsummary_stop();
	printsyscallsummary();
	return 0;
}
