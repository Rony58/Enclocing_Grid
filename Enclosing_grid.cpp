//Mohammad Rony
//ID: 213902058
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
int i,j,highest_total,lowest_total;
int main() {
    int n;
    cout << "Please enter the desire grid dimension: ";
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));

    cout << "Please enter the desire input:" << endl;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> max_sum(n, vector<int>(n));
    vector<vector<int>> min_sum(n, vector<int>(n));
    for (j = 0; j < n; j++) {
        max_sum[0][j] = grid[0][j];
        min_sum[0][j] = grid[0][j];
    }
    for (i = 1; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (j == 0) {
                max_sum[i][j] = max(max_sum[i-1][j], max_sum[i-1][j+1]) + grid[i][j];
                min_sum[i][j] = min(min_sum[i-1][j], min_sum[i-1][j+1]) + grid[i][j];
            } else if (j == n-1) {
                max_sum[i][j] = max(max_sum[i-1][j-1], max_sum[i-1][j]) + grid[i][j];
                min_sum[i][j] = min(min_sum[i-1][j-1], min_sum[i-1][j]) + grid[i][j];
            } else {
                max_sum[i][j] = max({max_sum[i-1][j-1], max_sum[i-1][j], max_sum[i-1][j+1]}) + grid[i][j];
                min_sum[i][j] = min({min_sum[i-1][j-1], min_sum[i-1][j], min_sum[i-1][j+1]}) + grid[i][j];
            }
        }
    }
    highest_total = *max_element(max_sum[n-1].begin(), max_sum[n-1].end());
    lowest_total = *min_element(min_sum[n-1].begin(), min_sum[n-1].end());

    cout << "Highest: " << highest_total << endl;
    cout << "Lowest: " << lowest_total << endl;

}
