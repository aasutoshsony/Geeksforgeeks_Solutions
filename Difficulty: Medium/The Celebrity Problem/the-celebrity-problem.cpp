//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++


class Solution {
  public:
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size(), ans=-1;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n && !c;j++) if(mat[i][j]) c++;
            if(!c){
                c=0;
                for(int j=0;j<n;j++) if(mat[j][i]) c++;
                if(c==n-1) ans=i;
            }
            if(ans!=-1) break;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends