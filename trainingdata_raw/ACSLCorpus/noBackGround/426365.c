#include <stdbool.h>
#include <stddef.h>

/*@ requires ((len) >= 1 && (len) <= 200000 &&
    \forall integer i; 0 <= i < (len) ==> (a)[i] >= 1 && (a)[i] <= 1000000);
    ensures \result >= -1 && \result <= (int)len;
*/
int func(int *a, size_t len) {
    int count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant (0 <= (count) <= (i) && (i) <= (len));
        loop invariant ((len) >= 1 && (len) <= 200000 &&
    \forall integer i; 0 <= i < (len) ==> (a)[i] >= 1 && (a)[i] <= 1000000);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        bool divisible = false;
        size_t j = 0;
        
        /*@ loop invariant 0 <= j <= i;
            loop invariant ((len) >= 1 && (len) <= 200000 &&
    \forall integer i; 0 <= i < (len) ==> (a)[i] >= 1 && (a)[i] <= 1000000);
            loop assigns j, divisible;
            loop variant i - j;
        */
        while (j < i) {
            //@ assert j < len && i < len;
            if (j < len && i < len) {
                int div_result = a[i] % a[j];
                if (div_result == 0) {
                    divisible = true;
                }
            }
            j++;
        }
        
        if (!divisible) {
            count++;
        }
        i++;
    }
    
    if (count == 0) {
        return -1;
    } else {
        return count;
    }
}
