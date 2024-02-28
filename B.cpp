#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<string>

using namespace std;

bool comp( pair <int, int>  a, pair <int, int>  b) {
	return a.first < b.first;
}


int main() {
	int n;
	cin >> n;
	vector<pair<int, int>>cost(9);
	for (int i = 0; i < 9; i++) {
		int a;
		cin >> a;
		cost[i] = { a, i + 1 };
	}


	reverse(begin(cost), end(cost));
    sort(cost.begin(), cost.end(), comp);


	vector<pair<int, int>>final;
	final.push_back(make_pair(cost[0].first, cost[0].second));
	for (int i = 1; i < 9; i++)
	{
		if (cost[i].first != cost[i - 1].first) {
			final.emplace_back(make_pair(cost[i].first, cost[i].second));
		}
	}

	bool flag = true;
	int k = 0;
	int p = 0;
	string s="";
	if (n < final[0].first) {
		cout <<-1;
		return 0;
	}

	while (flag) {
		int b = n - (n / final[0].first - 1) * final[0].first;
		flag = false;
		for (int i = final.size() - 1; i > 0; i--)
		{
			if (final[i].first <= n - (n / final[0].first - 1) * final[0].first && final[k].second < final[i].second) {
				flag = true;
				k = i;
			}
		}
		if (flag){
			for (int i = 0; i < (n - (n / final[0].first) * final[0].first) / (final[k].first - final[0].first); i++) {
				s+=final[k].second+48; 
				p++;
			}

		n = n - (n - (n / final[0].first) * final[0].first) / (final[k].first - final[0].first) * (final[k].first - final[0].first);
	}
		k = 0;
}
		for (int i = 0; i < n / final[0].first -p; i++) {
			s+=final[0].second+48;
		}
		cout << s;
}
/*
15
9 8 9
4 5 6
9 8 9

9
2 3 3
3 3 3
 3 3 3

14
5 7 15 15 15 15 15 15 15
*/