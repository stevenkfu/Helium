# Helium
Title: Helium: on top of Neon
Team Members: Steven Fu and Christopher Hung (skfu and christoh)

Summary:

We are going to implement a math library using NEON to take advantage of ARM advanced SIMD. We will perform analytics on the runtime of our library compared to other implementations and various programs utilizing our library across different vector widths as well as compile and run an application for Android that includes our library.

Background: 

We plan to use ARM advanced SIMD (NEON) to build a library of commonly used math functions and matrix operations. Since programs frequently perform mathematical operations over arrays, it would be of benefit to exploit SIMD to speed up the computation. This would become a library that developers could include in their programs or applications and replace existing loops with, by calling the library’s functions on their desired arrays or matrices. Using Android NDK, developers will be able to include our library functionality to assist in intensive but parallelizable computations in their apps.

The Challenge:

Because the user input would be of various lengths, it would be a challenge to figure out what SIMD vector widths to use depending on input, and how to best partition the work to be done to result in the best performance. Other difficulties are the vector and matrix operations that we plan to attempt to parallelize, which may not have high degrees of parallelism and have many alternative algorithms available. It would require testing and benchmarking to find a balance between the parallelizable components and the speedup that can be gained on those vs. the speed of an algorithm that may have fewer parallelizable steps.
We want to learn how to compile and run Android applications with our written library. We also hope to learn how to leverage the library’s functions to implement algorithms that have parallelism, e.g. those in signal or image processing. Another component would be to compare the performance of our library to other existing ones, such as Ne10 to see how close they are in performance and if there are optimizations to be made without writing assembly. 

Resources: 

We will be starting from scratch and using the Neon SIMD intrinsics to create our library. From there, we will test our implementation of certain operations against existing implementations such as Ne10. 
For more advanced operations such as large matrix multiplication, we may look into researched algorithms to achieve desired speedups if we are unable to with our own implementations. 

Goals and Deliverables:

We hope to learn how much speedup can be expected by using SIMD over sequential versions on ARM, since we have already studied this for x86 in class. We want to answer questions such as how to best optimize math and vector operations in a way that is generalized for various input sizes and values, and how the performance of our library compares to other professional and amateur implementations.

Plan to achieve:
Using NEON, implement arithmetic functions that operate on arrays to exploit SIMD, and vector and matrix operations such as inverse, transpose, multiply, and determinant.
Performance-wise, see how close to Ne10’s assembly implementation we can get using only NEON intrinsics.
Analysis of the performance of our implementation compared to other libraries.

Hope to achieve:
Android application that uses our library to implement signal or image processing, demonstrating a meaningful speedup over a sequential version that does not use SIMD.


Platform Choice:

We have chosen the ARM architecture as our platform because it is one that we have not studied much in class, and has been targeted as a low power consumption platform. It would be interesting to see how beneficial SIMD on ARM is, given that NEON is less flexible than the SIMD intrinsics for x86 and supports smaller widths. 

Schedule:

4/10 - 4/15:
Write benchmark sequential versions of the basic math operations that we plan to implement with NEON and begin implementing the SIMD versions and testing them on Linux.

4/16 - 4/22:
Finish writing SIMD versions and run speedup comparisons with the benchmark implementation as well as compare to existing Neon implementations and identify areas we can optimize further.


4/23 - 4/29:
Continue optimizing operations and begin identifying how to link and compile our library with an Android application.

4/30 - 5/6:
Write algorithms and an Android application that use our library to implement features such as image or signal processing.
