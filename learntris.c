#include<stdio.h>
#include<stdlib.h>

//function to set the value of active tetramino
void set_active_tetramino(char t[5][5], char c)
{
	int i, j;
	if(c == 'I')
	{
		for(i=0; i<5; i++)
		{
			for(j=0; j<5; j++)
			{
				if(i == 1)
					t[i][j] = 'c';
				else
					t[i][j] = '.';
			}
		}
	}
}

int main()
{
	char command;
	char tetris[23][11];
	char tetramino[5][5];
	int i, j, score, num_of_cleared_lines, flag;
	for(i=0; i<22; i++)
	{
		for(j=0; j<10; j++)
		{
			tetris[i][j] = '.';
		}
	}
	score = num_of_cleared_lines = 0;
	while((command=getchar())!= EOF)
	{
		if(command=='p')
		{
			for(i=0; i<22; i++)
			{
				for(j=0; j<10; j++)
				{
					printf("%c ",tetris[i][j]);
				}
			printf("\n");
			}
		}
		else if(command=='g')
		{
			for(i=0; i<22; i++)
			{
				for(j=0; j<10; j++)
				{
					scanf(" %c",&tetris[i][j]);
					
				}
			}
		}
		else if(command=='c')
		{
			for(i=0; i<22; i++)
			{
				for(j=0; j<10; j++)
				{
					tetris[i][j] = '.';
				}
			}
		}
		else if(command=='?')
		{
			command = getchar();
			if(command == 's')
			{
				printf("%d\n",score);
			}
			if(command == 'n')
			{
				printf("%d\n",num_of_cleared_lines);
			}
		}
		else if(command == 's')
		{
			for(i=0; i<22; i++)
			{
				flag = 1;
				for(j=0; j<10; j++)
				{
					if(tetris[i][j] == '.')
					{
						flag = 0;
						break;
					}
				}
				if(flag == 1)
				{
					for(j=0; j<10; j++)
						tetris[i][j] = '.';
					score += 100;
					num_of_cleared_lines += 1;
				}
			}	
		}
		else if(command == 'I')
			set_active_tetramino(tetramino, command);
		else if(command == 't')
		{
			for(i=0; i<4; i++)
				for(j=0; j<4; j++)
					(j == 3)?printf("%c\n",tetramino[i][j]):printf("%c ",tetramino[i][j]);
		}		
		else if(command=='q')
			exit(0);
	}	
	return 0;
}
