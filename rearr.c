#include <stdio.h>
int main()
{
	char a[3][60]={};
	char k[61]={};
	int d=0, dot=0;;
	_Bool t;

	k[50]='.';

	for(int i=0;i<3;i++)
		scanf("%s", a[i]);

	for(int i=0;i<3;i++)
	{
		t=0;
		for(d=0;d<60;d++)
			if(a[i][d]=='.')
			{
				dot=d;
				t=1;
			}

		if(t==0)
		{
			for(int j=59;j


	/*	for(int j=60;j>=0;i--)
		{
			if(a[i][j-1]!=0)
			{
				dot=j;
				break;
			}
		}


		for(int j=0;j<60;j++)
		{
			if(a[i][j]=='.')
			{
				dot=j;
				break;
			}
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
			if((a[i][dot+1]==0)||(dot==60))
				break;
		}
		for(int j=0;j<60;j++)
			a[i][j]=k[j];
		
		for(int j=0;j<60;j++)
			printf("%c", a[0][j]);
		printf("\n");
	}


}

