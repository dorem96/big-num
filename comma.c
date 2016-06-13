#include <stdio.h>
int main()
{
	char str[10000];
	char a[1000][60];
	int i;

	scanf("%s", str);

	for(i = 0 ; i < 60 ; i++)
	{
		if(str[i] == '.')
		{
			printf("%c", str[0]);

			for(int n = 1 ; n < i ; n++)
			{
				int g= i % 3;
				if(n % 3 == g)
				{
					printf(",");
					printf("%c", str[n]);
				}
				else
				{
					printf("%c", str[n]);
				}
			}

			printf("%c", str[i]);

			printf("%c", str[i+1]);
			for(int m = i + 2 ; str[m] >= '0' && str[m] <= '9' ; m++)
			{
				if((m-i-1) % 3 == 0)
				{
					printf(",");
					printf("%c", str[m]);
				}
				else
				{
					printf("%c", str[m]);
				}
			}
			break;
		}

		else if(str[i] != 0)
			continue;

		else
		{
			printf("%c", str[0]);

			for(int l = 1 ; l < i ; l++)
			{
				int g = i % 3;
				if(l % 3 == g)
				{
					printf(",");
					printf("%c", str[l]);
				}
				else
					printf("%c", str[l]);
			}
			break;
		}
	}

	return 0;
}
