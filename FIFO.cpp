#include <bits/stdc++.h>
using namespace std;


int main(){
    int fr;
    cout<<"Enter number of frames: ";
    cin>>fr;
    int n;
    cout<<"Enter number of inputs: ";
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cout<<"Enter input "<<i+1<<" ";
        cin>>v[i];
    }
    queue<int> q;
    set<int> s;
    int hit=0;
    int fault = 0;
    for(int i=0;i<n;i++){
        if(s.size()<fr){
            if(s.find(v[i]) == s.end()){
                s.insert(v[i]);
                q.push(v[i]);
                fault++;
            }
            else{
                hit++;
            }
        }
        else{
            if(s.find(v[i]) == s.end()){
                int val = q.front();
                q.pop();
                s.erase(val);
                s.insert(v[i]);
                q.push(v[i]);
                fault++;
            }
            else{
                hit++;
            }
        }

    }
    cout<<"Number of page faults: ";
    cout<<fault<<endl;
    cout<<"Number of page hits: ";
    cout<<hit<<endl;
    

    return 0;
}