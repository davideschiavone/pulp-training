# Dot Product C program

This application contain a simple dot product function between 2 byte-vectors of 1000 elements.

The innermost kernel is written in assembler to give you the whole control of the instructions
executed by the core.

For a quick guide to use assembler in GCC have a look at https://gcc.gnu.org/onlinedocs/gcc/Extended-Asm.html

```
Compile the application (make clean all)
Generate the assember (make dis > dis.s)
Run it in gui mode (make run gui=1)
```

Identify the dot product parts in the assembler.
After executing the code, check both the trace file in ./build/pulpissimo/trace_core_1f_0.log to see the instructions executed by the core and the assembly.
Can you find the dot product part?

```
How many cycles do you expect from such function? Why?
```

## Loop Unrolling

Improve the application using the loop unrolling technique we have seen at the lecture.
Complete the provided function and repeat the step above.

```
How many cycles do you expect from such function?
Analyze the trace around your function. Where is the stall?
```

## Use of the SIMD instructions

Rewrite the function to implement the dot product using the sum of dot product function
that you find the PULP extensions of the RI5CY core (in its user_manual.doc)

```
Complete the function.
How many cycles do you exept from such function?
Fix the HWloop first instruction address if needed.
What is the speed up?
```
