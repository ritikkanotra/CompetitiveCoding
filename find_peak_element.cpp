class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int n = arr.size(), flag = 0;
        // cin >> n;
        // int  arr[] = {10,20,15,2,23,45, 54, 14,52,10};
        // int arr[] = {10,20,15,2,23,45, 54, 63,68,10};
        // int arr[] = {1, 2,3,4,5,6};
        // int arr[] = {1};
        // for (int i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }
        int i = 0, j = n - 1;
        while (i < j) {
            int mid = (i + j) / 2;
            if (mid - 1 >= i && arr[mid - 1] > arr[mid]) {
                j = mid - 1;
            }
            else if (mid + 1 <= j && arr[mid + 1] > arr[mid]) {
                i = mid + 1;
            }
            else {
                flag = 1;
                // cout << mid;
                // break;
                return mid;
            }
        }
        if (flag == 0) {
            // cout << i;
            return i;
        }
        return 0;
    }
};
