#include <stddef.h>

/*@
    requires 2 <= n && n <= 100000;
    requires \valid(numbers + (0 .. n-1));
    requires (2 <= (n) && (n) <= 100000 &&
        (n) == (size_t)(n) &&
        \forall integer i; 0 <= i < (n) ==> 
            (((numbers)[i]) > 0 && ((numbers)[i]) <= ((n)) && ((numbers)[i]) != (i) + 1));
    ensures \result >= 0 && \result <= n;
*/
size_t func(size_t n, int *numbers) {
    size_t count = 0;
    size_t i = 0;
    
    /*@
        loop invariant (0 <= (i) && (i) <= (n) &&
        (count) >= 0 && (count) <= (i) &&
        (2 <= ((n)) && ((n)) <= 100000 &&
        ((size_t)(n)) == (size_t)((n)) &&
        \forall integer i; 0 <= i < ((n)) ==> 
            ((((numbers))[i]) > 0 && (((numbers))[i]) <= (((n))) && (((numbers))[i]) != (i) + 1)));
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        int a = numbers[i];
        //@ assert ((a) > 0 && (a) <= (n) && (a) != (i) + 1);
        if (i == (size_t)(a - 1)) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
