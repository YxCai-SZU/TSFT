#include <stdbool.h>

/*@ predicate is_even_sum(integer a, integer b, integer c) =
      (a + b + c) % 2 == 0;
*/

/*@
  requires 1 <= a <= 10000;
  requires 1 <= b <= 10000;
  requires 1 <= c <= 10000;
  ensures \result == ((a + b + c) % 2 == 0);
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    bool ans;

    sum = a + b + c;
    ans = (sum / 2) * 2 == sum;

    //@ assert ans == ((a + b + c) % 2 == 0);

    return ans;
}
