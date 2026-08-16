#include <stdbool.h>

/*@ predicate remainder_definition(integer N, integer R) =
      N % 500 == R;
*/

/*@
  requires 1 <= N <= 10000;
  requires 0 <= A <= 1000;
  ensures \result == ((N % 500) <= A);
*/
bool func(unsigned int N, unsigned int A)
{
    unsigned int r;
    unsigned int rr;
    bool result;

    r = N / 500;
    rr = N % 500;

    //@ assert remainder_definition(N, rr);

    result = (rr <= A);
    return result;
}
