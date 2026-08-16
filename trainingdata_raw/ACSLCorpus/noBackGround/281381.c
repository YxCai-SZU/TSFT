#include <stdbool.h>
/*@
    requires 3 <= n <= 20;
    requires \valid(p + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= p[i] <= n;
    requires \forall integer i; 0 <= i < n-1 ==> p[i] != p[i+1];
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int *p) {
    int res = 0;
    int i = 1;
    
    /*@
        loop invariant (1 <= (i) <= (n)-1 &&
        (res) >= 0 &&
        (3 <= ((n)) <= 20 &&
        \valid(((p)) + (0 .. ((n))-1)) &&
        \forall integer j; 0 <= j < ((n)) ==> 1 <= ((p))[j] <= ((n)) &&
        \forall integer j; 0 <= j < ((n))-1 ==> ((p))[j] != ((p))[j+1]) &&
        (res) <= (i));
        loop assigns i, res;
        loop variant n - i;
    */
    while (i < n - 1) {
        //@ assert 0 <= i-1 < n && 0 <= i < n && 0 <= i+1 < n;
        
        if ((p[i - 1] < p[i] && p[i] < p[i + 1]) ||
            (p[i - 1] > p[i] && p[i] > p[i + 1])) {
            res = res + 1;
        }
        
        i = i + 1;
    }
    
    //@ assert res <= n;
    return res;
}
