#include <stdbool.h>

/*@
    requires (100 <= (n) && (n) <= 999);
    ensures \result == (((n) / 100) == ((n) % 10));
    assigns \nothing;
*/
bool func(int n)
{
    unsigned int n_unsigned;
    unsigned int a0;
    unsigned int a1;
    unsigned int a2;
    bool result;

    //@ assert (100 <= (n) && (n) <= 999);
    n_unsigned = (n < 0) ? (unsigned int)(-n) : (unsigned int)n;

    a0 = n_unsigned / 100;
    a1 = (n_unsigned / 10) % 10;
    a2 = n_unsigned % 10;

    //@ assert a0 == ((n) / 100);
    //@ assert a2 == ((n) % 10);

    result = (a0 == a2);
    //@ assert result == (((n) / 100) == ((n) % 10));
    return result;
}
