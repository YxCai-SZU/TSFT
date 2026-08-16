#include <stdbool.h>
/*@
    requires n > 0 && n <= 100;
    requires \valid(arr + (0 .. n-1));
    requires \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 100;
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int *arr) {
    int count = 0;
    int index = 0;
    /*@
        loop invariant (0 <= (index) <= (n) &&
        0 <= (count) <= (index) &&
        (((n)) > 0 && ((n)) <= 100 &&
        \valid(((arr)) + (0 .. ((n))-1)) &&
        \forall integer i; 0 <= i < ((n)) ==> 1 <= ((arr))[i] <= 100));
        loop invariant index <= n;
        loop assigns count, index;
        loop variant n - index;
    */
    while (index < n) {
        //@ assert 0 <= index < n;
        int i = arr[index];
        if ((index & 1) == 0 && (i & 1) == 1) {
            count += 1;
        }
        index += 1;
    }
    //@ assert index == n;
    //@ assert count <= n;
    return count;
}
