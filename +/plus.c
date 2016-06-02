#include <stdio.h>
int main(void)
{
	char a[10]={0};
	char a1[10]={0};
	char b[10]={0};
	char b1[10]={0};
	char c[11]={0};

	printf("첫 숫자 : ");
	scanf("%s", a);
	printf("두 번째 : ");
	scanf("%s", b);

	for(int i=9, j=9;i>=0;i--)
	{
		if(a[i]==0)
			a1[i]=a[i];
		if(a[i]!=0)
			a1[j--]=a[i];
	}

	for(int i=9, j=9;i>=0;i--)
	{
		if(b[i]==0)
			b1[i]=b[i];
		if(b[i]!=0)
			b1[j--]=b[i];
	}

	for(int i=0;i<10;i++)
	{
		if(a1[i]==0)
			continue;
		a1[i]-='0';
	}

	for(int i=0;i<10;i++)
	{
		if(b1[i]==0)
			continue;
		b1[i]-='0';
	}

	for(int i=0;i<10;i++)
		printf("%d a : %d b : %d \n", i, a1[i],b1[i]);

	for(int i=0;i<10;i++)
	{
		
		c[10-i]+=a1[9-i]+b1[9-i];
		if(c[10-i]>=10)
		{
			c[9-i]+=1;
			if(c[10-i]>10)
				c[10-i]-=10;
		}
	}

	for(int i=0;i<11;i++)
	{
		if(c[i]==0)
			continue;
		if(c[i]==10)
			printf("0");
		else
			printf("%c", c[i]+'0');
	}
}
