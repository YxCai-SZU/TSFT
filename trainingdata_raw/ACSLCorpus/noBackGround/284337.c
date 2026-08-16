#include <stddef.h>

/*@
    requires 1 <= n && n <= 10000;
    ensures \result == (n / 500) * 1000 + (n % 500 / 5) * 5;
*/
size_t func(size_t n) {
    size_t c;
    size_t value;
    size_t count_500;
    size_t count_5;
    
    c = 0;
    value = n;
    count_500 = 0;
    count_5 = 0;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= count_500 <= n / 500;
        loop invariant value == n - count_500 * 500;
        loop assigns value, count_500;
        loop variant value;
    */
    while (value >= 500) {
        //@ assert value >= 500;
        value -= 500;
        count_500 += 1;
    }
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= count_500 <= n / 500;
        loop invariant 0 <= count_5 <= (n - count_500 * 500) / 5;
        loop invariant value == n - count_500 * 500 - count_5 * 5;
        loop assigns value, count_5;
        loop variant value;
    */
    while (value >= 5) {
        //@ assert value >= 5;
        value -= 5;
        count_5 += 1;
    }
    
    c = count_500 * 1000 + count_5 * 5;
    //@ assert c == (n / 500) * 1000 + (n % 500 / 5) * 5;
    return c;
}
