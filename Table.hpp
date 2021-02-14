/**
 * @file Table.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-02-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef TABLE_HPP
#define TABLE_HPP

#include <cstdio>
#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>

#include "Deck.hpp"

vector<string> createSpace(int height, int width);


void printCombined(vector<vector<string>> vec);


vector<vector<string>> combineCards(vector<class Card> hand);

void printTable(Player, Player, vector<string>, int winCondition=none);


void printBettingScreen(Player player);


#endif