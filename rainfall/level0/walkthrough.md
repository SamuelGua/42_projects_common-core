# Analyse du code

Avec GDB et ghidra nous voyons que le programme set les droits en tant qu'utilisateur
level1 et ensuite ouvre un bash a condition que la valeur de l'input est de 0x1a7 soit 423

# Prise du flag

./level0 423
$ cat /home/user/level1/.pass
$ 1fe8a524fa4bec01ca4ea2a869af2a02260d4a7d5fe7e7c24d8617e6dca12d3a