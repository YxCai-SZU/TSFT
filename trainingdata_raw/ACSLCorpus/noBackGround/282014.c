#include <stdbool.h>
/*@
    requires ((1 <= ((n)) <= 1000000) &&
        \valid((nums) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (1 <= ((nums)[i]) <= 1000000000));
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
int func(int n, int *nums) {
    int top = 0;
    int cur = 0;
    int index = 0;
    
    /*@
        loop invariant 0 <= index <= n;
        loop invariant 0 <= top <= index;
        loop invariant index > 0 ==> \forall integer i; 0 <= i < index ==> (1 <= (nums[i]) <= 1000000000);
        loop invariant ((1 <= ((n)) <= 1000000) &&
        \valid((nums) + (0 .. (n)-1)) &&
        \forall integer i; 0 <= i < (n) ==> (1 <= ((nums)[i]) <= 1000000000));
        loop assigns top, cur, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        int a = nums[index];
        if (cur <= a) {
            top += 1;
            cur = a;
        }
        index += 1;
    }
    return top;
}
