#include <iostream>
#include <random>
#include <stdlib.h>
#include <chrono>

using namespace std;

class GameMode
{
    public:
    int chances;
    int tries;
    string difficulty;
    bool exit;
    short seconds;
    GameMode()
    {
        tries = 0;
        chances = 0;
        seconds = 0;
        difficulty = "None";
        exit = false;
    }

    void resetGameCache()
    {
        tries = 0;
        chances = 0;
        seconds = 0;
        difficulty = "None";
    }
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
        int randomNum= 1+ (rand() % 100);
        int input;
        gameInfo.resetGameCache();


        cout << "Bem-vindo ao jogo de adivinhação de números!\n";
        cout << "Digite 0 para: Acessar regras!\n";
        cout << "Digite 1 para: Jogar!\n";
        cout << "Digite 2 para: Sair!\n";
        cout << "Aguardando resposta: ";
        cin >> input;

        switch (checkInput(input))
        {
            case 0:
                cout << "-> O computador escolherá aleatoriamente um número secreto entre 1 e 100.\n";
                cout << "-> Seu objetivo é adivinhar qual é esse número.\n";
                cout << "-> Você terá um número limitado de tentativas para acertar.\n";
                cout << "-> Se você adivinhar corretamente, o jogo termina e você vence!\n";
                cout << "-> Caso contrário, o jogo continuará até que suas tentativas se esgotem e você perca.\n";
                cout << "-> Boa sorte!\n";
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
                chrono::steady_clock::time_point clock_begin = chrono::steady_clock::now();
                cout << "A dificuldade selecionada foi o modo " << gameInfo.difficulty << endl;
                while (gameInfo.chances > 0) //Jogando
                {
                    gameInfo.tries++;
                    cout << "Você tem " << gameInfo.chances << " tentativas restantes...\n";
                    cout << "Digite seu palpite: ";
                    cin >> input;
                    input = checkInput(input);
                    if (input == randomNum)
                    {
                        chrono::steady_clock::time_point clock_end = chrono::steady_clock::now(); // O tempo desde que escolheu a dificuldade até acertar
                        chrono::steady_clock::duration time_span = clock_end - clock_begin;
                        auto seconds = double(time_span.count()) * chrono::steady_clock::period::num / chrono::steady_clock::period::den;
                        cout << "Parabéns! Você acertou o número correto em " << gameInfo.tries << " tentativa(s)\n";
                        cout << "Seu tempo foi de: " << seconds << " segundos\n";
                        break;
                    }
                    else
                    {
                        if (input > randomNum)
                        {
                            cout << "Incorreto! O número que estou pensando é menor que " << input << endl;
                        }
                        else if (input < randomNum)
                        {
                            cout << "Incorreto! O número que estou pensando é maior que " << input << endl;
                        }
                    }
                    gameInfo.chances--;
                }
                cout << "O número sorteado foi " << randomNum << "!\n";
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
