#include <stdio.h>
int main()
{
	char a[3][60]={};
	char k[60]=};
	int d, dot;

	for(int i=0;i<3;i++)
		scanf("%s", a[i]);

	for(int i=0;i<3;i++)
	{
		for(dot=0;dot<60;dot++)
		{
			if(a[i][dot]=='.')
				break;
		}
		d=dot;
		k[50]='.';
		for(int j=49;j>=0;j--)
		{
			k[j]=a[i][--dot];
			if(dot==0)
				break;
		}
		dot=d;
		for(int j=51;j<60;j++)
		{
			k[j]=a[i][++dot];
			if(a[i][dot+1]==0)
				break;
		}
		for(int j=0;j<60;j++)
			a[i][j]=k[j];
	}


}

