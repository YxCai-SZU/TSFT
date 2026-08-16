#include <stddef.h>
#include <stdbool.h>

/*@ requires ((n) >= 2 && (n) <= 50 &&
    \valid((a) + (0 .. (n)-1)) &&
    \forall integer j; 0 <= j < (n) ==> (a)[j] >= 100 && (a)[j] <= 200);
    assigns \nothing;
    ensures 0 <= \result <= n-2;
*/
size_t func(size_t n, int *a) {
    size_t cnt = 0;
    size_t i = 1;
    
    /*@ loop invariant 1 <= i <= n-1;
        loop invariant cnt >= 0;
        loop invariant cnt <= i-1;
        loop invariant ((n) >= 2 && (n) <= 50 &&
    \valid((a) + (0 .. (n)-1)) &&
    \forall integer j; 0 <= j < (n) ==> (a)[j] >= 100 && (a)[j] <= 200);
        loop assigns cnt, i;
        loop variant n-i;
    */
    while (i < n - 1) {
        //@ assert a[i-1] >= 100 && a[i-1] <= 200;
        //@ assert a[i] >= 100 && a[i] <= 200;
        //@ assert a[i+1] >= 100 && a[i+1] <= 200;
        
        if ((a[i - 1] < a[i] && a[i] < a[i + 1]) || 
            (a[i - 1] > a[i] && a[i] > a[i + 1])) {
            cnt += 1;
        }
        i += 1;
    }
    return cnt;
}
