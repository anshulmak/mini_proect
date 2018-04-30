#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int m,n,xs,ys,xe,ye,c=0;
bool findpath(int maze[m][n], int x, int y, int sol[m*n][2]);


void displaypath(int sol[m*n][2])
{
    int i,j;
    for (i = 0; i < c; i++)
    {
        for ( j = 0; j < 2; j++)
            printf(" %d ", sol[i][j]+1);
        printf("\n");
    }
}
bool checkobstacle(int maze[m][n], int x, int y)
{
    if(x >= 0 && x < m && y >= 0 && y < n && maze[x][y] == 1)
        return true;

    return false;
}

bool finalpath(int maze[m][n])
{
    int sol[15][2];
    if(findpath(maze,xs-1,ys-1, sol) == false)
    {
        printf("NO");
        return false;
    }

    printf("YES\n");
    printf("%d\n",c);
    displaypath(sol);
    return true;
}

bool findpath(int maze[m][n], int x, int y, int sol[m*n][2])
{
    if(x == xe-1 && y == ye-1)
    {
        sol[c][0] = xe-1;
        sol[c][1] = ye-1;
        c++;
        return true;
    }

    if(checkobstacle(maze, x, y) == true)
    {
        sol[c][0] = x;
        sol[c][1] = y;
        c++;

        if (findpath(maze, x+1, y, sol) == true)
            return true;

        if (findpath(maze, x, y+1, sol) == true)
            return true;

        if (findpath(maze, x-1, y, sol) == true)
            return true;

        if (findpath(maze, x, y-1, sol) == true)
            return true;
        c=0;
        sol[c][0] = 0;
        sol[c][1] = 0;
        return false;
    }
    return false;
}
int main()
{
    int i,j;
    scanf("%d %d",&m,&n);
    int maze[m][n];
    for(i= 0 ; i<m ; i++)
    {
        printf("Enter the row%d of maze\n",i+1);
        for(j = 0 ; j<n ; j++)
        {
            scanf("%d",&maze[i][j]);
        }
    }
    for(i= 0 ; i<m ; i++)
    {
        for(j = 0 ; j<n ; j++)
        {
            printf("%d\t",maze[i][j]);
        }
        printf("\n");
    }

    scanf("%d %d",&xs,&ys);
    scanf("%d %d",&xe,&ye);
    finalpath(maze);
    system("pause");
    return 0;
}
