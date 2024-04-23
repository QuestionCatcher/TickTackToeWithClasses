#include "Game.h"
#include "Board.h"
void Game::Play()
{
    {
        SetPlayersNames();
        GetPlayersInfo();
        GameBoard.PrintGuideBoard();
        GameLoop();
        while (!GameLoop())
        {
            std::cout << "Gracz " << CurrentPlayer->GetName() << ", podaj numer pola (od 1 do 9): ";
            std::string index;
            std::cin >> index;
        
            MakeMove(index, CurrentPlayer->GetSign());
        }
    
    }
}
//GameLoop

void Game::GameLoop()
{
    while (true)
    {
        GameBoard.PrintCurrentBoard();   
    }
    
}

//set player name
void Game::SetPlayersNames()
{
    std::string Name;
    std::cout << "Podaj imie player 1: \n";
    std::cin >> Name;
    Player1.SetName(Name);
    std::cout << "Podaj imie player 2: \n";
    std::cin >> Name;
    Player2.SetName(Name);
}
//get info about player name and sign
void Game::GetPlayersInfo()
{
    std::cout << "Player1: \n" + Player1.GetName() + "(znak: " + Player1.GetSign() + ")\n";
    std::cout << "Player2: \n" + Player2.GetName() + "(znak: " + Player2.GetSign() + ")\n";
}
//set player sign
Game::Game(): CurrentPlayer(&Player1)
{
    Player1.SetSign("X");
    Player2.SetSign("O");
}

void Game::MakeMove(std::string Board, const std::string& sign)
{
    std::cout << "Gracz: " + CurrentPlayer->GetName() + " wykonuje ruch.\n";
}

void Game::SwitchPlayer()
{
    if (CurrentPlayer == &Player1)
    {
        CurrentPlayer = &Player2;
    }
    else
    {
        CurrentPlayer = &Player1;
    }
}
