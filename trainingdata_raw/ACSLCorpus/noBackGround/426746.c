#include <stddef.h>
#include <stdint.h>

/*@ requires n > 0 && n <= 100;
    requires \valid_read(numbers + (0 .. n-1));
    requires (\forall int i; (0 <= (i) < ((n))) ==> (1 <= ((numbers)[i]) <= 100));
    ensures \result >= 0 && \result <= 200;
    assigns \nothing;
*/
int func(int n, int* numbers) {
    int max_val = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant max_val >= 0 && max_val <= 200;
        loop invariant \forall int j; 0 <= j < i ==> (1 <= (numbers[j]) <= 100);
        loop invariant n > 0 && n <= 100;
        loop invariant (\forall int i; (0 <= (i) < ((n))) ==> (1 <= ((numbers)[i]) <= 100));
        loop assigns max_val, i;
        loop variant n - i;
    */
    while (i < n) {
        int x = numbers[i];
        unsigned int x_unsigned = (x < 0) ? (unsigned int)(-x) : (unsigned int)x;
        unsigned int max_val_unsigned = (max_val < 0) ? (unsigned int)(-max_val) : (unsigned int)max_val;
        
        //@ assert x >= 1 && x <= 100;
        //@ assert max_val >= 0 && max_val <= 200;
        
        if (x_unsigned > max_val_unsigned) {
            max_val = x;
        }
        
        //@ assert max_val >= 0 && max_val <= 200;
        i++;
    }
    
    //@ assert max_val >= 0 && max_val <= 200;
    return max_val;
}
