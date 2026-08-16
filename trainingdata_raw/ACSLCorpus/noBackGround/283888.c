#include <stddef.h>
#include <stdbool.h>

/*@
    requires n > 0;
    requires \valid(numbers + (0 .. n-1));
    requires (\forall size_t i; 0 <= i < (n) ==> (numbers)[i] > 0);
    assigns \nothing;
    ensures \result <= n;
    ensures (\forall size_t i; 0 <= i < (n) ==> (numbers)[i] > 0);
*/
size_t func(size_t n, int *numbers) {
    size_t count = 0;
    size_t index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant count <= index;
        loop invariant (\forall size_t i; 0 <= i < (n) ==> (numbers)[i] > 0);
        loop assigns index, count;
        loop variant n - index;
    */
    while (index < n) {
        int i = numbers[index];
        //@ assert i > 0;
        if (i % 2 == 0 && (i / 2) % 2 == 0) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
