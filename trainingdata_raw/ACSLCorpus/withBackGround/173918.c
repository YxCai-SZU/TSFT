#include <stdbool.h>

/*@
    predicate all_unique(int *arr, integer len) =
        \forall integer x, y; 0 <= x < y < len ==> arr[x] != arr[y];

    predicate max_in_prefix(int *arr, integer i, int max_val) =
        \exists integer x; 0 <= x < i && arr[x] == max_val;

    predicate leq_in_prefix(int *arr, integer i, int max_val) =
        \forall integer x; 0 <= x < i ==> arr[x] <= max_val;
*/

/*@
    requires len > 0;
    requires \valid_read(arr + (0 .. len-1));
    requires all_unique(arr, len);
    ensures \exists integer x; 0 <= x < len && arr[x] == \result;
    ensures \forall integer x; 0 <= x < len ==> arr[x] <= \result;
*/
int max_unique(const int *arr, int len) {
    int max_value;
    int i;

    max_value = arr[0];
    i = 1;

    /*@
        loop invariant 0 <= i <= len;
        loop invariant leq_in_prefix(arr, i, max_value);
        loop invariant max_in_prefix(arr, i, max_value);
        loop invariant all_unique(arr, len);
        loop assigns max_value, i;
        loop variant len - i;
    */
    while (i < len) {
        //@ assert all_unique(arr, len);
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
        i = i + 1;
    }
    //@ assert \forall integer x; 0 <= x < len ==> arr[x] <= max_value;
    return max_value;
}
