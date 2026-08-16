#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100) && (1 <= (d) && (d) <= 100);
    ensures \result == ((a) * (c)) || \result == ((b) * (d)) || 
            \result == ((a) * (d)) || \result == ((b) * (c));
    ensures \result >= 1;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d) {
    uint32_t max_val;

    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (c) && (c) <= 100);
    //@ assert ((a) * (c)) <= 10000;
    max_val = a * c;

    //@ assert (1 <= (b) && (b) <= 100) && (1 <= (d) && (d) <= 100);
    //@ assert ((b) * (d)) <= 10000;
    if (b * d > max_val) {
        max_val = b * d;
    }

    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (d) && (d) <= 100);
    //@ assert ((a) * (d)) <= 10000;
    if (a * d > max_val) {
        max_val = a * d;
    }

    //@ assert (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    //@ assert ((b) * (c)) <= 10000;
    if (b * c > max_val) {
        max_val = b * c;
    }

    //@ assert max_val >= 1;
    return max_val;
}

int main() {
    return 0;
}
