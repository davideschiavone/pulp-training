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
            "lp.setup x0,%[n_elem],stop_loop_lu;"
            "p.lbu %[a], 1(%[addrA]!);"
            "p.lbu %[b], 1(%[addrB]!);"
            "p.lbu %[d], 1(%[addrA]!);"
            "p.lbu %[e], 1(%[addrB]!);"
            "p.mac %[c], %[a], %[b];"
            "stop_loop_lu: p.mac %[c], %[d], %[e];"
            : [c] "+r" (acc), [a] "+r" (elemA), [b] "+r" (elemB), [d] "+r" (elemD), [e] "+r" (elemD), [addrA] "+r" (vA), [addrB] "+r" (vB) : [n_elem] "r" (N>>1));

    return acc;
}


unsigned int dotproduct_loopunroll_simd(unsigned int acc, unsigned char* vA, unsigned char* vB, unsigned int N)
{
    int i;
    unsigned int elemA, elemB, elemD, elemE;

    //ADD HERE YOUR OPTIMIZED VERSION with the use of SIMD instructions
    asm volatile(
            ".align 4;"
            "lp.setup x0,%[n_elem],stop_loop_simd;"
            "p.lw %[a], 4(%[addrA]!);"
            "p.lw %[b], 4(%[addrB]!);"
            "p.lw %[d], 4(%[addrA]!);"
            "p.lw %[e], 4(%[addrB]!);"
            "pv.sdotup.b %[c], %[a], %[b];"
            "stop_loop_simd: pv.sdotup.b %[c], %[d], %[e];"
            : [c] "+r" (acc), [a] "+r" (elemA), [b] "+r" (elemB), [d] "+r" (elemD), [e] "+r" (elemD), [addrA] "+r" (vA), [addrB] "+r" (vB) : [n_elem] "r" (N>>3));

    return acc;
}