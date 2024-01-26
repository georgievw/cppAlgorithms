// https://informatics.msk.ru/mod/statements/view.php?id=241&chapterid=1327#1

#include <iostream>
#include <vector> 

using namespace std;

int x = 37;
int p = 1000000007;
vector<long int> prefix_hashes;
vector<long int> xs;
string str;

bool isEqual(int b1, int b2, int l)
{
    return (prefix_hashes[b1+l] + xs[l]*prefix_hashes[b2]) % p == (prefix_hashes[b2+l] + xs[l]*prefix_hashes[b1]) % p;
}

int main()
{
    cin >> str;
    int n = str.size();
    
    prefix_hashes.resize(n+1, 0);
    xs.resize(n+1, 1);
    
    for (int i = 0; i < n; i++)
    {   
        prefix_hashes[i+1] = (prefix_hashes[i] * x + (long int)(str[i])) % p;
        xs[i+1] =(xs[i] * x) % p;
    }
    
    int result = 1;
    for (int i = n - 1; i > 0; i--)
    {
        if (isEqual(0, n-i, i) && n % (n-i) == 0)
        {
            result = n / (n-i);
            break;
        }
    }

    cout << result << endl;
    return 0;
}