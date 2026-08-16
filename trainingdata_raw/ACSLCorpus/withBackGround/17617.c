#include <stdbool.h>

/*@ predicate is_valid_params(integer n, integer m, integer x, integer a, integer b, integer c) =
      0 <= n <= 100 &&
      0 <= m <= 100 &&
      0 <= x <= n &&
      0 <= a <= m &&
      0 <= b <= m &&
      0 <= c <= n + m &&
      c >= a + b;
*/

/*@ logic integer expression_value(integer n, integer m, integer c, integer b) =
      n + m - c + b;
*/

/*@ lemma bounds_lemma:
      \forall integer n, m, c, b;
      is_valid_params(n, m, 0, 0, b, c) ==>
      0 <= expression_value(n, m, c, b) <= 200;
*/

/*@ lemma expression_nonnegative:
      \forall integer n, m, c;
      is_valid_params(n, m, 0, 0, 0, c) ==>
      n + m - c >= 0;
*/

/*@ requires is_valid_params(n, m, x, a, b, c);
    ensures \result == (expression_value(n, m, c, b) >= x);
*/
bool func(long n, long m, long x, long a, long b, long c)
{
    //@ assert c >= a + b;
    long result_value;
    bool result;
    
    result_value = n + m - c + b;
    result = result_value >= x;
    
    return result;
}
