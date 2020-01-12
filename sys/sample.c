/* user.c - main */

#include <conf.h>
#include <kernel.h>
#include <proc.h>
#include <stdio.h>

/*------------------------------------------------------------------------
 *  main  --  user main program
 *------------------------------------------------------------------------
 */
/*int sample()
*{
*	kprintf("\n\nSample code executing");
*	return 0;
}*/
long zfunctest(long param)
{
	long output = (param & 0xff803fff) << 4;
	//kprintf("%x",output);
	return output;
}
