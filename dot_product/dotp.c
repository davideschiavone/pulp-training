//#define ADD_NOP
//define ADD_NOP in case the HWLoop is unaligned, otherwise to fetch the first instruction it takes 2 cycles


unsigned int dotproduct(unsigned int acc, unsigned char* vA, unsigned char* vB, unsigned int N)
{
    int i;
    unsigned char elemA, elemB;
    unsigned int instr, cycles, ldstall, jrstall, imstall;

        asm volatile(
#ifdef ADD_NOP
            "c.nop;"
#endif
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
    unsigned int instr, cycles, ldstall, jrstall, imstall;


    //ADD HERE YOUR OPTIMIZED VERSION
    asm volatile();

    return acc;
}


unsigned int dotproduct_loopunroll_simd(unsigned int acc, unsigned char* vA, unsigned char* vB, unsigned int N)
{
    int i;
    unsigned int elemA, elemB, elemD, elemE;
    unsigned int instr, cycles, ldstall, jrstall, imstall;


    //ADD HERE YOUR OPTIMIZED VERSION with the use of SIMD instructions
    asm volatile();


    return acc;
}