#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result >= 0;
    ensures \result < 1000;
    ensures \result == ((1000 - (n) % 1000) % 1000);
*/
int func(int n)
{
    unsigned int n_unsigned;
    unsigned int result_unsigned;
    int result;

    //@ assert (1 <= (n) && (n) <= 10000);
    
    if (n < 0) {
        n_unsigned = (unsigned int)(-n);
    } else {
        n_unsigned = (unsigned int)n;
    }
    
    //@ assert n_unsigned == (n < 0 ? (unsigned int)(-n) : (unsigned int)n);
    
    result_unsigned = (1000 - n_unsigned % 1000) % 1000;
    
    //@ assert result_unsigned == (1000 - n_unsigned % 1000) % 1000;
    
    result = (int)result_unsigned;
    
    //@ assert result == (int)result_unsigned;
    //@ assert result >= 0;
    //@ assert result < 1000;
    //@ assert result == ((1000 - (n) % 1000) % 1000);
    
    return result;
}
