# Shell (user program)

\
Shell program is pretty simple and it can only execute simple arithmetic operations. User can prompt the shell by executing `CALC` command and passing operands and operations. For example:

```
	CALC 10 + 4 / 7
```

Will output 1. User can specify multiple operands and operations and there is no operation priority.

Under the hood shell program calls `scanf` and `printf` functions that use system calls to read and write characters to the screen.

<div style="page-break-after: always; visibility: hidden">\pagebreak</div>
