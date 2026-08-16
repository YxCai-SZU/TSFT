#include <stdbool.h>

/*@
    requires 1 <= N <= 100;
    requires 1 <= K <= 100;
    ensures \result == true <==> (((N) % 2 == 0 && (N) / 2 >= (K)) || ((N) % 2 != 0 && ((N) / 2) + 1 >= (K)));
    assigns \nothing;
*/
bool func(unsigned int N, unsigned int K)
{
    bool result;
    
    //@ assert N >= 1 && N <= 100;
    //@ assert K >= 1 && K <= 100;
    
    if ((N % 2 == 0 && N / 2 >= K) || (N % 2 != 0 && (N / 2) + 1 >= K)) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
