#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(arr + (0 .. len-1));
    requires len > 0;
    assigns \nothing;
    ensures \result == true <==> (\forall integer i; 0 <= i < (len) ==> (arr)[i] >= 0);
 */
bool func(const int *arr, size_t len) {
    size_t i = 0;
    /*@
        loop invariant 0 <= i <= len;
        loop invariant \forall integer j; 0 <= j < i ==> arr[j] >= 0;
        loop invariant len > 0;
        loop assigns i;
        loop variant len - i;
     */
    while (i < len) {
        //@ assert 0 <= i < len;
        if (arr[i] < 0) {
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    return 0;
}
