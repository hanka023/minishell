# Minishell 

A minimalistic version of Unix shell written in C as part of the 42 School curriculum, mimicking core `bash` functionality.

## How to use 

compile with make (or make re)
start: ./minishell

makefile supports: make cleaan, make fclean

## Features

The shell supports:

Prompt display and user input
Command execution with arguments
Environment variable handling

Built‑in commands:

echo
cd
pwd
export
unset
env
exit
Quote handling

Redirections (>, >>, <)
Pipes (|)
Signal handling (Ctrl+C, Ctrl+\)

## Project Structure

Minishell
│
├── parsing	            # Parsing part
├── execute/            # Execution part
├── Makefile            # Build rules
├──	main.c
└── README.md

Signal handling (e.g., Ctrl+C, Ctrl+\)

