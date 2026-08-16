#include <stddef.h>
#include <stdbool.h>

/*@
    requires \valid(arr + (0 .. len-1));
    requires ((len) >= 1 && (len) <= 100000 &&
        \forall integer i; 0 <= i < (len) ==> 1 <= (arr)[i] && (arr)[i] <= 1000000000);
    assigns \nothing;
    ensures \result >= 1;
    ensures \result <= len;
*/
size_t func(int *arr, size_t len) {
    int m;
    size_t count;
    size_t index;

    m = arr[0];
    count = 1;
    index = 1;

    /*@
        loop invariant index <= len;
        loop invariant count >= 1;
        loop invariant count <= index;
        loop invariant \forall integer j; 0 <= j < index ==> m <= arr[j];
        loop assigns m, count, index;
        loop variant len - index;
    */
    while (index < len) {
        int i = arr[index];
        if (i < m) {
            m = i;
            count = count + 1;
        }
        index = index + 1;
    }

    //@ assert count >= 1 && count <= len;
    return count;
}
