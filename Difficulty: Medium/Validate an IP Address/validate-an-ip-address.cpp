//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {

public:

    int isValid(string str) {
 

      vector<string> parts;

        string part;

        stringstream ss(str);

        // Split the string by dots

        while (getline(ss, part, '.')) {
            parts.push_back(part);
        }

        // IPv4 address must have exactly 4 parts
        if (parts.size() != 4) {
            return 0;

        }

        for (const auto& part : parts) {
           

         // Check if the part is a number and is not empty
            if (part.empty() || !isNumber(part)) {
                return 0;
            }

            // Convert the part to an integer
            int num = stoi(part);

            // Check if the number is in the range 0-255
            if (num < 0 || num > 255) {
                return 0;
            }

            // Check for leading zeros
            if (part.length() > 1 && part[0] == '0') {
                return 0;
            }
        }

        return 1;
    }

private:
    bool isNumber(const string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }
};



//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends