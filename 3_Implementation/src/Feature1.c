#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

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

struct teams getdetails()
{
struct teams t;
return t;

}


error_t welcome(){ 
    
    
    printf("|===================================== VIRTUAL CRICKET ========================================|\n");
    printf("|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |\n");
    printf("                                                                                               |\n");
    printf("========================================== WELCOME!!! =========================================|\n");
    printf("|                                             TO                                               |\n");
    printf("|===================================== Virtual-Cricket-Game ===================================|\n");
    printf("                                                                                               |\n");
    printf("=========================================== RULES =============================================|\n");
    printf("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n");
    printf("                                                                                               |\n");
    printf("|1. You have to form Two teams.Select 4 players for each team from the given pool of  players|\n");
    printf("|2. Win the toss and select what you will do batting or bowling.                               |\n");
    printf("|3. There will be 6 balls in each inning.                                                      |\n");
    
    return SUCCESS;
}

error_t displayPoolPlayers(int totalPlayers) 
{
    char* player[8];   
    player[0] = "Virat";
    player[1] = "Rohit";
    player[2] = "Dhoni";
    player[3] = "Pant";
    player[4] = "KLRahul";
    player[5] = "Raina";
    player[6] = "Jadeja";
    player[7] = "Sachin";
     
    if(totalPlayers<=0)
    {
         printf("The total number of Players is lessthan or equal to zero                                   |\n");
         return FAILURE;
    }
    
    int i;
  
    printf("|                                                                                               |\n");
    printf("|==================================== Pool-of-players =======================================|\n");
   
    for(i = 0;i < totalPlayers; i++) {
        
        printf("[ %d ]. %s \n",i,player[i]); 
    }
        
    return SUCCESS;
}

int takeIntegerOnly() 
{
    int i; 
        
    while(scanf("%d", &i)==0) //if scanf failed to scan an integer
{
    printf("Invalid input. Try again\n");
    int c;
    while((c=getchar())!='\n' && c!=EOF); //clear the stdin
}
    
    return i;
}
