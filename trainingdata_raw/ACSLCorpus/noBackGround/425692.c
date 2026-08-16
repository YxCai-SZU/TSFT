#include <stdbool.h>
#include <stddef.h>

/*@ requires n >= 2 && n <= 100000;
    requires \valid(input + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 
              1 <= (integer)input[i] && (integer)input[i] <= 1000000000;
    assigns \nothing;
    ensures \result == true <==> 
            (\forall integer i; 0 <= i < n ==> 
                ((integer)input[i] % 2 == 0 ==> 
                 ((integer)input[i] % 3 == 0 || (integer)input[i] % 5 == 0)));
*/
bool func(size_t n, const unsigned long *input) {
    size_t i = 0;
    /*@ loop invariant 0 <= i <= n;
        loop invariant (\forall integer j; 0 <= j < (i) ==> (((integer)((unsigned long *)input)[j]) % 2 == 0 ==> (((integer)((unsigned long *)input)[j]) % 3 == 0 || ((integer)((unsigned long *)input)[j]) % 5 == 0)));
        loop assigns i;
        loop variant n - i;
    */
    while (i < n) {
        unsigned long value = input[i];
        //@ assert (((integer)value) % 2 == 0 ==> (((integer)value) % 3 == 0 || ((integer)value) % 5 == 0)) ==> (value % 2 != 0 || value % 3 == 0 || value % 5 == 0);
        if (value % 2 == 0) {
            bool condition = (value % 3 == 0) || (value % 5 == 0);
            if (!condition) {
                return false;
            }
        }
        i++;
    }
    return true;
}
