#include <stdbool.h>
#include <stddef.h>

/*@ predicate valid_array(integer n, int *a) =
      n >= 2 && n <= 100000 &&
      \valid(a + (0 .. n-1)) &&
      \forall integer i; 0 <= i < n ==> 1 <= a[i] && a[i] <= 1000000000;
*/

/*@
  requires valid_array(n, a);
  ensures \result == (n >= 2);
  assigns \nothing;
*/
bool func(size_t n, const int *a)
{
    // Variable declarations at scope top
    bool result;

    if (n == 1) {
        //@ assert n >= 2 ==> n >= 2;
        return true;
    }

    if (n >= 2) {
        //@ assert n >= 2;
        return true;
    }

    // Unreachable code path verification
    //@ assert n >= 2;
    return false;
}
