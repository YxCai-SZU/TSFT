#include <stdbool.h>
#include <stddef.h>

/*@
  requires n > 0 && n <= 200000;
  requires \valid(a + (0..n-1));
  requires ((n) > 0 && (n) <= 200000 &&
      \forall integer k; 0 <= k < (n) ==> (a)[k] >= 1 && (a)[k] <= 1000000);
  assigns \nothing;
  ensures \result >= 0;
*/
int func(size_t n, int *a) {
    int count = 0;
    size_t i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count <= (int)i;
      loop invariant ((n) > 0 && (n) <= 200000 &&
      \forall integer k; 0 <= k < (n) ==> (a)[k] >= 1 && (a)[k] <= 1000000);
      loop invariant (\forall integer k; 0 <= k < (n) ==> (a)[k] == \at((a)[k], Pre));
      loop assigns i, count;
      loop variant n - i;
    */
    while (i < n) {
        bool is_divisible = false;
        size_t j = 0;
        
        /*@
          loop invariant 0 <= j <= n;
          loop invariant ((n) > 0 && (n) <= 200000 &&
      \forall integer k; 0 <= k < (n) ==> (a)[k] >= 1 && (a)[k] <= 1000000);
          loop invariant (\forall integer k; 0 <= k < (n) ==> (a)[k] == \at((a)[k], Pre));
          loop assigns j, is_divisible;
          loop variant n - j;
        */
        while (j < n) {
            if (i != j) {
                //@ assert i < n && j < n;
                int a_val = a[i];
                int b_val = a[j];
                int temp = b_val;
                
                /*@
                  loop invariant temp >= 0;
                  loop assigns temp;
                  loop variant temp;
                */
                while (temp >= a_val) {
                    temp -= a_val;
                }
                
                if (temp == 0) {
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
    return count;
}
