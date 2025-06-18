# Ame-Compiler

This is a simple compiler I'm building from scratch — starting with tokenizing and converting programs like `exit 21;` into x86-64 assembly.

I began this project to understand what really happens behind the scenes when we go from high-level languages like C++, Java, or Python... all the way down to bare metal. After learning Assembly in my Microprocessor and Interfaces class, I was blown away by the jump in abstraction — and honestly, I’m just a nerd who likes to tweak things.

I’m not great at Assembly (yet), and maybe that’s why I find it so fascinating that high-level languages save us from writing all that manually. So, I'm building a compiler — not because I have to, but because I *want* to.

---

## What It Does (So Far)

* Tokenizes very simple `.ame` programs like:

```c
exit 21;
```

* Translates them into x86-64 Assembly using Linux system calls:

```asm
mov rax, 60     ; syscall number for exit
mov rdi, 21     ; exit code
syscall
```

* Outputs this to `out.asm`, which is assembled and linked into a Linux executable.

* Automatically:

  * Assembles the `.asm` using `nasm`
  * Links the object file using `ld`
  * Produces a binary called `out`

* Run the binary and get the correct exit status with:

```bash
echo $?
```

---

## Example Usage

```bash
g++ main.cpp -o ame
./ame test.ame
# Generates out.asm -> out.o -> out
./out
echo $?
# Output: 21
```

Contents of `test.ame`:

```c
exit 21;
```

---

## Why I’m Building This

> *"I wanted to build this compiler to understand how languages actually work. I’ve always wondered how we went from Assembly to C++ or Python. This project is for learning and having fun."*
> – Mehul Arya

---

## Tools & Tech Used

* C++ (core compiler logic)
* NASM (Netwide Assembler)
* GNU `ld` (linker)
* Linux syscalls (no libc)
* Terminal, because command-line is cool

---

## Future Plans

* Add support for arithmetic expressions: `exit 10 + 11;`
* Parse and generate intermediate representation (IR)
* Add error messages with line/column positions
* Implement a proper parser (recursive descent?)
* Learn about registers, stack, and calling conventions

---

## References & Inspirations

* MIT 6.035 - Computer Language Engineering (Fall 2005)
* [ChatGPT](https://openai.com/chatgpt) – helped me when I was stuck
* YouTube, Google, StackOverflow – always open
* Curiosity & late-night "what if I built a compiler" thoughts

---

## About Me

Hi, I’m **Mehul Arya**, a curious CS undergrad who loves learning by building things.

* [LinkedIn](https://www.linkedin.com/in/mehularya/)
* Into programming, philosophy, and the magic of code touching bare metal

---

## Getting Started

```bash
git clone https://github.com/your-username/ame-compiler.git
cd ame-compiler
g++ main.cpp -o ame
./ame test.ame
nasm -felf64 out.asm -o out.o
ld -o out out.o
./out
echo $?
```

---

## Thanks

Thanks to everyone who publishes open content — this project is built with curiosity and community support.

> I’ll keep updating this compiler and README as I learn more. Stay tuned!

---