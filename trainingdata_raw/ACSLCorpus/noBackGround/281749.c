#include <stdint.h>

/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) &&
             (1 <= (d) <= 100) && (1 <= (e) <= 100) && (1 <= (f) <= 100) &&
             (1 <= (g) <= 100) && (1 <= (h) <= 100) && (1 <= (i) <= 100) &&
             (1 <= (j) <= 100);
    ensures \result <= 1000;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c,
              uint32_t d, uint32_t e, uint32_t f,
              uint32_t g, uint32_t h, uint32_t i,
              uint32_t j)
{
    uint32_t x;
    uint32_t y;
    uint32_t z;
    uint32_t k;
    uint32_t result;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    //@ assert 1 <= a * b <= 100 * 100;
    //@ assert 1 <= a * b * c <= 100 * 100 * 100;
    
    if (a * b * c > 1000) {
        x = 1000;
    } else {
        x = a * b * c;
    }
    //@ assert x <= 1000;

    //@ assert (1 <= (d) <= 100) && (1 <= (e) <= 100) && (1 <= (f) <= 100);
    //@ assert 1 <= d * e <= 100 * 100;
    //@ assert 1 <= d * e * f <= 100 * 100 * 100;
    
    if (d * e * f > 1000) {
        y = 1000;
    } else {
        y = d * e * f;
    }
    //@ assert y <= 1000;

    //@ assert (1 <= (g) <= 100) && (1 <= (h) <= 100) && (1 <= (i) <= 100);
    //@ assert 1 <= g * h <= 100 * 100;
    //@ assert 1 <= g * h * i <= 100 * 100 * 100;
    
    if (g * h * i > 1000) {
        z = 1000;
    } else {
        z = g * h * i;
    }
    //@ assert z <= 1000;

    //@ assert x <= 1000 && y <= 1000 && z <= 1000;
    if (x + y + z > 1000) {
        k = 1000;
    } else {
        k = x + y + z;
    }
    //@ assert k <= 1000;

    //@ assert (1 <= (j) <= 100);
    //@ assert k <= 1000;
    if ((k + j) / 2 > 1000) {
        result = 1000;
    } else {
        result = (k + j) / 2;
    }
    //@ assert result <= 1000;

    return result;
}
