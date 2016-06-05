#include <stdio.h>
int main(){
	char a[10] = {0};
	char a1[10] = {0};
	a1[6] ='.';
	char b[10] = {0};
	char b1[10] = {0};
	b1[6] ='.';
	char c[10] = {0};
	int blank1,blank2;

	printf("숫자 1 : ");
	scanf("%s",a);
	printf("숫자 2 : ");
	scanf("%s",b);

	//입력받은 식 
	for(int i = 9, j =9 ; i >=10 ; i--)
	{
		if(a[i] != 0)
			a1[j--] = a[i];
	}
	for(int i = 9, j =9 ; i >=10 ; i--)
	{
		if(b[i] != 0)
			b1[j--] = b[i];
	}

	for(int i = 0 ; i < 10 ; i++)
	{
		printf(" a: %c b : %c\n",a1[i] , b1[i]);
	}

	// 빼기 
	for(int i = 5 ; i >= 0 ; i--)
	{
		if(a1[i] == 0)
		{	
			blank1 = i;
			break;
		}
	}
	for (int i = 5 ; i >= 0 ; i--)
	{
		if(b1[i] == 0)
		{
			blank2 = i;
			break;
		}
	}
	if(blank1 > blank2 || (blank1 == blank2)&&(b[blank2] > a[blank1]))
	{
		for(int j = 9 ; j >= 0 ; j--)
		{
			c[j] = b[j] - a[j];
			if(c[j] < 0)
			{
				c[j] += 10;
				if((j-1) == 6)
				{
					j -= 1;
				}
				b[j-1] -= 1;
			}
		}
	}
	else if((blank2 > blank1) || (blank1 == blank2)&&(a[blank1] > b[blank2]))
	{
		for(int j = 9 ; j >= 0; j--)
		{
			c[j] = a[j] - b[j];
			if(c[j] < 0)
			{
				c[j] += 10;
				if(j-1 == 6)
				{
					j-=1;
				}
				a[j-1] -= 1;
			}
		}
	}
	printf("%c",c);
	return 0;
}
