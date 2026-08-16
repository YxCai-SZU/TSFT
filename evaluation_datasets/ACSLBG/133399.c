#include <stdbool.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 5;
    predicate result_condition(integer n, bool result) = 
        result == (n == 2 || n == 4 || n == 1 || n == 3 || n == 5);
*/


bool func(int n)
{
    int x;
    bool result;

    x = 2;
    //@ assert 1 <= x && x <= 5;
    
    //@ assert (n == 2 || n == 4 || n == 1 || n == 3 || n == 5) ==> (n == 2 || n == 4 || n == 1 || n == 3 || n == 5);
    
    result = (n == 2 || n == 4 || n == 1 || n == 3 || n == 5);
    return result;
}
