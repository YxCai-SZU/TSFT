#include <stdbool.h>

/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_result(integer r, integer N, integer N1) = 
        r == N - N1 || r == 0;
*/

/*@
    requires 1 <= N <= 100;
    requires 1 <= N1 <= 100;
    ensures is_result(\result, N, N1);
    ensures is_nonnegative(\result);
*/
int func(int N, int N1)
{
    int result;
    //@ assert 1 <= N <= 100;
    //@ assert 1 <= N1 <= 100;
    
    result = N - N1;
    
    if (result < 0)
    {
        result = 0;
    }
    
    //@ assert is_result(result, N, N1);
    //@ assert is_nonnegative(result);
    
    return result;
}
