#include <stdio.h>
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
	for(int i=1;i<61;i++)
		a1[i]+='0';
	for(int i=1;i<61;i++)
		b1[i]=c[i]+'0';
}

void reminder(char a1[], char b1[])
{
	char k[61]={};
	int t=0, y=0;

	while(1)
	{
		for(int i=0;i<61;i++)
		{
			for(int j=0;j<61;j++)
				k[j]=b1[j];
			if(a1[i]>b1[i]||((i==61)&&(a1[i]==b1[i])))
			{
				minus(a1,b1);
				for(int j=0;j<61;j++)
					a1[j]=b1[j];
				for(int j=0;j<61;j++)
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
			for(int i=0;i<61;i++)
				b1[i]=a1[i];
			break;
		}
	}
}





int main()
{
	char a[61]={};
	char b[61]={};

	for(int i=0;i<61;i++)
	{
		a[i]='0';
		b[i]='0';
	}
	a[51]=b[51]='.';
	a[50]='3';
	a[49]='2';
	a[52]='0';
	b[50]='3';
	b[52]='2';

	for(int i=0;i<61;i++)
		printf("%c",a[i]);
	printf("\n");
	for(int i=0;i<61;i++)
		printf("%c",b[i]);
	printf("\n");
	reminder(a,b);
	for(int i=0;i<61;i++)
		printf("%c", b[i]);
}
