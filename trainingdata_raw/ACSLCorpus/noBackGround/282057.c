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
    int ans = 0;
    int i = 0;
    
    /*@ loop invariant 0 <= i <= n;
        loop invariant 0 <= ans <= i;
        loop invariant (\forall integer i; 0 <= i < (n) ==> 1 <= (heights)[i] <= 500);
        loop invariant 1 <= n <= 100000;
        loop invariant 1 <= k <= 500;
        loop assigns ans, i;
    */
    while (i < n) {
        int hi = heights[i];
        if (hi >= k) {
            ans += 1;
        }
        i += 1;
    }
    return ans;
}
