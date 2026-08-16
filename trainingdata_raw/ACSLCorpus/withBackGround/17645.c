#include <stdbool.h>
#include <stddef.h>

/*@
    predicate is_increasing{L}(unsigned int *arr, size_t len) =
        \forall size_t i; 0 <= i < len - 1 ==> arr[i] < arr[i + 1];
*/

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len >= 1;
    assigns \nothing;
    ensures \result == true <==> is_increasing(arr, len);
*/
bool is_increasing_sequence(unsigned int *arr, size_t len) {
    size_t i = 1;
    
    /*@
        loop invariant 1 <= i <= len;
        loop invariant \forall size_t j; 0 <= j < i - 1 ==> arr[j] < arr[j + 1];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 <= i - 1 < len;
        //@ assert 0 <= i < len;
        if (arr[i] <= arr[i - 1]) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    return 0;
}
