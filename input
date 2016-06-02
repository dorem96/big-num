#include <stdio.h>
int main()
{
  char str[10000];
  char a[1000][1000];
  int i=0, j=0, p=0, q;
  
  scanf("%s", str);
  
  for(;i < 10000;i++)
  {
    if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
    {
      a[++p][0] = str[i];
      p++;
      q=0;
    }
    else
    {
      a[p][q] = str[i];
      q++;
    }
  }
  
  return 0;
}
