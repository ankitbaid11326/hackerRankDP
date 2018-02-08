#include "stdc++.h"

using namespace std;

vector <int> longestCommonSubsequence(vector <int> a, vector <int> b) {
    
    int vec1Size =  a.size();
    int vec2Size = b.size();
    
    vector<int> resultVector;
    
    int ans[vec1Size + 1][vec2Size + 1];
    
    memset(ans, 0, sizeof(ans[0][0]) * (vec1Size+1) * (vec2Size+1));
    
    for(int m=1; m<=vec1Size; m++){
        for(int n=1; n<=vec2Size; n++){
            if(a[m-1] == b[n-1]){
//                cout << a[m-1] << b[n-1] << endl;
                ans[m][n] = ans[m-1][n-1] + 1;
            }else{
                ans[m][n] = max(ans[m][n-1], ans[m-1][n]);
            }
            cout << ans[m][n] << "\t";
        }
        cout << endl;
    }
    
    int ans2 = ans[vec1Size][vec2Size];
    cout << endl;
    for(int i =0; i<vec2Size; i++){
//        cout << b[i] << "\t";
    }
//    cout << endl;
    
    while(ans2 > 0){
        
        if(ans2 > ans[vec1Size][vec2Size - 1] && ans2 > ans[vec1Size-1][vec2Size]){
            resultVector.push_back(b[vec2Size-1]);
            ans2 = ans[--vec1Size][--vec2Size];
        }
        else if(ans2 == ans[vec1Size][vec2Size - 1]){
            ans2 = ans[vec1Size][vec2Size - 1];
            vec2Size--;
        }else{
            ans2 = ans[vec1Size - 1][vec2Size];
            vec1Size--;
        }
    }
    
    reverse(resultVector.begin(), resultVector.end());
    
    return resultVector;
    
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> a(n);
    for(int a_i = 0; a_i < n; a_i++){
        cin >> a[a_i];
    }
    vector<int> b(m);
    for(int b_i = 0; b_i < m; b_i++){
        cin >> b[b_i];
    }
    vector <int> result = longestCommonSubsequence(a, b);
    for (ssize_t i = 0; i < result.size(); i++) {
        cout << result[i] << (i != result.size() - 1 ? " " : "");
    }
    cout << endl;
    
    
    return 0;
}


