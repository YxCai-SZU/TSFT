#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 2 && (n) <= 200000 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer k; 0 <= k < (n) ==> (a)[k] >= 1 && (a)[k] <= 1000000000);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
unsigned int func(unsigned int n, int *a) {
    unsigned int cnt = 0;
    unsigned int i = 0;
    
    /*@ loop invariant ((i) >= 0 && (i) <= (n) &&
      (cnt) >= 0 && (cnt) <= (i) &&
      (((n)) >= 2 && ((n)) <= 200000 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer k; 0 <= k < ((n)) ==> ((a))[k] >= 1 && ((a))[k] <= 1000000000));
        loop assigns i, cnt;
        loop variant n - i;
    */
    while (i < n) {
        bool is_divisible = true;
        unsigned int j = 1;
        
        /*@ loop invariant ((j) >= 1 && (j) <= (n) &&
      (((n)) >= 2 && ((n)) <= 200000 &&
      \valid(((a)) + (0 .. ((n))-1)) &&
      \forall integer k; 0 <= k < ((n)) ==> ((a))[k] >= 1 && ((a))[k] <= 1000000000));
            loop assigns j, is_divisible;
            loop variant n - j;
        */
        while (j < n) {
            if (i != j) {
                //@ assert i < n && j < n;
                if (a[i] % a[j] == 0) {
                    is_divisible = false;
                    break;
                }
            }
            j++;
        }
        
        if (is_divisible) {
            cnt++;
        }
        i++;
    }
    
    //@ assert cnt >= 0 && cnt <= n;
    return cnt;
}
