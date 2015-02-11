/***************************************************
** hw7.cpp
** War Card Game
** Patrick Xie, 2/26/10
****************************************************/
#include <iostream>
#include "cards.h"
#include <ctime>
using namespace std;

int main(){
	srand( (int) time(0));
	Player dollars(100);
	while(dollars.get_money() > 0 && dollars.get_money() < 1000) {
		cout<< "You have $" << dollars.get_money() << ".\n";
		Card card1;
		Card card2;
		Card card3;
		cout<< "You got a " << card1.get_rank() << " of "
			<< card1.get_suit() << " and a " << card2.get_rank()
			<< " of " << card2.get_suit() << ".\n";
		cout<< "How much do you want to bet the next card is in between? ";

		int bet;
		cin>> bet;

		while (bet> dollars.get_money() || bet < 0){
			cout<<"\nYou only have $" << dollars.get_money() << " to bet! Enter a new bet: ";
			cin >> bet;
		}

		cout<< "\nYou got a " << card3.get_rank() << " of "
			<< card3.get_suit() << ".\n";

		if (card2 < card1){
			if(card2.rank2num() < card3.rank2num() && card3.rank2num() < card1.rank2num()){
				dollars.change_money(bet);
				cout<< "COOL! You win $" << bet << ".\n\n\n";
			}
			else if(card3.rank2num() <= card2.rank2num() || card1.rank2num() <= card3.rank2num()){
				dollars.change_money(-bet);
				cout<< "TOO BAD! You lose $" << bet << ".\n\n\n";
			}
		}

		if (card1 < card2){
			if(card1.rank2num() < card3.rank2num() && card3.rank2num() < card2.rank2num()){
				dollars.change_money(bet);
				cout<< "COOL! You win $" << bet << ".\n\n\n";
			}
			else if(card3.rank2num() <= card1.rank2num() || card2.rank2num() <= card3.rank2num()){
				dollars.change_money(-bet);
				cout<< "TOO BAD! You lose $" << bet << ".\n\n\n";
			}
		}
		if (card1.rank2num() == card2.rank2num()){
			dollars.change_money(-bet);
			cout << "TOO BAD! You lose $" << bet << ".\n\n\n";
		}
	}
	if (dollars.get_money() <= 0)
		cout<< "You are out of money. GAME OVER.\n";
	if (dollars.get_money() >= 1000)
		cout<< "YOU WIN. You have $1000 or more. GAME OVER.\n";
	return 0;
}