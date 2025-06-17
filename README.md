# Ame-Compiler

This is a simple compiler I'm building from scratch — starting with tokenizing and converting `return` statements into x86-64 assembly.

I began this project to understand what really happens behind the scenes when we go from high-level languages like C++, Java, or Python... all the way down to bare metal. After learning Assembly in my Microprocessor and Interfaces class, I was blown away by the jump in abstraction — and honestly, I’m just a nerd who likes to tweak things.

I’m not great at Assembly (yet), and maybe that’s why I find it so fascinating that high-level languages save us from writing all that manually. So, I'm building a compiler — not because I have to, but because I *want* to.

---

## What It Does (So Far)

- Tokenizes simple programs like:

```c
return 21;
```

- Translates that into x86-64 Assembly (Linux syscall):

```asm
mov rax, 60     ; syscall number for exit
mov rdi, 21     ; exit code
syscall
```

- Uses `nasm` and `ld` to compile the `.asm` into an executable.

- You can run the resulting binary and get the correct exit status using `echo $?`.

---

## Example Usage

```bash
g++ main.cpp -o ame
./ame ../test.ame
nasm -felf64 out.asm
ld -o out out.o
./out
echo $?
# Output: 21
```

---

## Why I’m Building This

-> *"I wanted to build this compiler to understand how languages actually work. I’ve always wondered how we went from Assembly to C++ or Python. This project is for learning, fun, and becoming more comfortable with low-level concepts."*
-> - Mehul Arya

---

## Tools & Tech

* C++
* NASM (Netwide Assembler)
* GNU `ld`
* A little bit of terminal muscle

---

## Future Plans

I plan to keep growing this compiler as I learn more.

---

## References & Inspirations

* MIT OpenCourseWare (MIT 6.035 Computer Language Engineering, Fall 2005)
* ChatGPT (for guidance and review)
* Google & YouTube (of course!)
* Curiosity and a desire to know what happens under the hood

---

## About Me

Hi, I’m **Mehul Arya**, a curious CS undergrad who loves learning by building things.

* [LinkedIn](https://www.linkedin.com/in/mehularya/)
* I like programming, philosophy, and tweaking with fun technology. 

---

## Getting Started

Clone the repo, write `.ame` files, and run them through your compiler:

```bash
git clone https://github.com/your-username/your-compiler-repo.git
cd your-compiler-repo
g++ main.cpp -o ame
./ame ../test.ame
nasm -felf64 out.asm
ld -o out out.o
./out
echo $?
```

---

## Thanks

Thanks to everyone who publishes open content — this project is built with curiosity and community support.

-> "I’ll keep updating this compiler and README as I learn more."
