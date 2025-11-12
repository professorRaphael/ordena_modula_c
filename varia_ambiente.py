import os
import subprocess

def adicionar_ao_path_permanente(novo_caminho):
    """
    Adiciona um novo caminho à variável de ambiente PATH do usuário no Windows.
    Esta mudança é permanente, mas requer uma nova sessão de console para ter efeito.
    """
    try:
        # Comando SETX para adicionar ao PATH do usuário atual (/M para sistema)
        # O subprocess.run é usado para executar o comando setx do Windows
        subprocess.run(f'setx PATH "%PATH%;{novo_caminho}"', shell=True, check=True)
        print(f"Caminho '{novo_caminho}' adicionado permanentemente ao PATH do usuário.")
        print("Por favor, feche e reabra o terminal ou IDE para que as mudanças tenham efeito.")
    except subprocess.CalledProcessError as e:
        print(f"Ocorreu um erro ao tentar adicionar o caminho: {e}")
    except Exception as e:
        print(f"Ocorreu um erro inesperado: {e}")

# Caminho a ser adicionado
caminho_msys = r"C:\msys64\ucrt64\bin"

# Executar a função
adicionar_ao_path_permanente(caminho_msys)
