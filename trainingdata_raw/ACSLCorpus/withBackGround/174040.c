#include <stdbool.h>
#include <stddef.h>

/*@
    predicate sorted(unsigned int *arr, integer len) =
        \forall integer i; 0 <= i < len - 1 ==> arr[i] <= arr[i + 1];
*/

/*@
    requires \valid_read(arr + (0 .. len - 1));
    assigns \nothing;
    ensures \result <==> sorted(arr, len);
*/
bool is_sorted(const unsigned int *arr, size_t len) {
    size_t i = 0;
    
    if (len < 2) {
        //@ assert sorted(arr, len);
        return true;
    }
    
    /*@
        loop invariant 0 <= i <= len - 1;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] <= arr[j + 1];
        loop assigns i;
        loop variant len - i;
    */
    while (i < len - 1) {
        if (arr[i] > arr[i + 1]) {
            //@ assert !sorted(arr, len);
            return false;
        }
        i = i + 1;
    }
    
    //@ assert sorted(arr, len);
    return true;
}

int main() {
    return 0;
}
