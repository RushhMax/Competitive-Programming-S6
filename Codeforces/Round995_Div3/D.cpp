#include <bits/stdc++.h>

using namespace std;

int x = 0;
int y = 0;
int sumaTotal = 0;

bool ok (int n){
    if( x <= n && n <= y) return true;
    return false;
}

vector<int> memo(1000000, -1);

int pairs(vector<int> sequence, int mid, int i, int n){
    //cout<<mid<<" "<<i<<" "<<n<<" "<<endl;
    if(mid <= i || mid > n-1 || memo[mid] !=-1) return 0;
    int sumaParcial = sequence[i] + sequence[mid];
    memo[mid] = 1;
    if(ok(sumaTotal - sumaParcial)){
        //cout<<"found"<<endl;
        int right = pairs(sequence,mid + 1, i, n);
        int left = pairs(sequence,mid - 1, i, n);
        
        return right+left+1;
    }else if(sumaTotal - sumaParcial > y){
        //cout<<"mayor"<<endl;
        return pairs(sequence, mid+1, i,n);
    }else if(sumaTotal - sumaParcial < x){
        //cout<<"menor"<<endl;
        return pairs(sequence,mid-1, i,n);
    }
    return 0;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n; 
        cin>>n>>x>>y;

        vector<int> sequence(n);
      
        sumaTotal = 0;
        for(int i=0; i<n; i++){
            cin>>sequence[i];
            sumaTotal += sequence[i];
        }

        sort(sequence.begin(), sequence.end());


        int ans = 0;
        for(int i=0; i<n; i++){    
            int min = i+1, max = n;
            int mid = (min+max)/2;
            memo = vector<int>(1000000, -1);
            ans += pairs(sequence, mid, i,n);
        }        
        cout<<ans<<endl;
    }
}
