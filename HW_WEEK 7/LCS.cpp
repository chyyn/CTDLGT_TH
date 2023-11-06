#include <iostream>
#include <vector>
using namespace std;

int findLCS(vector<int>& a, vector<int>& b) {
    int sizeA = a.size();
    int sizeB = b.size();
    vector<vector<int>> lengthOfLCS(sizeA + 1, vector<int>(sizeB + 1));

    for (int i = 0; i <= sizeA; i++) {
        for (int j = 0; j <= sizeB; j++) {
            if (i == 0 || j == 0)
                lengthOfLCS[i][j] = 0;
            else if (a[i - 1] == b[j - 1])
                lengthOfLCS[i][j] = lengthOfLCS[i - 1][j - 1] + 1;
            else
                lengthOfLCS[i][j] = max(lengthOfLCS[i - 1][j], lengthOfLCS[i][j - 1]);
        }
    }
    return lengthOfLCS[sizeA][sizeB];
}

int main() {
    int m, n;
    cout << "Enter the number of elements in sequence a: ";
    cin >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
        cout << "Enter element " << i + 1 << " of sequence a: ";
        cin >> a[i];
    }

    cout << "Enter the number of elements in sequence b: ";
    cin >> n;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter element " << i + 1 << " of sequence b: ";
        cin >> b[i];
    }

    int lcs = findLCS(a, b);
    cout << "The length of the longest common subsequence is: " << lcs << endl;

    return 0;
}
