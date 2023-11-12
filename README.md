# Introduction
This repository provides a framework that you can use to deliberately practice implementing data structures.

# Quickstart
## Instructions (File Structure 1 - DSA Definition and Implementation)
1. Copy-paste one of the provided directories under `boilerplate`
2. Change the name of the directory into the name of the data structure you wish to practice implementing (e.g. `data-structure-1` to `binary-search-tree`)
3. Under the `_header.h` file in the `implementation-[number]` directory, place the structure definition and operations
4. In the adjacent `def.c` file, implement the logic of the operations defined in `_header.h`
5. In `main.c`, include the `def.c` file you just filled up and call the operations for testing
6. Should you wish to practice the same implementation again, create another folder under the same `implementation` directory and call it `v-[number]`, where `number` is your nth attempt to implement the data structure with the aforementioned implementation.
7. Redo steps 3-5. If the output for this new attempt isn't the same as that of the previous attempts, then refactor the new attempt until the output is the same (no need to rewrite tests!!)

## Instructions (File Structure 2 - DSA Implementation Only)
1. Copy-paste one of the provided directories under `boilerplate`
2. Change the name of the directory into the name of the data structure you wish to practice implementing (e.g. `data-structure-1` to `binary-search-tree`)
3. Under the `_header.h` file in the `implementation-[number]` directory, place the structure definition and operations
4. In the adjacent `def-[number].c` file, implement the logic of the operations defined in `_header.h`
5. In `main.c`, include the `def-[number].c` file you just filled up and call the operations for testing
6. Should you wish to practice the same implementation again, create `def-[number].c`file, where `number` is your nth attempt to implement the data structure with the aforementioned implementation, in the same directory as the previous one
7. Redo steps 3-5. If the output for this new attempt isn't the same as that of the previous attempts, then refactor the new attempt until the output is the same (no need to rewrite tests!!)

## Example
Say you want to practice implementing the `adt-list` data structure via the following implementations:

1. Linked List
2. Array
3. Cursor-based

Basing it off the boilerplate provided under `boilerplate/data-structure-1`, the resulting directory you can use for practice is as follows:

```c
| adt-list/
|-- main.c
|-- modules/
|---- linked-list-implementation/ // Implementation 1
|------ v1/ // Practice version 1
|-------- _header.h
|-------- def.c
|------ v2/ // Practice version 2
|-------- _header.h
|-------- def.c
|---- array-implementation/ // Implementation 2
|------ v1/ // Practice version 1
|-------- _header.h
|-------- def.c
|---- cursor-based-implementation/ // Implementation 3
|------ v1/ // Practice version 1
|-------- _header.h
|-------- def.c
```

# Philosophy
## Introduction
Deliberate practice is a learning technique wherein one focuses on improving a specific aspect of the skill they're trying to learn. They go into the practice session knowing what they need to improve and how to improve it. This repo provides a framework that allows one to perform deliberate practice in the context of data structures and algorithms.

The go-to method of learning how to implement data structures and algorithms is to...implement data structures and algorithms. However, when practicing this, there are a lot more steps than meets the eye. For example, when trying to implement a linked list, one normally creates a C file and starts coding right away. However, besides just writing the definition of a linked list and implementing the different operations, the student has to also do other things such as:

- Importing the necessary libraries
- Writing out tests to verify the correctness of the implementation

This additional overhead presents an additional challenge to the student which, although serves as practice for how to set up the C file from the ground up, takes away time and concentration the main point of the practice session - **implementing data structures**.

When a student is finished with this practice file and wishes to re-implement the data structure again later, he/she must create a new file and recreate everything.

## Purpose
The main goal of this repository is to allow students to focus more on implementing different data structures and algorithms. As such, the file organization proposed in this repository is optimized for such.


# File Structure
There are two file structures proposed in this repo, both of which can be found in the `boilerplate/` directory. The common elements present are as follows:

- `data-structure-[number]/` - The directory, labelled according to the name of the data structure you wish to practice, containing all the code for that data structure
- `main.c` - The main file where your code is to be executed. Here is where you define your tests for each implementation you have to verify that it works.
- `modules/` - The directory containing all the implementation code
- `implementation-[number]/` - The directory, labelled according to the name of the data structure implementation you want to practice, containing the code for all your implementations
- `_header.h` - The file containing the structure definition and operations
- `def.c` - The file containing the implementation of the operations defined in `_header.h`

## File Structure 1
```c
| data-structure-1/
|-- main.c
|-- modules/
|---- implementation-1/
|------ v1/
|-------- _header.h
|-------- def.c
|------ v2/
|-------- _header.h
|-------- def.c
|---- implementation-2/
|------ v1/
|-------- _header.h
|-------- def.c
|---- implementation-3/
|------ v1/
|-------- _header.h
|-------- def.c
```

Under the `implementation-[number]` folder, you can see a number of folders following the format `v-[number]`. These refer to the "versions", which are created when you want to practice the aforementioned implementation. Doing so allows you to practice everything about implementing the data structure, from structure definition to operation implementation. However, if you only want to focus on implementing the logic behind the implementation, you can use file structure 2 (see below).


## File Structure 2
```c
| data-structure-2/
|-- main.c
|-- modules/
|---- implementation-1/
|------ _header.h
|------ def-1.c
|------ def-2.c
|---- implementation-2/
|------ _header.h
|------ def-1.c
|------ def-2.c
```

Under the `implementation-[number]` folder, you can see a single `_header.h` file along with multiple other c files with the format `def-[number].c`. In this file structure, you can focus more on implementing the operations behind each data structure instead of having to redefine the structure in each version (unlike file structure 1 above).

## Conclusion

As was hopefully demonstrated, the proposed file structures allow you to focus on actually practice implementing data structures, instead of using up time on unnecessary overhead. As you can see, having the `main.c` file contain only the tests, instead of code for each implementation, allows you to test new implementation by simply replacing the import statement (i.e. the tests are implementation-agnostic). By drilling down the focus of your practice sessions to implementing data structures and algorithms, not only will your implementations be more optimized, but hopefully your grades as well 😉 Happy coding!

## Other Study Techniques

1. [Pomodoro Technique](https://todoist.com/productivity-methods/pomodoro-technique)
2. [Spaced Repetition](https://e-student.org/spaced-repetition/)
3. [Interleaving](https://psychology.ucsd.edu/undergraduate-program/undergraduate-resources/academic-writing-resources/effective-studying/other-learning-techniques.html#:~:text=Interleaved%20practice%20%E2%80%93%20when%20you%20are,B%20on%20the%20next%2C%20you)

## TODOS
1. Check if version number is necessary in `#ifndef`
2. Flesh out study techniques here w/ concrete examples
