#include <stdbool.h>

/*@
    requires 1 <= N <= 100;
    requires 1 <= K <= 100;
    ensures \result == ( (N % 2 == 0 && N / 2 >= K) || (N % 2 == 1 && (N / 2 + 1) >= K) );
*/
bool func(unsigned int N, unsigned int K)
{
    bool ans;
    ans = false;

    if (N % 2 == 0)
    {
        if (N / 2 >= K)
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
        //@ assert ans == (N / 2 >= K);
    }
    else
    {
        unsigned int a;
        unsigned int b;
        a = N / 2;
        b = a + 1;
        if (b >= K)
        {
            ans = true;
        }
        else
        {
            ans = false;
        }
        //@ assert ans == (b >= K);
    }
    return ans;
}
