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

int main()
{
	kprintf("\n\nHello World, Xinu lives\n\n");
	long o = zfunction(0xaabbccdd);
	kprintf("\n Task 1: Input = 0xaabbccdd; Output = 0x%x",o);
	printsegaddress();
	printprocstks(1);
	return 0;
}
