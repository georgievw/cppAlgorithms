#include <iostream>

using namespace std;

long int get_n(long int a, long int b, long int w, long int h, long int d)
{
    return max(( w / (a + 2*d)) * ( h /(b + 2*d)), (w / (b + 2*d)) * ( h / (a + 2*d) ));
}

int main()
{
    long int n, a, b, w, h;
    cin >> n >> a >> b >> w >> h;
    
    long int l = 0, r = min(w,h) / 2, mid;
    while (r - l > 1)
    {
        mid = (r + l) / 2;
        if (get_n(a, b, w, h, mid) < n)
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    cout << l << endl;

    return 0;
}