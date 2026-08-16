#include <stdbool.h>
#include <stddef.h>

/*@ requires 1 <= n <= 100000;
    requires 1 <= k <= 500;
    requires \valid(heights + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (heights)[i] <= 500);
    assigns \nothing;
    ensures 0 <= \result <= n;
*/
int func(int n, int k, int *heights) {
    int cnt = 0;
    int index = 0;
    
    /*@ loop invariant 0 <= index <= n;
        loop invariant (0 <= (cnt) <= (index) <= (n));
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (heights)[i] <= 500);
        loop assigns cnt, index;
        loop variant n - index;
    */
    while (index < n) {
        int height = heights[index];
        //@ assert 1 <= height <= 500;
        if (height >= k) {
            cnt += 1;
        }
        index += 1;
    }
    return cnt;
}
