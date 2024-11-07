# Pipex

Welcome to Pipex, a project from 42 School focused on understanding inter-process communication in Unix systems. This project involves creating a program that mimics the behavior of a shell pipeline, allowing data to be passed between commands via pipes. Working on Pipex introduced key concepts in process management, piping, and redirection in C. Also, I have done the bonus part, though I did not shorten the functions to be able to submit it in 42 School.

## Project Overview

Pipex replicates the Unix pipeline functionality (e.g., `cmd1 | cmd2`) by connecting the output of one command to the input of another. The program takes multiple command arguments, handles file redirection, and establishes pipes to transfer data between commands. Pipex is an introduction to forking processes, setting up pipes, and managing standard input and output in a controlled environment.

## Features

- **Process Management**: Uses `fork` to create child processes for each command in the pipeline.
- **Pipes for IPC**: Implements pipes to allow communication between commands, passing data as if through a standard Unix pipeline.
- **File Redirection**: Supports input and output file redirection, allowing commands to read from and write to specified files.
- **Error Handling**: Basic error handling for invalid commands, file access issues, and system calls.

## Usage

To use Pipex, compile the program and run it with input and output file arguments, along with the commands to pipe. For example:
```bash
./pipex infile "cmd1" "cmd2" outfile
```

This example would execute `cmd1`, pipe its output to `cmd2`, and write the final output to `outfile`.

## Compilation

To compile the project, run:
```bash
make
```

This will generate the `pipex` executable, which can then be used to test various command pipelines.

---

Pipex was a foundational project for understanding how Unix handles piping and process communication. It was a challenging yet rewarding experience that provided insight into core system-level concepts. Feel free to explore the code to see how Pipex brings shell pipelines to life!
