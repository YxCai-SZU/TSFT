#include <stdint.h>

/*@
    requires
        (1 <= (a) && (a) <= 123) && (1 <= (b) && (b) <= 123) && (1 <= (c) && (c) <= 123) &&
        (1 <= (d) && (d) <= 123) && (1 <= (e) && (e) <= 123);
    ensures
        \result <= a + b + c + d + e + 5;
    ensures
        \result >= 0;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t d, uint64_t e)
{
    uint64_t min;
    uint64_t result;

    min = a;
    //@ assert min == a;
    
    if (b < min) {
        min = b;
    }
    //@ assert min <= a && min <= b;
    
    if (c < min) {
        min = c;
    }
    //@ assert min <= a && min <= b && min <= c;
    
    if (d < min) {
        min = d;
    }
    //@ assert min <= a && min <= b && min <= c && min <= d;
    
    if (e < min) {
        min = e;
    }
    //@ assert min <= a && min <= b && min <= c && min <= d && min <= e;
    
    result = 0;
    
    if (a == min) {
        result += 1;
    }
    //@ assert result <= 1;
    
    if (b == min) {
        result += 1;
    }
    //@ assert result <= 2;
    
    if (c == min) {
        result += 1;
    }
    //@ assert result <= 3;
    
    if (d == min) {
        result += 1;
    }
    //@ assert result <= 4;
    
    if (e == min) {
        result += 1;
    }
    //@ assert result <= 5;
    
    //@ assert result >= 0 && result <= 5;
    
    return result;
}
