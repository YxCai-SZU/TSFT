#include <stdbool.h>

/*@
    requires 1 <= N <= 100;
    requires 0 <= M <= N;
    ensures \result == (N == M);
*/
bool func(int N, int M)
{
    int x;
    int y;
    int max_val;
    int min_val;
    bool result;

    x = N;
    y = M;

    //@ assert x == N;
    //@ assert y == M;

    // Implementing the abs function manually
    if (x < 0)
    {
        x = -x;
    }
    //@ assert ((N) >= 0 ==> (x) == (N) &&         (N) < 0 ==> (x) == -(N));

    if (y < 0)
    {
        y = -y;
    }
    //@ assert ((M) >= 0 ==> (y) == (M) &&         (M) < 0 ==> (y) == -(M));

    // Implementing the max function manually
    if (x > y)
    {
        max_val = x;
    }
    else
    {
        max_val = y;
    }
    //@ assert max_val == ((x) > (y) ? (x) : (y));

    // Implementing the min function manually
    if (x < y)
    {
        min_val = x;
    }
    else
    {
        min_val = y;
    }
    //@ assert min_val == ((x) < (y) ? (x) : (y));

    result = (max_val == min_val);
    //@ assert result == (((x) > (y) ? (x) : (y)) == ((x) < (y) ? (x) : (y)));

    return result;
}
