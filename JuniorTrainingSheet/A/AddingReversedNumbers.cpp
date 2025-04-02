#include <bits/stdc++.h>

using namespace std;


int main(){
    int tc;cin>>tc;
    while(tc--){
        string a, b;cin>>a>>b;

        vector<int> ans;

        bool flag1 = false, flag2=false;
        int lleva = 0;
        int a_size = a.size(), b_size = b.size();

        for(int i=0; ;i++){
            int fd = 0, sd = 0;
            if(i < a_size) fd = a[i] - '0';
            else flag1 = true;
            if(i < b_size) sd = b[i] - '0';
            else flag2 = true;

            if(flag1 && flag2) break;
            
            int res = fd+sd+lleva;
            lleva = res/10;
            res = res%10;

            ans.push_back(res);
        }

        if(lleva > 0) ans.push_back(lleva);

        flag1 = false;
        for(int i=0; i<ans.size(); i++){
            if(ans[i] == 0 && !flag1) continue; 
            else if(ans[i] != 0)flag1 = true;
            cout<<ans[i];
        }
        cout<<endl;
    }
}
