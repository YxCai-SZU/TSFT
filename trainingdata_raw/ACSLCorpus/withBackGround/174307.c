#include <stdbool.h>
#include <stddef.h>

/*@
    predicate strictly_increasing(unsigned int *arr, integer len) =
        len >= 1 &&
        \forall integer i; 0 <= i < len - 1 ==> arr[i] < arr[i + 1];
 */

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len >= 1;
    assigns \nothing;
    ensures \result <==> strictly_increasing(arr, len);
 */
bool is_strictly_increasing(unsigned int *arr, size_t len) {
    size_t i = 0;
    
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] < arr[j + 1];
        loop assigns i;
        loop variant len - i;
     */
    while (i < len - 1) {
        //@ assert 0 <= i < len - 1;
        if (arr[i] >= arr[i + 1]) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    return 0;
}
