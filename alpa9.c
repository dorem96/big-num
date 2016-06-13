#include <stdio.h> 
void cal(char, int);
char str[10000]={}; 
char a[1000][62] = {}; 
char waste[62]={};
int g=0, n=0;
int first=0, second=0;
char iv[2]={};
char v[10][64]={};
char vn=0;

void input()
{

	int c = 0, i = 0, p = 0, q = 1, x = 49; 
	iv[0]=0;
	iv[1]=0;

	gets(str); 

	for(;i < 10000;i++) 
	{ 
		if(str[i]==' ')
			continue;
		if(((str[i]>='a')&&(str[i]<='z'))||(str[i]=='='))
		{
			iv[c]=str[i];
			c++;
		}
		else if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') 
		{ 
			if((str[i]=='-')&&(str[i-1] == '+' || str[i-1] == '-' || str[i-1] == '*' || str[i-1] == '/' || p==0)) 
				a[p][0]='-';
			else
			{
				a[++p][0] = str[i]; 
				p++; 
				if(str[i] == '+' || str[i] == '-' )
					second++;
				if(str[i] == '*' || str[i] == '/' || str[i] == '%') 
					first++;
			}
			q = 2; 
		} 
		else 
		{ 
			a[p][q] = str[i]; 
			q++; 
		} 
	} 
	g=p+1;
	for(p = 0;p < 1000;p++) 
	{ 
		x = 51;
		if(p%2 == 0 || p == 0) 
		{ 
			char b[62] = {}; 

			for(q = 2;q < 62;q++) 
			{ 
				if(a[p][q] == '.') 
				{ 
					b[52] = '.'; 

					for(int r = q-1, x = 51;r >= 0;r--) 
					{ 
						b[x] = a[p][r]; 
						x--; 
					} 
					for(int s = q+1, x = 53;a[p][s] != 0;s++) 
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
						if(a[p][62-q] != 0) 
						{ 
							b[x] = a[p][62-q]; 
							b[52] = '.';
							x--; 
							break; 
						} 
						else 
							break; 
					} 
				} 
			} 
			for(int m = 2;m < 62;m++) 
			{
				a[p][m] = b[m];
				if(b[m]==0)
					a[p][m]='0';
				if(b[m]=='-')
					a[p][m]='0';
			}	   
			a[p][1]='0';
		} 
		else 
			continue; 
	}
}

char plus(char a1[], char b1[])
{
	char c[62]={};
	for(int i=1;i<62;i++)
		a1[i]-='0';

	for(int i=1;i<62;i++)
		b1[i]-='0';

	for(int i=1;i<62;i++)
	{
		if((62-i)==52)	
		{
			c[62-i]='.'-'0';
			continue;
		}
		else if((62-i)==53)
		{
			c[62-i]+=a1[62-i]+b1[62-i];
			if(c[62-i]>=10)
			{
				c[60-i]+=1;
				c[62-i]-=10;
			}
		}
		else
		{
			c[62-i]+=a1[62-i]+b1[62-i];
			if(c[62-i]>=10)
			{
				c[61-i]+=1;
				c[62-i]-=10;
			}
		}
	}
	for(int i=1;i<62;i++)
		a1[i]+='0';
	for(int i=1;i<62;i++)
		b1[i]=c[i]+'0';

}

void minus(char a1[], char b1[])
{
	int blank1, blank2;
	char c[62]={};
	for(int j = 1 ; j < 62 ; j++)
	{
		a1[j] -= '0';
		b1[j] -= '0';
	}

	for (int j = 1 ; j < 62 ; j++)
	{
		if(a1[j] > b1[j])
		{
			for(int j = 61 ; j >= 1; j--)
			{
				c[j] = a1[j] - b1[j];
				if(c[j] < 0)
				{
					c[j] += 10;
					if(j-1 == 52)
						j-=1;
					a1[j-1] -= 1;
				}
				if(j == 52)
					c[j] = '.'-'0';
			}
			break;
		}
		else if(a1[j] < b1[j])
		{
			c[0]='-'-'0';
			for(int j = 61 ; j >= 1 ; j--)
			{
				c[j] = b1[j] - a1[j];
				if(c[j] < 0)
				{
					c[j] += 10;
					if((j-1) == 52)
						j -= 1;
					b1[j-1] -= 1;
				}
				if(j == 52)
					c[j] = '.' - '0';
			}
			break;
		}
		else
			c[52]='.'-'0';
	}
	for(int i=1;i<62;i++)
		a1[i]+='0';
	for(int i=0;i<62;i++)
		b1[i]=c[i]+'0';
}
char multi(char a2[], char b2[])
{
	char k[62]={};
	int t=52, q;
	for(int i=61;i>52;i--)
		if(a2[i]!='0')
		{
			t=i+1;
			break;
		}
	for(int i=1;i<62;i++)
		if((a2[i]!='0')&&(a2[i]!='.'))
		{
			q=i;
			break;
		}
	for(int i=1;i<62;i++)
		k[i]=b2[i];
	for(int i=q;i<t;i++)
	{
		int p=a2[i]-'0';
		if(i==52)
		{
			if(t==53)
				break;
			continue;
		}
		for(int j=0;j<p;j++)
		{
			if((i==q)&&(j==0))
				continue;
			plus(k,b2);
		}
		if(i==t-1)
			break;
		for(int j=1;j<61;j++)
		{
			if(j==51)
				b2[j]=b2[j+2];
			else if(j==52)
				continue;
			else
				b2[j]=b2[j+1];
		}
		b2[61]='0';
	}
	if(t>52)
	{
		q=t-53;
		for(int j=61;j>=1;j--)
		{
			if((j-q)>52)
				b2[j]=b2[j-q];
			else if((j>52)&&((j-q)<=52))
				b2[j]=b2[j-q-1];
			else if(j==52)
				continue;
			else if(j<52)
				b2[j]=b2[j-q];
		}
		for(int i=1;i<t-53;i++)
			b2[i]='0';
	}

}



