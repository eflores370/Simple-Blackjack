#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int drawCard() {
	return (rand() + 1 ) % 11;	
}

int main() {
  cout << "Blackjack\n" << endl;

  int dealerFirst, dealerSecond, playerFirst, playerSecond;

  srand(time(NULL));
  dealerFirst = drawCard();
  dealerSecond = drawCard();

  cout << "Dealer's Card #1: " + to_string(dealerFirst) << endl;
  cout << "Secret: " + to_string(dealerSecond) + "\n" << endl;

  playerFirst = drawCard();
  playerSecond = drawCard();

  cout << "Your cards" << endl;
  cout << "#1: " + to_string(playerFirst) << endl;
  cout << "#2: " + to_string(playerSecond) << endl;


}