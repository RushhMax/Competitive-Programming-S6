#include <bits/stdc++.h>

using namespace std;

int main(){
    int year, month, day;
    cin>>year>>month>>day;
    
    tm time = {0,0,0,day, month-1, year -1900};

    mktime(&time);

    vector<string> days = {"Domingo", "Lunes", "Martes", "Miercoles", "JUeves", "Viernes", "Sabado"};

    cout<<days[time.tm_wday]<<endl;

    return 0;
}
