#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

// Player data structure
struct Player {
    string name;
    int position;
};

// Board square data structure
struct BoardSquare {
    string narration;
    int move;  // Number of steps to move forward or backward
};

int main() {
    system("cls");
    srand(time(0));

    const int numPlayers = 4;
    vector<Player> players(numPlayers);

    a:

    // Enter player names
    for (int i = 0; i < numPlayers; i++) {
        cout << "Enter Player " << i + 1 << "'s name: ";
        cin >> players[i].name;
        players[i].position = 0;  // All players start at square 0
    }

    vector<BoardSquare> board(100);

    // Initialize the game board with rules and narration
    board[1].narration = "You accidentally stumble upon a portal in the ruins leading to a place called 'Sanctuary of God,' the dwelling of the Almighty Deus Ex Machina. You receive his blessing and get teleported to floor 50.";
    board[7].narration = "Meeting an Administrator alone is fortunate, but you encounter Pendragon, one of the Sovereign Dragons. You receive his blessing and easily reach floor 30.";
    board[10].narration = "You arrive at Floor 10. You battle the ruler of Floor 10, Archais the Tyrant, and successfully defeat him. You get the opportunity to climb to a higher floor.";
    board[15].narration = "You arrive at Floor 15. You discover a cave on the mountainside that takes you to Floor 20.";
    board[35].narration = "You arrive at Floor 35. Accidentally, you encounter a High-Rank Ranker. You are defeated soundly and end up being taken by their subordinates to Floor 17.";
    board[20].narration = "You receive a reward from the Tower Administrator. 'Ascend to a higher floor, O Explorer,' he says.";
    board[25].narration = "You arrive at a large city named Fortessy on Floor 35. You enjoy the city's atmosphere and proceed to the next floor with full stamina.";
    board[39].narration = "You arrive at Floor 39. You engage in an intense battle. You suffer a fatal blow from a sorcerer and are severely wounded. You are forced to retreat to Floor 25 to recover.";
    board[45].narration = "You realize that the ruler of Floor 45 is difficult to defeat with your current equipment! You need stronger gear. You go back to Floor 25 to buy new equipment.";
    board[53].narration = "Accidentally, you encounter the ruler of Floor 53 and meet a tragic end at their hands. You retreat to Floor 40 to recover your strength.";
    board[60].narration = "You have reached Floor 60. You encounter Regno, the Sovereign Dragon. You receive his blessing and easily climb to Floor 80.";
    board[68].narration = "You arrive at Floor 68. You feel the difficulty of the test given by an Administrator named Lyon. You decide to descend to the previous floor as you feel not ready to conquer this floor.";
    board[73].narration = "You arrive at a city on Floor 73 famous for its beauty. You are captivated by the city's beauty and decide to relax in completing this floor.";
    board[79].narration = "While exploring a dungeon on Floor 79, you fall into a trap and are severely injured. You decide to descend to Floor 73 to rest.";
    board[84].narration = "Accidentally, you discover the legendary sword, Excalibur, while exploring ruins. The sword easily takes you to Floor 95.";
    board[87].narration = "On this floor, you battle against a Wyvern and successfully defeat it. You get the opportunity to climb to a higher floor.";
    board[93].narration = "During the journey to the next floor, you battle a High Ranker named Archane, and surprisingly, you defeat them. You get the chance to climb to a higher floor.";
    board[95].narration = "You battle against Ashbell, one of the Sovereign Dragons. Unfortunately, you die in the battle. Out of mercy, Ashbell resurrects you on Floor 70.";
    board[98].narration = "A God dislikes your presence on this floor. You get teleported to Floor 50.";


    // Rules for moving forward or backward in narration
    board[1].move = 49;
    board[7].move = 23;     
    board[10].move = 5;  
    board[15].move = 5;   
    board[20].move = 8;   
    board[25].move = 1;
    board[35].move = -18; 
    board[39].move = -14; 
    board[45].move = -20; 
    board[53].move = -13;
    board[60].move = 20;
    board[68].move = -1;
    board[73].move = 1;
    board[79].move = -6;
    board[84].move = 11;
    board[87].move = 5;
    board[93].move = 3;
    board[95].move = -25;
    board[98].move = -48;
    // ... (other board square movements)

    system("cls");

    cout << "================================================================================================================" << endl;
    cout <<"         Welcome to the Tower of the Gods, brave adventurers. To gain the blessings of the Gods, "<<endl;
    cout <<"                      you must successfully climb to floor 99 and conquer this tower.                       " << endl;
    cout << "================================================================================================================" << endl;

    cout << "Snake and Ladder Rules: " << endl;
    cout << "1. There are 4 Players in 1 Game " << endl;
    cout << "2. You are allowed to roll the dice again if you get a 3 "  << endl;
    cout << "3. There are various obstacles and opportunities that may help you win the game" <<endl;
    cout << "=========================================================================================================" <<endl;

    cin.get();

    while (true) {

        cout << "Press enter to continue your journey...";
        cin.get();
        system("cls");

        for (int i = 0; i < numPlayers; i++) {

            cout << players[i].name << ", Press Enter to start your journey...";
            cin.get();

            int dice = rand() % 6 + 1;
            cout << players[i].name << " starts the journey and successfully climbs " << dice << " floors" << endl;

            if (dice == 3) {
                cout << "Congratulations! You climbed 3 floors and are eligible to roll the dice again." << endl;
                cout << players[i].name << ", press Enter to start the journey again...";
                cin.get();
                int additionalDice = rand() % 6 + 1;
                cout << players[i].name << " starts the journey again and successfully climbs " << additionalDice << endl;
                dice += additionalDice;
            }

            int currentPosition = players[i].position;

            if (currentPosition + dice <= 99) {
                players[i].position += dice;
            } else {
                int remainingSteps = 99 - currentPosition;
                players[i].position = 99 - remainingSteps;
            }

            cout << players[i].name << " is now on floor " << players[i].position << endl;
            cout << endl;

            if (!board[players[i].position].narration.empty()) {
                cout << board[players[i].position].narration << endl;

                if (board[players[i].position].move > 0) {
                    int move = board[players[i].position].move;
                    players[i].position += move;
                    cout << players[i].name << " moves forward " << move << " floors and is now on floor " << players[i].position << endl;
                    cout << endl;
                } else {
                    int move = -board[players[i].position].move;
                    players[i].position -= move;
                    cout << players[i].name << " moves backward " << move << " floors and is now on floor " << players[i].position << endl;
                    cout << endl;
                }

                if (players[i].position < 0) {
                    players[i].position = 0;
                }

                for (int i = 0; i < numPlayers; i++) {
                    if (players[i].position == 99) {

                        cout << players[i].name << ", You have reached floor 99. Congratulations on your hard work, brave adventurer. May luck always be with you!" << endl;
                        char playAgain;
                        cout << "Do you want to play again? (y/n): ";
                        cin >> playAgain;

                        if (playAgain == 'y' || playAgain == 'Y') {
                            // Reset game state
                            for (int j = 0; j < numPlayers; j++) {
                                players[j].position = 0;
                            }
                            system("cls");
                            goto a;
                        } else {
                            return 0;
                        }
                    }
                }
            }
            cout << "--------------------------------------------" << endl;
        }
    }
}
