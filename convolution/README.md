Write your 2D convolutional layer for PULPissimo.

The convolutional neural network (CNN) layer takes as input a 16x16 image and
convolves a 5x5 filter followed by the linear rectifier activation function
(ReLU) with saturarion.

The image is represented by the Q1.13 fixed point format, thus they need
16bits to be stored.
This choice has been made to prevent overflow during the 5x5 convolution.
Look at the gen_stimuli.m matlab script for better understanding.

The filter has the same Q1.13 format.

1. Task 1
    - Complete the Conv5x5_Scalar function to implement the CNN layer.
        - Write normal C code as you would normally do
    - Compile it and run it. Check whether the results are correct or not.
    - Generate the assembler and look for possible source of load stalls.
    - Report the performance in the form of MAC/cycles.
    - [Optional] Rewrite the convolutional part of the Conv5x5_Scalar function to
    exploit loop unrolling as seen in the previous exercise.
        - Can you beat the compiler? Why?

2. Task 2
    - Compile the kernel written in Task 1 with PULP extensions.
    - Generate the assembler and look for possible source of load stalls.
    - Report the performance in the form of MAC/cycles.
    - [Optional] Rewrite the convolutional part of the Conv5x5_Scalar function to
    exploit loop unrolling as seen in the previous exercise.
        - Can you beat the compiler? Why?
       
To exploit the PULP pSIMD extensions, you need to let the compiler now that we want to use
vectors instead of normal scalar number.

To do so, GCC has some special attribute to be used in the data type and built-in functions
to force the use of special instrucions like for example the shuffle.

Have a look at https://gcc.gnu.org/onlinedocs/gcc/Vector-Extensions.html
for more information.

The file convolution.h explains the vector data types and the built-in functions
you need during the exercise.

3. Task 3
    -  Define in the Makefile the DOTP flag and complete the Conv5x5_Vector function.
        - Refer to the lecture to know the steps to do and use the built-in functions when needed.
    - Compile it and run it. Check whether the results are correct or not.
    - Generate the assembler and look for possible source of load stalls.
    - Report the performance in the form of MAC/cycles.
        - What is the speedup?




Useful information:

The  PULP builtin functions are defined [here](https://github.com/pulp-platform/pulp-riscv-gcc/blob/bfb8fa748e5d0c79b0958c7870cd42a4923c6d9f/gcc/config/riscv/pulp_builtins.def)

The PULP extensions are defined [here](https://cv32e40p.readthedocs.io/en/latest/instruction_set_extensions/)
