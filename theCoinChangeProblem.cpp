//
//  theCoinChangeProblem.cpp
//  TestingC++
//
//  Created by Ankit Baid on 06/02/18.
//  Copyright © 2018 Ankit Baid. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long getWays(int n, vector < int > c){

    long vecSize = c.size();
    long ans[n+1][vecSize];

    memset(ans, 0, sizeof(ans[0][0]) * (n+1) * vecSize);

    long x, y;

    for(long i=1; i<vecSize; i++)
        ans[0][i] = 1;

    ans[0][0] = 1;

    for(long i=1; i<(n+1); i++){
        for(long j=0; j<vecSize; j++){
            x = (i - c[j] >= 0) ? ans[i - c[j]][j] : 0;
            y = (j >= 1) ? ans[i][j-1] : 0 ;

            ans[i][j] = x + y;
        }
    }
    return ans[n][vecSize - 1];


}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<int> c(m);
    for(int c_i = 0; c_i < m; c_i++){
        cin >> c[c_i];
    }
    long ways = getWays(n, c);
    cout << "\n\n" << ways << endl;
    return 0;
}

