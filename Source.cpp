#include <iostream>

using namespace std;
int main() {
	
	int t, k, n, m;
	cin>>t>>k;
	for (int i = 0; i < t; i++) {
		cin>>n>>m;
		if (n > m) swap(n, m);
		if (!(n % (k + 1)) || (m - n + n / (k + 1) * (k != 1)) % 2) cout<<"+";
		else cout<<"-";
		cout<<'\n';
	}
}