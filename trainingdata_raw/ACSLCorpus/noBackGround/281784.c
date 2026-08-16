#include <stdbool.h>
#include <stddef.h>

/*@ requires n > 0 && n <= 100;
    requires \valid(a + (0 .. n-1));
    requires ((n) > 0 && (n) <= 100 &&
      \forall size_t i; 0 <= i < (n) ==> 1 <= (a)[i] <= 100);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(size_t n, const int *a) {
    int count = 0;
    size_t num = 0;
    
    /*@ loop invariant (0 <= (num) <= (n) &&
      0 <= (count) <= (num) &&
      (((n)) > 0 && ((n)) <= 100 &&
      \forall size_t i; 0 <= i < ((n)) ==> 1 <= ((a))[i] <= 100) &&
      \forall size_t k; 0 <= k < (num) ==> 1 <= (a)[k] <= 100);
        loop invariant num <= n;
        loop assigns count, num;
        loop variant n - num;
    */
    while (num < n) {
        //@ assert count <= num;
        if (a[num] == count + 1) {
            count = a[num];
        }
        num += 1;
        //@ assert count <= num;
    }
    return count;
}
