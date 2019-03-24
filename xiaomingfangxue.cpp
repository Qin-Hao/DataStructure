/*
	小明放学 
*/
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	int r, y, g;
	cin >> r >> y >> g;
	int num;
	cin >> num;
	
	int a[2 * num + 1];
	for (int i = 1; i <= num; ++i) {
		int num1, num2;
		cin >> num1 >> num2;
		a[2 * i - 1] = num1;
		a[2 * i] = num2;
	}
	
	long long result = 0;
	for (int j = 1; j < 2 * num; ++(++j)) {
		if (a[j] == 1) {
			if (a[j - 1] < a[j + 1]) {
				result += a[j + 1] - a[j -1];
			}
		} else if (a[j] == 2) {
			if(result < a[j + 1] + r) {
				result += a[j + 1] + r - result;
			}
		} else if (a[j] == 3) {
			if (a[j] < result) {
				if (result < a[j + 1] + y + r) {
					result += a[j + 1] + y + r - result;
				}
			}
		} else if (a[j] == 0) {
			result += a[j + 1];
		}
	}
	cout << result << endl;
	
	/*
	#include<iostream>
	using namespace std;
	int main()
	{
		long long res=0,t;
		int r,y,g,n,k;
		cin>>r>>y>>g>>n;
		while(n--)
		{
			cin>>k>>t;
			switch(k)
			{
				//平路的话直接加上花费的时间 
				case 0:{
					res+=t;
					break;
				}
				//红灯的话，从初始状态到当前状态所花费的时间是r-t，然后加上res，再对（r+g+y）取余。 
				case 1:{
					t=(r-t)+res;
					t%=(r+g+y);
					if(t<r)		//若持续时间小于红灯总时间，那么经过这个灯的时间就是红灯所剩的时间。 
						res+=(r-t);		 
					else if(t>=g+r)		//若持续时间大于红+绿总时间且小于黄灯总时间，即在黄灯状态下，就既要等黄灯还要等红灯。 
						res+=(r+r+g+y-t);		//r+g+y-t是当前黄灯所剩的时间。 
					break;
				}
				//黄灯的话，从初始状态到当前状态所花费的时间是r+g+y-t，然后加上res，再对（r+g+y）取余。 
				case 2:{
					t=(r+g+y-t)+res;
					t%=(r+g+y);
					if(t<r)
						res+=(r-t);
					else if(t>=g+r)
						res+=r+(r+g+y-t);
					break;
				}
				//绿灯的话，从初始状态到当前状态所花费的时间是r+g-t，然后加上res，再对（r+g+y）取余。 
				case 3:{
					t=(r+g-t)+res;
					t%=(r+g+y);
					if(t<r)
						res+=(r-t);
					else if(t>=g+r)
						res+=r+(r+g+y-t);
					break;
				}
			}
		}
		printf("%lld",res);
		return 0; 
	}
	*/
	
	return 0;
}
