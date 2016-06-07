#include <stdio.h> 
char str[10000]={0}; 
char a[1000][60] = {0}; 
char c[60] = {0};
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
		x = 49;
		if(p%2 == 0 || p == 0) 
		{ 
			char b[60] = {0}; 

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

char minus(char a1[], char b1[])
{
	int blank1, blank2;

	for(int j = 0 ; j < 60 ; j++)
	{
		a1[j] -= '0';
		b1[j] -= '0';
	}

	for (int j = 0 ; j < 60 ; j++)
	{
		if(a1[j] > b1[j])
		{
			for(int j = 59 ; j >= 0; j--)
			{
				c[j] = a1[j] - b1[j];
				if(c[j] < 0)
				{
					c[j] += 10;
					if(j-1 == 50)
					{
						j-=1;
					}
					a1[j-1] -= 1;
				}
				if(j == 50)
				{
					c[j] = '.'-'0';
				}
			}
			break;
		}
		else if(a1[j] < b1[j])
		{
			for(int j = 59 ; j >= 0 ; j--)
			{
				c[j] = b1[j] - a1[j];
				if(c[j] < 0)
				{
					c[j] += 10;
					if((j-1) == 50)
					{
						j -= 1;
					}
					b1[j-1] -= 1;
				}
				if(j == 50)
				{
					c[j] = '.' - '0';
				}
			}
			break;
		}
	}

}
int main(){
	input();
	if(a[1][0] == '-')
		minus(a[0],a[2]);
	for(int i = 0 ; i < 60 ; i++)
		printf("%c",c[i]+'0');
}
