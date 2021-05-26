#include "pulp.h"

unsigned int dotproduct(unsigned int acc, unsigned char* vA, unsigned char* vB, unsigned int N)
{
    int i;
    unsigned char elemA, elemB;

        asm volatile(
            ".align 4;"
            "lp.setup x0,%[n_elem],stop_loop;"
            "p.lbu %[a], 1(%[addrA]!);"
            "p.lbu %[b], 1(%[addrB]!);"
            "stop_loop: p.mac %[c], %[a], %[b];"
            : [c] "+r" (acc), [a] "+r" (elemA), [b] "+r" (elemB), [addrA] "+r" (vA), [addrB] "+r" (vB) : [n_elem] "r" (N));

    return acc;
}

unsigned int dotproduct_loopunroll(unsigned int acc, unsigned char* vA, unsigned char* vB, unsigned int N)
{
    int i;
    unsigned char elemA, elemB, elemD, elemE;

    //ADD HERE YOUR OPTIMIZED VERSION
    asm volatile(
            ".align 4;"
    );

    return acc;
}


unsigned int dotproduct_loopunroll_simd(unsigned int acc, unsigned char* vA, unsigned char* vB, unsigned int N)
{
    int i;
    unsigned int elemA, elemB, elemD, elemE;

    //ADD HERE YOUR OPTIMIZED VERSION with the use of SIMD instructions
    asm volatile(
            ".align 4;"
    );

    return acc;
}