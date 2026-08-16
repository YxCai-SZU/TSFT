#include <stddef.h>

/*@ requires ((n) > 0 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> -100 <= (a)[i] <= 100);
    ensures \result >= 0 && \result <= n;
    assigns \nothing;
*/
int func(size_t n, int *a) {
    int pos_count = 0;
    size_t i = 0;
    
    /*@ loop invariant ((i) >= 0 && (i) <= (n) &&
      (pos_count) >= 0 && (pos_count) <= (i) &&
      \forall integer j; 0 <= j < (i) ==> ((a)[j] > 0 ==> (pos_count) >= 1));
        loop invariant ((n) > 0 && (n) <= 100 &&
      \valid((a) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> -100 <= (a)[i] <= 100);
        loop assigns i, pos_count;
        loop variant n - i;
    */
    while (i < n) {
        if (a[i] > 0) {
            pos_count += 1;
        }
        i += 1;
    }
    
    //@ assert pos_count >= 0 && pos_count <= n;
    return pos_count;
}
