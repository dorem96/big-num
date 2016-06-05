#include <stdio.h>
char str[10000]={0};
char a[1000][60] = {0};
char b[10][61] ={0};
int plus(char a[], char b[])
{
	char c[61]={0};


	for(int i=0;i<60;i++)
		a[i]-='0';

	for(int i=0;i<60;i++)
		b[i]-='0';


	for(int i=0;i<60;i++)
	{
		if((59-i)==50)	
		{
			c[60-i]='.'-'0';
			continue;
		}
		else if((59-i)==51)
		{
			c[60-i]+=a[59-i]+b[59-i];
			if(c[60-i]>=10)
			{
				c[58-i]+=1;
				if(c[60-i]>10)
					c[60-i]-=10;
			}
		}
		else
		{
			c[60-i]+=a[59-i]+b[59-i];
			if(c[60-i]>=10)
			{
				c[59-i]+=1;
				if(c[60-i]>10)
					c[60-i]-=10;
			}
		}
	}

	for(int i=0;i<61;i++)
	{
		if(c[i]==10)
			printf("0");
		else
			printf("%c", c[i]+'0');
	}
}
int rearr(char a[])
{
	char k[60]={};
	int d, dot;


	for(int i=0;i<60;i++)
	{
		if(a[58-i]!=0)
		{
			dot=59-i;
			break;
		}
		for(int i=0;i<60;i++)
		{
			if(a[i]=='.')
			{
				dot=i;
				break;
			}
		}
		d=dot;
		k[50]='.';
		for(int j=49;j>=0;j--)
		{
			k[j]=a[--dot];
			if(dot==0)
				break;
		}
		dot=d;
		for(int j=51;j<60;j++)
		{
			k[j]=a[++dot];
			if(a[dot+1]==0)
				break;
		}
		for(int j=0;j<60;j++)
			a[j]=k[j];
		
	}

}
void input()
{
	int i=0, j=0, p=0, q, k=0;

	printf("식을 입력하세여 ");
	scanf("%s", str);

	//식 입력받기
	for(;i < 10000;i++)
	{
		if(str[i]==0)
			break;
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') //부호를 입력했을 때
		{
			a[++p][0] = str[i];
			p++;
			q=0;
		}
		else if ((('A' <= str[i]) && (str[i]<= 'Z')) || (('a' <= str[i]) && (str[i] <= 'z'))) //변수를 앱력했을 때
		{
			if((str[i] == 'c')&&(str[i+1] == 'l')&&(str[i+2] == 'e')&&(str[i+3] == 'a')&&(str[i+4] == 'r'))
			{
				//clear 실행
			}
			else if((str[i] == 's')&&(str[i+1] == 'a')&&(str[i+2] == 'v')&&(str[i+3] == 'e'))
			{
				//save 실행
			}
			else if((str[i] == 'l')&&(str[i+1] == 'o')&&(str[i+2] == 'a')&&(str[i+3] == 'd'))
			{
				//load 실행
			}
			else if((str[i] == 'e')&&(str[i+1] == 'n')&&(str[i+2] == 'd'))
			{
				//end 실행
			}
			else
			{
				b[k][0] = str[i];
				k++;
			}
		}
		else if((str[i] == '.')||  ((str[i] >= '0')&&(str[i] <= '9')))//숫자를 입력했을 때
		{
			a[p][q] = str[i];
			q++;
		}
		else 
		{
			printf(" = error");
		}
	}
}

int main()
{
	input();

	for(int i=0;i<100;i++)
		rearr(a[2*i]);

	for(int i=0;i<100;i++)
		if(a[i][0]=='+')
			plus(a[i-1],a[i+1]);
}
