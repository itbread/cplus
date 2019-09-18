#include <iostream>
#include <algorithm>
#include <iterator>
#include <functional>

using namespace std;
int main()
{
    double a[] = {1.1, 4.4, 3.3, 2.2}, b[4];
    ostream_iterator<double> output(cout, " ");
    copy(a, a + 4, output);
    cout << endl;

    reverse_copy(a, a + 4, output);
    cout << endl;

    copy(a, a + 4, b);
    copy(b, b + 4, output);
    cout << endl;

    sort(a, a + 4);
    copy(a, a + 4, output);
    cout << endl;

    reverse_copy(a, a + 4, b);
    copy(b, b + 4, output);
    cout << endl;

    return 0;
}
