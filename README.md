# Quantum-Mech-Solver

A robust mathematical expression solver and compiler written in modern C++. I intend to use this during my upcoming QM classes (spring 2026).

This project is also intended to showcase various stages of computer science and electrical engineering concepts, from
software abstractions to hardware-level execution.

# For my future reference:

## Project Status

This is a snapshot of the project at the end of **Phase 1: Parsing & AST**.
At this point, the project is still in its infancy and has some major limitations.
The AST is recursive, which can lead to stack overflow issues for large expressions.
The project is also missing a lot of features, as it only supports a small subset of mathematical operations and does
not support vectors or matrices.

This phase can be properly seen as a proof of concept and serves as a good starting point for future work.

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
