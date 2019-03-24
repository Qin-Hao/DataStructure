/*
	小明上学问题 
*/
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	int r, y, g;
	cin >> r >> y >> g;
	int num;
	cin >> num;
	
	int result;
	while(num != 0) {
		int num1, num2;
		cin >> num1 >> num2;
		if(num1 == 0 || num1 == 1) {
			result += num2;
		} else if(num1 == 2) {
			result += num2 + r;
		}
		--num;
	}
	cout << result << endl;
	return 0;
} 
