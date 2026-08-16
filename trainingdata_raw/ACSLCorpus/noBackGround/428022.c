#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) > 0 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (a)[i] > 0 && (a)[i] <= 1000000000);
    ensures 0 <= \result <= n;
    assigns \nothing;
 */
size_t func(size_t n, int *a)
{
    size_t count = 0;
    size_t i = 0;
    
    /*@ loop invariant ((((n)) > 0 && ((n)) <= 200000 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> ((a))[i] > 0 && ((a))[i] <= 1000000000) &&
      0 <= (i) <= (n) &&
      0 <= (count) <= (i));
        loop assigns i, count;
        loop variant n - i;
    */
    while (i < n) {
        int is_divisible = 1;
        size_t j = 0;
        
        /*@ loop invariant ((((n)) > 0 && ((n)) <= 200000 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> ((a))[i] > 0 && ((a))[i] <= 1000000000) &&
      0 <= (i) < (n) &&
      0 <= (j) <= (n) &&
      ((is_divisible) == 1 ==> \forall integer k; 0 <= k < (j) && k != (i) ==> (a)[(i)] % (a)[k] != 0));
            loop assigns j, is_divisible;
            loop variant n - j;
        */
        while (j < n) {
            if (i != j && a[i] % a[j] == 0) {
                is_divisible = 0;
            }
            j++;
        }
        
        if (is_divisible) {
            count++;
        }
        i++;
    }
    
    //@ assert count <= n;
    return count;
}
