#include <stdio.h> 
char str[10000]={}; 
char a[1000][61] = {}; 
char c[61] = {};
void input()
{

	int i = 0, p = 0, q = 1, x = 49; 

	scanf("%s", str); 

	for(;i < 10000;i++) 
	{ 
		if(str[i]==' ')
			continue;
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') 
		{ 
			if((str[i]=='-')&&(str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '*' || str[i-1] == '/' || i==0)) 
				a[p][0]='-';
			else
			{
				a[++p][0] = str[i]; 
				p++; 
			}
			q = 1; 
		} 
		else 
		{ 
			a[p][q] = str[i]; 
			q++; 
		} 
	} 

	for(p = 0;p < 1000;p++) 
	{ 
		x = 50;
		if(p%2 == 0 || p == 0) 
		{ 
			char b[61] = {}; 

			for(q = 1;q < 61;q++) 
			{ 
				if(a[p][q] == '.') 
				{ 
					b[51] = '.'; 

					for(int r = q-1, x = 50;r >= 0;r--) 
					{ 
						b[x] = a[p][r]; 
						x--; 
					} 
					for(int s = q+1, x = 52;a[p][s] != 0;s++) 
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
						if(a[p][61-q] != 0) 
						{ 
							b[x] = a[p][61-q]; 
							b[51] = '.';
							x--; 
							break; 
						} 
						else 
							break; 
					} 
				} 
			} 
			for(int m = 1;m < 61;m++) 
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
	for(int i=1;i<61;i++)
		a1[i]-='0';

	for(int i=1;i<61;i++)
		b1[i]-='0';

	for(int i=1;i<61;i++)
	{
		if((61-i)==51)	
		{
			c[61-i]='.'-'0';
			continue;
		}
		else if((61-i)==52)
		{
			c[61-i]+=a1[61-i]+b1[61-i];
			if(c[61-i]>=10)
			{
				c[59-i]+=1;
				c[61-i]-=10;
			}
		}
		else
		{
			c[61-i]+=a1[61-i]+b1[61-i];
			if(c[61-i]>=10)
			{
				c[60-i]+=1;
				c[61-i]-=10;
			}
		}
	}

}

void minus(char a1[], char b1[])
{
	int blank1, blank2;

	for(int j = 1 ; j < 61 ; j++)
	{
		a1[j] -= '0';
		b1[j] -= '0';
	}

	for (int j = 1 ; j < 61 ; j++)
	{
		if(a1[j] > b1[j])
		{
			for(int j = 60 ; j >= 1; j--)
			{
				c[j] = a1[j] - b1[j];
				if(c[j] < 0)
				{
					c[j] += 10;
					if(j-1 == 51)
						j-=1;
					a1[j-1] -= 1;
				}
				if(j == 51)
					c[j] = '.'-'0';
			}
			break;
		}
		else if(a1[j] < b1[j])
		{
			c[0]='-';
			for(int j = 60 ; j >= 1 ; j--)
			{
				c[j] = b1[j] - a1[j];
				if(c[j] < 0)
				{
					c[j] += 10;
					if((j-1) == 51)
						j -= 1;
					b1[j-1] -= 1;
				}
				if(j == 51)
					c[j] = '.' - '0';
			}
			break;
		}
		else
			c[51]='.'-'0';
	}
}



int main()
{
	input();
	for(int k=0;k<100;k++)
	{
		if(a[k][0]=='-')
			minus(a[k-1],a[k+1]);
		if(a[k][0]=='+')
			plus(a[k-1],a[k+1]);
	}
	for(int i = 0 ; i < 61 ; i++)
	{
		if(i==0)
		{
			printf("%c",c[i]);
			continue;
		}
		printf("%c",c[i]+'0');
	}
}
