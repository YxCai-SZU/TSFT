#include <stdint.h>
#include <stdbool.h>

/*@ requires n > 0;
    requires \valid(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (((numbers)[i]) > 0 && ((numbers)[i]) <= 100));
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t numbers[]) {
    uint64_t count = 0;
    uint64_t index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant 0 <= count <= index;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (((numbers)[i]) > 0 && ((numbers)[i]) <= 100));
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        uint64_t number = numbers[index];
        //@ assert ((number) > 0 && (number) <= 100);
        if (number % 2 == 0 && number % 3 == 0) {
            count += 1;
        }
        index += 1;
    }
    //@ assert count <= n;
    return count;
}
