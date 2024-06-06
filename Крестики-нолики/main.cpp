#include <iostream>
#include <fstream>
#include <locale> 
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Game.h"

void saveResultToFile(const std::string& winner, int numMoves) {
    std::ofstream file("results.txt", std::ios::app); 
    if (file.is_open()) {
        std::time_t now = std::time(nullptr);
        std::tm localTime;
        localtime_s(&localTime, &now);
        char buffer[80]; 
        std::strftime(buffer, sizeof(buffer), "%c", &localTime);
        file << "Дата и время: " << buffer << std::endl;
        file << "Победитель: " << winner << std::endl; 
        file << "Количество ходов: " << numMoves << std::endl; 
        file << "-----------------------\n"; 
        file.close(); 
    }
    else {
        std::cerr << "Не удалось открыть файл для записи результатов." << std::endl;
    }
}

int main() {
    std::locale::global(std::locale("")); 
    std::cout.imbue(std::locale()); 

    char playerSymbol;
    while (true) {
        std::cout << "Выберите символ для игры (X или O): ";
        std::cin >> playerSymbol;
        playerSymbol = std::toupper(playerSymbol); 
        if (playerSymbol == 'X' || playerSymbol == 'O') {
            break;
        }
        else {
            std::cerr << "Неверный символ. Используйте X или O." << std::endl;
        }
    }

    std::cout << "Выбранный символ: " << playerSymbol << std::endl;

    AIPlayer aiPlayer((playerSymbol == 'X') ? 'O' : 'X'); 
    HumanPlayer humanPlayer(playerSymbol);

    Board board;

    Game game(aiPlayer, humanPlayer, board);

    game.start();

    saveResultToFile(game.getWinner(), game.getNumMoves());

    return 0;
}
