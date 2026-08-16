#include <limits.h>

/*@
    predicate valid_range(integer N) = 1 <= N <= 10000;
    
    logic integer ceiling_div(integer N_unsigned) = (N_unsigned + 999) / 1000;
    
    logic integer expected_result(integer N) = (1000 - N % 1000) % 1000;
*/

/*@
    requires valid_range(N);
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == expected_result(N);
*/
int func(int N)
{
    unsigned int N_unsigned;
    unsigned int result_unsigned;
    int result;
    
    //@ assert valid_range(N);
    
    if (N < 0) {
        //@ assert N >= 1; // From precondition
        N_unsigned = (unsigned int)(-N);
    } else {
        N_unsigned = (unsigned int)N;
    }
    
    //@ assert N_unsigned <= 10000;
    //@ assert N_unsigned + 999 <= 10000 + 999;
    
    result_unsigned = (N_unsigned + 999) / 1000;
    
    //@ assert result_unsigned == ceiling_div(N_unsigned);
    
    result = (int)result_unsigned * 1000 - N;
    
    //@ assert result >= 0;
    //@ assert result < 1000;
    //@ assert result == expected_result(N);
    
    return result;
}
