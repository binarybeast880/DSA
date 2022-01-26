#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>> 
int getMin(vi &a)
{
    int min_index = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] < a[min_index])
            min_index = i;
    }
    return min_index;
}

int getMax(vi &a)
{
    int max_index = 0;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] > a[max_index])
            max_index = i;
    }
    return max_index;
}

int min_of_two(int a, int b)
{
    return (a < b) ? a : b;
}

void rec_min_cash_flow(vi &amount)
{
    int max_credit = getMax(amount);
    int max_debit = getMin(amount);
    if (amount[max_credit] == 0 && amount[max_debit] == 0)
        return;
    int minn = min_of_two(-amount[max_debit], amount[max_credit]);
    amount[max_credit] -= minn;
    amount[max_debit] += minn;

    cout << "Person " << max_debit << " pay " << minn << "to person " << max_credit << '\n';
    rec_min_cash_flow(amount);
}

void min_cash_flow(vvi &graph)
{
    vi amount(graph.size(), 0);
    for (int p = 0; p < graph.size(); p++)
    {
        for (int q = 0; q < graph[0].size(); q++)
        {
            amount[p] += (graph[q][p] - graph[p][q]);
        }
    }
    rec_min_cash_flow(amount);
}

void binarybeast880()
{
    int n;
    cin >> n;
    vvi graph(n, vi(3));
    for (int i = 0; i < n; i++)
    {
        int u, v, m;
        cin >> u >> v >> m;
        graph[i][0] = u;
        graph[i][1] = v;
        graph[i][2] = m;
    }
    min_cash_flow(graph);
}

main()
{
    int t;
    cin >> t;
    while (t--)
    {
        binarybeast880();
    }
}