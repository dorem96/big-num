#include <stdio.h>
int main(){
    char a[62]={0};
    char a1[62]={0};
    char b[62]={0};
    char b1[62]={0};
    char c[62]={0};
    char op[4]={'+', '-', '*', '/'};
    printf("첫 숫자: ");
    scanf("%s", a);
    printf("부호: ");
    scanf("%c", &op);
    printf("두 번째: ");
    scanf("%s", b);
    if(op=='+'&&b[0]=='-'){ //op로만 계산하는 것
        op='-'; b[0]='+';}
    else if(op=='-'&&b[0]=='-'){
        op='+'; b[0]='+';}
    if(op=='*'||op=='/'&&a[0]=='+'&&b[0]=='-'){
        c[0]='-';} //해의 부호가 -
    else if(op=='*'||op=='/'&&a[0]=='-'&&b[0]=='+'){
        c[0]='-';} //해의 부호가 -
    else if(op=='*'||op=='/'&&a[0]=='-'&&b[0]=='-'){
        c[0]='+';} //해의 부호가 +
    return 0;
}
