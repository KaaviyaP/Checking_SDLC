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
 * @brief Function to get team player details
 * 
 */
struct teams getdetails();


/**
 * @brief Welcome to Virtual Cricket function to display instructions
 * 
 */
error_t welcome();


/**
 * @brief Function to display all the members of the pool
 * 
 * @param[in] totalPlayers 
 */
error_t displayPoolPlayers(int totalPlayers);


/**
 * @brief Function to return only an Integer value
 * 
 * @return int An integer value
 */
int takeIntegerOnly();


/**
 * @brief Function to generate IDs
 * 
 * @param[in] lower Lower limit of valid IDs
 * @param[in] upper Upper limit of valid IDs
 * @param[in] count Number of Ids required
 * @return int Generated ID
 */
int getID(int lower, int upper, int count);


/**
 * @brief Function to check if IDs are between 1-8
 * 
 * @param[in] x The ID number 
 * @return int 1 if within the range, -1 if not within range
 */
int checkIDRange(int x);


/**
 * @brief Function to validate player IDs
 * 
 * @param[in] p_id Player ID
 * @param[in] x The generated ID
 * @param[in] availibility Player's availibility status
 * @return int 
 */
int validateID(int p_id,int x,int availibility);


/**
 * @brief Function to define the 8 players
 * 
 * @param[in] totalPlayers 8 player in total
 * @return error_t SUCCESS/FAILURE of defining 8 players
 */
error_t defineplayers(int totalPlayers);


/**
 * @brief Function to create 2 Teams with 4 player each
 * 
 * @return struct teams Details of 2 Teams created
 */
struct teams createTeam();


/**
 * @brief Function to display teams
 * 
 * @param[in] n The number of players(8)
 * @return error_t SUCCESS/FAILURE of displaying 8 players
 */
error_t displayTeam(int n);


/**
 * @brief Function to return results of the toss
 * 
 * @param[in] TeamA Team A
 * @param[in] TeamB Team B
 * @param[in] t Team details
 * @return struct Tuple 
 */
struct Tuple GetPlayerToss(char TeamA[],char TeamB[],struct teams t);


/**
 * @brief Function to declare the winner's and loser's state of playing
 * 
 * @param[in] winner Winning team
 * @param[in] loser Losing team
 * @return char* BAT/BOWL choice
 */
char* getChoice(char winner[],char loser[]);


/**
 * @brief Checking the team for the Toss
 * 
 * @param[in] t The Team name
 * @return int 1 if correct,0 if wrong
 */
int checktossTeam(char t[50]);


/**
 * @brief Choice for Head or Tail
 * 
 * @param[in] c BAT/BOWL
 * @return int 1 if correct,0 if wrong
 */
int checktossChoice(char c[10]);


/**
 * @brief Function to pass the toss winning team to the first Inning function
 * 
 * @param[in] t Team details
 * @param[in] toss Toss details
 */
void start(struct teams t,struct Tuple toss);


/**
 * @brief Function to start the first innings
 * 
 * @param[in] TeamA Team A
 * @param[in] TeamB Team B 
 * @param maxballs Number of total balls
 */
void startFirstInnings(char TeamA[4][50],char TeamB[4][50],int maxballs);


/**
 * @brief Function for initialising the players
 * 
 * @param[in] TeamA Team A
 * @param[in] TeamB Team B 
 * @param maxballs Number of total balls
 */
void initialisingPlayers(char TeamA[4][50],char TeamB[4][50],int maxballs);


/**
 * @brief Function to start the Second Innings
 * 
 * @param[in] TeamB Team B
 * @param[in] TeamA Team A 
 * @param maxballs Number of total balls
 */
void startSecondInnings(char TeamB[4][50],char TeamA[4][50],int maxballs );


/**
 * @brief Function to start the play
 * 
 * @param[in] TeamA Team A
 * @param[in] TeamB Team B
 * @param[in] batsman batsman details
 * @param[in] bowler bowler details
 * @param[in] maxballs Total number of balls
 * @return int Scores of innings
 */
int letsPlay(char TeamA[4][50],char TeamB[4][50],char batsman[50],char bowler[50],int maxballs);


/**
 * @brief Function to start the batting
 * 
 * @param[in] TeamA Team A
 * @param[in] TeamB Team B
 * @param[in] batsman batsman details
 * @param[in] bowler bowler details
 * @return int Batting and bowling stats
 */
int bat(char TeamA[4][50],char TeamB[4][50],char batsman[50],char bowler[50]);


/**
 * @brief Function to display the scorecard
 * 
 */
void showScoreCard();


/**
 * @brief Function to Validate the innings
 * 
 * @return int 1 if valid 0 if invalid
 */
int validateInnings();


/**
 * @brief 
 * Sort the array
 * 
 * @param[in] arr_name 
 * @param[in] count 
 * @param[in] size 
 * @param[in] new_size 
 */
void sort_array(int*arr_name, int *count,int size, int*new_size);


/**
 * @brief Merging the arrays
 * 
 * @param[in] arr_name 
 * @param[in] left 
 * @param[in] right 
 * @param[in] count 
 * @param[in] count_left 
 * @param[in] count_right 
 * @param[in] left_size 
 * @param[in] right_size 
 * @param[in] new_size 
 */
void merge_array(int*arr_name, int*left,int*right, int *count, int*count_left,int*count_right, int left_size, int right_size, int*new_size);


/**
 * @brief Get the position object
 * 
 * @param[in] arr_name Array name
 * @param[in] num Number
 * @param[in] size Size od array
 * @return int Position of object
 */
int get_position(int*arr_name, int num, int size);


/**
 * @brief Median of array
 * 
 * @param[in] arr_name Array name
 * @param[in] size Array size
 * @return int median of array
 */
int median_of_array(int*arr_name, int size);


/**
 * @brief Sub game played between 2 players each selected between the rival teams
 * 
 */
void rivalGame();

#endif  /* #define __VIRTUAL_CRICKET_H__ */
