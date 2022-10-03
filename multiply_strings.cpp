class Solution {
public:
    
    string addStrings(string num1, string num2) {
        int n1 = num1.length(), n2 = num2.length();
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int i = 0;
        int c = 0;
        string ans = "";
        while (i < n1 && i < n2) {
            int a = num1[i] - '0';
            int b = num2[i] - '0';
            a += b + c;
            ans += (a % 10) + '0';
            a /= 10;
            c = a;
            i++;
        }
        while (i < n1) {
            int a = num1[i] - '0';
            a += c;
            ans += (a % 10) + '0';
            a /= 10;
            c = a;
            i++;
        }
        while (i < n2) {
            int a = num2[i] - '0';
            a += c;
            ans += (a % 10) + '0';
            a /= 10;
            c = a;
            i++;
        }
        if (c != 0) {
            ans += c + '0';
        }
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
    
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int n1 = num1.length(), n2 = num2.length();
        reverse(num1.begin(), num1.end());
        string ans = "";
        int i = n2 - 1;
        int cnt = 0;
        while (i >= 0) {
            int dig = num2[i] - '0';
            // num2 /= 10;
            string temp = "";
            int c = 0;
            for (char ch: num1) {
                int a = ch - '0';
                a *= dig;
                a += c;
                // cout << (a % 10) + '0';
                temp += (a % 10) + '0';
                a /= 10;
                c = a;
            }
            // cout << temp << endl;
            if (c != 0) {
                temp += (c + '0');
            }
            reverse(temp.begin(), temp.end());
            for (int j = 0; j < cnt; j++) {
                temp += '0';
            }
            // cout << temp << endl;
            ans = addStrings(ans, temp);
            i--;
            cnt++;
        }
        return ans;
    }
};
