#include <chrono>
#include <print>
#include <cstdlib>
#include <iostream>


using std::cout;
using std::cin;
using std::chrono::steady_clock;

class GameMode
{
 public:
    void resetGameCache() {
        tries = 0;
        chances = 0;
        seconds = 0;
        difficulty = "None";
    }

    int tries = 0;
    bool exit = false;
    int chances = 0;
    double seconds = 0.0;
    std::string difficulty = "None";

};
/*class Player
{
    public:
    int highScore;

}; */

int checkInput(int input)
{
        while (cin.fail()) // Verifica se houve erro na entrada
        { 
            cin.clear(); // Limpa o estado de erro
            cin.ignore(1000, '\n'); // Ignora os caracteres restantes no buffer
            cout << "Entrada inválida! Tente novamente.\n";
            cin >> input;
        }
        return input;
}

void runGame(GameMode &gameInfo)
{
    if(!gameInfo.exit){
        int random_num = 1+ (rand() % 100);
        int input{};
        gameInfo.resetGameCache();

        cout << "Bem-vindo ao jogo de adivinhação de números!\n"
                "Digite 0 para: Acessar regras!\n"
                "Digite 1 para: Jogar!\n"
                "Digite 2 para: Sair!\n"
                "Aguardando resposta: ";
        cin >> input;

        switch (checkInput(input))
        {
            case 0:
                cout << "-> O computador escolherá aleatoriamente um número secreto entre 1 e 100.\n"
                        "-> Seu objetivo é adivinhar qual é esse número.\n"
                        "-> Você terá um número limitado de tentativas para acertar.\n"
                        "-> Se você adivinhar corretamente, o jogo termina e você vence!\n"
                        "-> Caso contrário, o jogo continuará até que suas tentativas se esgotem e você perca.\n"
                        "-> Boa sorte!\n";
                system("Pause");
                system("CLS");
                cout << "-------------------------------------------------------------------------------------\n\n";
                runGame(gameInfo);
                break;
            case 1:
            {
                cout << "Bem-vindo ao Jogo de Adivinhação de Números! Estou pensando em um número entre 1 e 100.\n";
                cout << "Selecione o nível de dificuldade:\n";
                cout << "1 - Easy (20 tentativas)\n";
                cout << "2 - Medium (10 tentativas)\n";
                cout << "3 - Hard (5 tentativas)\n";
                cin >> input;
                
                switch (checkInput(input))
                {
                    case 1:
                        gameInfo.chances = 20;
                        gameInfo.difficulty = "Easy";
                        break;
                    case 2:
                        gameInfo.chances = 10;
                        gameInfo.difficulty = "Medium";
                        break;
                    case 3:
                        gameInfo.chances = 5;
                        gameInfo.difficulty = "Hard";
                        break;
                    default:
                        cout << "Entrada inválida! ";
                        system("Pause");
                        break;
                }
                steady_clock::time_point clock_begin = steady_clock::now();
                // cout << "A dificuldade selecionada foi o modo " << gameInfo.difficulty << '\n';

                std::print("A dificuldade selecionada foi o modo {}\n", gameInfo.difficulty);
                while (gameInfo.chances > 0) //Jogando
                {
                    gameInfo.tries++;
                    cout << "Você tem " << gameInfo.chances << " tentativas restantes...\n";
                    cout << "Digite seu palpite: ";
                    cin >> input;
                    input = checkInput(input);
                    if (input == random_num)
                    {
                        steady_clock::time_point clock_end = steady_clock::now(); // O tempo desde que escolheu a dificuldade até acertar
                        steady_clock::duration time_span = clock_end - clock_begin;
                        auto seconds = double(time_span.count()) * steady_clock::period::num / steady_clock::period::den;
                        cout << "Parabéns! Você acertou o número correto em " << gameInfo.tries << " tentativa(s)\n";
                        cout << "Seu tempo foi de: " << seconds << " segundos\n";
                        break;
                    }
                    if (input > random_num)
                    {
                        cout << "Incorreto! O número que estou pensando é menor que " << input << '\n';
                    }
                    else if (input < random_num)
                    {
                        cout << "Incorreto! O número que estou pensando é maior que " << input << '\n';
                    }
                    gameInfo.chances--;
                }
                cout << "O número sorteado foi " << random_num << "!\n";
                cout << "Deseja jogar novamente? ";
                cout << "1 - (Sim) | 2 - (Não)\n";
                cout << "Aguardando resposta: ";
                cin >> input;
                if (input==1) {system("CLS"); runGame(gameInfo);}
                else
                {
                    cout << "--------------------------------------\n";
                    cout << "Obrigado por jogar. Até a próxima!\n";
                    gameInfo.exit = true;
                }
                //playing = false;
                break;
            }
            case 2:
                cout << "Até a próxima!\n";
                gameInfo.exit = true;
                break;
            default:
                cout << "Entrada inválida! "; 
                system("Pause");
                break;
        }
    }
}


int main()
{
    //bool playing = true;
    setlocale(LC_ALL, "pt_BR.UTF-8");
    srand(time(NULL));
    GameMode game;
    // When the gameInfo starts, it should display a welcome message along with the rules of the gameInfo.
    runGame(game);
    
    
    return 0;
}
