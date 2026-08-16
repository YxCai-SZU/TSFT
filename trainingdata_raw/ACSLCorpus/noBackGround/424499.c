#include <stdbool.h>

/*@
    requires (1 <= (N) <= 100 && 0 <= (M) <= (N));
    ensures \result == (N == M);
    assigns \nothing;
*/
bool func(int N, int M) {
    // Variable declarations at top of scope
    bool result;
    
    //@ assert N >= M;
    //@ assert N - M <= 100;
    
    if (N == M) {
        result = true;
    } else {
        result = false;
    }
    
    return result;
}
