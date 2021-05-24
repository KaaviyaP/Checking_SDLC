#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int isFirstInnings = 0;
int netbatsmanrun=0;
int playersPerTeam = 4;
int batsmanrun=0;
int neteamrun=0;
int ballsplayed=0;
int totalballsbawled=0;
int bowlsbawled=0;
int runGiven=0;
int wicketlost=0;
int wickettaken=0;
int maxBalls = 6;
int totalPlayers = 11;
int count=0;

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
struct Tuple toss;

void startFirstInnings(char TeamA[4][50],char TeamB[4][50],int maxballs);
void initialisingPlayers(char TeamA[4][50],char TeamB[4][50],int maxballs);
void startSecondInnings(char TeamB[4][50],char TeamA[4][50],int maxballs );
int letsPlay(char TeamA[4][50],char TeamB[4][50],char batsman[50],char bowler[50],int maxballs);
int bat(char TeamA[4][50],char TeamB[4][50],char batsman[50],char bowler[50]);
void start(struct teams t,struct Tuple toss);

void start(struct teams t,struct Tuple toss)
{
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
    
    if(strcmp(toss.wonteam,"TeamA")==0 && strcmp(toss.choice,"BAT")==0)
    {
        startFirstInnings(TeamA,TeamB,maxBalls);
    }
    else if(strcmp(toss.wonteam,"TeamA")==0 && (strcmp(toss.choice,"BOWL")==0))
    {
        startFirstInnings(TeamB,TeamA,maxBalls);
    }
    else if(strcmp(toss.wonteam,"TeamB")==0 && strcmp(toss.choice,"BAT")==0)
    {
        startFirstInnings(TeamB,TeamA,maxBalls);
    }
    else 
    {
        startFirstInnings(TeamA,TeamB,maxBalls);
    }
}



void startFirstInnings(char TeamA[4][50],char TeamB[4][50],int maxballs) {
    
    
    printf("|                                                                                               |\n");
    printf("|===================================== FIRST-INNINGS-STARTS ====================================|\n");
    printf("|                                                                                               |\n");
    printf("\t\t\t\tPress Enter\n");
    while((getchar())!='\n');
    
	isFirstInnings=1;
    
    initialisingPlayers(TeamA,TeamB,maxBalls);
}

void initialisingPlayers(char TeamA[4][50],char TeamB[4][50],int maxballs){
	char batsman[50];
	char bowler[50];
    strcpy(batsman,TeamA[0]);
    strcpy(bowler,TeamB[0]);
	printf("Ready To bat %s\n",batsman);
	printf("Ready To bowl %s\n",bowler);
	letsPlay(TeamA,TeamB,batsman,bowler,maxballs);
    
}

void startSecondInnings(char TeamA[4][50],char TeamB[4][50],int maxballs ) {
    
    
    printf("|                                                                                               |\n");
    printf("|===================================== SECOND-INNINGS-STARTS ===================================|\n");
    printf("|_|\n");
    printf("\t\t\t\tPress Enter\n");
    while((getchar())!='\n');
    netbatsmanrun=0;
	batsmanrun=0;
	neteamrun=0;
	ballsplayed=0;
	bowlsbawled=0;
	runGiven=0;
	wicketlost=0;
	wickettaken=0;
    count++;
    initialisingPlayers(TeamA,TeamB,maxballs);
}

int letsPlay(char TeamA[4][50],char TeamB[4][50],char batsman[50],char bowler[50],int maxballs){
	int i;
	if(maxballs>0){
		for(i=0;i<maxballs;i++){
		
		printf("\t\t\t\tLet's Play \n");
		printf("\t\t\t\tPress Enter\n");
        while((getchar())!='\n');
        if(count>0)
		{
		batsman=TeamB[wicketlost];}
		else
		{
		batsman=TeamA[wicketlost];	
		}
        
		bat(TeamA,TeamB,batsman,bowler);
		
		
	}
}
printf("\t\t\t\tTEAM B SCORED %d\n",neteamrun);//displaying individual batsman run
}

int bat(char TeamA[4][50],char TeamB[4][50],char batsman[50],char bowler[50])
{

printf("\t\t\t\tpress Enter to start batting\n");
 while((getchar())!='\n');
//batsman status
srand(time(NULL));
batsmanrun=rand()%7;//batsmanrun per bowl
netbatsmanrun+=batsmanrun;
neteamrun+=batsmanrun;
ballsplayed+=1;

//bowler status 
bowlsbawled+=1;
runGiven+=batsmanrun;
totalballsbawled+=1;

if(batsmanrun==4){
printf("Runs = 4\n");
printf("Hurray! Hit the Four\n");
}
else if(batsmanrun==6){
printf("Runs = 6\n");
printf("Awsome! That's what the Yes Bank MAXIMUM SIX\n");
}
else if(batsmanrun==1){
printf("Runs = 1\n");
printf("Well Played\n");
}
else if(batsmanrun==0){
printf("Runs = 0\n");
printf("Hurray! Bowled\n");
printf(" BATSMAN %s SCORED %d RUNS\n",batsman,netbatsmanrun);//displaying individual batsman run
printf(" BATSMAN %s PLAYED %d BALLS\n",batsman,ballsplayed);//displaying individual batsman run
netbatsmanrun=0;
ballsplayed=0;
wicketlost+=1;
wickettaken+=1;
batsman=TeamA[wicketlost];
printf("BOWLER NAME %s\n",bowler);
}
else{
printf("Runs = %d\n",batsmanrun);
}

	

if((totalballsbawled==maxBalls)||(wicketlost==4)){
	printf("\t\t\t\tTEAM A SCORED %d\n",neteamrun);//displaying individual batsman run
	startSecondInnings(TeamB,TeamA,maxBalls);
}

}





