#include <stdbool.h>
#include <stddef.h>

/*@
    predicate valid_index_range(integer i) = 0 <= i <= 2;
    predicate valid_value(integer v) = 1 <= v <= 13;
    predicate array_valid(int *arr, integer len) = 
        len >= 3 &&
        \valid(arr + (0 .. 2)) &&
        valid_value(arr[0]) &&
        valid_value(arr[1]) &&
        valid_value(arr[2]);
*/

/*@
    requires array_valid(a, len);
    ensures \result == (a[1] == a[2] || a[0] == a[2] || a[1] == a[0]);
*/
bool func(int *a, size_t len) {
    int i;
    
    i = 0;
    /*@
        loop invariant 0 <= i <= 3;
        loop invariant array_valid(a, len);
        loop assigns i;
        loop variant 3 - i;
    */
    while (i < 3) {
        //@ assert valid_index_range(i);
        if (a[i] > 13 || a[i] < 1) {
            return false;
        }
        i = i + 1;
    }
    
    //@ assert valid_value(a[0]) && valid_value(a[1]) && valid_value(a[2]);
    return (a[1] == a[2]) || (a[0] == a[2]) || (a[1] == a[0]);
}

int main() {
    return 0;
}
