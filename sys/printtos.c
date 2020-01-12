#include<stdio.h>

static unsigned long *esp;

void printtos()
{
	unsigned long *sp;
	asm("movl %esp,esp");
	sp = esp;
	kprintf("\n\nBefore[%X]: %X", (sp+1), *(sp+1) );
	kprintf("\nAfter[%X]: %X", sp, *sp);
	
	kprintf("\nelement[%X]: %X", (sp+1), *(sp+1) );
	kprintf("\nelement[%X]: %X", (sp+2), *(sp+2) );
	kprintf("\nelement[%X]: %X", (sp+3), *(sp+3) );
	kprintf("\nelement[%X]: %X", (sp+4), *(sp+4) );

}

