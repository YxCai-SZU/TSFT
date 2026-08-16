#include <stdbool.h>


bool func(int a, int b, int c, int k)
{
    bool ans;
    ans = true;

    if (a < b && b < c)
    {
        ans = true;
    }
    else if (a > b && b > c)
    {
        ans = true;
    }
    else if (a == b && b == c)
    {
        ans = (k == 1);
    }
    else if (a != b && b != c && a != c)
    {
        ans = (k == 2);
    }
    else if (a != b && b == c && a != c)
    {
        ans = (k == 1);
    }
    else if (a == b && b != c && a != c)
    {
        ans = (k == 1);
    }
    else if (a != b && b != c && a == c)
    {
        ans = (k == 1);
    }

    //@ assert ans == ((a < b && b < c) || (a > b && b > c) || (a == b && b == c && k == 1) || (a != b && b != c && a != c && k == 2) || (a != b && b == c && a != c && k == 1) || (a == b && b != c && a != c && k == 1) || (a != b && b != c && a == c && k == 1) || (a == b && b == c && a != c && k == 2));

    return ans;
}
