#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int drawCard(int playerTotal) {
    int card = (rand() % 11) + 1;
    if (playerTotal >= 11 && card == 11) {
        card = 1;
        cout << "(Debug) Face Card" << endl;
    }
    return card;
}

void dealersTurn(int playerTotal, int dealersTotal) {
    while (dealersTotal <= 21 && dealersTotal < playerTotal) {
        int newCard = drawCard(dealersTotal);
        dealersTotal += newCard;
    }
    if (dealersTotal == 21 || ) {
        cout << "Dealer Wins!";
    }
    if (dealersTotal > 21) {
        cout << "Dealer BUSTS! You Win!\n";
    }
}


void displayTotal(int total) {
    cout << "Total: " + to_string(total) << endl;
}

int main() {
        while(true) {
        cout << "======================\n      Blackjack\n======================\n" << endl;

        int dealerFirst, dealerSecond, dealersTotal, playerFirst, playerSecond;

        // Seed Random
        srand(time(NULL));
        dealerFirst = drawCard(0);
        dealerSecond = drawCard(0);
        dealersTotal = dealerFirst + dealerSecond;

        cout << "Dealer's First Card: " + to_string(dealerFirst) << endl;
        cout << "(Debug) Secret: " + to_string(dealerSecond) + "\n" << endl;

        playerFirst = drawCard(0);
        playerSecond = drawCard(0);

        cout << "Your cards\n============" << endl;
        cout << "First Card: " + to_string(playerFirst) << endl;
        cout << "Second Card: " + to_string(playerSecond) << endl;

        int playerTotal = playerFirst + playerSecond;
        int playerChoice;

        displayTotal(playerTotal);

        do { 

            cout << "\nHit[1] or Stay[2]" << endl;
            cin >> playerChoice;

            if (playerChoice == 1) {
                int newCard = drawCard(playerTotal);           
                cout << "\nNew Card: " + to_string(newCard) << endl;
                playerTotal += newCard;
                displayTotal(playerTotal);
            }
            else if (playerChoice == 2) {
                break;
            }
            else {
                cout << "\nPlease try again" << endl;
            }
        }   while (playerTotal < 21);

        if (playerTotal > 21) {
            cout << "\nBUST! You Lose" << endl;
        }

        else if (playerTotal == 21) {
            cout << "\nJackpot!\n";
            break;
        }

        cout << "\nDealer's Turn\n" << endl;

        dealersTurn(dealersTotal, playerTotal);
    }
}