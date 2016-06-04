#include <stdio.h>
int main()
{
	char str[10000]={0};
	char a[1000][60] = {0};
	char b[10][61] ={0};
	int i=0, j=0, p=0, q, k=0;

	scanf("%s", str);

	//식 입력받기
	for(;i < 10000;i++)
	{
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') //부호를 입력했을 때
		{
			a[++p][0] = str[i];
			p++;
			q=0;
		}
		else if ((('A' <= str[i]) && (str[i]<= 'Z')) || (('a' <= str[i]) && (str[i] <= 'z'))) //변수를 입력했을 때
		{
 22             	if((str[i] == 'c')&&(str[i+1] == 'l')&&(str[i+2] == 'e')&&(str[i+3] == 'a')&&(str[i+4] == 'r'))
 23     		{
 24                 		//clear 실행
 25             	}
 26             	else if((str[i] == 's')&&(str[i+1] == 'a')&&(str[i+2] == 'v')&&(str[i+3] == 'e'))
 27             	{
 28                 		//save 실행
 29     		}
 30             	else if((str[i] == 'l')&&(str[i+1] == 'o')&&(str[i+2] == 'a')&&(str[i+3] == 'd'))
 31      		{
 32                 		//load 실행
 33             	}
 34             	else if((str[i] == 'e')&&(str[i+1] == 'n')&&(str[i+2] == 'd'))
 35             	{
 36             		 //end 실행
 37             	}
			else
			{
				b[k][0] = str[i];
				k++;
			}
		}

		else //숫자를 입력했을 때
		{
			a[p][q] = str[i];
			q++;
		}
	}
	return 0;
}
