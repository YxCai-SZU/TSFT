#include <stddef.h>

/*@
  requires \valid_read(x + (0 .. 4));
  requires (\exists integer j; 0 <= j < 5 && (x)[j] == 0);
  ensures \result > 0;
  ensures \result < 6;
  ensures x[\result - 1] == 0;
*/
size_t func(const long long *x)
{
    size_t ans = 0;
    size_t i = 0;

    /*@
      loop invariant 0 <= i <= 5;
      loop invariant (((ans) == 0 && (\forall integer k; 0 <= k < (i) ==> (x)[k] != 0)) ||
      ((ans) > 0 && (ans) < 6 && (x)[(ans) - 1] == 0));
      loop assigns i, ans;
      loop variant 5 - i;
    */
    while (i < 5)
    {
        if (x[i] == 0)
        {
            ans = i + 1;
            break;
        }
        i += 1;
    }

    //@ assert ans > 0;
    //@ assert ans < 6;
    //@ assert x[ans - 1] == 0;

    return ans;
}
