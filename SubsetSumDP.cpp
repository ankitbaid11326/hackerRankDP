//
//  SubsetSumDP.cpp
//  TestingC++
//
//  Created by Ankit Baid on 08/02/18.
//  Copyright © 2018 Ankit Baid. All rights reserved.
//

#include "stdc++.h"

using namespace std;

vector<int> subsetSum(vector<int> val, int total){
    sort(val.begin(), val.end());
    int vecSize = val.size();
    
    vector<int> result;
    
    bool ans[vecSize+1][total+1];
    
    for(int i=0; i<=vecSize; i++)
        ans[i][0] = true;
    
    for(int j=1; j<=total; j++)
        ans[0][j] = false;
    
    for(int i=1; i<=vecSize; i++){
        cout << val[i-1] << " = ";
        for(int j=1; j<=(total); j++){
            if(val[i-1] <= j){
                ans[i][j] = ans[i-1][j-val[i-1]];
            }
            else{
                ans[i][j] = ans[i-1][j];
            }
            cout << "[" << i <<"][" << j << "]= " << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    bool ans2 = ans[vecSize][total];
    
    if(ans2 == 0){
        result.push_back(-1);
        return result;
    }else{
        int i = vecSize;
        int j = total;
        
        while(j != 0){
            if(ans2 != ans[i - 1][j]){
                result.push_back(val[i-1]);
                j = j - val[i-1];
                i--;
                ans2 = ans[i][j];
            }else{
                ans2 = ans[i-1][j];
            }
        }
    }
    return result;
}

int main(){
    
    vector<int> vec1;
    vec1.push_back(2);
    vec1.push_back(4);
    vec1.push_back(1);
    vec1.push_back(5);
    
    vector<int> resuleVector = subsetSum(vec1, 13);
    
    for(int i =0; i<resuleVector.size(); i++){
        cout << resuleVector[i]<< " ";
    }
    
    return 0;
}
