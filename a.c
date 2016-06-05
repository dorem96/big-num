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
		else if(str[i] == '.' || str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9' || str[i] == '0')//숫자를 입력했을 때
		{
			a[p][q] = str[i];
			q++;
		}
		else 
		{
			printf(" = error");
		}
	}
	return 0;
}

