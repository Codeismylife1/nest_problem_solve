#include <iostream>

using namespace std;

int main()
{
int n, s ;
cin >> n ;
s=n*n;
int a[100][100] ;
for(int i=1; i<=n ; i++){
for (int j=1 ; j<=n; j++){
a[i][j]=s;
s--;
}
}
for(int i=1; i<=n ; i++){
for (int j=1 ; j<=n; j++){
if (i%2==0){

if (a[i][n-j+1]<10){
cout << " "<< a[i][n-j+1];
}
else {
cout << " "<< a[i][n-j+1];
}
}
else {
if (a[i][j]<10)
cout << " "<< a[i][j];
else
cout << " "<< a[i][j];
}
}
cout << endl;
}
return 0;
}

