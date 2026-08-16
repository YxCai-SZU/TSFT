#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) >= 0 && (len) <= 0x7FFFFFFF);
    requires len <= 0x7FFFFFFF;
    ensures \result >= 0;
    ensures \result <= len;
    ensures (\forall integer i; 0 <= i < len && arr[i] == target ==> \result >= 1);
    ensures (\forall integer i; 0 <= i < len && arr[i] != target ==> \result <= len - 1);
    assigns \nothing;
*/
int count_occurrences(int *arr, size_t len, int target) {
    int count = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant count >= 0;
        loop invariant count <= i;
        loop invariant (\forall integer j; 0 <= j < i && arr[j] == target ==> count >= 1);
        loop invariant (\forall integer j; 0 <= j < i && arr[j] != target ==> count <= i - 1);
        loop assigns i, count;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert ((i) >= 0 && (i) <= (len) &&         (count) >= 0 && (count) <= (i) &&         (\forall integer j; 0 <= j < (i) ==> ((arr)[j] == (target) ==> (count) >= 1)) &&         (\forall integer j; 0 <= j < (i) ==> ((arr)[j] != (target) ==> (count) <= (i) - 1)));
        if (arr[i] == target) {
            count = count + 1;
        }
        i = i + 1;
    }
    //@ assert ((i) >= 0 && (i) <= (len) &&         (count) >= 0 && (count) <= (i) &&         (\forall integer j; 0 <= j < (i) ==> ((arr)[j] == (target) ==> (count) >= 1)) &&         (\forall integer j; 0 <= j < (i) ==> ((arr)[j] != (target) ==> (count) <= (i) - 1)));
    return count;
}
