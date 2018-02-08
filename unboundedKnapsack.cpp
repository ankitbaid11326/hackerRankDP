#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int unboundedKnapsack(int k, vector <int> arr) {
    // Complete this function
    
    int dp[k+1];
    memset(dp, 0, sizeof dp);
    
    
    int arrSize = arr.size();
    for(int i=0; i<=k; i++){
        for(int j=0; j <= arrSize; j++){
            if(arr[j] <= i){
                dp[i] = max(dp[i], dp[i - arr[j]] + arr[j]);
            }
        }
    }
    
    return dp[k];
    
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        int k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
            cin >> arr[arr_i];
        }
        int result = unboundedKnapsack(k, arr);
        cout << result << endl;
    }
    return 0;
}

