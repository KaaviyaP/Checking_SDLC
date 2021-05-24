/**
 * @file virtualcricket.h
 * Plays a virtual cricket with 2 teams
 * 
 */

#ifndef __VIRTUAL_CRICKET_H__
#define __VIRTUAL_CRICKET_H__

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

typedef enum error_t{
    SUCCESS=1,
    FAILURE=0,
}error_t;

/**
 * @brief 
 * 
 */
struct teams getdetails();

/**
 * @brief Welcome to Virtual Cricket function
 * 
 */
error_t welcome();


/**
 * @brief 
 * 
 * @param totalPlayers 
 */
error_t displayPoolPlayers(int totalPlayers);

/**
 * @brief 
 * 
 * @return int 
 */
int takeIntegerOnly();

/**
 * @brief 
 * 
 * @param lower 
 * @param upper 
 * @param count 
 * @return int 
 */
int getID(int lower, int upper, int count);

/**
 * @brief 
 * 
 * @param p_id 
 * @param x 
 * @param availibility 
 * @return int 
 */
int validateID(int p_id,int x,int availibility);

/**
 * @brief 
 * 
 */
const char* defineplayers(int totalPlayers);

/**
 * @brief Create a Team object
 * 
 * @return struct teams 
 */


/**
 * @brief 
 * 
 */
void displayTeam();

/**
 * @brief Get the Player Toss object
 * 
 * @param TeamA 
 * @param TeamB 
 * @param t 
 * @return struct Tuple 
 */
struct Tuple GetPlayerToss(char TeamA[],char TeamB[],struct teams t);

/**
 * @brief Get the Choice object
 * 
 * @param winner 
 * @param loser 
 * @return char* 
 */
char* getChoice(char winner[],char loser[]);

void play();

#endif  /* #define __VIRTUAL_CRICKET_H__ */
