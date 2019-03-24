/*
	约瑟夫环问题 
*/

#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	int sum, num;	//sum为总人数，num为开始的报数 
	cin >> sum >> num;
	
	int a[sum + 1];
	for(int i = 1; i <= sum; ++i) {
		a[i] = 1;
	}
	
	int out = 0;	//阵亡人数 
	int count = 0;	//计数 
	while(out != sum) {
		for(int j = 1; j <= sum; ++j) {
			if(a[j] == 1) {
				++count;
				if(count == num) {
					a[j] = 0;
					count = 0;
					++out;
					cout << j << endl;
				}
			}
		}
	}
	
	return 0;
} 
