/**
 * @file Deck.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Deck.hpp"

#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
#include <random>
#include <ctime>
#include <cstdlib>

Deck :: Deck(){
    size = STANDARD_SIZE;
    CardsLeft = STANDARD_SIZE;

    for(int i=0; i < 4; i++){
        for(int j=0; j < 13; j++){
            switch(i){
                case 0:
                    deck.push_back(Card(j+1,SPADE));
                    break;
                case 1:
                    deck.push_back(Card(j+1,DIAMOND));
                    break;
                case 2:
                    deck.push_back(Card(j+1,CLUB));
                    break;
                case 3:
                    deck.push_back(Card(j+1,HEART));
                    break;
            }
        }
    }
}

Deck :: Deck(int i){
    size = i;
    CardsLeft = i;
}

void Deck :: deckShuffle(){

    
    random_device rd;
    mt19937 randomizer(rd());
    // auto seed = unsigned(time(0));
    // srand(seed);
    // random_device rd;
    // default_random_engine rng;
    // rng.seed(srand(unsigned(time(0))));
    shuffle(begin(deck), end(deck), randomizer);
}

void Deck :: Discard(Card to_discard){

}

Card Deck :: DrawCard(){
    if((int)deck.size() == 0){
        deck = used;
        used.clear();
        deckShuffle();
    }
    Card tempCard = deck.back();
    deck.pop_back();
    used.push_back(tempCard);
    return tempCard;
}

void Deck :: PrintDeck(){
    for(int i=0; i< (int)deck.size(); i++){
        cout << "Rank: " << deck[i].rank << " Suit: " << deck[i].suit << endl;
    }
}