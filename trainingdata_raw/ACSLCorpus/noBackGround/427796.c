#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == (k * 2 >= n || k * 2 + 1 >= n);
*/
bool func(int n, int k)
{
    int max_uncovered;
    bool result;

    max_uncovered = k * 2;

    if (max_uncovered >= n)
    {
        result = true;
        //@ assert k * 2 >= n;
        return result;
    }
    else if (max_uncovered + 1 >= n)
    {
        result = true;
        //@ assert k * 2 + 1 >= n;
        return result;
    }
    else
    {
        //@ assert max_uncovered < n && max_uncovered + 1 < n;
        result = false;
        //@ assert !(k * 2 >= n || k * 2 + 1 >= n);
        return result;
    }
}
