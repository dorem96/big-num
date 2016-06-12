#include <stdio.h> 
char str[10000]={}; 
char a[1000][61] = {}; 
char waste[61]={};
void input()
{

	int i = 0, p = 0, q = 1, x = 49; 

	gets(str); 

	for(;i < 10000;i++) 
	{ 
		if(str[i]==' ')
			continue;
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%') 
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
	char c[61]={};
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
	for(int i=1;i<61;i++)
		a1[i]+='0';
	for(int i=1;i<61;i++)
		b1[i]=c[i]+'0';

}

void minus(char a1[], char b1[])
{
	int blank1, blank2;
	char c[61]={};
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
			c[0]='-'-'0';
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
	for(int i=1;i<61;i++)
		a1[i]+='0';
	for(int i=0;i<61;i++)
		b1[i]=c[i]+'0';
}
char multi(char a2[], char b2[])
{
	char k[61]={};
	int t=51, q;
	for(int i=60;i>51;i--)
		if(a2[i]!='0')
		{
			t=i+1;
			break;
		}
	for(int i=1;i<61;i++)
		if((a2[i]!='0')&&(a2[i]!='.'))
		{
			q=i;
			break;
		}
	printf("%d %d\n", q, t);
	for(int i=1;i<61;i++)
		k[i]=b2[i];
	for(int i=q;i<t;i++)
	{
		int p=a2[i]-'0';
		if(i==51)
		{
			if(t==52)
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
		for(int j=1;j<60;j++)
		{
			if(j==50)
				b2[j]=b2[j+2];
			else if(j==51)
				continue;
			else
				b2[j]=b2[j+1];
		}
		b2[60]='0';
	}
	if(t>51)
	{
		q=t-52;
		for(int j=60;j>=1;j--)
		{
			if((j-q)>51)
				b2[j]=b2[j-q];
			else if((j>51)&&((j-q)<=51))
				b2[j]=b2[j-q-1];
			else if(j==51)
				continue;
			else if(j<51)
				b2[j]=b2[j-q];
		}
		for(int i=1;i<t-52;i++)
			b2[i]='0';
	}

}



void reminder(char a1[], char b1[], char c1[], int z)
{
	char k[61]={};
	int t=0, y=0;
	char r[61]={};
	for(int j=0;j<61;j++)
		k[j]=b1[j];

	for(int i=0;i<61;i++)
		r[i]='0';
	r[51]='.';
	r[50]='1';

	while(1)
	{
		for(int i=1;i<61;i++)
		{
			if(a1[i]>b1[i]||((i==60)&&(a1[i]==b1[i])))
			{
				minus(a1,b1);
				plus(r, c1);
				for(int j=1;j<61;j++)
					a1[j]=b1[j];
				for(int j=1;j<61;j++)
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
			for(int i=1;i<61;i++)
				b1[i]=a1[i];
			break;
		}
	}
}

void divide(char a1[], char b1[])
{
	char quo[10][61]={};
	char c[61]={};
	for(int j=0;j<10;j++)
	{
		for(int i=0;i<61;i++)
			quo[j][i]='0';
		quo[j][51]='.';
	}
	for(int i=0;i<61;i++)
		c[i]='0';
	c[51]='.';

	for(int i=0;i<10;i++)
	{
		reminder(a1, b1, quo[i], 1);
		for(int j=0;j<61;j++)
		{
			if(j==51)
				continue;
			else if(j==50)
				a1[j]=a1[j+2];
			else
			a1[j]=a1[j+1];
		}
		a1[60]='0';
	}
	for(int i=0;i<10;i++)
	{
		for(int j=61;j>=0;j--)
		{
			if(j>51+i)
			quo[i][j]=quo[i][j-i];
			else if((j>51)&&(j<=51+i))
				quo[i][j]=quo[i][j-i-1];
			else if(j==51)
				continue;
			else if((j<51)&&(j>=i))
				quo[i][j]=quo[i][j-i];
			else if(j<i)
				quo[i][j]='0';
		}
		plus(quo[i], c);
	}
	for(int i=0;i<61;i++)
		b1[i]=c[i];

}

int main()
{
	input();	

	for(int k=0;k<100;k++)
	{
		if(a[k][0]=='+')
			plus(a[k-1],a[k+1]);
		else if(a[k][0]=='-')
			minus(a[k-1],a[k+1]);
		else if(a[k][0]=='*')
			multi(a[k-1],a[k+1]);
		else if(a[k][0]=='%')
			reminder(a[k-1],a[k+1], waste, 0);
		else if(a[k][0]=='/')
			divide(a[k-1],a[k+1]);
	}
	for(int i = 0 ; i < 61 ; i++)
		printf("%c",a[2][i]); 
}
