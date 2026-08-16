#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@ requires (2 <= (n) && (n) <= 100000);
    requires \valid_read(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) && ((numbers)[i]) <= 1000000000));
    ensures 0 <= \result;
    ensures \result <= n-2;
*/
uint64_t func(size_t n, uint64_t* numbers) {
    uint64_t count = 0;
    size_t i = 1;
    
    /*@ loop invariant 1 <= i <= n-1;
        loop invariant (2 <= (n) && (n) <= 100000);
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) && ((numbers)[i]) <= 1000000000));
        loop invariant 0 <= count;
        loop invariant count <= i-1;
        loop assigns i, count;
        loop variant n-i;
    */
    while (i < n - 1) {
        uint64_t n1 = numbers[i - 1];
        uint64_t n2 = numbers[i];
        uint64_t n3 = numbers[i + 1];
        
        //@ assert (1 <= (n1) && (n1) <= 1000000000);
        //@ assert (1 <= (n2) && (n2) <= 1000000000);
        //@ assert (1 <= (n3) && (n3) <= 1000000000);
        
        if ((n1 < n2 && n2 < n3) || (n1 > n2 && n2 > n3)) {
            count += 1;
        }
        i += 1;
    }
    return count;
}