void reminder(char a1[], char b1[], char c1[], int z)
{
	char k[62]={};
	int t=0, y=0;
	char r[62]={};
	for(int j=0;j<62;j++)
		k[j]=b1[j];

	for(int i=0;i<62;i++)
		r[i]='0';
	r[52]='.';
	r[51]='1';

	while(1)
	{
		for(int i=1;i<62;i++)
		{
			if(a1[i]>b1[i]||((i==61)&&(a1[i]==b1[i])))
			{
				minus(a1,b1);
				plus(r, c1);
				for(int j=1;j<62;j++)
					a1[j]=b1[j];
				for(int j=1;j<62;j++)
					b1[j]=k[j];
				break;
			}
			if(a1[i]<b1[i])
			{
				y=1;
				break;
			}
		}
		if(y!=0)
		{
			if(z==1)
				return;
			for(int i=1;i<62;i++)
				b1[i]=a1[i];
			break;
		}
	}
}

void divide(char a1[], char b1[])
{
	char quo[10][62]={};
	char c[62]={};
	for(int j=0;j<10;j++)
	{
		for(int i=0;i<62;i++)
			quo[j][i]='0';
		quo[j][52]='.';
	}
	for(int i=0;i<62;i++)
		c[i]='0';
	c[52]='.';

	for(int i=0;i<10;i++)
	{
		reminder(a1, b1, quo[i], 1);
		for(int j=0;j<62;j++)
		{
			if(j==52)
				continue;
			else if(j==51)
				a1[j]=a1[j+2];
			else
				a1[j]=a1[j+1];
		}
		a1[61]='0';
	}
	for(int i=0;i<10;i++)
	{
		for(int j=62;j>=0;j--)
		{
			if(j>52+i)
				quo[i][j]=quo[i][j-i];
			else if((j>52)&&(j<=52+i))
				quo[i][j]=quo[i][j-i-1];
			else if(j==52)
				continue;
			else if((j<52)&&(j>=i))
				quo[i][j]=quo[i][j-i];
			else if(j<i)
				quo[i][j]='0';
		}
		plus(quo[i], c);
	}
	for(int i=0;i<62;i++)
		b1[i]=c[i];

}

void arr(int h)
{
	for(int i=h;i<g-2;i++)
	{
		for(int j=0;j<62;j++)
			a[i][j]=a[i+2][j];
	}
	for(int i=g-2;i<g;i++)
		for(int j=0;j<62;j++)
			a[i][j]=0;
	g-=2;
}

void sv(char a1[1000][62], char b1[10][64], char c1[2])
{
	if(n>9)
		return;
	for(int i=0;i<2;i++)
		b1[n][i]=iv[i];
	for(int i=0;i<62;i++)
		b1[n][i+2]=a1[0][i];
	n++;
}

void lv(int u, char b1[10][64])
{
	for(int i=0;i<64;i++)
		printf("%c", b1[u][i]);
	printf("*\n");
}



int main()
{
	input();	
	cal(a, g);
	if(iv[0]==0)
	{
		for(int i=0;i<62;i++)
			printf("%c", a[0][i]);
		printf("\n");
	}

	
	else if(iv[0]!=0)
	{
		if(iv[1]=='=')
			sv(a, v, iv);
		else if(iv[1]!='=')
		{
			for(int i=0;i<10;i++)
				if(v[i][0]==iv[0])
					lv(i, v);
		}
	}

	for(int i=0;i<10000;i++)
		str[i]=0;
	for(int i=0;i<1000;i++)
		for(int j=0;j<62;j++)
			a[i][j] = 0; 
	g=0;
	first=0, second=0;

	main();
}



