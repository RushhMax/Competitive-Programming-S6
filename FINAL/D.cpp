#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    stack<int> B;

    vector<string> instructions;

    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int nVagon = 1;
    for(int i = A.size()-1; i >= 0; i--) {
        while(!B.empty() && B.top() == nVagon) {
            B.pop();
            instructions.push_back("B C");
            nVagon++;
        }
        if(A[i] == nVagon) {
            nVagon++;
            instructions.push_back("A C");
        }
        else {
            B.push(A[i]);
            instructions.push_back("A B");
        }

    }
   
    while(!B.empty()) {
        if(B.top() == nVagon) {
            B.pop();
            instructions.push_back("B C");
            nVagon++;
        }
        else {
            cout<<"-1"<<endl;
            return 0;
        }
    }

    cout<<instructions.size()<<endl;
    for(int i = 0; i < instructions.size() ; i++) {
        cout<<instructions[i]<<endl;
    }


}
