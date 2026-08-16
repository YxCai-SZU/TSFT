#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
    ensures \result >= 0;
    ensures \result <= m;
    ensures n > m ==> \result == 0;
    ensures n <= m ==> \result == m - n + 1;
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    int64_t result;
    //@ assert (1 <= (n) && (n) <= 1000000000000 &&         1 <= (m) && (m) <= 1000000000000);
    
    if (n > m)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        //@ assert m >= n && m <= 1000000000000 && n >= 1 && n <= 1000000000000;
        //@ assert m - n + 1 <= 1000000000000;
        result = m - n + 1;
        //@ assert result == m - n + 1;
    }
    
    //@ assert result >= 0;
    //@ assert result <= m;
    return result;
}
