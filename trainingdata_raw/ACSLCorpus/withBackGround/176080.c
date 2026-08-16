#include <stdbool.h>

/*@
    predicate is_in_range(integer n, integer x) =
        0 <= n <= 100 && 0 <= x <= n;

    predicate result_condition(integer n, integer x, bool result) =
        result == true <==> (
            n == x ||
            x == n - 1 || x == n - 2 || x == n - 3 || x == n - 4 || x == n - 5 ||
            x == n - 6 || x == n - 7 || x == n - 8 || x == n - 9 || x == n - 10 ||
            x == n - 11 || x == n - 12 || x == n - 13 || x == n - 14 || x == n - 15 ||
            x == n - 16 || x == n - 17 || x == n - 18 || x == n - 19 || x == n - 20 ||
            x == n - 21 || x == n - 22 || x == n - 23 || x == n - 24 || x == n - 25 ||
            x == n - 26 || x == n - 27 || x == n - 28 || x == n - 29 || x == n - 30
        );
*/

/*@
    requires is_in_range(n, x);
    ensures result_condition(n, x, \result);
*/
bool func(int n, int x)
{
    //@ assert 0 <= n <= 100;
    //@ assert 0 <= x <= n;
    
    bool result;
    result = (n == x || x == n - 1 || x == n - 2 || x == n - 3 || x == n - 4 || x == n - 5 ||
              x == n - 6 || x == n - 7 || x == n - 8 || x == n - 9 || x == n - 10 ||
              x == n - 11 || x == n - 12 || x == n - 13 || x == n - 14 || x == n - 15 ||
              x == n - 16 || x == n - 17 || x == n - 18 || x == n - 19 || x == n - 20 ||
              x == n - 21 || x == n - 22 || x == n - 23 || x == n - 24 || x == n - 25 ||
              x == n - 26 || x == n - 27 || x == n - 28 || x == n - 29 || x == n - 30);
    
    return result;
}
