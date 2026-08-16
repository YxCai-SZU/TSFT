#include <stddef.h>

/*@
    requires ((n) > 0 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (nums)[i] && (nums)[i] <= 1000000);
    ensures \result <= n;
    ensures \result >= 1;
    assigns \nothing;
*/
size_t count_operations(int* nums, size_t n) {
    size_t count;
    int current;
    size_t index;

    count = 1;
    current = nums[0];
    index = 1;

    /*@
        loop invariant 1 <= index <= n;
        loop invariant 1 <= count <= index;
        loop invariant ((n) > 0 &&
        \forall integer i; 0 <= i < (n) ==> 1 <= (nums)[i] && (nums)[i] <= 1000000);
        loop assigns count, current, index;
        loop variant n - index;
    */
    while (index < n) {
        int next;
        next = nums[index];

        //@ assert 1 <= next <= 1000000;
        if (current <= next) {
            count = count + 1;
            current = next;
        }
        index = index + 1;
    }
    return count;
}
