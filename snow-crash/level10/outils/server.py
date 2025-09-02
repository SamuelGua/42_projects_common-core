import socket
import sys

def start_server(ip, port):
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((ip, port))
    server_socket.listen(5)
    print(f"Serveur démarré sur {ip}:{port}, en attente de connexions...")

    while True:
        client_socket, client_address = server_socket.accept()
        print(f"Connexion reçue de {client_address[0]}:{client_address[1]}")

        while True:
            data = client_socket.recv(1024)
            if not data:
                break
            print(f"Reçu: {data.decode('utf-8')}")

        client_socket.close()
        print(f"Connexion fermée avec {client_address[0]}:{client_address[1]}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("need arg: server.py   ip   port")
        exit(1)

    start_server(sys.argv[1], int(sys.argv[2]))