[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/f_6PzPyj)
# ds-graphical-recursive

Let's get creative. On this lab, you will be creating a recursive program that generates the base for a graphical recursive algorithm. Since we haven't seen any graphics library, you don't need to worry about the visualization, the professor will provide the mechanism ro visualize your data.

From the _Essential Algorithms: A Practical Approach to Computer Algorithms_ book, in [Chapter 9: Recursion](https://learning.oreilly.com/library/view/essential-algorithms-a/9781118612101/17_chapter09.html#c09-5), implement one of the following 3 graphical recursive algorithms

- Koch Curves
- Hilbert Curve
- Sierpiński Curve

# Implementation Requirements

- Each algorithm has its own parameters, make sure you document them in the [following section](#how-to-compile--run-you-program)
- Parameters must be sent through the command line. Example below:
    ```
    ./your-program <param1> <param2> ... 
    ```
- The output of your program will be a list of line segments in a file called `lines.txt`. The `lines.txt` file must follow the following format. Each pair represents a point in a 2D plane
    ```
    (1,2)(33,3)
    (3,5)(3,43)
    (2,1)(3,3)
    ```
- There's a 1024x1024 canvas, make sure that your generated points are inside that limited space. 
- The progressor will provide the mechanism to visualize your data, just make sure you generate the proper `lines.txt` file




# How to compile & run you program

- _You must document compilation and execution here_
- _Don't forget to document which algorithm you're implementing_

# Grading Policy

| **Rubric**                             | **Points** |
|----------------------------------------|------------|
| Successful Compilation                 | 25%        |
| Coding Practices                       | 5%         |
| Well formed `lines.txt` file           | 35%        |
| Proper Algorithm's graphics rendering  | 35%        |
| **Total**                              | 100%       |