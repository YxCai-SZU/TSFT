#include <stdbool.h>

/*@
    requires (1 <= (N) && (N) <= 100 &&
        1 <= (M) && (M) <= 100);
    ensures \result >= 0;
    ensures \result == N - M * 2 || \result == 0;
*/
int func(int N, int M)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert 1 <= N && N <= 100;
    //@ assert 1 <= M && M <= 100;
    //@ assert M * 2 <= 100 * 2;
    
    result = N - M * 2;
    
    if (result < 0) {
        result = 0;
    }
    
    return result;
}
