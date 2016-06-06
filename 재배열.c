#include <stdio.h>
int main()
{
  char str[10000];
  char a[1000][60] = {0};
  char b[60] = {0};
  
  int i = 0, p = 0, q = 0, x = 49;
  
  scanf("%s", str);
  
  for(;i < 10000;i++)
  {
    if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
    {
      a[++p][0] = str[i];
      p++;
      q = 0;
    }
    else
    {
      a[p][q] = str[i];
      q++;
    }
  }
  
  for(p = 0;p < 1000;p++)
  {
    if(p%2 == 0 && p == 0)
    {
      for(q = 0;q < 60;q++)
      {
        if(a[p][q] == '.')
        {
          b[50] = '.';
          
          for(int r = q-1, x = 49;r >= 0;r--)
          {
            b[x] = a[p][r];
            x--;
          }
          for(int s = q+1, x = 51;a[p][s] != 0;s++)
          {
            b[x] = a[p][s];
            x++;
          }
          break;
        }
        else
        {
          while(x >= 0)
          {
            if(a[p][59-q] != 0)
            {
              b[x] = a[p][59-q];
              x--;
              break;
            }
            else
              break;
          }
        }
      }
    }
    else
      continue;
  }
  
  return 0;
}
