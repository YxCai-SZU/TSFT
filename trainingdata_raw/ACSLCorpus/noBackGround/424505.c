#include <stddef.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (((a) * (b) + 1) / 2);
    assigns \nothing;
*/
size_t func(size_t a, size_t b) {
    size_t c;
    size_t result;
    size_t temp;
    size_t count;
    
    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    
    //@ assert a * b <= 10000;
    c = a * b;
    
    result = 0;
    temp = c;
    count = 0;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant temp >= 0;
        loop invariant temp == c - 2 * count;
        loop invariant count >= 0;
        loop invariant count <= c / 2;
        loop invariant c <= 10000;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2) {
        temp -= 2;
        count += 1;
    }
    
    result = count + (temp == 1 ? 1 : 0);
    
    //@ assert result == (((a) * (b) + 1) / 2);
    
    return result;
}
