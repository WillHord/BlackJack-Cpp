/**
 * @file Table.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <cstdio>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include "Deck.hpp"
#include "Table.hpp"

using namespace std;


// vector<int> getHandValue1(vector<class Card> hand){
//     vector<int> values = {0,0};
//     // int value = 0;
//     for(auto i:hand){
//         if(i.rank > 10){
//             values[0] += 10;
//             values[1] += 10;
//         } else if(i.rank == 1){
//             values[0] += 1;
//             values[1] += 11;
//         } else {
//             values[0] += i.rank;
//             values[1] += i.rank;
//         }
//     }

//     return values;
// }

vector<string> createSpace(int height, int width){
    vector<string> tempVector;
    for(int i=0; i < height; i++){
        string tempstr = "";
        for(int j=0; j < width; j++){
            tempstr += " ";
        }
        tempVector.push_back(tempstr);
    }
    return tempVector;
}

void printCombined(vector<vector<string>> vec){
    for(int i=0; i< (int)vec[0].size(); i++){
        for(auto j : vec){
            cout << j[i];
        }
        cout << endl;
    }
}

vector<vector<string>> combineCards(vector<class Card> hand){
    vector<vector<string>> tempVec;
    for(auto i: hand){
        tempVec.push_back(i.cardDesign);
    }
    return tempVec;
}

void printBettingScreen(Player player){
    system("clear");
    cout << "|Balance: " << player.balance << endl;
    cout << "|Enter your bet: ";
}


void printTable(Player dealer, Player player, vector<string> movesAvaliable, int winCondition){

    system("clear");

    vector<string> initspace = createSpace(CardHeight,10);
    vector<string> cardSpace = createSpace(CardHeight, 5);


    // Print Dealer hand

    vector<vector<string>> dealerCombined = combineCards(dealer.hand);

    if(dealer.hand.size() < 2){
        // vector<string> hiddenCard = getHiddenCard();
        dealerCombined.push_back(getHiddenCard());
    }

    printCombined(dealerCombined);

    cout << "\n\n";

    vector<vector<string>> playerCombined = combineCards(player.hand);

    printCombined(playerCombined);

    string Moves = "";
    for(auto i: movesAvaliable){
        if(i != movesAvaliable.back()){
            Moves += i + ", ";
        } else {
            Moves += i;
        }
        
    }

    switch(winCondition){
        case win:
            cout << "\n\n|Current bet: " << player.bet << "||Balance: " << player.balance << "|" << endl;
            cout << "|You WIN! Do you want to play again? (y/n) ";
            break;

        case lose:
            cout << "\n\n|Current bet: " << player.bet << "||Balance: " << player.balance << "|" << endl;
            cout << "|You Lose! Do you want to play again? (y/n) ";
            break;

        case bust:
            cout << "\n\n|Current bet: " << player.bet << "||Balance: " << player.balance << "|" << endl;
            cout << "|BUST!! Do you want to play again? (y/n) ";
            break;

        default:
            cout << "\n\n|Current bet: " << player.bet << "||Balance: " << player.balance << "|" << endl;
            cout << "|Moves avaliable: " << Moves << "|   ";
    }
    // if(!bust && !lower && !win){
    //     cout << "\n\n|Current bet: " << player.bet << "||Balance: " << player.balance << "|" << endl;
    //     cout << "|Moves avaliable: " << Moves << "|   ";
    // } else if(bust){
    //     // vector<int> playerValue = getHandValue1(player.hand);
    //     // cout << "playerValue[0]: " << playerValue[0] << " playerValue[1]: " << playerValue[1] << endl;
    //     cout << "\n\n|Current bet: " << player.bet << "||Balance: " << player.balance << "|" << endl;
    //     cout << "|BUST!! Do you want to play again? (y/n) ";
    // } else if(lower){
    //     // vector<int> playerValue = getHandValue1(player.hand);
    //     // cout << "playerValue[0]: " << playerValue[0] << " playerValue[1]: " << playerValue[1] << endl;
    //     cout << "\n\n|Current bet: " << player.bet << "||Balance: " << player.balance << "|" << endl;
    //     cout << "|You Lose! Do you want to play again? (y/n) ";
    // } else if(win){
    //     // vector<int> playerValue = getHandValue1(player.hand);
    //     // cout << "playerValue[0]: " << playerValue[0] << " playerValue[1]: " << playerValue[1] << endl;
    //     cout << "\n\n|Current bet: " << player.bet << "||Balance: " << player.balance << "|" << endl;
    //     cout << "|You WIN! Do you want to play again? (y/n) ";
    // }
    


}