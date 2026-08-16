#include <stdbool.h>
/*@
    requires (1 <= (a) <= 100);
    requires (1 <= (b) <= 100);
    ensures \result == a * b;
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int result;

    if (a == 0 || b == 0) {
        //@ assert a * b == 0;
        result = 0;
    } else {
        //@ assert 1 <= a && a <= 100;
        //@ assert 1 <= b && b <= 100;
        //@ assert a * b <= 100 * 100;
        result = a * b;
    }

    return result;
}
