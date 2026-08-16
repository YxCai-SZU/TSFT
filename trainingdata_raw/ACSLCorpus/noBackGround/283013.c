#include <stdbool.h>
#include <stddef.h>

/*@ requires (1 <= (n) <= 1000000);
    requires n >= 1;
    requires \valid(numbers + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
    ensures \result >= 0;
    ensures \result <= n;
*/
size_t func(int n, int *numbers) {
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant (1 <= (n) <= 1000000);
        loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < (size_t)n) {
        bool is_divisible = false;
        size_t j = 1;
        
        /*@ loop invariant 1 <= j <= n;
            loop invariant (1 <= (n) <= 1000000);
            loop invariant (\forall integer i; 0 <= i < (n) ==> (1 <= ((numbers)[i]) <= 1000000000));
            loop invariant j <= n;
            loop assigns j, is_divisible;
            loop variant n - j;
        */
        while (j < (size_t)n) {
            if (i != j) {
                int num = numbers[i];
                int divisor = numbers[j];
                int remainder = num;
                
                /*@ loop invariant remainder >= 0;
                    loop assigns remainder;
                    loop variant remainder;
                */
                while (remainder >= divisor) {
                    remainder -= divisor;
                }
                
                //@ assert remainder >= 0;
                if (remainder == 0) {
                    is_divisible = true;
                }
            }
            j++;
        }
        
        if (!is_divisible) {
            count++;
        }
        i++;
    }
    
    //@ assert count >= 0;
    //@ assert count <= n;
    return count;
}
