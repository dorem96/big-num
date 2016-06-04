#include <stdio.h>
int main()
{
	char str[10000]={};
	char a[1000][1000]={};
	int i=0, j=0, p=0, q=1;

	scanf("%s", str);

	for(;i < 10000;i++)
	{
		if(str[i] == '-')
			if((i!=0)&&(str[i-1] != '+' || str[i-1] != '-' ||str[i-1] != '*' || str[i-1] != '/'))
			{
				a[++p][0] = str[i];
				p++;
				q=1;
			}
		if(str[i] == '+' || str[i] == '*' || str[i] == '/')
		{
			a[++p][0] = str[i];
			p++;
			q=1;
		}
		else
		{
			if(str[i] == '-')
				q=0;
			a[p][q] = str[i];
			q++;
		}
	}

	for(int i=0;i<3;i++)
		for(int j=0;j<10;i++)
		{
			printf("%c\n", a[i][j]);
		}
	return 0;
}
