#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void showboard(int r,int c)
{
    for(int i = 0;i<r;i++)
	{
		printf("\n\t       |");
		for(int j=0;j<c;j++)
		{
			printf("        |",j);
		}
		if(i == (r-1))
		{
			printf("\n\t");
		}
		else
        {
        	printf("\n\t\t");
        	for(int j=0; j<c; j++){
        		printf("_________");
			}
        }
	}
}
bool checkwin(int r, int c, char repeat[r][c]){
	bool check;
	int i=0, j=0, checks = 0;
	while(j<c){
		while(i<r){
			if(repeat[i][j]=='P'){
				checks++;
			}f
		}
		
	}
	
}
void update(int r, int c, char repeat[][c])
{
    for(int i = 0;i<r;i++)
	{
		printf("\n\t       |");
		for(int j=0;j<c;j++)
		{
            if(repeat[i][j]=='E'||repeat[i][j]=='P')
            {
                printf("    %c   |",repeat[i][j]);
            }
            else
            {
                printf("        |");
            }
	    }
        if(i == (r-1))
		    {
		       printf("\n\t");
		    }
            else
           {
           	printf("\n\t\t");
        	for(int j=0; j<c; j++){
        		printf("_________");
			}
        }
    }
}
int autorow(int size)
{
    int rowmove;
    srand(time(NULL));
    rowmove=rand()%size;
    return rowmove;
}
int autocol(int size)
{
    int rowcol;
    srand(time(NULL));
    rowcol=rand()%size;
    return rowcol;
}
int checkboard(int r, int c, char checker[][c])
{
    int end=1;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(checker[i][j]!='0')
                {
                    end++;
                    if(end==r*c)
                    {
                        return 1;
                    }
                }
            }
        }
}
int main()
{
    int row,col,er,ec,pr,pc,i,j,k,wincnt=1, turns=1, choice,end=1;
    printf("Enter size of board: ");
    scanf("%d", &row);
    col=row;
    char board[row][col];
    for(int i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            board[i][j]='0';
        }
    }
    showboard(row,col);
    printf("Enter 1 for passer or 2 for eater to play automatically: ");
    scanf("%d", &choice);
    if(choice==1)
    {
        pr=autorow(row);
        pc=autocol(row);
        board[pr][pc]='P';
        printf("\n\tPASSER occupied a cell at row %d, column %d", pr+1, pc+1);
        printf("\n\tEater:: Enter the row and column of a cell to occupy it: ");
        scanf("%d %d", &er, &ec);
        if(board[er-1][ec-1]=='P')
        {
            board[er-1][ec-1]='E';
            printf("\tWARNING: Passer has been eaten at row %d, column %d\n", er, ec);
        }
        else
        {
            board[er-1][ec-1]='E';
        }
        for(i=0;i<row;i++)
        while(turns!=100)
        {
            update(row,col,board);
            if(checkboard(row,col,board)==1)
            {
                printf("\n\tMAX MOVES REACHED");
                break;
            }
            if(checkboard(row,col,board)==1)
            {
                break;
            }
            
            printf("\n\tEater:: Enter the row and column of a cell to occupy it: ");
            scanf("%d %d", &er, &ec);
            if(board[er-1][ec-1]=='E')
            {
                printf("\tAn Eater has already occupied this cell!");
                while(board[er-1][ec-1]=='E')
                {
                    printf("\n\tEater:: Enter the row and column of a cell to occupy it:");
                    scanf("%d %d", &er, &ec);
                }
            }
           if(board[er-1][ec-1]=='P')
            {
                board[er-1][ec-1]=='E';
                printf("\n\tWARNING: Passer has been eaten at row %d, column %d\n", er, ec);
            }
            board[er-1][ec-1]='E';
            pr=autorow(row);
            pc=autocol(col);
            if(board[pr][pc]=='P')
            {
                while(board[pr][pc]=='P' || board[pr][pc]=='E')
                {
                    pr=autorow(row);
                    pc=autocol(row);
                    if(board[pr][pc]!='E' && board[pr][pc]!='P')
                    {
                        board[pr][pc]='P';
                        printf("\n\tPASSER occupied a cell at row %d, column %d", pr+1, pc+1);
                        break;
                    }
                }
                
           }
           if(board[pr][pc]=='E')
           {
                while(board[pr][pc]=='E' || board[pr][pc]=='P')
                {
                    pr=autorow(row);
                    pc=autocol(col);
                    if(board[pr][pc]!='E' && board[pr][pc]!='P')
                    {
                        board[pr][pc]='P';
                        printf("\n\tPASSER occupied a cell at row %d, column %d", pr+1, pc+1);
                        break;
                    }
                }
              
            }
            if(board[pr][pc]!='E' && board[pr][pc]!='P')
            {
            board[pr][pc]='P';
            printf("\n\tPASSER occupied a cell at row %d, column %d", pr+1, pc+1);
            }
            
            
        }
    }
    if(choice==2)
    {
        {
            
            er=autorow(row);
            ec=autorow(col);
            board[er][ec]='E';
            printf("\tEater occupied a cell at row %d & column %d", er+1, ec+1);
            printf("\n\tPasser: Enter the row and column of a cell to occupy it: ");
            scanf("%d %d", &pr, &pc);
            if(board[pr-1][pc-1]=='E')
            {
                while(board[pr-1][pc-1]='E')
                {
                    printf("\tAn Eater has already occupied this cell!");
                    printf("\n\n\tPasser:: Enter the row and column of a cell to occupy it: ");
                    scanf("%d %d", &pr, &pc);
                    if(board[pr-1][pc-1]!='E')
                    {
                        board[pr-1][pc-1]='P';
                    }
                }
            }
           else
            {
                board[pr-1][pc-1]='P';
            }
            while(turns<=100)
            { 

                update(row,col,board);
            if(checkboard(row,col,board)==1)
            {
                printf("\n\tMAX MOVES REACHED");
                break;
            }
            if(checkboard(row,col,board)==1)
            {
                break;
            }
                 er=autorow(row);
                 ec=autocol(col);
                 if(board[er][ec]=='E')
                {
                    while(board[er][ec]='E')
                    {
                        er=autorow(row);
                        ec=autocol(row);
                        if(board[er][ec]!='E')
                        {
                            if(board[er][ec]=='P')
                            {
                                board[er][ec]='E';
                                printf("\tEater has eaten Passer at row %d & column %d", er+1, ec+1);
                                break;
                            }
                            else
                            {
                                board[er][ec]='E';
                                printf("\tEater has occupied a cell at row %d & column %d", er+1, ec+1);
                                break;
                            }
                        }
                    }
                }
                if(board[er][ec]=='P')
                {
                    board[er][ec]='E';
                    printf("\tWARNING: Passer has been eaten at row %d, column %d\n", er+1, ec+1);
                }
                if(board[er][ec]!='E'  && board[er][ec]!='P')
                {
                    board[er][ec]='E';
                    printf("\tEater occupied a cell at row %d & column %d", er+1, ec+1);
                }
                
                printf("\n\tPasser:: Enter the row and column of a cell to occupy it: ");
                scanf("%d %d", &pr, &pc);
                if(board[pr-1][pc-1]=='E' || board[pr-1][pc-1]=='P')
                {
                    while(board[pr-1][pc-1]=='E' || board[pr-1][pc-1]=='P')
                    {
                        printf("\tCell is already occupied by an Eater or a Passer!\n");
                        printf("\tPasser:: Enter the row and column of a cell to occupy it: ");
                        scanf("%d %d", &pr, &pc);
                        if(board[pr-1][pc-1]!='E' && board[pr-1][pc-1]!='P')
                        {
                            board[pr-1][pc-1]='P';
                            turns++;
                            break;
                        }
                    }
                }
                else
                {
                    board[pr-1][pc-1]='P';
                    turns++;
                }
            }
                
        }
    }
    
}



    
