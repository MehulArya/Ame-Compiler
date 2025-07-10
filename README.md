# Ame Compiler

Ame is a toy compiler for a minimalistic programming language that supports basic variable declarations and program termination via the `exit()` statement.

This compiler performs:
- Tokenization of source code into lexical tokens.
- Parsing into an Abstract Syntax Tree (AST).
- Code Generation into x86-64 NASM assembly.
- Assembly & Linking using `nasm` and `ld` to produce an executable.

## Language Features

Currently, the language supports:
- Integer literals and identifiers.
- Variable declarations using `let`.
- Exiting a program using `exit(expression);`.

### Example Input (`input.ame`)

```plaintext
let x = 9;
let y = 7;
exit(x);
```

This program will return 9 as the exit code of the compiled executable.

## Build Instructions

### Requirements

- C++17 compatible compiler
- NASM (Netwide Assembler)
- GNU linker (`ld`)

### Compile the Compiler

```bash
g++ Main.cpp -o Ame
```

### Run

```bash
./Ame input.ame
```

This will generate:
- `out.asm`: NASM assembly code
- `out.o`: Object file
- `out`: Executable binary

Run the output:

```bash
./out
echo $?  # Check the exit code (will output 9 for above example)
```

## Project Structure

```
.
├── Main.cpp          # Entry point for the compiler
├── tokenization.h    # Lexer: Token definitions and tokenizer class
├── parser.h          # Parser: AST structures and parsing logic
├── generation.h      # Code generator for x86-64 NASM output
├── input.ame         # Sample input program
├── out.asm           # Generated NASM assembly
├── out.o             # Compiled object file
└── out               # Final executable
```

## Notes

- The compiler only supports `exit(expr);` with either literals or declared variables.
- Variable shadowing or complex expressions are not yet supported.
- This is a proof-of-concept and educational compiler project.

## Future Improvements

- Support arithmetic operations (e.g., `+`, `-`)
- Add variable reassignment and scoping
- Implement functions or loops
- Better error handling and diagnostics

## Author

**Mehul Arya**  
[LinkedIn](https://www.linkedin.com/in/mehul-arya-3063a630b/)

## License

This project is for educational purposes and currently does not include a specific license.
