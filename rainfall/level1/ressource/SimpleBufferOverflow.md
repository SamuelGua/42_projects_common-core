# Buffer overflow

## Definition

Un buffer overflow (ou débordement de tampon) en C se produit lorsqu'un programme écrit plus de données que prévu dans une zone mémoire (buffer), écrasant ainsi des données adjacentes, ce qui peut provoquer des comportements indéterminés, des plantages, ou être exploité pour exécuter du code malveillant.

## Schema stack frame

```bash
|--------------------------|  <-- Valeurs hautes (vers le bas de la pile)
|     Variables locales    |
|		(Buffer[16])	   |  ← créées par la fonction
|--------------------------|
|  Adresse de retour EIP   |  ← où le programme doit revenir après l’appel
|--------------------------|
|  Ancien EBP		       |  ← pour restaurer le cadre précédent
|--------------------------|
|  Arguments 	           |  ← passés à la fonction (par l’appelant)
|--------------------------|  <-- Valeurs basses (vers le haut de la pile)
```

## Exploit

Pour exploiter un buffer overflow, l’attaquant remplit le buffer au-delà de sa taille pour écraser l’adresse de retour (EIP).

L’objectif est de :

-	Remplacer EIP par une adresse pointant vers du code malveillant (ex: un shellcode injecté).
-	Rediriger l’exécution vers une fonction système utile (ex: system("/bin/sh")).

## 📌 Exemple de payload (simplifié) :

[padding pour remplir le buffer][adresse cible dans EIP]

