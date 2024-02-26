#include<stdio.h>
#include<math.h>
main()
{
int i,n,j,t,a[100][100];
scanf("%d",&n); t=1;
for (i=n-1;i>=0;i--) {
for(j=n-1; j>=0 ;j--) {a[i][j]=t; t++;}}

for(i=0; i<n; i++) {
for(j=0; j<n ;j++) printf("%3d",a[i][j]);
printf("\n");
}
}
