#include <iostream>
using namespace std;

int max(int a, int b);
int max(int a, int b, int c);

int main()
{
    cout << max(35, 25) << "." << max(25, 39, 35) << endl;
    return 0;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int max(int a, int b, int c)
{

    int t = max(a, b);
    return max(t, c);
}
