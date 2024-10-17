#include <bits/stdc++.h>

using namespace std;

struct Student{
    int a;
    int b;
    int c;
};

void solve(int n, int tc){
    vector<Student> students(n);
    for(int i=0; i<n; i++){
        cin>>students[i].a>>students[i].b>>students[i].c;
    }


}

int main(){
    int n;
    int tc = 1;
    while(cin>>n && n!=0){
        solve(n, tc);
        tc++;
    }
}
