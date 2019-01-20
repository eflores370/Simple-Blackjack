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


void displayTotal(int total) {
    cout << "Total: " + to_string(total) << endl;
}

void dealersTurn(int dealersTotal, int playerTotal) {
    displayTotal(dealersTotal);
    while (dealersTotal <= 21 && dealersTotal < playerTotal) {
        int newCard = drawCard(dealersTotal);
        cout << "Dealer's Card: " + to_string(newCard) << endl;
        dealersTotal += newCard;
        displayTotal(dealersTotal);
    }
    if (dealersTotal == playerTotal) {
        cout << "Draw!\n\n\n";
    }
    if (dealersTotal == 21 || (dealersTotal < 21 && dealersTotal > playerTotal) ) {
        cout << "Dealer Wins!\n\n\n";
    }
    if (dealersTotal > 21) {
        cout << "Dealer BUSTS! You Win!\n\n\n";
    }
}


int main() {
    while(true) {
        cout << "======================\n      Blackjack\n======================\n" << endl;

        int dealerFirst, dealerSecond, dealersTotal, playerFirst, playerSecond;

        // Seed Random
        srand(time(NULL));
        dealerFirst = drawCard(0);
        dealerSecond = drawCard(dealerFirst);
        dealersTotal = dealerFirst + dealerSecond;

        cout << "Dealer's First Card: " + to_string(dealerFirst) << endl;
        cout << "(Debug) Secret: " + to_string(dealerSecond) + "\n" << endl;

        playerFirst = drawCard(0);
        playerSecond = drawCard(playerFirst);

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
            continue;
        }

        else if (playerTotal == 21) {
            cout << "\nJackpot!\n";
            continue;
        }

        cout << "\nDealer's Turn\n" << endl;
        dealersTurn(dealersTotal, playerTotal);
    }
}