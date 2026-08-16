#include <stdbool.h>

/*@ predicate is_equal(integer a, integer b, integer c) =
      (b - a) == (c - b);
*/

/*@
  requires 1 <= A <= 100;
  requires 1 <= B <= 100;
  requires 1 <= C <= 100;
  ensures \result == true <==> is_equal(A, B, C);
*/
bool func(long long A, long long B, long long C)
{
    bool result;
    //@ assert is_equal(A, B, C) <==> ((B - A) == (C - B));
    result = (B - A) == (C - B);
    return result;
}
