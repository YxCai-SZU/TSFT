#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result == -1 || \result == 0 || \result == 1;
    ensures \result == -1 ==> 2*m + 1 <= n;
    ensures \result == 1 ==> 2*m + 1 > n;
    ensures \result == 0 ==> 2*m + 1 == n;
    assigns \nothing;
*/
int64_t func(uint64_t n, uint64_t m)
{
    // Variable declarations at top of scope
    int64_t result;

    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);

    if (2*m + 1 <= n)
    {
        //@ assert 2*m + 1 <= n;
        result = -1;
    }
    else if (2*m + 1 > n)
    {
        //@ assert 2*m + 1 > n;
        result = 1;
    }
    else
    {
        //@ assert 2*m + 1 == n;
        result = 0;
    }

    //@ assert result == -1 || result == 0 || result == 1;
    return result;
}

int main()
{
    return 0;
}
