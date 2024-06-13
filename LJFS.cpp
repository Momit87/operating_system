#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

   
    cin >>n;
    vector<pair<pair<int, int>, char>> v(n);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first.second >> v[i].first.first;
        v[i].second = 'A' + i;
    }
    sort(v.begin(), v.end());
     cout << "----------------Gantt Chart-----------------" << endl;
    cout << "Time  : Character " << endl;
    int time=0;
    for(int i=n-1;i>=0;i--){
        time=max(v[i].first.second,time);
        time+=v[i].first.first;
        cout<<time<<' '<<v[i].second<<endl;
    }
    
    cout<<"Times : "<<time<<endl;
    

    return 0;
}