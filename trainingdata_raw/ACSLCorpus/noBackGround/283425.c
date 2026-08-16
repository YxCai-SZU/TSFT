#include <stdbool.h>

/*@
    requires (1 <= (a) <= 500 &&
        1 <= (b) <= 500 &&
        1 <= (c) <= 1000);
    ensures \result == (a + b >= c);
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    bool result = false;
    unsigned int sum = 0;

    //@ assert 1 <= a <= 500;
    //@ assert 1 <= b <= 500;
    //@ assert 1 <= c <= 1000;

    sum = a + b;
    //@ assert sum == a + b;

    if (sum >= c) {
        result = true;
    }

    //@ assert result == (sum >= c);
    return result;
}
