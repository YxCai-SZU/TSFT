#include <stdbool.h>

/*@ requires \valid(arr + (0 .. len-1));
    requires \forall integer i; 0 <= i < len - 1 ==> arr[i] <= arr[i + 1];
    ensures \result == true;
*/
bool is_sorted_example(int *arr, int len) {
    bool sorted;
    //@ assert (\forall integer i; 0 <= i < (len) - 1 ==> (arr)[i] <= (arr)[i + 1]);
    sorted = true;
    return sorted;
}

/*@ requires \valid(arr + (0 .. len-1));
    requires \forall integer i; 0 <= i < len ==> ((arr[i]) >= (min_val) && (arr[i]) <= (max_val));
    ensures \result == true;
*/
bool is_array_in_range_example(int *arr, int len, int min_val, int max_val) {
    bool within_range;
    //@ assert (\forall integer i; 0 <= i < (len) ==> (((arr)[i]) >= ((min_val)) && ((arr)[i]) <= ((max_val))));
    within_range = true;
    return within_range;
}
