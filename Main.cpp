#include <iostream>
#include <random>

using namespace std;

bool wrongEntry()
{
        if (cin.fail()) // Verifica se houve erro na entrada
        { 
            cin.clear(); // Limpa o estado de erro
            cin.ignore(1000, '\n'); // Ignora os caracteres restantes no buffer
            cout << "Entrada inválida! Tente novamente.\n";
            return true;
        }
        else
            return false;
}

struct GameMode
{
    int chances;
    int tries;
    string difficulty;
    GameMode()
    {
        tries = 0;
        chances = 0;
        difficulty = "None";
    }
};


int main()
{
    bool playing = true;
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));
    // When the game starts, it should display a welcome message along with the rules of the game.
    while (playing)
    {
        int randomNum= 1+ (rand() % 100);
        int entry;
        GameMode game;

        cout << "Bem-vindo ao jogo de adivinhação de números!\n";
        cout << "Digite 0 para: Acessar regras!\n";
        cout << "Digite 1 para: Jogar!\n";
        cout << "Aguardando resposta: ";
        cin >> entry;
        if(wrongEntry()) {continue;} // Reinicia o loop

        switch (entry)
        {
            case 0:
                cout << "-> O computador escolherá aleatoriamente um número secreto entre 1 e 100.\n";
                cout << "-> Seu objetivo é adivinhar qual é esse número.\n";
                cout << "-> Você terá um número limitado de tentativas para acertar.\n";
                cout << "-> Se você adivinhar corretamente, o jogo termina e você vence!\n";
                cout << "-> Caso contrário, o jogo continuará até que suas tentativas se esgotem e você perca.\n";
                cout << "-> Boa sorte!\n";
                system("Pause");
                cout << "-------------------------------------------------------------------------------------\n\n";
                break;
            case 1:
                cout << "Bem-vindo ao Jogo de Adivinhação de Números! Estou pensando em um número entre 1 e 100.\n";
                cout << "Selecione o nível de dificuldade:\n";
                cout << "1 - Easy (20 tentativas)\n";
                cout << "2 - Medium (10 tentativas)\n";
                cout << "3 - Hard (5 tentativas)\n";
                cin >> entry;
                if(wrongEntry()) {continue;} // Reinicia o loop
                
                switch (entry)
                {
                case 1:
                    game.chances = 20;
                    game.difficulty = "Easy";
                    break;
                case 2:
                    game.chances = 10;
                    game.difficulty = "Medium";
                    break;
                case 3:
                    game.chances = 5;
                    game.difficulty = "Hard";
                    break;
                default:
                    cout << "Entrada inválida! ";
                    system("Pause");
                    break;
                }
                cout << "A dificuldade selecionada foi o modo " << game.difficulty << endl;
                while (game.chances > 0) //Jogando
                {
                    cout << "Você tem " << game.chances << " tentativas restantes...\n";
                    cout << "Digite seu palpite: ";
                    cin >> entry;
                    if (wrongEntry())
                    {
                        continue;
                    }
                    else if (entry == randomNum)
                    {
                        cout << "Parabéns! Você acertou o número correto em " << game.tries << " tentativas\n";

                        break;
                    }
                    else
                    {
                        if (entry > randomNum)
                        {
                            cout << "Incorreto! O número que estou pensando é menor que " << entry << endl;
                        }
                        else if (entry < randomNum)
                        {
                            cout << "Incorreto! O número que estou pensando é maior que " << entry << endl;
                        }
                    }
                    game.chances--;
                }
                cout << "O número sorteado foi " << randomNum << "!\n";
                cout << "--------------------------------------\n";
                cout << "Obrigado por jogar. Até a próxima!\n";
                playing = false;
                break;
            default:
                cout << "Entrada inválida! "; 
                system("Pause");
                break;
        }
    }
    
    return 0;
}
