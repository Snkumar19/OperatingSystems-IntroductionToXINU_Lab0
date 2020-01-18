#include<stdio.h>

extern long etext;
extern long edata;
extern long end;

void printsegaddress()
{
long *etext_addr = &etext;
long *_edata_addr = &edata;
long *_end_addr = &end;
kprintf("\n\nvoid printsegaddress():");
//kprintf("\nCurrent: etext[0x%x]= 0x%x", &etext,etext, &_edata,_edata);
kprintf("\nCurrent: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x", etext_addr,*etext_addr,_edata_addr,*_edata_addr,_end_addr,*_end_addr);
kprintf("\nPreceding: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x", (etext_addr-1),*(etext_addr-1),(_edata_addr-1),*(_edata_addr-1),(_end_addr-1),*(_end_addr-1));
kprintf("\nAfter: etext[0x%08x]=0x%08x, edata[0x%08x]=0x%08x, ebss[0x%08x]=0x%08x", (etext_addr+1),*(etext_addr+1),(_edata_addr+1),*(_edata_addr+1),(_end_addr+1),*(_end_addr+1));
}
