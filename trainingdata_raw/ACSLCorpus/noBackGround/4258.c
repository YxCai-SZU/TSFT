#include <stdbool.h>

/*@ requires (1 <= (K) <= 100 && 1 <= (X) <= 100000);
    ensures \result == ((500 * (K)) >= X);
*/
bool func(int K, int X)
{
    bool result;
    
    //@ assert (500 * (K)) >= X ==> ((500 * (K)) >= X);
    
    result = (500 * K >= X);
    return result;
}
