# Minishell 


*This project has been created as part of the 42 curriculum by jkralice [Jachym Kralicek], haskalov [Hana Skalova]*


## Description

A minimalistic version of Unix shell written in C as part of the 42 School curriculum, mimicking core `bash` functionality.


### Features


The shell supports:
```text
- Prompt display and user input (`readline`)
- Command execution with arguments (`path` resolution)
- Environment variable expansion (`$VAR`, `$?`)
- Built‑in commands: `echo` (with `-n`), `cd`, `pwd`, `export`, `unset`, `env`, `exit`
- Quote handling (single and double quotes)
- Redirections (`<`, `>`, `>>`, `<<` heredoc)
- Pipes (`|`)
- Signal handling (`SIGINT`, `SIGQUIT`, `EOF`)
```


## Project Structure

```text
Minishell/
├── parsing/
├── execute/
├── Makefile
├── main.c
└── README.md
```

## Instructions
```text
Compile:   `make` (or `make re`)
Start:     `./minishell`
Quit:      type `exit` or press `Ctrl + D`

Makefile rules:** `make clean`, `make fclean`, `make re`
```

## Resources


Linux programming interface https://broman.dev/download/The%20Linux%20Programming%20Interface.pdf  
> Main source about knowledge about processing

Minishell tester https://github.com/LucasKuhn/minishell_tester

https://github.com/dkolarova/Minishell/tree/main good example of project


### AI used 

> AI used as advisor, for helping choose best strategy of work, for checking bugs and expalining outputs from fsanitize debugger

