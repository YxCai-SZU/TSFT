#include <stddef.h>
#include <stdbool.h>

/*@ requires ((n) >= 2 && (n) <= 100000 &&
    \valid((a) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
    assigns a[0..n-1];
    ensures \result >= 0 && \result <= n-1;
*/
size_t func(size_t n, int *a) {
    int *an;
    size_t cnt;
    size_t i;
    
    //@ assert ((n) >= 2 && (n) <= 100000 &&     \valid((a) + (0 .. (n)-1)) &&     \forall integer i; 0 <= i < (n) ==> (a)[i] >= 1 && (a)[i] <= 1000000000);
    an = a;
    cnt = 0;
    i = 0;
    
    /*@ loop invariant (0 <= (i) && (i) <= (n)-1 &&
    \valid((an) + (0 .. (n)-1)) &&
    (cnt) >= 0 && (cnt) <= (i) &&
    \forall integer j; 0 <= j < (n) ==> (an)[j] >= 1 && (an)[j] <= 1000000000 &&
    (n) >= 2 && (n) <= 100000);
        loop assigns i, cnt, an[0..n-1];
        loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert (0 <= (i) && (i) <= (n)-1 &&     \valid((an) + (0 .. (n)-1)) &&     (cnt) >= 0 && (cnt) <= (i) &&     \forall integer j; 0 <= j < (n) ==> (an)[j] >= 1 && (an)[j] <= 1000000000 &&     (n) >= 2 && (n) <= 100000);
        if (an[i] == 2 && i < n - 1) {
            //@ assert an[i] == 2;
            cnt = cnt + 1;
            an[i] = 3;
            //@ assert an[i] == 3;
        }
        i = i + 1;
        //@ assert i <= n-1;
    }
    //@ assert cnt <= n-1;
    return cnt;
}
