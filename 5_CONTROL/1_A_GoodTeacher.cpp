#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

pair<int, string> findCLose(vector<string> students, int pos, bool dir){
    //cout<<"pos"<<pos<<"dir"<<dir<<"."<<students[pos]<<"."<<endl;
    int size = students.size();
    if((pos == 0 &&  !dir) || (pos == size-1 && dir)) return make_pair(-1, "");
    while(students[pos] == "?" && pos >=0 && pos < size){
        if(dir){
            pos++;
        }else if(!dir){
            pos--;
        }
    }
    if(pos < 0 || pos >= size) return make_pair(-1, "");
    string letra = students[pos];
    //cout<<"letra mas cercana "<<letra<<" en pos "<<pos<<" - "<<dir<<endl;
    return make_pair(pos, letra);
}

string query(vector<string> students, int pos){
    if(students[pos] != "?" ){
        return students[pos];
    }else{
        pair<int, string> right = findCLose(students, pos, true);
        pair<int, string> left = findCLose(students, pos, false);
        
        int distRight = (right.first != -1) ? right.first - pos:10000;
        int distLeft = (left.first != -1) ? pos - left.first : 10000;

        //cout<<distRight<<" vs "<<distLeft<<endl;
        if(distLeft == distRight){
            return "middle of " + left.second + " and " + right.second;
        }else if(distRight < distLeft){
            string result = "";
            for(int i =  0; i < distRight; i++){
                result += "left of ";
            }
            result += right.second;
            return result;

        }else if(distRight > distLeft){
            string result = "";
            for(int i =  0; i < distLeft; i++){
                result += "right of ";
            }
            result += left.second;
            return result;
        }
    }
    return "";
}


int main(){
    int n;
    cin>>n;
    cin.ignore();

    vector<string> students;
    string s;
    while(n--){
        cin>>s;
        students.push_back(s);
    }

    int q;
    cin>>q;

    for(int i=0; i<q; i++){
        int pos;
        cin>>pos;
        cout<<query(students, pos-1)<<endl;
    }
}

// 10
// A ? ? D ? ? ? H ? ?
// 4
// 3
// 8
// 6
