#include <stdbool.h>

/*@
    requires (0 <= (A) && (A) <= 100 &&
        0 <= (B) && (B) <= 100 &&
        0 <= (C) && (C) <= 100 &&
        1 <= (K) && (K) <= 100 &&
        (A) + (B) + (C) >= (K));
    ensures \result == true <==> A >= K;
*/
bool func(unsigned long long A, unsigned long long B, unsigned long long C, unsigned long long K)
{
    // Variable declarations at top of scope
    bool result;
    
    if (A >= K) {
        result = true;
        //@ assert A >= K;
    } else {
        //@ assert A < K;
        result = false;
    }
    
    return result;
}
