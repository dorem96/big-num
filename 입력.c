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
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') //부호
		{
			a[++p][0] = str[i];
			p++;
			q=0;
		}
		else if ((('A' <= str[i]) && (str[i]<= 'Z')) || (('a' <= str[i]) && (str[i] <= 'z'))) //변수
		{
			b[k][0] = str[i];
			k++;
		}

		else //숫자
		{
			a[p][q] = str[i];
			q++;
		}
	}
	return 0;
}
