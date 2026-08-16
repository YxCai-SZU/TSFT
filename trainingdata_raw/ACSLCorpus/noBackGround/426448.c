#include <stdbool.h>

/*@
    requires (1 <= (N) <= 10000 && 0 <= (A) <= 1000);
    ensures \result == (N % 500 <= A);
*/
bool func(unsigned long long N, unsigned long long A)
{
    unsigned long long pay;
    bool result;

    //@ assert (1 <= (N) <= 10000 && 0 <= (A) <= 1000);
    pay = N / 500;
    
    //@ assert ((N) % 500) == N - pay * 500;
    //@ assert N % 500 <= A ==> (N - pay * 500) <= A;
    
    result = (N % 500 <= A);
    return result;
}
