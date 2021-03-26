/*
This program replicates a dice game called "Pig." It consists 3 function prototypes which actually help run the game. The rules of the game are taken from the website provided in the assignment:
https://en.wikipedia.org/wiki/Pig_(dice_game)
An extra function  prints how the game is played. After reading the rules, the player can choose to continues with the game or leave the program.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int dieRoll(void);//rolling die
int house(void);//PLayer 1
int opponent(void);//Player 2
void gameRule(void);//prints the rules of the game

enum Turn { HOUSE, OPPONENT };//help dictate whose turn it is

int main(void){//the main function will count the total of all rounds
  srand(time(NULL));//randomise dice numbers

  int house_total=0;//counts all points for PLAYER 1
  int opponent_total=0;//counts all points for PLAYER 2
  int play;//helps with some user interaction
  enum Turn contenderTurn;

  //some friendly intitial user interaction.
  printf("Welcome to Pigs!\nTo play the game type 1.\nTo read how the game works type 2.\n");
  scanf(" %d", &play);


  if(play == 2){//allows user to view game rules.
    gameRule();//calls function prototype (returns nothing, only prints rules).

    //the player either wants to play or not after reading the rules; they choose
    printf("\nIf you wish to play the game now, please type 1.\n");
    printf("\nIf you are uninterested in playing, please type 0.\n");
    scanf(" %d", &play);

    //ensures the player enters a valid option
    while(play != 1){
      if(play == 0){
        return -1;//game not played
      }
      else{
        printf("Invalid option.\n");
        printf("\nIf you wish to play the game now, please type 1.\n");
        printf("\nIf you are uninterested in playing, please type 0.\n");
        scanf(" %d", &play);
      }
    }
  }


  if(play == 1 ){//this instigates the game

    //the game continues until someone reaches 100 points
    while(house_total < 100 && opponent_total < 100){

      //returns the value from PLAYER 1 round and adds it to the player 1 total.
      house_total += house();
      printf("Your total is %d\n",house_total);

      //If PLAYER 1 earns more than 100 points, they win.
      if(house_total >= 100){
        printf("Congratulations Player 1, you have won with a grand total of %d!\n", house_total);
        return 0;
      }
      //returns the value from PLAYER 2 round and adds it to the player 2 total.
      opponent_total += opponent();
      printf("Your total is %d\n",opponent_total);

    }
    //If PLAYER 2 earns more than 100 points, they win.
    if(opponent_total >= 100){
      printf("Congratulations Player 2, you have won with a grand total of %d!\n", opponent_total);
      return 0;
    }

  }

}



void gameRule(void){//this function prints out the rules of the game as specified in Miscellaneous
  printf("Each turn, a player repeatedly rolls a die until either a 1 is rolled or the player decides to:\n");

  printf("If the player rolls a 1, they score nothing and it becomes the next player's turn.\n");
  printf("If the player rolls any other number,\nit is added to their turn total and the player's turn continues.\n");
  printf("If a player chooses to \"hold\", their turn total is added to their score,");
  printf("and it becomes the next player's turn.\n");
  printf("The first player to score 100 or more points wins.\n\n");

  printf("For example:\nthe first player, Donald, begins a turn with a roll of 5.\n");
  printf("Donald could hold and score 5 points, but chooses to roll again.\n");
  printf("Donald rolls a 2, and could hold with a turn total of 7 points,\nbut chooses to roll again.\n");
  printf("Donald rolls a 1, and must end his turn without scoring.\n");
  printf("The next player, Alexis, rolls the sequence 4-5-3-5-5,\n");
  printf("after which she chooses to hold, and adds her turn total\nof 22 points to her score.\n\n");
}



int house(void){//prototype function associated with player 1
  int house_sum =0;//sets player 1's score to 0 at every new turn.
  int roll;//die role
  char proceed = 'y';//set to 'y' to enter the while loop (assumed that they want to take their first turn)
  enum Turn contenderTurn = HOUSE;//It is Player 1's turn


  printf("\nPLAYER 1.\n");//distinguishes turn

  //while it is Player 1's turn and the player wants to proceed...
  while(contenderTurn == HOUSE && (proceed == 'y' || proceed == 'Y')){
    roll = dieRoll();//they roll their dice; it calls the dieRoll prototype function

    if(roll == 1){
      printf("\nYou rolled a 1!\nYou earned 0 points\nIt is Player 2's turn.\n");
      house_sum = 0;//they receive no points because the did not hold (refer to rules)
      contenderTurn = OPPONENT;//swap; now it's Player 2's turn.
    }

    if(roll > 1){
      house_sum = house_sum + roll;//sums the number on the dice after each roll (unless = 1)
      printf("\nYou rolled a %d!\nYour total for this round so far is %d\nWould you like to continue y/n?\n", roll, house_sum);
      scanf(" %c", &proceed);//checks whether the player holds or proceeds
    }

  }

  return house_sum;//returns the value of the sum(numbers on dice faces) of this turn.

}



int opponent(void){//prototype function associated with player 2
  int opponent_sum =0;//sets player 2's score to 0 at every new turn.
  int roll;//die roll
  char proceed = 'y';//set to 'y' to enter the while loop (assumed that they want to take their first turn)
  enum Turn contenderTurn = OPPONENT;//It is player 2's turn

  printf("\nPLAYER 2.\n");//distinguishes turn

  //while it is Player 1's turn and the player wants to proceed...
  while(contenderTurn == OPPONENT && (proceed == 'y' || proceed == 'Y')){
    roll = dieRoll();//they roll their dice; it calls the dieRoll prototype function

    if(roll == 1){
      printf("You rolled a 1!\nYou earned 0 points and it's the other players turn.\n");
      opponent_sum = 0;//they receive no points because the did not hold (refer to rules)
      contenderTurn = HOUSE;//swap; now it's Player 1's turn
    }

    if(roll > 1){
      opponent_sum = opponent_sum + roll;//adds the number on the dice after each roll (unless = 1)
      printf("\nYou rolled a %d!\nYour total for this round so far is %d\nWould you like to continue y/n?\n", roll, opponent_sum);
      scanf(" %c", &proceed);//checks whether the player holds or proceeds
    }

  }

  return opponent_sum;//returns the value of the sum(numbers on dice faces) of this turn.

}



int dieRoll(void){
  int die = 1 + (rand() % 6);//provides random number between 1-6 (replicates die)

  return die;//returns the number on die
  }


