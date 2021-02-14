/**
 * @file BlackJack.cpp
 * @author Will Hord (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <cstdio>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <array>
#include <stdio.h>
#include <ctype.h>

#include "Deck.hpp"
#include "Table.hpp"


using namespace std;

vector<string> CombineCards(Card card1, Card card2){
    vector<string> tempVector;
    for(int i=0; i < card1.cardDesign.size(); i++){
        string tempstr = card1.cardDesign[i] + "      " + card2.cardDesign[i];
        tempVector.push_back(tempstr);
    }
    return tempVector;
}



void printStringVec(vector<string> vec){
    for(int i=0; i <= (int)vec.size(); i++){
        cout << vec[i] << endl;
    }
}

int getBet(Player player){
    string tempstr = "";
    while(!all_of(tempstr.begin(),tempstr.end(), ::isdigit) || tempstr == ""){
        cin.sync();
        getline(cin, tempstr);

        if(!all_of(tempstr.begin(), tempstr.end(), ::isdigit)){
            if(tolower(tempstr[0]) == 'q'){
                exit(0);
            }
            cout << "INVALID BET" << endl;
            cout << "Enter new bet: ";
        } else {
            if(stoi(tempstr) > player.balance){
                cout << "INVALID BET" << endl;
                cout << "Enter new bet: ";
            }
        }
    }
    return stoi(tempstr);
}

vector<int> getHandValue(vector<class Card> hand){
    vector<int> values = {0,0};
    // int value = 0;
    for(auto i:hand){
        if(i.rank > 10){
            values[0] += 10;
            values[1] += 10;
        } else if(i.rank == 1){
            values[0] += 1;
            values[1] += 11;
        } else {
            values[0] += i.rank;
            values[1] += i.rank;
        }
    }

    return values;
}


vector<string> getMoves(vector<int> hand){
    vector<string> moves;
    for(auto i:hand){
        if(i > 21){
            if((int)moves.size() == 0){
                moves = {"BUST", to_string(i)};
            }
        } else if(i < 21){
            moves.clear();
            moves.push_back("Quit (Q)");
            moves.push_back("Hit (H)");
            moves.push_back("Stand (S)");
        }
    }
    // sort(moves.begin(), moves.end());
    // moves.erase(unique(moves.begin(), moves.end()), moves.end());

    return moves;
}

string userMove(){
    string tempstr = "";
    while(tempstr == ""){
        cin.sync();
        getline(cin, tempstr);

        transform(tempstr.begin(), tempstr.end(), tempstr.begin(),
        [](unsigned char c){ return tolower(c); });

        if(tempstr == "hit" || tempstr == "h"){
            tempstr = "H";
        } else if(tempstr == "stand" || tempstr == "s"){
            tempstr = "S";
        } else if(tempstr == "quit" || tempstr == "q"){
            exit(0);
        } else {
            cout << "INVALID COMMAND" << endl;
            cout << "Enter New Command: ";
            tempstr = "";
        }
    }
    return tempstr;
}

void playAgain(){
    string tempstr = "";
    while(tempstr == ""){
        cin.sync();
        getline(cin, tempstr);

        transform(tempstr.begin(), tempstr.end(), tempstr.begin(),
        [](unsigned char c){ return tolower(c); });

        if(tempstr == "yes" || tempstr == "y"){
            tempstr = "Y";
        } else if(tempstr == "no" || tempstr == "n"){
            exit(0);
        } else {
            cout << "INVALID COMMAND" << endl;
            cout << "Enter New Command: ";
            tempstr = "";
        }
    }
}

void Lose(Player& player, Player& dealer, int winCondition){
    player.bet = 0;
    // if(bust){
        
    // } else {
    //     printTable(dealer,player,getMoves(getHandValue(player.hand)), winCondition);
    // }
    printTable(dealer,player,getMoves(getHandValue(player.hand)), winCondition);
    player.hand.clear();
    dealer.hand.clear();
}

void Win(Player& player, Player& dealer){
    player.balance += player.bet *2;
    player.bet = 0;
    printTable(dealer,player,getMoves(getHandValue(player.hand)), win);
    player.hand.clear();
    dealer.hand.clear();
}

void Tie(Player& player, Player& dealer){
    player.balance += player.bet;
    player.bet = 0;
    // printTable(dealer,player,getMoves(getHandValue(player.hand)), false, false, true);
    player.hand.clear();
    dealer.hand.clear();
}

int main(int argc, char** argv){
    srand(unsigned(time(NULL)));

    Deck deck = Deck();
    Player dealer, player;

    player.balance = 1000;
  
    while(player.balance > 0){
        printBettingScreen(player);
        int bet = getBet(player);

        player.bet = bet;
        player.balance = player.balance - bet;

        deck.deckShuffle();

        dealer.hand.push_back(deck.DrawCard());

        player.hand.push_back(deck.DrawCard());
        player.hand.push_back(deck.DrawCard());

        printTable(dealer,player,getMoves(getHandValue(player.hand)));

        string move = userMove();
        while((getHandValue(player.hand)[0] < 21 || getHandValue(player.hand)[1] < 21) || move != "S"){
            if(move == "S" || (getHandValue(player.hand)[0] > 21 && getHandValue(player.hand)[1] > 21)){
                break;
            }
            if(move == "H"){
                cout << "HERE" << endl;
                player.hand.push_back(deck.DrawCard());
                cout << "HERE1" << endl;
            }
            cout << "HERE3" << endl;
            if(getHandValue(player.hand)[0] > 21 && getHandValue(player.hand)[1] > 21){
                // cout << "HERE4" << endl;
                // Lose(player,dealer,true);
                break;
            }
            cout << "HERE5" << endl;
            printTable(dealer,player,getMoves(getHandValue(player.hand)));
            cout << "HERE6" << endl;
            move = userMove();
            cout << "HERE7" << endl;
        }
        if(getHandValue(player.hand)[0] <= 21 || getHandValue(player.hand)[1] <= 21){
            dealer.hand.push_back(deck.DrawCard());
            vector<int> dealerValue = getHandValue(dealer.hand);
            while(dealerValue[0] < 17 || dealerValue[1] < 17){
                dealer.hand.push_back(deck.DrawCard());
                dealerValue = getHandValue(dealer.hand);
            }
            vector<int> playerValue = getHandValue(player.hand);
            // for(auto i: playerValue){
            //     cout << i << endl;
            // }
            for(auto& i:playerValue){
                if(i > 21){
                    i = 0;
                }
            }
            // for(auto i: playerValue){
            //     cout << i << endl;
            // }
            // exit(0);
            for(auto& i:dealerValue){
                if(i > 21){
                    i = 0;
                }
            }
            if(dealerValue[0] > 21 && dealerValue[1] > 21){
                // player.balance += player.bet *2;
                // player.bet = 0;
                // printTable(dealer,player,getMoves(getHandValue(player.hand)), false, false, true);
                // player.hand.clear();
                // dealer.hand.clear();
                Win(player,dealer);
                playAgain();
            }else if(playerValue[0] > dealerValue[0] || playerValue[0] > dealerValue[1] ||
                playerValue[1] > dealerValue[0] || playerValue[1] > dealerValue[1]){
                    // player.balance += player.bet *2;
                    // player.bet = 0;
                    // printTable(dealer,player,getMoves(getHandValue(player.hand)), false, false, true);
                    // player.hand.clear();
                    // dealer.hand.clear();
                    Win(player,dealer);
                    playAgain();
            } else {
                // player.bet = 0;
                // printTable(dealer,player,getMoves(getHandValue(player.hand)), false, true);
                // player.hand.clear();
                // dealer.hand.clear();
                Lose(player, dealer, lose);
                playAgain();

            }
        } else {
            // player.bet = 0;
            // printTable(dealer,player,getMoves(getHandValue(player.hand)), true, false, false);
            // player.hand.clear();
            // dealer.hand.clear();
            Lose(player,dealer, bust);
            playAgain();
        }
        }

    return 1;
}