#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b) {
    // if (a[1] == b[1])
    // {
    //     if (a[2] == b[2]) return a[0] < b[0];
    //     else return a[2] < b[2];
    // }
    return a[1] < b[1];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int x;
            cin >> x;
            v[i].push_back(x);
        }
    }
    sort(v.begin(), v.end(), comp);
    vector<int> comp;
    vector<int> tat;
    vector<int> wt;
    auto first = v[0][2];
    comp.push_back(first);
    for (int i = 1; i < n; i++)
    {
        auto prev = comp[i -1];
        if (prev >= v[i][1]) comp.push_back(prev + v[i][2]);
        else comp.push_back(v[i][1] + v[i][2]);
    }
    for (int i = 0; i < n; i++)
    {
        tat.push_back(comp[i] - v[i][1]);
    }
    for (int i = 0; i < n; i++)
    {
        wt.push_back(tat[i] - v[i][2]);
    }
    cout << "The answer is: " << endl;
    cout << "Process\tArival Time\tBurst Time\tWaiting Time\tTurnaround Time<\tCompletion Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P[" << v[i][0] << "]\t\t" << v[i][1]<< "\t\t"<< v[i][2] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t" << comp[i]<< endl;
    }
}