void cal(char a1, int g1)
{
	int m=0, k=0;
	char c;
	while(1)
	{
		for(k=1;k<g;k+=2)
		{
			if(a[k][0]=='*')
			{
				if(a[k-1][0]=='-')
				{
					if(a[k+1][0]!='-')
						c='-';
					if(a[k+1][0]=='-')
						c=0;
				}
				else if(a[k-1][0]!='-')
				{
					if(a[k+1][0]=='-')
						c='-';
					if(a[k+1][0]!='-')
						c=0;
				}
				multi(a[k-1],a[k+1]);
				a[k+1][0]=c;
				arr(k-1);
				first--;
				break;
			}
			else if(a[k][0]=='%')
			{
				if(a[k-1][0]=='-')
				{
					if(a[k+1][0]!='0')
						c='-';
					if(a[k+1][0]=='0')
						c=0;
				}
				else if(a[k-1][0]!='-')
				{
					if(a[k+1][0]=='-')
						c='-';
					if(a[k+1][0]!='-')
						c=0;
				}
				reminder(a[k-1],a[k+1], waste, 0);
				a[k+1][0]=c;
				arr(k-1);
				first--;
				break;
			}
			else if(a[k][0]=='/')
			{
				if(a[k-1][0]=='-')
				{
					if(a[k+1][0]!='0')
						c='-';
					if(a[k+1][0]=='0')
						c=0;
				}
				else if(a[k-1][0]!='-')
				{
					if(a[k+1][0]=='-')
						c='-';
					if(a[k+1][0]!='-')
						c=0;
				}
				divide(a[k-1],a[k+1]);
				a[k+1][0]=c;
				arr(k-1);
				first--;
				break;
			}
		}
		if(first==0)
			break;
	}

	while(1)
	{
		for(k=1;k<g;k+=2)
		{
			if(a[k][0]=='+')
			{
				if(a[k-1][0]=='-')
				{
					if(a[k+1][0]!='-')
					{
						a[k-1][0]=a[k+1][0]=0;
						minus(a[k-1],a[k+1]);
						if(a[k+1][0]=='-')
						{
							a[k+1][0]=0;
							arr(k-1);
							second--;
							break;
						}
						else if(a[k+1][0]!='-')
						{
							a[k+1][0]='-';
							arr(k-1);
							second--;
							break;
						}
					}
					if(a[k+1][0]=='-')
					{
						a[k-1][0]=a[k+1][0]=0;
						plus(a[k-1],a[k+1]);
						a[k+1][0]='-';
						arr(k-1);
						second--;
						break;
					}
				}
				else if(a[k-1][0]!='-')
				{
					if(a[k+1][0]=='-')
					{
						a[k-1][0]=a[k+1][0]=0;
						minus(a[k-1],a[k+1]);
						arr(k-1);
						second--;
						break;
					}
					if(a[k+1][0]!='-')
					{
						a[k-1][0]=a[k+1][0]=0;
						plus(a[k-1],a[k+1]);
						a[k+1][0]=0;
						arr(k-1);
						second--;
						break;
					}
				}
			}
			else if(a[k][0]=='-')
			{
				if(a[k-1][0]=='-')
				{
					if(a[k+1][0]=='-')
					{
						a[k-1][0]=a[k+1][0]=0;
						minus(a[k-1],a[k+1]);
						if(a[k+1][0]=='-')
						{
							a[k+1][0]=0;
							arr(k-1);
							second--;
							break;
						}
						else if(a[k+1][0]!='-')
						{
							a[k+1][0]='-';
							arr(k-1);
							second--;
							break;
						}
					}
					if(a[k+1][0]!='-')
					{
						a[k-1][0]=a[k+1][0]=0;
						plus(a[k-1],a[k+1]);
						a[k+1][0]='-';
						arr(k-1);
						second--;
						break;
					}
				}
				else if(a[k-1][0]!='-')
				{
					if(a[k+1][0]=='-')
					{
						a[k-1][0]=a[k+1][0]=0;
						plus(a[k-1],a[k+1]);
						arr(k-1);
						second--;
						break;
					}
					if(a[k+1][0]!='-')
					{
						a[k-1][0]=a[k+1][0]=0;
						minus(a[k-1],a[k+1]);
						arr(k-1);
						second--;
						break;
					}
				}
			}
		}
		if(second==0)
			break;
	}


}
