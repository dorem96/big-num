#include <stdio.h>
int main()
{
	char a[3][60]={};
	char k[3][60]={};
	int d, dot, x, y;

	for(int i=0;i<3;i++)
	{
		scanf("%s", a[i]);
	}

	for(int i=0;i<3;i++)
	{
		x = 0;
		y = 0;

		for(dot=0;dot<60;dot++)
		{
			if(a[i][dot] == '.')
			{
				x = 1;
				break;
			}
			else if((a[i][dot] != '.') && (a[i][dot] != 0))
			{
				y++;
			}
			if(x == 1)
			{
				d=dot;
				k[i][50]='.';
				for(int j=49;j>=0;j--)
				{
					k[i][j]=a[i][--dot];
					if(dot==0)
						break;
				}

				dot=d;
				for(int j=51;j<60;j++)
				{
					k[i][j]=a[i][++dot];
					if(a[i][dot+1]==0)
						break;
				}

				for(int j=0;j<60;j++)
				{
					a[i][j]=k[i][j];
				}
			}
			else 
			{
				for(int j = 49 ; j >= 0 ; j--)
				{
					k[i][j] = a[i][--y];
					if(y == 0)
						break;
				}

				for(int j = 0 ; j < 60 ;j++)
				{
					a[i][j] =k[i][j];	
				}
			}
		}
		for(int m = 0 ; m < 60 ; m++)
		{
			printf("%c", k[i][m]);
		}
		printf("\n");
	}
	return 0;
}
