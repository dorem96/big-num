char choice(void)
{
  if(p % 2 != 0)
  {
    for(int p = 0 ; p < 1000 ; p++)
    {
      switch(a[p][0])
      {
        case '*' : multiply(a[p-1], a[p+1]);
                   break;
        case '/' : divide(a[p-1], a[p+1]);
                   break;
        case '%' : extra(a[p-1], a[p+1]);
                   break;
        default : break;
      }
    }
    
    for(int p = 0 ; p < 1000 ; p++)
    {
      switch(a[p][0])
      {
        case '+' : plus(a[p-1], b[p+1]);
                   break;
        case '-' : minus(a[p-1], b[p+1]);
                   break;
        default : break;
      }
    }
  }
}
