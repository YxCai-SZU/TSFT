#include <stdint.h>

/*@ requires ((a) >= 1 && (a) <= 100 &&
    (b) >= 1 && (b) <= 100 &&
    (h) >= 1 && (h) <= 100 &&
    (h) % 2 == 0);
    ensures \result == (((a) + (b)) * (h) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t h) {
    uint64_t sum;
    uint64_t product;
    uint64_t area;
    
    //@ assert a >= 1 && a <= 100;
    //@ assert b >= 1 && b <= 100;
    //@ assert h >= 1 && h <= 100;
    //@ assert h % 2 == 0;
    
    sum = a + b;
    //@ assert sum >= 2 && sum <= 200;
    
    //@ assert sum * h <= 20000;
    product = sum * h;
    
    area = product / 2;
    //@ assert area == (a + b) * h / 2;
    
    return area;
}
