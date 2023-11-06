#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Artifact {
    int weight;
    int profit;
};

bool compare(Artifact a, Artifact b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, std::vector<Artifact>& artifacts, int n) {
    sort(artifacts.begin(), artifacts.end(), compare);

    int curWeight = 0;
    double finalprofit = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + artifacts[i].weight <= W) {
            curWeight += artifacts[i].weight;
            finalprofit += artifacts[i].profit;
        }
        else {
            int remain = W - curWeight;
            finalprofit += artifacts[i].profit * ((double)remain / artifacts[i].weight);
            break;
        }
    }

    return finalprofit;
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

    double maxProfit = fractionalKnapsack(W, artifacts, n);
    cout << "The maximum profit that can be obtained is: " << maxProfit << std::endl;

    return 0;
}
