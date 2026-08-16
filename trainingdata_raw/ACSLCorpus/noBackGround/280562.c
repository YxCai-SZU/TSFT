#include <stdbool.h>
#include <stddef.h>

/*@
  requires 1 <= n <= 100000;
  requires 1 <= m <= 100000;
  ensures \result >= 0;
  ensures \result <= n + m;
  assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    // Declare all variables at the top
    size_t rem;
    size_t result;

    if (n * 2 > m)
    {
        //@ assert m / 2 <= n + m;
        result = m / 2;
    }
    else
    {
        //@ assert n + (m - n * 2) / 4 <= n + m;
        rem = m - n * 2;
        result = n + (rem / 4);
    }

    return result;
}
