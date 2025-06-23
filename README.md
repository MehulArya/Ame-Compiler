# Ame Compiler

A toy compiler written in modern **C++** that translates a minimal language (`.ame`) into **x86-64 Linux assembly**. Currently supports simple programs like:

```c
exit 21;
```

which compile down to:

```asm
mov rax, 60     ; syscall: exit  
mov rdi, 21     ; exit code  
syscall
```

Built from scratch to explore how compilers work — from tokenizing source code to generating executable binaries.

---

## Features

* Tokenizer
  Parses `.ame` source files into tokens (`exit`, integer literals, semicolons).

* Parser
  Builds a minimal AST (Abstract Syntax Tree) with support for integer expressions in `exit` statements.

* Code Generator
  Generates x86-64 assembly code that uses Linux syscalls to exit with a user-defined code.

* Assembler & Linker Integration
  Automatically:

  * Assembles with NASM
  * Links with ld
  * Outputs an executable binary: `out`

---

## Example

### Input: `test.ame`

```c
exit 21;
```

### Compile and Run

```bash
g++ main.cpp -o ame
./ame test.ame      # Generates out.asm, compiles and links it
./out               # Run the compiled binary
echo $?             # Output: 21
```

---

## Project Structure

```
ame-compiler/
├── main.cpp          # Entry point: reads .ame files and drives compilation
├── tokenization.h    # Token definitions and tokenizer class
├── parser.h          # AST structures and parser
├── generation.h      # Assembly code generator
├── test.ame          # Sample Ame program
└── README.md
```

---

## Future Plans

* Add arithmetic expression support: `exit 10 + 11;`
* Add proper error reporting (line/column)
* Implement recursive descent parsing
* Build an intermediate representation (IR)
* Support variables and function definitions
* Learn stack/register-level architecture deeper

---

## Why I’m Building This

<<<<<<< HEAD
> “Those who can imagine anything, can create the impossible.”
> — Dr. Alan Turing

---

## Tools and Technologies

* C++ for compiler implementation
* NASM for assembly
* GNU `ld` for linking
* Linux syscalls (without libc)
* Terminal-based development and testing

---

## References and Inspirations

* MIT 6.035 - Computer Language Engineering
* ChatGPT for guidance and debugging help
* Stack Overflow, YouTube, and documentation
* Curiosity and exploration
=======
* MIT 6.035 - Computer Language Engineering (Fall 2005)
* ChatGPT
* YouTube, Google, StackOverflow – always open
* Curiosity & late-night "what if I built a compiler" thoughts
>>>>>>> 6906d37357154c9ccd1133b6736853f464b154ca

---

## About Me

Hi, I’m **Mehul Arya**, a computer science undergrad who enjoys learning by building things from scratch. I’m especially interested in how code touches bare metal.

* [LinkedIn](https://www.linkedin.com/in/mehularya/)
* [LeetCode](https://leetcode.com/u/2RDp5z7CQu/)

---

## Getting Started

```bash
git clone https://github.com/your-username/ame-compiler.git
cd ame-compiler
g++ main.cpp -o ame
./ame test.ame
./out
echo $?
```

---

## Thanks

Thanks to the open-source community and educators who freely share knowledge. This project is built on the foundation of that generosity.

I will keep updating this compiler and README as I learn more.

---
