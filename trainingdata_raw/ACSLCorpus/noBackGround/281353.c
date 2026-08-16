#include <stdint.h>
#include <stdbool.h>

/*@
    requires 3 <= n <= 20;
    requires \valid(a + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= a[i] <= n;
    requires \forall integer i; 0 <= i < n-1 ==> a[i] != a[i+1];
    assigns \nothing;
    ensures \result >= 0;
    ensures \result <= n-2;
*/
int32_t func(int32_t n, int64_t *a) {
    int32_t cnt = 0;
    int32_t i = 1;
    
    /*@
        loop invariant 1 <= i <= n-1;
        loop invariant cnt >= 0;
        loop invariant cnt <= i-1;
        loop invariant (3 <= (n) <= 20 &&
        \valid((a) + (0 .. (n)-1)) &&
        \forall integer j; 0 <= j < (n) ==> 1 <= (a)[j] <= (n) &&
        \forall integer j; 0 <= j < (n)-1 ==> (a)[j] != (a)[j+1]);
        loop assigns cnt, i;
        loop variant n-i;
    */
    while (i < n - 1) {
        //@ assert (3 <= (n) <= 20 &&         \valid((a) + (0 .. (n)-1)) &&         \forall integer j; 0 <= j < (n) ==> 1 <= (a)[j] <= (n) &&         \forall integer j; 0 <= j < (n)-1 ==> (a)[j] != (a)[j+1]);
        
        if ((a[i-1] < a[i] && a[i] < a[i+1]) || 
            (a[i-1] > a[i] && a[i] > a[i+1])) {
            cnt += 1;
        }
        
        i += 1;
    }
    
    //@ assert cnt >= 0;
    //@ assert cnt <= n-2;
    return cnt;
}
