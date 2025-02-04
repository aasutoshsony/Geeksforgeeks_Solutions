//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/


class Solution 
{
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
       vector<int>ans;
       sort(arr,arr+n,[&](Job a,Job b){
           return (a.profit == b.profit)?a.dead < b.dead:a.profit > b.profit;
       });
       int ct = 0;
       int profit = 0;
       vector<int>timeline(n+1,0);
       for(int i=0;i<n;i++){
           int st = arr[i].dead-1;
           if(st < 0)continue;
           while(timeline[st]==1){
               st--;
           }
           if(st < 0)continue;
           timeline[st] = 1;
           ct++;
           profit += arr[i].profit;
       }
       ans.push_back(ct);
       ans.push_back(profit);
       return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends