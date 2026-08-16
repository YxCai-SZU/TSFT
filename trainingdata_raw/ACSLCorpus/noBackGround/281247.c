#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == true <==> (n + 1) / 2 >= k;
*/
bool func(unsigned int n, unsigned int k) {
    unsigned int half_n;

    half_n = (n + 1) / 2;

    //@ assert half_n <= 50;
    //@ assert half_n >= k <==> (n + 1) / 2 >= k;

    return half_n >= k;
}
