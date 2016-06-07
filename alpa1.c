#include <stdio.h>
char str[10000];
char a[1000][60] = {0};
char c[61];
void input()
{

	int i = 0, p = 0, q = 0, x = 49;

	scanf("%s", str);

	for(;i < 10000;i++)
	{
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			a[++p][0] = str[i];
			p++;
			q = 0;
		}
		else
		{
			a[p][q] = str[i];
			q++;
		}
	}

	for(p = 0;p < 1000;p++)
	{
		x=49;
		if(p%2 == 0 || p == 0)
		{
			char b[60] = {};

			for(q = 0;q < 60;q++)
			{
				if(a[p][q] == '.')
				{
					b[50] = '.';

					for(int r = q-1, x = 49;r >= 0;r--)
					{
						b[x] = a[p][r];
						x--;
					}
					for(int s = q+1, x = 51;a[p][s] != 0;s++)
					{
						b[x] = a[p][s];
						x++;
					}
					break;
				}
				else
				{
					while(x >= 0)
					{
						if(a[p][59-q] != 0)
						{
							b[x] = a[p][59-q];
							x--;
							break;
						}
						else
							break;
					}
				}
			}
			for(int m = 0;m < 60;m++)
			{
				a[p][m] = b[m];
				if(b[m]==0)
					a[p][m]='0';
			}
		}
		else
			continue;
	}
}

char plus(char a1[], char b1[])
{
	for(int i=0;i<60;i++)
		a1[i]-='0';

	for(int i=0;i<60;i++)
		b1[i]-='0';

	for(int i=0;i<60;i++)
	{
		if((59-i)==50)	
		{
			c[60-i]='.'-'0';
			continue;
		}
		else if((59-i)==51)
		{
			c[60-i]+=a1[59-i]+b1[59-i];
			if(c[60-i]>=10)
			{
				c[58-i]+=1;
				if(c[60-i]>10)
					c[60-i]-=10;
			}
		}
		else
		{
			c[60-i]+=a1[59-i]+b1[59-i];
			if(c[60-i]>=10)
			{
				c[59-i]+=1;
				if(c[60-i]>10)
					c[60-i]-=10;
			}
		}
	}

}

int main()
{
	input();
	if(a[1][0]=='+')
		plus(a[0],a[2]);
	for(int i=0;i<61;i++)
	  printf("%c",c[i]+'0');
}

