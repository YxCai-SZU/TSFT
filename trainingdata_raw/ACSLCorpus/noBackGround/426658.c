#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 2 && (n) <= 100000 &&
      \valid((aa) + (0 .. (n)-1)) &&
      \forall integer i; 0 <= i < (n) ==> (aa)[i] >= 1 && (aa)[i] <= 1000000000);
    assigns \nothing;
    ensures \result >= 0 && \result <= n;
*/
int func(size_t n, int *aa) {
    int cnt = 0;
    size_t i = 0;
    
    /*@ loop invariant ((i) >= 0 && (i) <= (n) &&
      (cnt) >= 0 && (cnt) <= (i) &&
      (((n)) >= 2 && ((n)) <= 100000 &&
      \valid(((aa)) + (0 .. ((n))-1)) &&
      \forall integer i; 0 <= i < ((n)) ==> ((aa))[i] >= 1 && ((aa))[i] <= 1000000000));
        loop assigns i, cnt;
        loop variant n - i;
    */
    while (i < n) {
        int a = aa[i];
        //@ assert a >= 1 && a <= 1000000000;
        
        if ((a & 1) == 0) {
            cnt += 1;
        }
        //@ assert cnt >= 0;
        //@ assert cnt <= i + 1;
        
        i += 1;
    }
    //@ assert i == n;
    //@ assert cnt >= 0 && cnt <= n;
    
    return cnt;
}
