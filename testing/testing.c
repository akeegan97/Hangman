#include<stdlib.h>
#include<stdio.h>
#include<time.h>
#include<string.h>
#define MAXLINES 1050
#define MAXLEN 100

int main(){
    char data[MAXLINES][MAXLINES];
    printf("\x1b[46m*************************************\x1b[0m\n");
    printf("*        WELCOME TO HANGMAN         *");
    printf("*************************************\n");
    printf("enter player name: ");
    char player[50];
    int PlayAgain = 1;
    scanf("%s", player);
    int loops;
    do{
    
    FILE * file;
    file = fopen("/Users/andrewkeegan/Desktop/Code_Things/C/Hangman/testing/words.txt","r");

    if(file==NULL)
    {
        printf("error opening file");
        return 1;
    }
    int line = 0;

    while(!feof(file) && !ferror(file))
        if(fgets(data[line],MAXLEN,file)!= NULL)
            line++;
    fclose(file);

    //for ( int i =0; i< line ; i++ )
    //    printf("%s\n",data[i]);
    
    char *SW;
    srand(time(0));
    int SECRET_NUMBER = rand()%1000;
    SW = data[SECRET_NUMBER];
    //printf("THIS IS THE ONE: %s",SW);
   
    //printf("this is the answer: %s",SW);

    //getting the name of player2
    
    
    // getting the word that player 1 is using for the game
    /*char SECRET_WORD[500]; //initializing the variable to hold the word
    //asking for stdin for the word
    printf("Enter Hangman Word: ");
    fflush(stdout);
    scanf(" %s",SECRET_WORD);
    */
    //flushing the stdout so that it can be reused
    //need the length of the SECRET_WORD so that the true/false array can be normalized to that size
    int len = strlen(SW)-1;//stores the word's length in variable len
    //initializing the true/false array
    int answerCheck[len];
    for(int i = 0;i < len; ++i ){//intialize counter, while counter is less than len, increment counter
        answerCheck[i]=0;
    }//makes the answerCheck array all have 0's for the length of the SECRET_WORD
    int won = 0; // variable that checks if the player has won or not 0=false, 1 = true
    //implement while loop for the remaining game logic
    while(won == 0){
        printf("1The word is: ");//printing the first part of the stdout message: second part requires a logic operator
        
        for(int x = 0; x < len; ++x){
            if (answerCheck[x]==1) {//loops through the answercheck array when encountering a 1 which is a true value, prints the char at the index position of the SECRET_WORD
                printf("%c",SW[x]);
                
            }else{
                printf("*");//for answerCheck indexes that contain a 0 it prints out a 
                
            }
            
        }
        fflush(stdout);
        printf("\n");
        
        //getting answers from the player:
        char Guess;//initialize the guess char that will hold the value of the guess for one loop 
        printf("3Enter Letter: \n");//asking for the guess
        //flushing stdout
        scanf(" %c",&Guess);//scaning the stdin for the value pushing to var Guess
        //next checking if the char in guess is inside of the SECRET_WORD char array need to return the index so that the true/false array can be flipped at that index position
        for(int y = 0; y < len; ++y){
            if(SW[y]==Guess){
                answerCheck[y]=1;
            }
        }
        //setting the won var to true
        won = 1;
        for(int z=0;z<len;++z){
            if(answerCheck[z]==0){
                won = 0;
                ++loops;
                break;//exit the loop
            }
        }//continue with the while loop
    }
    printf("You won %s! The word was\"%s\".\n",player, SW);
    printf("it took you %d guesses\n",loops);
    printf("Play Again? : Enter 1 for yes and 0 for no!: ");
    scanf("%d",&PlayAgain);
    }while(PlayAgain == 1);

    printf("Thanks for playing: %s",player);
    
    
    
    
    
    return 0;
}

