#include <stdbool.h>

/*@
    requires 1 <= n <= 20;
    requires \valid(v + (0..n-1));
    requires \valid(c + (0..n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] <= 50);
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (c)[i] <= 50);
    assigns \nothing;
    ensures \result >= 0;
*/
int func(int n, int* v, int* c) {
    int ans = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant ans >= 0;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (v)[i] <= 50);
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (c)[i] <= 50);
        loop invariant ans <= ((index) * 49);
        loop assigns ans, index;
        loop variant n - index;
    */
    while (index < n) {
        int x = v[index];
        int y = c[index];
        
        //@ assert 1 <= x <= 50 && 1 <= y <= 50;
        
        int diff = x - y;
        if (diff > 0) {
            ans += diff;
        }
        index++;
    }
    return ans;
}
