#include <stdint.h>

/*@
    predicate white_in_bounds(integer n, integer white) =
        1 <= n <= 100 && 0 <= white <= n * n;

    logic integer black_value(integer n, integer white) =
        n * n - white;

    lemma n_square_bounds:
        \forall integer n; 1 <= n <= 100 ==> 0 <= n * n <= 10000;
*/

/*@
    requires white_in_bounds(n, white);
    ensures \result == black_value(n, white);
    ensures \result >= 0;
*/
int32_t func(int32_t n, int32_t white)
{
    int32_t ans;
    //@ assert white_in_bounds(n, white);
    //@ assert n >= 1 && n <= 100;
    //@ assert white >= 0 && white <= n * n;
    //@ assert n * n >= 0;
    //@ assert n * n <= 10000;
    
    ans = (n * n) - white;
    
    //@ assert ans == black_value(n, white);
    //@ assert ans >= 0;
    
    return ans;
}
