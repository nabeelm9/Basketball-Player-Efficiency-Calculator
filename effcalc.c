#include<stdio.h>
#include<math.h>
#include <stdbool.h>
/*
Author: Nabeel Merali
Purpose: Calculate a Basketball Players efficiency
Calculation Information Obtained From:
https://captaincalculator.com/sports/basketball/efficiency/
*/

//statistics for calculations
char answer;
int points;
int assists;
int rebounds;
int steals;
int blocks;
int mfg;
int mft;
int to;
int gp;
double mp;
double effans;
char secanswer;
char thirdanswer;
char gomode;




//Function prototypes for introQuestion, eff, epg, epFortyEight
bool answertoquestion(char answer);
int eff (int points, int assists, int rebounds, int steals, int blocks, int mfg, int mft, int to);
double epg (double effans, int gp);
double epFortyEight (double eff, double mp);



// introQuestion function
bool answertoquestion(char answer){
    if(answer == 'y'){
        return true;
    }
    else if(answer == 'n') {
        return false;
    }
}

// function that calculates player efficiency 
int eff (int points, int assists, int rebounds, int steals, int blocks, int mfg, int mft, int to){
    int efficiency = (points + rebounds + assists + steals + blocks + mfg + mft + to);
    return efficiency;
    
}
//function that calculates player efficiency per game
double epg (double effans, int gp) {
    double efficiencypergame = effans / gp;
    return efficiencypergame;
}
//function that calculates player efficiency per 48 minutes
double epFortyEight (double effans, double mp){
    int efficiencyperfourtyeight = (effans / mp) * 48;
    return efficiencyperfourtyeight;
}
//main function
int main() {
   printf("Would you like to calculate a players efficiency based on one games statistics? (y - yes, n - no) \n");
   scanf("%c", &answer);
   if(answertoquestion(answer) == true) {
    printf("Ok let's calculate the efficiency!\n");
   }
   else if(answertoquestion(answer) == false) {
    printf("Ok have a nice day!");
    return 0;
   }
   printf("What is the players positive stats during the game?(points, assists, rebounds, steals, blocks)?\n");
   scanf("%i %i %i %i %i", &points, &assists, &rebounds, &steals, &blocks);

   printf("What is the players negative stats during the game?(mfg - missed field goals, mft - missed free throws, to - turnovers)\n");
   scanf("%i %i %i", &mfg, &mft, &to);

   int playerEfficiency = eff(points, assists, rebounds, steals, blocks, mfg, mft, to);
   printf("This is your players efficiency %i.\n", playerEfficiency);
   
   printf("Would you like to calculate the players efficiency per game? (y - yes, n - no)\n");
   scanf(" %c", &secanswer);
   
   if(answertoquestion(secanswer) == true) {
    printf("Ok let's calculate the efficiency per game!\n");
   }
   else if(answertoquestion(secanswer) == false) {
    printf("Ok have a nice day!");
    return 0;
   }
   printf("How many games has this player played?\n");
   scanf("%i", &gp);
   int playerefficiencypergame = epg((double)playerEfficiency, gp);
   printf("Your players efficiency per game is %d.\n", playerefficiencypergame);

   printf("Would you like to calculate the players efficiency per 48 minutes? (y - yes, n - no)\n");
   scanf(" %c", &thirdanswer);
   if(answertoquestion(thirdanswer) == true) {
    printf("Ok let's calculate the efficiency per 48 minutes!\n");
   }
   else if(answertoquestion(thirdanswer) == false) {
    printf("Ok have a nice day!");
    return 0;
   }
   printf("How many minutes did the player play during the 48 minutes?\n");
   scanf("%d", &mp);
   int playerefficiencyperfortyeightmins = epFortyEight((double)playerEfficiency, mp);
   printf("Your players efficiency per 48 minutes is %d.\n", playerefficiencyperfortyeightmins);

   printf("Everyone deserves to play the game of basketball no matter what their efficiency!\n Keep Playing!");
   

   for(int i = 0; i < 10; i++)
   {
    printf(i);
    
   }
}

