#include <stdbool.h>
#include <stdint.h>

/*@ requires (2 <= (n) <= 200000);
    requires \valid_read(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int32_t func(uint32_t n, const int64_t *numbers) {
    int32_t count = 0;
    uint32_t i = 0;
    
    //@ assert (2 <= (n) <= 200000);
    //@ assert (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
    
    /*@ loop invariant 0 <= i <= n-1;
        loop invariant 0 <= count <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
        loop invariant (2 <= (n) <= 200000);
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n - 1) {
        int64_t a = numbers[i];
        int64_t b = numbers[i + 1];
        int64_t sum = a + b;
        
        //@ assert (1 <= (a) <= 1000000000);
        //@ assert (1 <= (b) <= 1000000000);
        //@ assert 2 <= sum <= 2000000000;
        
        if ((sum & 1) == 1) {
            count += 1;
        }
        
        i += 1;
        
        //@ assert 0 <= count <= i;
    }
    
    //@ assert 0 <= count <= n;
    return count;
}
