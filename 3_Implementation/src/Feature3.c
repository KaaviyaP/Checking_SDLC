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
 


struct Tuple {

    char wonteam[50],choice[50];
};
struct Tuple GetPlayerToss(char TeamA[],char TeamB[],struct teams t);
char* getChoice(char winner[],char loser[]);

struct Tuple GetPlayerToss(char TeamA[],char TeamB[],struct teams t)
{
    
    char choice[50];
    char str[50];
    struct Tuple retstr;
    printf("%s Captain Name: %s\n",TeamA,t.A.captainA.name);

    printf("%s Captain Name: %s\n",TeamB,t.B.captainB.name);

    int player1Choice,player2Choice,toss,player1Toss,batorbowlChoice,player2Score,player1Score;
      printf("\n%s (Team A) Choose your choice either 1 for head or 2 for tail: ",t.A.captainA.name);
     scanf("%d",&player1Choice);
      if(player1Choice==1)
      {
      player2Choice=2;
      printf("%s (Team A) Choice is Head\n",t.A.captainA.name);
     printf("%s (Team B) Choice is Tail\n",t.B.captainB.name);
   }
   else if(player1Choice==2)
   {
    player2Choice=1;
    printf("%s (Team A) Choice is Tail\n",t.A.captainA.name);
    printf("%s (Team B) Choice is Head\n",t.B.captainB.name);
   }
   else
   {
    printf("--------------------------------------------Invalid Choice--------------------------------------------\n");
   }
    toss=rand()%2;
    toss=toss+1;
   if(toss==1)
    printf("\nToss = Head\n");
    else
    printf("\nToss = Tail\n");
    if(toss==player1Choice)
    {
     player1Toss=1;
    printf("%s Won the Toss\n",TeamA);
    sprintf(retstr.wonteam, "%s", TeamA);
    
    sprintf(retstr.choice, "%s", getChoice(TeamA,TeamB));
    
    printf("%s",choice);
     
    }
  else if(toss==player2Choice)
  {
   player1Toss=2;
   printf("%s Won the Toss\n",TeamB);
   sprintf(retstr.wonteam, "%s", TeamB);
   sprintf(retstr.choice, "%s", getChoice(TeamB,TeamA));
     
    
  }
  return retstr;
}

int checktossTeam(char t[50])
{
  if((strcmp(t,"TeamA")==0) || (strcmp(t,"TeamB")==0)){
            return 1;
        }
  else{
            return 0;
        }
}

int checktossChoice(char c[10])
{
   if(c=="BAT" || c=="BOWL")
        {
            return 1;
        }
        else{
            return 0;
        }
}

char* getChoice(char winner[],char loser[])
{
    int batorbowl;

    printf("\n%s choose your choice either to bat or bowl \n",winner);
    printf("1:BAT 2:BOWL\n");
    scanf("%d",&batorbowl);
    if(batorbowl==1)
       { printf("\n%s decided to bat first \n", winner); 
        printf("\n%s will Bowl first \n", loser); 
       return "BAT";
       }
    else if(batorbowl==2)
      { printf("\n%s decided to Bowl first \n", winner); 
      printf("\n%s will Bat first \n", loser); 
      
      return "BOWL";
      }
    else
     { 
         printf("-------------------Invalid choice-----------------------");
          }
     return "";
}
