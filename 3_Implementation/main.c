#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include "virtual_cricket.h"

// Structure to store all the player details
struct players{
        char name[50];
        int id;  
        int runsScored;
        int ballsPlayed;
        int ballsBowled;
        int runsGiven;
        int wicketsTaken;
};
//Structure to store all the Team A details
struct teamA{
    struct players PA1;
    struct players PA2;
    struct players PA3;
    struct players PA4;
    struct players captainA;
};
//Structure to store all the Team B details
struct teamB{
    struct players PB1;
    struct players PB2;
    struct players PB3;
    struct players PB4;
    struct players captainB;
};
//Structure for Team A,B
struct teams{
    struct teamA A;
    struct teamB B;
};
//Structure for Toss details
struct Tuple {
    char wonteam[50],choice[50];
};

//Function declarations
error_t welcome();
error_t displayPoolPlayers(int totalPlayers);
error_t defineplayers(int totalPlayers);
error_t displayTeam(int n);
struct teams createTeam();
void start();
void showScoreCard();
int validateInnings();
void rivalGame();

int main()
{      
    //Feature 1
    int playersPerTeam=4;
    int maxBalls=6;
    int totalPlayers=8;
    welcome();
    printf("\t\t\t\tPress Enter to display list of all players\n");
    while((getchar())!='\n');
    displayPoolPlayers(totalPlayers);
   
    //Feature 2
    defineplayers(totalPlayers);
    struct teams t;
    t =createTeam();
    displayTeam(8);
   
    //Feature 3
    int r,c;
    struct Tuple toss;
    r=rand() %2;
    toss=GetPlayerToss("Team A","Team B",t);
    printf("\n**************************************\n");
    printf("\n%s\n",toss.wonteam);
    printf("%s\n",toss.choice);
     
    //Feature 4
    start(t,toss);
   
    //Feature 5 
    showScoreCard();
    validateInnings();
    rivalGame();
     
     return 0;
}
