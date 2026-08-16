#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result <==> (((a) + (b) + (c)) % 3 == 0 && (a) + (b) + (c) >= 3);
*/
bool can_distribute_evenly(unsigned int a, unsigned int b, unsigned int c) {
    unsigned int sum;
    sum = a + b + c;
    //@ assert sum == a + b + c;
    return (sum % 3 == 0) && (sum >= 3);
}
