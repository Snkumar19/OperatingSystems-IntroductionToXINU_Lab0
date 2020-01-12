#include<stdio.h>

extern long etext;
extern long _edata;
extern long _end;

void printsegaddress()
{
long *etext_addr = &etext;
long *_edata_addr = &_edata;
long *_end_addr = &_end;
kprintf("\n\nTask2:");
//kprintf("\nCurrent: etext[0x%x]= 0x%x", &etext,etext, &_edata,_edata);
kprintf("\nCurrent: etext[0x%x]= 0x%x, edata[0x%x]=0x%x, ebss[0x%x]=0x%x", etext_addr,*etext_addr,_edata_addr,*_edata_addr,_end_addr,*_end_addr);
kprintf("\nPreceding: etext[0x%x]= 0x%x, edata[0x%x]=0x%x, ebss[0x%x]=0x%x", (etext_addr-1),*(etext_addr-1),(_edata_addr-1),*(_edata_addr-1),(_end_addr-1),*(_end_addr-1));
kprintf("\nAfter: etext[0x%x]= 0x%x, edata[0x%x]=0x%x, ebss[0x%x]=0x%x", (etext_addr+1),*(etext_addr+1),(_edata_addr+1),*(_edata_addr+1),(_end_addr+1),*(_end_addr+1));
}
