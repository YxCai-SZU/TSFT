#include <stdbool.h>

/*@
    predicate non_negative(integer x) = x >= 0;
    
    logic integer compute_result(integer n, integer m) =
        n - 2 * m > 0 ? n - 2 * m : 0;
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result >= 0;
    ensures \result == n - 2 * m || \result == 0;
*/
int func(int n, int m)
{
    int result;
    
    //@ assert 1 <= n <= 100;
    //@ assert 1 <= m <= 100;
    
    if (n - 2 * m > 0) {
        //@ assert n - 2 * m >= 0;
        result = n - 2 * m;
    } else {
        //@ assert 0 >= 0;
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == n - 2 * m || result == 0;
    
    return result;
}

int main()
{
    return 0;
}
