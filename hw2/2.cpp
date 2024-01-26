// https://informatics.msk.ru/mod/statements/view.php?chapterid=1672#1

#include <iostream>
#include <vector>

using namespace std;

vector<int> tree;
vector<int> arr;

int get_size(int n)
{
    int new_n = 1;
    while (new_n < n) new_n *= 2;
    return new_n;
}

int build(int v, int l, int r)
{
    if (r - l == 1){
        return tree[v] = arr[l];
    }
    return tree[v] = build(2*v+1, l, (l + r) / 2) + build(2*v+2, (l + r) / 2, r);
}

int get_sum(int v, int l, int r, int q_l, int q_r)
{
    if (l >= q_l && r <= q_r) return tree[v];

    if (l >= q_r || r <= q_l) return 0;

    return get_sum(2*v+1, l, (l + r) / 2, q_l, q_r) + get_sum(2*v+2, (l + r) / 2, r, q_l, q_r);
}

void update(int v, int delta)
{
    tree[v] += delta;
    if (v != 0) update((v - 1)/2, delta);
}

int main()
{
    int n;
    cin >> n;
    n = get_size(n);
    arr.resize(n, 0);
    tree.resize(2*n-1);
    build(0, 0, n);

    int command, op1, op2;
    while (true) 
    {
        cin >> command;
        if (command == 0) break;
        cin >> op1 >> op2;

        if (command == 1)
        {
            int delta = op2;
            update(n + op1 - 2, delta);
            arr[op1-1] += delta;

            continue;
        }
        if (command == 2)
        {
            cout << get_sum(0, 0, n, op1-1, op2) << endl;
            continue;
        }

    }
    return 0;
}