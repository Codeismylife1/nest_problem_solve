#include<bits/stdc++.h>
using namespace std;
int main ()
{
int i,j,b=1,a[10][10],n,m;
scanf("%d" ,&n);
for(i=1;i<=n;i++)
{for(j=1;j<=n;j++)
{ a[i][j]=(i*n)-(j-1);
}}


for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("%3d " ,a[i][j]); }
printf("\n"); }

return 0;
} 
