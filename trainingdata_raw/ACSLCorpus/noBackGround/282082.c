#include <stdbool.h>

/*@
    requires 1 <= N <= 20;
    requires 1 <= M <= 20;
    ensures N > M ==> \result == 1;
    ensures N == M ==> \result == 0;
    ensures N < M ==> \result == 0;
*/
int func(int N, int M) {
    int result;
    
    if (N > M) {
        //@ assert N > M;
        result = 1;
    } else {
        //@ assert N <= M;
        result = 0;
    }
    
    return result;
}
