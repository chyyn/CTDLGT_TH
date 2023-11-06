#include <iostream>
#include <vector>
using namespace std;

struct Artifact {
    int weight;
    int profit;
};

int knapSack(int W, std::vector<Artifact>& artifacts, int n) {
    vector<vector<int>> K(n + 1, std::vector<int>(W + 1));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (artifacts[i - 1].weight <= w)
                K[i][w] = max(artifacts[i - 1].profit + K[i - 1][w - artifacts[i - 1].weight], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int n;
    cout << "Enter the number of artifacts: ";
    cin >> n;

    std::vector<Artifact> artifacts(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter the weight and profit of artifact " << i + 1 << ": ";
        cin >> artifacts[i].weight >> artifacts[i].profit;
    }

    int W;
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;

    int maxProfit = knapSack(W, artifacts, n);
    cout << "The maximum profit that can be obtained is: " << maxProfit << std::endl;

    return 0;
}
