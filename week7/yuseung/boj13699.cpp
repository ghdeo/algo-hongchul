#include<iostream>
using namespace std;
typedef long long lng;

int ready[36] = { 0, };
lng val[36];
lng catalan(int n) {
	if (n == 0)return 1;
	if (ready[n]!=0)return val[n];
	ready[n] = 1;
	lng sum = 0;
	for (int k = 0; k < n; k++) {
		sum += catalan(k) * catalan(n - k - 1);
	}
	val[n] = sum;
	return val[n];

}


int main(void) {
	int n; cin >> n;
	ready[0] = 1;

	cout << catalan(n);
	return 0;
}