#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_sequences(string x, int m, string y, int n, int p_gap, int p_miss);

int min_2(int a, int b){
    if(a < b)
        return a;
    return b;
}

int min(int a, int b, int c){
    return min_2(min_2(a, b), c);
}

int sequence_alignment(string x, string y, int p_gap, int p_miss)
{ 
    int n = y.length();
    int m = x.length();
    int i, j;
    int penalty_1, penalty_2, penalty_3;

    // alpha[i][j] --> shows the minimum penalty for aligning
    // x0 x1 .... xi
    // y0 y1 .... yj
    int alpha[m+1][n+1] = {0};

    // initializing alpha[][]
    for (i = 0; i <= m; i++)
        alpha[i][0] = p_gap * i;
    for (j = 0; j <= n; j++) 
        alpha[0][j] = p_gap * j; 

    for (i = 1; i <= m; i++) 
    { 
        for (j = 1; j <= n; j++) 
        { 
            if (x[i - 1] == y[j - 1]) 
            { 
                alpha[i][j] = alpha[i - 1][j - 1]; 
            } 
            else
            {
                // penalty of :
                // x0 x1 .... xi-1
                // y0 y1 .... yj-1
                // + penalty of P_miss
                penalty_1 = alpha[i - 1][j - 1] + p_miss;

                // penalty of :
                // x0 x1 .... xi-1
                // y0 y1 .... yj
                // + penalty of p_gap
                penalty_2 = alpha[i - 1][j] + p_gap;

                // penalty of :
                // x0 x1 .... xi
                // y0 y1 .... yj-1
                // + penalty of p_gap
                penalty_3 = alpha[i][j - 1] + p_gap;

                alpha[i][j] = min(penalty_1, penalty_2, penalty_3); 
            } 
        } 
    }

    return alpha[m][n];
}

int main(){

    cout << sequence_alignment("CG", "CA", 3, 7);
    cout << "\n";
    // cout << sequence_alignment("AGGGCT", "AGGCA", 2, 3);

    return 0;
}