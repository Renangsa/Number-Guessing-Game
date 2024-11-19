#include <iostream>

using namespace std;
int main()
{
    bool game = true;
    setlocale(LC_ALL, "pt_BR.UTF-8");
    // When the game starts, it should display a welcome message along with the rules of the game.
    while (game)
    {
        cout << "Bem-vindo ao jogo de adivinhação de números!\n";
        cout << "Digite 0 para: Acessar regras!\n";
        cout << "Digite 1 para: Jogar!\n";
        cout << "Aguardando resposta: ";
        int entry;
        cin >> entry;

        if (cin.fail()) // Verifica se houve erro na entrada
        { 
            cin.clear(); // Limpa o estado de erro
            cin.ignore(1000, '\n'); // Ignora os caracteres restantes no buffer
            cout << "Entrada inválida! Tente novamente.\n";
            continue; // Reinicia o loop
        }


        switch (entry)
        {
            case 0:
                cout << "-> O computador escolherá aleatoriamente um número secreto entre 1 e 100.\n";
                cout << "-> Seu objetivo é adivinhar qual é esse número.\n";
                cout << "-> Você terá um número limitado de tentativas para acertar.\n";
                cout << "-> Se você adivinhar corretamente, o jogo termina e você vence!\n";
                cout << "-> Caso contrário, o jogo continuará até que suas tentativas se esgotem e você perca.\n";
                cout << "-> Boa sorte!\n";
                cout << "-------------------------------------------------------------------------------------\n\n";
                break;
            case 1:
                game = false;
                break;
            default:
                cout << "Entrada inválida! "; 
                system("Pause");
                break;
        }
    }
    
    return 0;
}