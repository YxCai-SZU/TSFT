#include <stdint.h>

/*@
    requires (0 <= (a) && (a) <= 100) && (0 <= (b) && (b) <= 100) && (0 <= (c) && (c) <= 100) && (0 <= (d) && (d) <= 100);
    ensures \result == a * b - c * d;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t d) {
    // Variable declarations at scope top
    int64_t product1;
    int64_t product2;
    int64_t result;

    //@ assert (0 <= (a) && (a) <= 100);
    //@ assert (0 <= (b) && (b) <= 100);
    //@ assert (0 <= (c) && (c) <= 100);
    //@ assert (0 <= (d) && (d) <= 100);

    //@ assert 0 <= a * b && a * b <= 10000;
    product1 = a * b;

    //@ assert 0 <= c * d && c * d <= 10000;
    product2 = c * d;

    //@ assert 0 <= product1 && product1 <= 10000;
    //@ assert 0 <= product2 && product2 <= 10000;

    result = product1 - product2;

    //@ assert -10000 <= result && result <= 10000;
    //@ assert result == a * b - c * d;

    return result;
}
