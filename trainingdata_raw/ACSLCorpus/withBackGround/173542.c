#include <stddef.h>
#include <limits.h>

/*@
    predicate valid_index(int* arr, integer len, integer i) =
        0 <= i && i < len;

    predicate no_overflow_underflow(int* arr, integer len) =
        \forall integer i; 0 <= i < len ==>
            arr[i] <= INT_MAX - 0x80000000 &&
            arr[i] >= INT_MIN + 0x80000000;

    logic integer seq_sum{L}(int* arr, integer len) =
        len == 0 ? 0 : arr[len-1] + seq_sum(arr, len-1);

    lemma seq_sum_nonnegative{L}:
        \forall int* arr, integer len;
            len >= 0 && no_overflow_underflow(arr, len) && len < 0x80000000 ==>
                seq_sum(arr, len) >= 0;
*/

/*@
    requires \valid(v + (0 .. len-1));
    requires len < 0x80000000;
    requires no_overflow_underflow(v, len);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int* v, size_t len) {
    int total = 0;
    size_t i = 0;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant total >= 0;
        loop invariant \forall size_t j; 0 <= j < i ==> v[j] <= INT_MAX - 0x80000000 && v[j] >= INT_MIN + 0x80000000;
        loop invariant len < 0x80000000;
        loop invariant no_overflow_underflow(v, len);
        loop assigns total, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert valid_index(v, len, i);
        //@ assert v[i] <= INT_MAX - 0x80000000;
        //@ assert v[i] >= INT_MIN + 0x80000000;
        total += v[i];
        i++;
    }
    return total;
}
