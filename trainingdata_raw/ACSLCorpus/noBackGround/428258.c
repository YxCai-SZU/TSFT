#include <stddef.h>

/*@ requires n >= 1 && n <= 200000;
    requires \valid(p + (0 .. n-1));
    requires ((n) >= 1 && (n) <= 200000 &&
      \forall integer i; 0 <= i < (n) ==> (p)[i] >= 1 && (p)[i] <= (n) &&
      \forall integer i, j; 0 <= i < j < (n) ==> (p)[i] != (p)[j]);
    ensures \result >= 1 && \result <= n;
*/
int func(size_t n, int *p) {
    int cnt = 1;
    size_t index = 1;
    
    /*@ loop invariant ((index) <= (n) &&
      (cnt) >= 1 &&
      (cnt) <= (index) &&
      (((n)) >= 1 && ((n)) <= 200000 &&
      \forall integer i; 0 <= i < ((n)) ==> ((p))[i] >= 1 && ((p))[i] <= ((n)) &&
      \forall integer i, j; 0 <= i < j < ((n)) ==> ((p))[i] != ((p))[j]) &&
      ((index) > 1 ==> \forall integer k; 0 <= k < (index) ==> (p)[k] >= 1 && (p)[k] <= (n)));
        loop invariant n >= 1 && n <= 200000;
        loop assigns cnt, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert index >= 1 && index < n;
        
        if (p[index - 1] <= p[index]) {
            cnt += 1;
        }
        
        index += 1;
    }
    
    //@ assert cnt >= 1 && cnt <= n;
    return cnt;
}
