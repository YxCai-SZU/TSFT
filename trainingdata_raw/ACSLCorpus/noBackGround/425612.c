#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t h) {
    uint32_t sum;
    uint32_t product;
    uint32_t result;
    uint32_t count;
    uint32_t temp;

    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= h <= 100;
    //@ assert h % 2 == 0;

    sum = a + b;
    //@ assert sum <= 200;

    product = sum * h;
    //@ assert product <= 20000;

    result = 0;
    count = 0;
    temp = product;

    /*@
        loop invariant 0 <= count <= product / 2;
        loop invariant result == 0;
        loop invariant temp + 2 * count == product;
        loop invariant (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (h) <= 100 &&
        (h) % 2 == 0);
        loop assigns count, temp;
        loop variant temp;
    */
    while (temp >= 2) {
        temp -= 2;
        count += 1;
    }

    result = count;
    //@ assert result == (a + b) * h / 2;

    return result;
}
