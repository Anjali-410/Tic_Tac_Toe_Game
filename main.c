#include<stdio.h>
void emptyboard(char board[3][3]);
void printboard(char board[3][3]);
void playerchoice(char player1,char player2,char board[3][3]);
int main()
{
    printf("\n      <----Tic-Tac-Toe game---->\n");
    char board[3][3];
    int choice;
    do
    {
       char winner;
        emptyboard(board);
        printboard(board);
        char player1='X';
        char player2='O';
        printf("Player 1: X\n");
        printf("Player 2: O\n");
        playerchoice(player1,player2,board);
        while(1)
        {
            printf("Do you want to replay ?\n");
            printf("1.Yes\n");
            printf("2.No\n");
            printf("Enter Your Choice: ");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: printf("\n      <---Starting New Game--->   \n");
                        break;
                case 2: printf("<---Thanks For Playing--->\n");
                        break;
                default: printf("Invalid Choice--->Enter Valid Choice\n");
            }
            break;
        }
    } while (choice!=2);
    return 0;
}