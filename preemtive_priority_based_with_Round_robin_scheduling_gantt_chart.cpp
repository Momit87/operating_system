#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define endl "\n"


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll cpu_lim = 2;
    priority_queue<pair<pair<ll, ll>, string>> p;
    ll lim = INT_MAX;
    p.push({{3, lim - 0}, "Alice"});
    p.push({{2, lim - 1}, "Bob"});
    p.push({{1, lim - 2}, "Charlie"});
    p.push({{3, lim - 3}, "David"});
    p.push({{2, lim - 4}, "Eve"});
    lim = lim - 5;

    map<string, ll> m;
    m["Alice"] = 4;
    m["Bob"] = 7;
    m["Charlie"] = 4;
    m["David"] = 10;
    m["Eve"] = 7;
    vector<pair<ll,string>>gantt_chart;
    ll cntr = 0;
    while (!p.empty())
    {
        // cout << p.top().second << ' ';

        ll mini = min(m[p.top().second], cpu_lim);
        cntr+=mini;
        gantt_chart.push_back({cntr,p.top().second});
        m[p.top().second] -= mini;
        pair<pair<ll, ll>, string> temp;
        temp = p.top();
        p.pop();
        if (m[temp.second] > 0)
        {
            p.push({{temp.first.first, lim}, temp.second});
            lim--;
        }
    }
    cout<<"----------------Gantt Chart-----------------"<<endl;
    cout<<"Time  : Character "<<endl;
    for (auto u : gantt_chart)
    {
        cout<<"---> " << u.first <<"  "<< u.second << endl;
    }

    return 0;
}