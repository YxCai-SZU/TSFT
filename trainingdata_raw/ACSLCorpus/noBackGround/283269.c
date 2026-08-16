#include <stdbool.h>
#include <stddef.h>

/*@
    requires 1 <= n <= 100;
    requires \valid(nums + (0 .. n-1));
    requires (\forall integer i; 0 <= i < (n) ==> 1 <= (nums)[i] <= 100);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int *nums) {
    int ans = 0;
    int num = 1;
    size_t index = 0;

    /*@
        loop invariant (0 <= (index) <= (n) &&
        0 <= (ans) <= (index) &&
        1 <= (num) <= (index) + 1 &&
        ((index) > 0 ==> \forall integer i; 0 <= i < (index) ==> 1 <= (nums)[i] <= 100) &&
        1 <= (n) <= 100 &&
        (\forall integer i; 0 <= i < ((n)) ==> 1 <= ((nums))[i] <= 100));
        loop invariant index <= n;
        loop assigns ans, num, index;
        loop variant n - index;
    */
    while (index < (size_t)n) {
        int s = nums[index];
        //@ assert 0 <= index < n;
        //@ assert 1 <= s <= 100;
        if (s >= num) {
            ans += 1;
            num += 1;
        }
        index += 1;
        //@ assert ans <= index;
        //@ assert num <= index + 1;
    }
    //@ assert ans <= n;
    return ans;
}
