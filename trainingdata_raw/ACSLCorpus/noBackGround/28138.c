#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires \forall size_t i; 0 <= i < n ==> 1 <= a[i] <= 100;
    ensures \result >= 0 && \result <= (int)n;
    assigns \nothing;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t num = 0;
    
    /*@ loop invariant ((num) <= (n) &&
      (count) >= 0 &&
      (count) <= (int)(num) &&
      (((n)) > 0 && ((n)) <= 100 &&
      \forall size_t i; 0 <= i < ((n)) ==> 1 <= ((a))[i] <= 100));
        loop assigns count, num;
        loop variant n - num;
    */
    while (num < n) {
        int value = a[num];
        //@ assert 1 <= value <= 100;
        
        if (value & 1) {
            count++;
        }
        num++;
    }
    
    return count;
}
