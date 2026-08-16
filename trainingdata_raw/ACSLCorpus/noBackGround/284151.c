#include <stdbool.h>

/*@
    requires (1 <= (N) && (N) <= 100 &&
        1 <= (K) && (K) <= 100);
    ensures \result == true <==> N >= ((K) * 2 - 1);
    assigns \nothing;
*/
bool func(int N, int K)
{
    int n;
    int k;
    bool result;

    n = N;
    k = K;

    //@ assert k * 2 <= 200;
    
    if (n >= k * 2 - 1)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
