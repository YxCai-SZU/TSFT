#include <stdbool.h>

/*@
    requires (1 <= (n) <= 100);
    requires (1 <= (m) <= 100);
    ensures \result == (m <= n * 4 && m % 2 == n % 2);
*/
bool func(unsigned int n, unsigned int m)
{
    //@ assert (1 <= (n) <= 100);
    //@ assert (1 <= (m) <= 100);
    return m <= n * 4 && m % 2 == n % 2;
}
