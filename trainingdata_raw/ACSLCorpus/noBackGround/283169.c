#include <stdbool.h>

/*@
  requires 1 <= n <= 10000;
  requires 0 <= a <= 1000;
  ensures \result == ((n % 500) <= a);
  assigns \nothing;
*/
bool func(unsigned long n, unsigned long a)
{
    unsigned long remainder;
    bool result;

    remainder = n;

    /*@
      loop invariant 1 <= n <= 10000;
      loop invariant 0 <= a <= 1000;
      loop invariant remainder <= n;
      loop invariant remainder >= 0;
      loop invariant remainder == n - 500 * ((n - remainder) / 500);
      loop assigns remainder;
      loop variant remainder;
    */
    while (remainder >= 500)
    {
        remainder -= 500;
    }

    /*@
      loop invariant 1 <= n <= 10000;
      loop invariant 0 <= a <= 1000;
      loop invariant remainder < 500;
      loop invariant remainder == n - 500 * ((n - remainder) / 500);
      loop assigns remainder;
      loop variant 500 + remainder;
    */
    while (remainder < 0)
    {
        remainder += 500;
    }

    //@ assert remainder == n % 500;
    //@ assert 0 <= remainder < 500;

    if (remainder <= a)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    //@ assert result == (remainder <= a);
    //@ assert result == ((n % 500) <= a);
    return result;
}
