/*@
    predicate strictly_increasing{L}(int *arr, integer len) =
        \forall integer j; 0 < j < len ==> arr[j-1] < arr[j];
*/

#include <stdbool.h>

/*@
    requires \valid(arr + (0..len-1));
    requires len > 1;
    assigns \nothing;
    ensures \result == 1 <==> strictly_increasing(arr, len);
*/
bool is_strictly_increasing(int *arr, int len) {
    int i = 1;
    /*@
        loop invariant 1 <= i <= len;
        loop invariant strictly_increasing(arr, i);
        loop assigns i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert 0 < i < len;
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
