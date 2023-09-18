#include <iostream>
#include <stack>

using namespace std;

int main() {
    int n;
    cin >> n;

    stack<int> st;

    for (int i = 0; i < n; i++) {
        string operation;
        cin >> operation;

        if (operation == "push") {
            int x;
            cin >> x;
            st.push(x);
        }
        else if (operation == "pop") {
            if (!st.empty()) {
                st.pop();
            }
        }
    }

    stack<int> reversedStack;
    while (!st.empty()) {
        reversedStack.push(st.top());
        st.pop();
    }

    while (!reversedStack.empty()) {
        cout << reversedStack.top() << " ";
        reversedStack.pop();
    }
    cout << endl;

    return 0;
}