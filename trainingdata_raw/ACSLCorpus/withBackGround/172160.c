#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_odd(integer x) = (x & 1) != 0; */

/*@ predicate exists_odd_in_range(int *arr, integer len, integer start, integer end) =
        \exists integer j; start <= j < end && is_odd(arr[j]); */

/*@ lemma odd_exists_in_full_array:
        \forall int *arr, integer len, integer i;
            0 <= i < len && is_odd(arr[i]) ==> exists_odd_in_range(arr, len, 0, len); */

/*@ requires \valid_read(A + (0..len-1));
    requires len < 0x80000000;
    assigns \nothing;
    ensures 0 <= \result <= len;
    ensures \forall integer i; 0 <= i < len && is_odd(A[i]) ==> 
                exists_odd_in_range(A, len, 0, len);
 */
int count_odd_numbers(int *A, size_t len) {
    int count = 0;
    size_t i = 0;
    
    /*@ loop invariant 0 <= i <= len;
        loop invariant 0 <= count <= i;
        loop invariant \forall integer k; 0 <= k < i && is_odd(A[k]) ==> 
                        exists_odd_in_range(A, len, 0, len);
        loop invariant len < 0x80000000;
        loop assigns i, count;
        loop variant len - i;
     */
    while (i < len) {
        //@ assert 0 <= i < len;
        if ((A[i] & 1) != 0) {
            count++;
        }
        i++;
    }
    return count;
}

int main() {
    return 0;
}
