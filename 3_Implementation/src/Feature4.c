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

void startFirstInnings(char TeamA[4][50],char TeamB[4][50],int maxballs);
void initialisingPlayers(char TeamA[4][50],char TeamB[4][50],int maxballs);
void startSecondInnings(char TeamB[4][50],char TeamA[4][50],int maxballs );
int letsPlay(char TeamA[4][50],char TeamB[4][50],char batsman[50],char bowler[50],int maxballs);
int bat(char TeamA[4][50],char TeamB[4][50],char batsman[50],char bowler[50]);




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
	printf("Ready To bowler %s\n",bowler);
	letsPlay(TeamA,TeamB,batsman,bowler,maxballs);
    
}

void startSecondInnings(char TeamA[4][50],char TeamB[4][50],int maxballs ) {
    
    
    printf("|                                                                                               |\n");
    printf("|===================================== SECOND-INNINGS-STARTS ===================================|\n");
    printf("|_|\n");
    printf("\t\t\t\tPress Enter\n");
    while((getchar())!='\n');
    netbatsmanrun=0;
    neteamrun=0;
    ballsplayed=0;
    count++;
    initialisingPlayers(TeamA,TeamB,maxballs);
}

int letsPlay(char TeamA[4][50],char TeamB[4][50],char batsman[50],char bowler[50],int maxballs){
	int teamtotalscore=0,i;
	if(maxballs>0){
		for(i=0;i<maxballs;i++){
		
		printf("\t\t\t\tLet's Play \n");
		printf("\t\t\t\tPress Enter\n");
        while((getchar())!='\n');
        if(count>0)
		{
		batsman=TeamB[wicketlost-1];}
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

printf("\t\t\t\tpress Enter to start the spell\n");
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





