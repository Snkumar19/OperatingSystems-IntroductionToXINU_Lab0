#include<stdio.h>

static unsigned long *esp;
static unsigned long *ebp;

void printtos()
{
	int i;
	//int a=1,b=2,c=3,d=4;
	unsigned long *sp;
	unsigned long *bp;
	asm("movl %esp,esp");
	asm("movl %ebp,ebp");
	sp = esp;
	bp = ebp;
	kprintf("\n\nTask 3:");
	kprintf("\nBefore[0x%08X]: 0x%08X", (bp+2), *(bp+2) );
	kprintf("\nAfter[0x%08X]: 0x%08X", bp, *bp);
	
	for(i=1;i<4;i++)
	kprintf("\n\telement[0x%08X]: 0x%08X", (sp+i), *(sp+i) );
}

