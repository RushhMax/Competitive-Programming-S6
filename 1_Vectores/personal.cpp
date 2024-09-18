#include <iostream>
#include <vector>
#include <algorithm> // For std::transform
#include <cctype>    // For std::tolower
#include <list>
#include <map>  // arbol binario equilibrado, clave valor
#include <unordered_map> // hash table
#include <set>  // arbol binario equilibrado, valor
#include <unordered_set> // tabla hash
#include <cmath>
#include <sstream> // Necesario para ostringstream

using namespace std;


// LEGEND OF FREYA THE FROG
// https://codeforces.com/problemset/problem/2009/C


// int main(){
//     int t;
//     for(int i=0; i<t; i++){
//         int x,y,k;
//         cin>>x>>y>>k;
//     }   
// }


// // DUBSTEP 
// // https://codeforces.com/problemset/problem/208/A

// int main(){
//     string song;
//     cin>>song;

//     string aux;
//     bool space = false;
//     for(int i=0; i<song.size(); i++){
//         if(song[i] == 'W' && song[i+1] == 'U' && song[i+2] =='B') { 
//             i += 2;
//             if(space){
//                 aux += " ";
//                 space = false;
//             } 
//         }else{
//             aux += song[i];
//             space = true;
//         }
//     }
//     cout<<aux;
// }

// HQ9+
// https://codeforces.com/problemset/problem/133/A

// int main(){
//     string input;
//     cin>>input;
//     for(int i=0; i<input.size() ; i++){
//         if(input[i] == 'H' || input[i] == 'Q' || input[i] == '9'){
//             cout<<"YES";
//             return 0;
//         }
//     }
//     cout<<"NO";
// }



//EVEN ODDS
// https://codeforces.com/problemset/problem/318/A

// 1 2 3 4 5 6 7 8 9 10
// 1 3 5 7 2 4 6

// int main(){
//     long long int n, k;
//     cin>>n>>k;
//     long long int mitad = (n + 2 - 1) / 2;  // Redondeo hacia arriba
//     if(k <= mitad){// es impar
//         k--;
//         cout<<1+(2*k)<<endl;
//     } else{ // par
//         k -= mitad;
//         cout<<2*k<<endl; 
//     }    
// }


// int main(){
//     long int n, k;
//     cin>>n>>k;

//     long int indice = 1;
//     for(int i=1; i<k; i++){
//         indice += 2;
//         if(indice >= n){
//             indice = 2;
//         }
//     }
//     cout<<indice<<endl;
// }


// TWINS
// https://codeforces.com/problemset/problem/160/A

// int suma(vector<int>& coins, int i, int j){
//     int suma = 0;
//     for(int k=i; k<j; k++){
//         suma += coins[k];
//     }
//     return suma;
// }

// int main(){
//     int n;
//     cin>>n;
//     std::vector<int> coins(n);

//     for(int i=0; i<n; i++){
//         cin>>coins[i]; 
//     }

//     sort(coins.begin(), coins.end(),greater<int>());

//     for(int i=0; i<n; i++){
//         if(suma(coins, 0, i) > suma(coins, i, n)){
//             cout<<i<<endl;
//             return 0;
//         }
//     }
//     cout<<n<<endl;
// }





// int main(){
//     // int a, b;
//     // int n;
//     // cin>>n;
//     // for(int i=0; i<n; i++){
//     //     cin>>a>>b;
//     //     if(a < b) cout<<"<\n";
//     //     else if(a > b) cout<<">\n";
//     //     else 
//     //         cout<<"=\n";
//     // }

//     // int v, t; //  5 12
//     // for(int i=0; i<2; i++){
//     //     cin>>v>>t;
//     //     cout<<v*2*t<<endl;
//     // }

//     // string input;
//     // while (getline(cin, input)) {
//     //     if (input.empty()) {
//     //         break; // Termina cuando no se inserta ninguna línea
//     //     }
//     //     stringstream ss(input); // Convertir la línea a un stream
//     //     int v, t;
//     //     ss >> v >> t; // Leer los valores de la línea
//     //     cout << v * 2 * t << endl;
//     // }

//     // int t;
//     // cin>>t;
//     // int n;
//     // for(int i=0; i<t; i++){
//     //     cin>>n;
//     //     int max = 0;
//     //     for(int j=0; j<n; j++){
//     //         int h;
//     //         cin>>h;
//     //         if(h>max) max = h;
//     //     }
//     //     cout<<"Case "<<i+1<<": "<<max<<endl;
//     // }


//     // int n,h;
//     // cin>>n>>h;
//     // int width = 0;
//     // for(int i=0; i<n; i++){
//     //     int h1;
//     //     cin>>h1;
//     //     if(h1>h) width+=2;
//     //     else width++;
//     // }
//     // return width;

//     // int k,n,w;
//     // cin>>k>>n>>w;
//     // int price = 0;
//     // int nBanana = 1;
//     // while(w > 0){  
//     //     price += nBanana*k; // 17 = 17 - 1*3  // 14 // 8 // -1   // 3 6 9 12
//     //     nBanana++;
//     //     w--;
//     // }
    
//     // cout<< (price < n ? 0 : (price-n) ); 

//     // //// A. FOOTBALL
//     // string situation;
//     // cin>>situation;

//     // for (size_t i = 0; i < situation.size(); i++){

//     // }


//     // string input;
//     // while (getline(cin, input)) {
//     //     if (input.empty()) {
//     //         break; // Termina cuando no se inserta ninguna línea
//     //     }

//     //     bool first_last = true; 
//     //     int max;
//     //     int antX = 0;
//     //     for(int i=1; i<=input.size(); i++){
//     //         if(input[i-1] == 'X'){
//     //             if(first_last) {
//     //                 if(i < 2) max = 0;
//     //                 else max = i - 2;
//     //                 first_last = false;
//     //             }
//     //             else{
//     //                 int dist = i - antX - 1;
//     //                 dist = (dist % 2 == 0 ? (dist/2)-1 : (dist/2));
//     //                 if(dist > max){
//     //                     max = dist;
//     //                 }
//     //             }
//     //             antX = i;
//     //         }
//     //     }
//     //     // cout<<input.length()<<" "<<antX<<" "<<max<<endl;
//     //     // if( (input.length() - antX - 1) > max ){
//     //     //     max = input.size() - antX - 1;
//     //     // }
//     //     if (antX < input.length() && (input.length() - antX - 1) > max) {
//     //         max = input.size() - antX - 1;
//     //     }

//     //     cout<<max<<endl;


// }


// int main(){
    
//     string first;
//     while (getline(cin, first)) {
//         if (first.empty()) {
//             break; // Termina cuando no se inserta ninguna línea
//         }

//         string second;
//         getline(cin, second);

//         bool letter = false;

//         for(int i=0; i<first.size(); i++){
//             if(first[i] == ' ' || second[i] == ' ') continue;
//             if(!(first[i]^second[i])) {
//                 cout<<"N"<<endl;
//                 letter = true;
//                 break;
//             }else{

//             }
//         }
//         if(!letter)cout<<"Y"<<endl;
//     }
// }

// int main(){

//     string players;
//     cin>>players;

//     int cont = 0;
//     char actual = players[0];
//     for(int i=0; i<players.size(); i++){
//         if(players[i] == actual){
//             cont++;
//         }else{
//             actual = players[i];
//             cont = 1;
//         }
//         if(cont >= 7){
//             cout<<"YES"<<endl;
//             return 0;
//         }
//     }
//     cout<<"NO"<<endl;
// }


