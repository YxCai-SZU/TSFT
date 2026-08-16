#include <stdbool.h>

/*@
    requires 1 <= N <= 100;
    requires 1 <= M <= 100;
    ensures \result == (N * 2 >= M && M * 2 >= N && N + M >= 2);
*/
bool func(unsigned long N, unsigned long M) {
    // Variable declarations at top of scope
    bool result;

    //@ assert N * 2 <= 200;
    //@ assert M * 2 <= 200;
    //@ assert N + M <= 200;

    result = (N * 2 >= M && M * 2 >= N && N + M >= 2);
    return result;
}
