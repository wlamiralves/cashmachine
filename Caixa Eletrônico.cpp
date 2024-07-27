#include <iostream>
#include <locale.h>
#include <cstdlib> // Para usar system("pause") no Windows

using namespace std;

void limparTela() {
    // Limpar a tela do console
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void exibirMenu() {
    // Exibir o menu principal
    cout << "\n========================================\n";
    cout << "           Bem-vindo ao Caixa           \n";
    cout << "========================================\n";
    cout << "Escolha uma opção:\n";
    cout << "1. Sacar dinheiro\n";
    cout << "0. Sair\n";
    cout << "========================================\n";
    cout << "Opção: ";
}

void sacar(int valor) {
    int notas[] = {200, 100, 50, 20, 10, 5, 2};
    int quantidade[7] = {0};

    for (int i = 0; i < 7; ++i) {
        quantidade[i] = valor / notas[i];
        valor %= notas[i];
    }

    limparTela();
    cout << "\n========================================\n";
    cout << "            Saque realizado             \n";
    cout << "========================================\n";
    cout << "Notas retiradas:\n";
    for (int i = 0; i < 7; ++i) {
        if (quantidade[i] > 0) {
            cout << "Nota(s) de " << notas[i] << ": " << quantidade[i] << "\n";
        }
    }
    cout << "========================================\n";
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao, valor;

    do {
        exibirMenu();
        cin >> opcao;

        switch (opcao) {
            case 1:
                limparTela();
                cout << "========================================\n";
                cout << "           Saque de Dinheiro             \n";
                cout << "========================================\n";
                cout << "Digite o valor a ser sacado (entre 2 e 2000):\n";
                cout << "Valor: ";
                cin >> valor;
                if (valor < 2 || valor > 2000) {
                    cout << "Valor inválido! Tente novamente.\n";
                } else {
                    sacar(valor);
                }
                break;
            case 0:
                limparTela();
                cout << "Obrigado por utilizar nosso serviço!\n";
                break;
            default:
                limparTela();
                cout << "Opção inválida! Tente novamente.\n";
                break;
        }

        // Aguardar confirmação do usuário antes de limpar a tela
        cout << "\nPressione Enter para continuar...";
        cin.ignore();
        cin.get();

        limparTela();

    } while (opcao != 0);

    return 0;
}

