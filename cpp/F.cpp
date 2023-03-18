#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		int nums_of_piles, number,sum = 0;
		cin >> nums_of_piles;
		for (int i = 0; i < nums_of_piles; ++i) {
			cin >> number;
			if(number % 2 != 0) sum += 1;
		}
		if (sum % 2 == 0 && nums_of_piles % 2 == 0) cout << "Windberu" << endl;
		else cout << "ITcarrot" << endl;
	}
	return 0;
}

//1个奇数：直接全部收走
//1个偶数：直接拆分

//场上剩下2个奇数：先拿走1个 
//场上剩下1奇1偶： 
//场上剩下2个偶数：拿走1个 或者拆分1堆 