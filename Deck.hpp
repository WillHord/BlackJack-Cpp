/**
 * @file Deck.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef DECK_HPP
#define DECK_HPP

#define SPADE "\u2660"
#define DIAMOND "\u25C6"
#define CLUB "\u2663"
#define HEART "\u2665"

#define STANDARD_SIZE 52


#define cardTop "┌───────────────┐"
#define cardBottom "└───────────────┘"
#define CardHeight 11
#define CardWidth 17


#include <vector>
#include <string>

using namespace std;

enum WinLoseConditions {none,win,tie,bust,lose};

class Card{
    private:
        

    public:
        Card(int r, string s);

        vector<string> cardDesign;
        int rank;
        string suit;

        void PrintCard();


};

class Deck{
    private:
        int size;
        int CardsLeft;
        vector<class Card> deck;
        vector<class Card> used;

    public:
        Deck();
        Deck(int i);

        void deckShuffle();
        Card DrawCard();
        void Discard(Card to_discard);
        void PrintDeck();
};

class Player{
    public:
        vector<class Card> hand;
        vector<class Card> splitHand;

        int handValue;
        int handValue_Ace;
        int splitHandValue;
        int splitHandValue_Ace;

        bool split = false;

        int bet;
        int balance;

};


vector<string> getHiddenCard();


#endif