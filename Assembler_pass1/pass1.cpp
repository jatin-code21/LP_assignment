#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
    vector<vector<string>> inp(5,vector<string>(4));
    for(int i=0;i<5;i++){
        for(int j=0;j<4;j++){
            cin>>inp[i][j];
        }
    }
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<inp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    int st = stoi(inp[0][2]);
    vector<vector<string>> sym;
    int key =0;
    st--;
    for(int i=1;i<5;i++){
        st++;
        if (inp[i][0] != "-1"){
            sym.push_back({inp[i][0],to_string(st)});
        }
        if (inp[i][3] <= "Z" && inp[i][3] >= "A"){
            sym.push_back({inp[i][3],"-999"});
        }
        if(inp[i][1] <= "Z" && inp[i][1] >= "A"){
            key = st;
        }
    }
    for(int i=0;i<sym.size();i++){
        if(sym[i][1] == "-999"){
            sym[i][1] = to_string(key);
        }
    }
    for(int i=0;i<sym.size();i++){
        cout<<sym[i][0]<<" "<<sym[i][1]<<endl;
    }
    





    return 0;
}