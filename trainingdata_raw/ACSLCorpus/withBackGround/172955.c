#include <stdbool.h>

/*@
    predicate valid_params(integer n, integer m, int* xs) =
        1 <= n <= 100 &&
        1 <= m <= 100 &&
        \valid(xs + (0..1)) &&
        1 <= xs[0] <= n &&
        1 <= xs[1] <= m;

    logic integer compute_result(integer n, integer m, integer x0, integer x1) =
        n - x0 + m - x1;
*/

/*@
    requires valid_params(n, m, xs);
    ensures \result >= 0;
    ensures \result == compute_result(n, m, xs[0], xs[1]) || \result == 0;
    assigns \nothing;
*/
int func(int n, int m, int* xs) {
    int result;
    //@ assert \valid(xs + (0..1));
    //@ assert 1 <= xs[0] <= n;
    //@ assert 1 <= xs[1] <= m;
    
    result = n - xs[0] + m - xs[1];
    
    if (result > 0) {
        //@ assert result == compute_result(n, m, xs[0], xs[1]);
        return result;
    } else {
        //@ assert result == compute_result(n, m, xs[0], xs[1]);
        return 0;
    }
}
