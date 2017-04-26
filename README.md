# Helium: On top of Neon
## Team Members: Steven Fu and Christopher Hung (skfu and christoh)

### Summary:

We are going to implement a math library using NEON to take advantage of ARM advanced SIMD. We will perform analytics on the runtime of our library compared to other implementations and various programs utilizing our library across different vector widths as well as compile and run an application for Android that includes our library.

### Background: 

We plan to use ARM advanced SIMD (NEON) to build a library of commonly used math functions and matrix operations. Since programs frequently perform mathematical operations over arrays, it would be of benefit to exploit SIMD to speed up the computation. This would become a library that developers could include in their programs or applications and replace existing loops with, by calling the library’s functions on their desired arrays or matrices. Using Android NDK, developers will be able to include our library functionality to assist in intensive but parallelizable computations in their apps.

### The Challenge:

Because the user input would be of various lengths, it would be a challenge to figure out what SIMD vector widths to use depending on input, and how to best partition the work to be done to result in the best performance. Other difficulties are the vector and matrix operations that we plan to attempt to parallelize, which may not have high degrees of parallelism and have many alternative algorithms available. It would require testing and benchmarking to find a balance between the parallelizable components and the speedup that can be gained on those vs. the speed of an algorithm that may have fewer parallelizable steps.
We want to learn how to compile and run Android applications with our written library. We also hope to learn how to leverage the library’s functions to implement algorithms that have parallelism, e.g. those in signal or image processing. Another component would be to compare the performance of our library to other existing ones, such as Ne10 to see how close they are in performance and if there are optimizations to be made without writing assembly. 

### Resources: 

We will be starting from scratch and using the Neon SIMD intrinsics to create our library. From there, we will test our implementation of certain operations against existing implementations such as Ne10. 
For more advanced operations such as large matrix multiplication, we may look into researched algorithms to achieve desired speedups if we are unable to with our own implementations. 

### Goals and Deliverables:

We hope to learn how much speedup can be expected by using SIMD over sequential versions on ARM, since we have already studied this for x86 in class. We want to answer questions such as how to best optimize math and vector operations in a way that is generalized for various input sizes and values, and how the performance of our library compares to other professional and amateur implementations.

#### Plan to achieve:
Using NEON, implement arithmetic functions that operate on arrays to exploit SIMD, and vector and matrix operations such as inverse, transpose, multiply, and determinant.
Performance-wise, see how close to Ne10’s assembly implementation we can get using only NEON intrinsics.
Analysis of the performance of our implementation compared to other libraries.

#### Hope to achieve:
Android application that uses our library to implement signal or image processing, demonstrating a meaningful speedup over a sequential version that does not use SIMD.

### Platform Choice:

We have chosen the ARM architecture as our platform because it is one that we have not studied much in class, and has been targeted as a low power consumption platform. It would be interesting to see how beneficial SIMD on ARM is, given that NEON is less flexible than the SIMD intrinsics for x86 and supports smaller widths. 

### Schedule:

#### 4/10 - 4/15:
Write benchmark sequential versions of the basic math operations that we plan to implement with NEON and begin implementing the SIMD versions and testing them on Linux.

#### 4/16 - 4/22:
Finish writing SIMD versions and run speedup comparisons with the benchmark implementation as well as compare to existing Neon implementations and identify areas we can optimize further.

#### 4/23 - 4/29:
Continue optimizing operations and begin identifying how to link and compile our library with an Android application.

#### 4/30 - 5/6:
Write algorithms and an Android application that use our library to implement features such as image or signal processing.

## Checkpoint
### Work Completed:
- Serial and vector versions of 1xn vector addition, subtraction, multiplication
- Serial and vector versions of 2x2 and 4x4 matrix multiplication
- Serial versions of 2x2 and 4x4 matrix transpose, inverse, and multiply
- Benchmarking platform for timing both serial and vector functions.

#### 4/26.5 - 4/29: 
Finish writing matrix operations, including determinant and inverse in both serial (Steven) and vector (Christopher), study for exam (Steven & Christopher)
#### 4/30 - 5/3.5: 
Benchmark against existing Neon implementations (Steven) and improve our vector implementations (Christopher)
#### 5/3.5 - 5/06: 
Begin looking into how to use our library in an android app (Christopher), begin planning an application that will use some of the features we implemented (Steven)
#### 5/07 - 5/12: 
Finish app (Steven & Christopher) and compare performance between vector library and serial library (Christopher & Steven).

### Work completed so far:
We first had to learn how to set up an environment to be able to compile our code. We decided on using a Raspberry Pi to run our code because it comes with an ARMv7 processor that supports the Neon instruction set we are using. After that, we had to learn how to write a makefile that would compile and link the source code located in multiple files. Once we had the framework to compile our code set up, we could begin writing a benchmark suite and our library functions
	For our library functions, we started by writing the serial versions of add, subtract, and multiply and then wrote the vector versions of those functions. In our preliminary benchmarks, we saw a 50% speedup with vectors of width 4 for those 3 functions. We then moved on to matrix operations, starting with multiplication of 2x2 and 4x4 matrices (because Neon does not have native support for scatter and gather type operations with a stride length of more than 4). However, we were unable to get significant speedups with the 4x4 vector implementation over the serial one, so we will be looking into that as well as continuing to add more matrix functions to our library. 

At the parallelism competition, we plan to show some graphs of performance of our implementation of operations compared to serial versions and other libraries that use Neon. These will include graphs comparing basic operations on vectors and matrices, as well as the full application so that situations more reflective of real-world utilization can be compared. 

### Preliminary results:

<img src="/images/intadd.png" width="400"><img src="/images/floatadd.png" width="400">

At this point it is mostly a matter of coding and doing the work; however, one thing that may pose a significant challenge is integrating our work into an Android application, as we have no background knowledge in this and have no experience adding a library written in C to an Android application. Another possible difficulty is deciding on what application to write that will effectively utilize the vector and matrix operations that we have written, although graphics transforms are a direct application of 4x4 matrix multiplication. Finally, especially after measuring the speedup of our matrix multiplication algorithm, it may be difficult to achieve significant speedups over the sequential algorithm without embedding assembly in our code. 

