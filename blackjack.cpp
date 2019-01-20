#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int drawCard() {
    return (rand() + 1 ) % 11;  
}

int main() {
    cout << "Blackjack\n" << endl;
    int BUST = 21;

    int dealerFirst, dealerSecond, playerFirst, playerSecond;

    srand(time(NULL));
    dealerFirst = drawCard();
    dealerSecond = drawCard();

    cout << "Dealer's First Card: " + to_string(dealerFirst) << endl;
    cout << "Secret: " + to_string(dealerSecond) + "\n" << endl;

    playerFirst = drawCard();
    playerSecond = drawCard();

    cout << "Your cards" << endl;
    cout << "First Card: " + to_string(playerFirst) << endl;
    cout << "Second Card: " + to_string(playerSecond) << endl;

    int playerTotal = playerFirst + playerSecond;
    int playerChoice;

    cout << "playerTotal: " +  to_string(playerTotal) << endl;

    do { 

        cout << "\nHit[1] or Stay[2]" << endl;
        cin >> playerChoice;

        if (playerChoice == 1) {
            int newCard = drawCard();        
            cout << "New Card: " + to_string(newCard) << endl;        
            playerTotal += newCard;
            cout << "Total: " + to_string(playerTotal) << endl;
        }
        else if (playerChoice == 2) {
            break;
        }
        else {
            cout << "Please try again" << endl;
        }
    }   while (playerTotal < 22);

    if (playerTotal > 21) {
        cout << "BUST! You Lose" << endl;
    }

    cout << "Dealer's Turn" << endl;
}