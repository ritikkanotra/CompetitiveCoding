#include<bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
    	cin >> arr[i];
	}
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << "\n";
    cin >> k;
    int diff[n - 1];
    for(int i = 0; i < (n - 1); i++) {
        diff[i] = arr[i + 1] - arr[i];
        cout << diff[i] << endl;
    }
    cout << endl;
    for(int i = 0; i < n - 1; i++) {
    	cout << diff[i] << endl;
	}
	cout << endl;
    sort(diff, diff + n, greater<int>());
    for(int i = 0; i < n - 1; i++) {
    	cout << diff[i] << endl;
	}
	cout << endl;
    cout << diff[k];
}
