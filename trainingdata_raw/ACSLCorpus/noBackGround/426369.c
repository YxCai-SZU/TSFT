#include <stdbool.h>
/*@
    requires (1 <= (n) && (n) <= 100);
    requires \valid(nums + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 0 <= (nums)[i] && (nums)[i] <= 100);
    assigns \nothing;
    ensures 0 <= \result <= n;
    ensures (\forall integer i; 0 <= i < (n) ==> 0 <= (nums)[i] && (nums)[i] <= 100);
*/
int func(int n, int *nums) {
    int ans = 0;
    int i = 1;
    
    /*@
        loop invariant 1 <= i <= n + 1;
        loop invariant ((ans) >= 0 && (ans) <= (i) - 1 && (i) - 1 <= (n));
        loop invariant (\forall integer i; 0 <= i < (n) ==> 0 <= (nums)[i] && (nums)[i] <= 100);
        loop assigns ans, i;
        loop variant n + 1 - i;
    */
    while (i < n + 1) {
        int num = nums[i - 1];
        
        //@ assert 0 <= num <= 100;
        
        if ((i & 1) == 1) {
            if ((num & 1) == 1) {
                ans += 1;
            }
        }
        i += 1;
    }
    return ans;
}
