#include <stdbool.h>

/*@
    requires (1 <= (n) <= 16 && 1 <= (m) <= 16 && (n) + (m) <= 16);
    ensures \result == true <==> ((n) <= 8 && (m) <= 8);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int m)
{
    // Variable declarations at scope top
    bool result;

    if (n <= 8 && m <= 8)
    {
        //@ assert ((n) <= 8 && (m) <= 8);
        result = true;
    }
    else
    {
        if (n > 8 && m <= 8)
        {
            //@ assert 9 <= n <= 16;
            //@ assert 1 <= m <= 8;
            //@ assert 9 <= n + m <= 24;
            result = false;
        }
        else if (n <= 8 && m > 8)
        {
            //@ assert 1 <= n <= 8;
            //@ assert 9 <= m <= 16;
            //@ assert 10 <= n + m <= 24;
            result = false;
        }
        else
        {
            //@ assert 9 <= n <= 16;
            //@ assert 9 <= m <= 16;
            //@ assert 18 <= n + m <= 32;
            result = false;
        }
    }

    return result;
}
