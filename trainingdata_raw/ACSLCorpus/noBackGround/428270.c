#include <stdbool.h>
#include <stddef.h>

/*@ requires (0 < (n) && (n) <= 200000);
    requires \valid_read(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (0 < ((numbers)[i]) && ((numbers)[i]) <= 1000000000));
    assigns \nothing;
    ensures 0 <= \result <= n;
 */
int func(size_t n, const unsigned long long *numbers) {
    int count = 0;
    size_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop assigns count, index;
        loop variant n - index;
     */
    while (index < n) {
        unsigned long long num = numbers[index];
        if (num % 2 == 0) {
            count += 1;
        }
        index += 1;
    }
    return count;
}
