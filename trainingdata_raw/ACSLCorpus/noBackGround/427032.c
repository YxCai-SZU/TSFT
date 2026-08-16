#include <stddef.h>

/*@
    requires (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
    ensures \result <= A * 3 + P;
    ensures \result == (A * 3 + P) / 2;
*/
size_t func(size_t A, size_t P)
{
    size_t ans;
    size_t temp;

    //@ assert A * 3 <= 300;
    temp = A * 3;
    
    //@ assert temp + P <= 400;
    ans = temp + P;
    
    //@ assert ans == A * 3 + P;
    //@ assert A * 3 <= ans;
    //@ assert P <= ans;
    //@ assert ans >= 0;
    //@ assert ans / 2 >= 0;
    //@ assert ans / 2 <= ans;
    //@ assert (A * 3 + P) / 2 <= 200;
    
    return ans / 2;
}
