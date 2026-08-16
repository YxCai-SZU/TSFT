#include <stdbool.h>
#include <stddef.h>

/*@
    requires n >= 2 && n <= 100000;
    requires \valid_read(input + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= input[i] <= 1000000000;
    ensures \result == true <==> (\forall integer i; 0 <= i < n ==> input[i] % 2 == 0);
    assigns \nothing;
*/
bool func(size_t n, const unsigned long *input) {
    bool all_even = true;
    size_t index = 0;

    /*@
        loop invariant 0 <= index <= n;
        loop invariant all_even == true <==> (\forall integer i; 0 <= i < (index) ==> (input)[i] % 2 == 0);
        loop assigns all_even, index;
        loop variant n - index;
    */
    while (index < n) {
        unsigned long value = input[index];
        //@ assert value >= 1 && value <= 1000000000;
        if (value % 2 != 0) {
            all_even = false;
        }
        index++;
    }
    return all_even;
}
