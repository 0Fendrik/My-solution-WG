#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>

using namespace std;


int main() {
	int n,k=0;
	cin >> n;
	int** streng;
	streng = new int*[n];
	for (int i = 0; i < n; i++){
		streng[i] = new int[10];
		for (int j = 0; j < 10; j++) {
			int a;
			cin >> a;
			streng[i][j] = a;
		}
	}

	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = 1; j < 10; j++) {

			if (streng[i][j] < streng[i][j - 1] && j != 0) {
				k++;
				swap(streng[i][j], streng[i][j - 1]);
				j-=2;
			}
		}
		if (k == 0) {
			printf("%f \n", static_cast<double>(0.));
		}
		else {
			printf("%f \n", static_cast<double>(45./k));
		}
		

	}

}
