#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include "virtual_cricket.h"

struct players{
        char name[50];
        int id;  
        int runsScored;
        int ballsPlayed;
        int ballsBowled;
        int runsGiven;
        int wicketsTaken;
};
struct teamA{
    struct players PA1;
    struct players PA2;
    struct players PA3;
    struct players PA4;
    struct players captainA;
};
struct teamB{
    struct players PB1;
    struct players PB2;
    struct players PB3;
    struct players PB4;
    struct players captainB;
};

struct teams{
    struct teamA A;
    struct teamB B;
};

typedef struct p {
char name[50];
int id;
int available;
} player;

struct teams createTeam();
struct Tuple {
    char wonteam[50],choice[50];
};


  void startFirstInnings(char TeamA[4][50],char TeamB[4][50],int maxballs);
  int validateInnings();
  void rivalGame();
  void showScoreCard();

int main()
{      

    int playersPerTeam=4;
    int maxBalls=6;
    int totalPlayers=8;
   
    welcome();
    printf("\t\t\t\tPress Enter to display list of all players\n");
    while((getchar())!='\n');
    displayPoolPlayers(totalPlayers);
   
    //Feature 2
    defineplayers();
    struct teams t;
    t =createTeam();
    displayTeam();
   
    //Feature 3
    int r,c;
    struct Tuple toss;
    r=rand() %2;
    toss=GetPlayerToss("Team A","Team B",t);
    printf("\n**************************************\n");
    printf("\n%s\n",toss.wonteam);
    printf("%s\n",toss.choice);
     

    //Feature 4
  
    char TeamA[4][50];
    char TeamB[4][50];
    strcpy(TeamA[0],t.A.PA1.name);
    strcpy(TeamA[1],t.A.PA2.name);
    strcpy(TeamA[2],t.A.PA3.name);
    strcpy(TeamA[3],t.A.PA4.name);

    strcpy(TeamB[0],t.B.PB1.name);
    strcpy(TeamB[1],t.B.PB2.name);
    strcpy(TeamB[2],t.B.PB3.name);
    strcpy(TeamB[3],t.B.PB4.name);
    
    if(toss.wonteam=="TeamA" && toss.choice=="BAT")
    {
        startFirstInnings(TeamA,TeamB,maxBalls);
    }
    else if(toss.wonteam=="TeamA" && toss.choice=="BOWL")
    {
        startFirstInnings(TeamB,TeamA,maxBalls);
    }
    else if(toss.wonteam=="TeamB" && toss.choice=="BAT")
    {
        startFirstInnings(TeamB,TeamA,maxBalls);
    }
    else 
    {
        startFirstInnings(TeamA,TeamB,maxBalls);
    }


    //Feature 5 
    showScoreCard();
    validateInnings();
    rivalGame();
     
     return 0;
}
