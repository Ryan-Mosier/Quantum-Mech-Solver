# Quantum-Mech-Solver

A robust mathematical expression solver and compiler written in modern C++. I intend to use this during my upcoming QM classes (spring 2026).

This project is also intended to showcase various stages of computer science and electrical engineering concepts, from
software abstractions to hardware-level execution.

# For my future reference:

## Project Status

The project is currently in the **Phase 1: Parsing & AST** stage. The goal is to transform raw string inputs into a structured Abstract Syntax Tree using the **Strategy Pattern** for operator evaluation and a recursive **Composite Pattern** for the tree structure.

## Project Vision & Roadmap

The project is structured to showcase various stages of computer science and electrical engineering concepts, from software abstractions to hardware-level execution.

### Phase 1: Parsing & AST (Functional Design)
- **Concept:** Transform raw string inputs into a structured Abstract Syntax Tree.
- **Implementation:** Uses the **Strategy Pattern** for operator evaluation and a recursive **Composite Pattern** for the tree structure.
- **Key Skills:** OOP Design Patterns, Recursive Algorithms, Pratt Parsing.

### Phase 2: AST Flattening (Data-Oriented Design)
- **Concept:** Move from a "forest of pointers" to a cache-friendly memory layout.
- **Implementation:** Flatten the recursive tree into a `std::vector` (Node Pool).
- **Key Skills:** Memory Management, CPU Cache Locality, Data-Oriented Design (DOD).

### Phase 3: Bytecode Generation (Intermediate Representation)
- **Concept:** Define a custom Instruction Set Architecture (ISA) and compile the AST into linear bytecode.
- **Implementation:** Convert the flattened AST into instructions like `PUSH`, `ADD`, `MUL`, etc., suitable for a Virtual Machine.
- **Key Skills:** Compiler Theory, Intermediate Representation (IR) design.

### Phase 4: Assembly Translation (Native Execution)
- **Concept:** Translate bytecode instructions into native x86-64 (or ARM?) assembly code.
- **Implementation:** A backend that emits assembly text, managing CPU registers (like `rax`, `rbx`) and the call stack.
- **Key Skills:** Instruction Set Architecture (ISA), Register Allocation, Calling Conventions.

### Phase 5: Toolchain Integration
- **Concept:** Use professional assemblers and linkers to produce a standalone executable.
- **Implementation:** Integration with `NASM` or `GCC` to assemble and link the generated code into a runnable binary.
- **Key Skills:** Professional Toolchain usage (Assemblers, Linkers), System Integration.
