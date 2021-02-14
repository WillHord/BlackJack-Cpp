/**
 * @file Card.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>

#include "Deck.hpp"

using namespace std;


vector<string> getHiddenCard(){
    vector<string> tempVector;
    tempVector.push_back(cardTop);
    for(int i=0; i < CardHeight -2; i++){
        string tempstr = "";
        for(int j=0; j < CardWidth; j++){
            switch(j){
                case 0:
                    tempstr += "│";
                    break;
                case CardWidth-1:
                    tempstr += "│";
                    break;
                default:
                    tempstr += "▒";
            }
        }
        tempVector.push_back(tempstr);
    }
    tempVector.push_back(cardBottom);
    return tempVector;
}

Card :: Card(int r, string s){
    rank = r;
    suit = s;

    string tempRank;
    switch(rank){
        case 1:
            tempRank = "A";
            break;
        case 11:
            tempRank = "J";
            break;
        case 12:
            tempRank = "Q";
            break;
        case 13:
            tempRank = "K";
            break;
        default:
             tempRank= to_string(r);
    }


    cardDesign.push_back(cardTop);
    for(int i=0; i < CardHeight - 2; i++){
        string tempstr = "";
        for(int j=0; j < CardWidth ; j++){
            switch(j){
                case 0:
                    tempstr += "│";
                    break;
                case 2:
                    if(i == 0){
                        tempstr += tempRank;
                    } else {
                        tempstr += " ";
                    }
                    break;
                case CardWidth-3:
                    if(i == CardHeight - 3){
                        tempstr += tempRank;
                    } else {
                        tempstr += " ";
                    }
                    break;
                case CardWidth -1:
                    tempstr += "│";
                    break;

                default:
                    if(j == ceil(CardWidth/2) && i == ceil((CardHeight-2)/2)){
                        tempstr += s;
                    } else if(tempRank == "10" && j == 3 && i == 0){
                        break;
                    } else if(tempRank == "10" && j == CardWidth-4 && i == CardHeight -3){
                        break;
                    }else{
                        tempstr += " ";
                    }
            }
        }
        cardDesign.push_back(tempstr);
    }
    cardDesign.push_back(cardBottom);
}


void Card :: PrintCard(){
    for(int i=0; i < (int)cardDesign.size(); i++){
        cout << cardDesign[i] << endl;
    }
}