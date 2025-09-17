#include<stdio.h>
#include<stdlib.h>
int validmove(int row,int column,char board[3][3]);
int checkwinner(char board[3][3],char * winner);
void emptyboard(char board[3][3])
{
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            board[i][j]=' ';
        }
    }
}
void printboard(char board[3][3])
{
    int i,j;
    printf("\n%5c C%-5c %5cC%-5c%5cC%-5c\n",' ','0',' ','1',' ','2');
    printf("   -------------------------------\n");
    for(i=0;i<3;i++)
    {
        printf("R%d ",i);
        printf("%s","|");
        for(j=0;j<3;j++)
        {
            printf("%5c",board[i][j]);
            printf("%5s","|");
            
        }
        printf("\n   -------------------------------\n");
    }
}
void playerchoice(char player1,char player2,char board[3][3])
{
    int c=0,row,column;
    //int * rowarr=malloc(9*sizeof(int));
    //int * colarr=malloc(9*sizeof(int));
    char winner;
    while(1)
    {
        c++;
        if(c%2==1)
        {
            printf("\nPlayer 1 turn--->Enter row and column: ");
            scanf("%d %d",&row,&column);
            if(validmove(row,column,board))
            {
                //rowarr[c-1]=row;
                //colarr[c-1]=column;
                board[row][column]='X';
                printboard(board);
                if(checkwinner(board,&winner))
                {
                    printf("\nPlayer 1--->'X' is the Winner\n");
                    break;
                }
            }
            else
            {
                c--;
                printf("\nInvalid move--->Please enter valid move\n");
            }
        }
        else if(c%2==0)
        {
            printf("\nPlayer 2--->turn Enter row and column: ");
            scanf("%d %d",&row,&column);
            if(validmove(row,column,board))
            {
                //rowarr[c-1]=row;
                //colarr[c-1]=column;
                board[row][column]='O';
                printboard(board);
                if(checkwinner(board,&winner))
                {
                    printf("Player 2--->'O' is the Winner\n");
                    break;
                }
            }
            else
            {
                c--;
                printf("\nInvalid move--->Please enter valid move\n");
            }
        }
        if(c==9)
        {
            printf("\nNo Winner--->Its a draw\n");
            break;
        }
    }
}
int validmove(int row,int column,char board[3][3])
{
    if(row>2||row<0||column<0||column>2)
    {
        return 0;
    }
    else if(board[row][column]!=' ')
    {
        return 0;
    }
    return 1;
}
int checkwinner(char board[3][3],char * winner)
{
    int i,j,k,l;
    for(i=0;i<3;i++)
    {
        if((board[i][0]!=' ')&&(board[i][0]==board[i][1])&&(board[i][0]==board[i][2]))
        {
            *winner=board[i][0];
            return 1;
        }
    }
    for(j=0;j<3;j++)
    {
        if((board[0][j]!=' ')&&(board[0][j]==board[1][j])&&(board[0][j]==board[2][j]))
        {
            *winner=board[0][j];
            return 1;
        }
    }
    if((board[0][0]!=' ')&&(board[0][0]==board[1][1])&&(board[0][0]==board[2][2]))
    {
        *winner=board[0][0];
        return 1;
    }
    else if((board[0][2]!=' ')&&(board[0][2]==board[1][1])&&(board[0][2]==board[2][0]))
    {
        *winner=board[1][1];
        return 1;
    }
    return 0;
}