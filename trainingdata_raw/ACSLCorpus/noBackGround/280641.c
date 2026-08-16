#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> ((n) % 2 == 0);
    ensures \result == 0 ==> ((n) % 2 != 0);
*/
int func(unsigned int n)
{
    bool is_even_bool;
    int result;

    is_even_bool = (n % 2 == 0);
    result = is_even_bool ? 1 : 0;

    //@ assert result == 1 || result == 0;
    //@ assert result == 1 ==> ((n) % 2 == 0);
    //@ assert result == 0 ==> ((n) % 2 != 0);
    //@ assert 1 <= n <= 100;

    return result;
}
