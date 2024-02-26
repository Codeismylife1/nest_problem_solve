#include <iostream>
using namespace std;
int main(){
	int n, m, x = 0;
	cin>>n>>m;
	while(n != m)
		{
			if(m > n){
				if(m % 2 == 0)
					{
							m = m / 2;
							x++;
						}
						else
						{
							m++;
							x++;
						}
}						
					else if (n > m){
						m++;
						 x++;
					}
					}
					cout<< x << endl;
					return 0;
}
