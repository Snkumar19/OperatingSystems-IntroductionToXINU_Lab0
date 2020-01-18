/* zfunction.s - zfunction */

        
        .text
        .globl        zfunction

zfunction:
        push   %ebp
        mov    %esp,%ebp
        sub    $0x10,%esp
        mov    0x8(%ebp),%eax
        and    $0xff803fff,%eax
        shl    $0x4,%eax
        mov    %eax,-0x4(%ebp)
        mov    -0x4(%ebp),%eax
        leave  
        ret            
