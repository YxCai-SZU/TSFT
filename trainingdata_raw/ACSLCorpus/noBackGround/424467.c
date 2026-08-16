#include <stdbool.h>
#include <stddef.h>

/*@ requires ((n) >= 1 && (n) <= 100000 &&
    \valid((h) + (0 .. (n)-1)) &&
    \forall integer i; 0 <= i < (n) ==> (h)[i] >= 1 && (h)[i] <= 1000000000);
    assigns \nothing;
    ensures 0 <= \result <= n-1;
*/
int func(int n, int *h) {
    int acc = 0;
    int cnt = 0;
    int prev = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n-1;
        loop invariant 0 <= acc <= i;
        loop invariant 0 <= cnt <= i;
        loop invariant \valid(h + (0 .. n-1));
        loop invariant \forall integer j; 0 <= j < n ==> h[j] >= 1 && h[j] <= 1000000000;
        loop assigns acc, cnt, prev, i;
        loop variant n - i;
    */
    while (i < n - 1) {
        int current = h[i];
        int next = h[i + 1];
        
        if (current < next) {
            cnt = 0;
        } else {
            cnt = cnt + 1;
            //@ assert cnt >= 0;
            acc = (acc > cnt) ? acc : cnt;
        }
        
        //@ assert 0 <= cnt <= i+1;
        //@ assert 0 <= acc <= i+1;
        
        prev = current;
        i = i + 1;
    }
    
    //@ assert 0 <= acc <= n-1;
    return acc;
}
