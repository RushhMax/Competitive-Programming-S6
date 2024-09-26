#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();

    stack<string> namesDreams;

    while(n--){
        string s;
        getline(cin,s);

        if(s.find("Sleep") == 0){
            s = s.substr(6);
            namesDreams.push(s);
        }else if(s == "Test"){
            if(namesDreams.empty()){
                cout<<"Not in a dream"<<endl;
            }else{
                cout<<namesDreams.top()<<endl;
            }
        }else if(s == "Kick"){
            if(!namesDreams.empty())
                namesDreams.pop();
        }
    }
}