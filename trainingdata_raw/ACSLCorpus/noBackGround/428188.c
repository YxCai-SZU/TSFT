#include <stdbool.h>

/*@
    requires (1 <= (k) <= 1000);
    requires (1 <= (a) <= 1000);
    requires (1 <= (b) <= 1000);
    requires ((a) <= (b));
    ensures \result == (b / k * k >= a);
*/
bool func(unsigned int k, unsigned int a, unsigned int b) {
    unsigned int a_div_k;
    unsigned int b_div_k;
    bool result;

    a_div_k = a / k;
    b_div_k = b / k;

    //@ assert b_div_k * k <= b;
    //@ assert a_div_k * k <= a || (a_div_k + 1) * k > b;

    result = (b_div_k * k >= a);
    return result;
}
