#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void start(); //function prototype
void start() //function that prints the game's instructions
{
  printf("---------------------------------------------------------------------------------------------------------------------\n");
  printf("Welcome to the Pig Dice Game!\n");
  printf("Instructions:\n");
  printf("The Pig Dice Game is a two-player game where player1 starts off by rolling the dice.\n");
  printf("After the dice roll, player has two options: continue rolling or hold their turn (in which case it's player2's turn).\n");
  printf("Aside from rolling a 1, rolls are added to player's total score. In case of rolling a 1, 0 points are scored.\n");
  printf("Whoever gets more than or equal to 100 points first, wins.\n");
  printf("---------------------------------------------------------------------------------------------------------------------\n");
}



int score(); //function prototype
int score(int score1, int score2) //function that shows the scoreboard
{
  printf("--Game Scoreboard--\n");
  printf("Player1:%d - Player2:%d\n", score1, score2);
  return 0;
}

int main(void)
{
  //Srand that you forgot to use
  srand(time(0));
  int player1, player2; // points that are scored for that turn
  int score1=0, score2=0;// overall points count (initialized to 0 in the beginning)
  int i; // each turn
  int turn; //indicates whose turn it is
  bool t = true;
  char choice; //choice of play, either continue or hold
  while(t)
  {


     //Player 1 do while loop -so this loop keeps on running if player 1 one wants to continue and up to 100
     //but if it gets 1 then it exits the loop
    do{//PLAYER 1 DO WHILE LOOP!//We are using a do while loop because it will check at the end if it the score of player one is less then 100
        printf("Player 1:Please enter N if you want to continue or press Y if you want to hold!:\n");
        choice = getchar();
    if(choice=='N') //when it's player1's turn and they want to continue
    {

      player1 = 1+(rand()%6);
      printf("Player1 rolled a %d.\n", player1);
      if (player1==1 )
      {
        score1 = score1 + 0;
      break;

      }
      else if (player1 >0)
      {
          score1 = score1 + player1;
      }
      score(score1, score2);
    }

    else if (choice=='Y') //when it's player1's turn and they want to hold
    {
      printf("Player1 holds their turn.\n");
      printf("Player2's turn.\n");
      player2 = 1+(rand()%6);
      printf("Player2 rolled a %d.\n", player2);
      break;// breaks out of the loop and goes to player 2 do while loop
    }
    }while(score1 < 100);
    if (score1>=100)
    {
      printf("Player1 wins!\n");
      t = false;
    }



    //PLAYER 2
   while(score2 <100 && score1 <100){
    //Player 2 do while loop
    printf("Please enter N if you want to continue or else press Y\n");
    choice = getchar();
    if(choice=='N') //when it's player2's turn and they want to continue
    {
      player2 = 1+(rand()%6);
      printf("Player2 rolled a %d.\n", player2);
      if (player2==1)
      {
          score2 = score2 + 0;
          //THIS BREAK WILL BREAK OUT OF THE WHILE LOOP AND GO BACK TO PLAYER 1 ABOVE BECAUSE THERE IS AN OUTTER WHILE LOOP
          break;//lidl you could use a bool check variable and then set it to false if you want to and do it in the
                //in the if statement too if possible so if player2 ==1 & check = false then set it to true in for loop
      }

      else {
          score2 = score2 + player2;}
          score(score1, score2);
    }


    else if(choice == 'Y'){
     //when it's player2's turn and they want to hold

      printf("Player2 holds their turn.\n");
      printf("Player1's turn.\n");

      player1 = 1+(rand()%6);
      printf("Player1 rolled a %d.\n", player1);
      if (player1==1)
      {
          score1 = score1 + 0;
          break;//we are breaking because we want to leave this player mini player 2 while loop and go to the next while loop which
                // which is next loop so this breaks this loop and goes to the next one
          }
      else {
          score1 = score1 + player1;
          break;//same reason as above
          }
      score(score1, score2);
      break;//same reason as above

    }
  }
  }

    if (score2>=100)
    {
      printf("Player2 wins!\n");
      t = false;
    }
  }
