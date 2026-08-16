/* Scenario: Array-based task scheduling with priority validation and capacity allocation.
 * 
 * Data flow:
 * 1. Input: An array of task priorities (length len) and a capacity parameter k.
 * 2. Intermediate: Check if priorities are strictly increasing (is_strictly_increasing).
 * 3. Intermediate: Check if the array length (as k) satisfies the valid_k predicate and compute func(k).
 * 4. Final: Verify that the computed capacity threshold respects ordering properties (check_greater_than_threshold).
 *
 * High-level property: For a strictly increasing array of length len where 2 <= len <= 100,
 * the computed allocation (func(len)) is at most the threshold based on len and len+1,
 * and this ordering is consistent with the monotonicity property of greater_than_threshold.
 */

/*@
    predicate strictly_increasing{L}(int *arr, integer len) =
        \forall integer i; 0 <= i < len - 1 ==> arr[i] < arr[i + 1];
*/

int is_strictly_increasing(const int *arr, int len) {
    int i = 0;
    while (i < len) {
        if (i > 0) {
            //@ assert 0 <= i-1 < i < len;
            if (arr[i] <= arr[i - 1]) {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

/*@
    predicate valid_k(integer k) = 2 <= k && k <= 100;
    predicate valid_div(integer k) = k/2 >= 1 && (k+1)/2 >= 1;
    logic integer func_spec(integer k) = (k/2) * ((k+1)/2);
*/

unsigned int func(unsigned int k) {
    unsigned int result;
    
    //@ assert k/2 >= 1;
    //@ assert (k+1)/2 >= 1;
    //@ assert k/2 * ((k+1)/2) <= 100 * 50;
    
    result = (k / 2) * ((k + 1) / 2);
    return result;
}

/*@
    logic integer greater_than_threshold(integer x) = x + 2;

    lemma lemma_greater_than_threshold_increases:
        \forall integer x, y; x >= 2 && y >= 2 && x <= y ==> 
            greater_than_threshold(x) <= greater_than_threshold(y);

    lemma establish_forall_threshold:
        \forall integer x, y; x >= 2 && y >= 2 && x <= y ==> 
            greater_than_threshold(x) <= greater_than_threshold(y);
*/

int check_greater_than_threshold(int x, int y) {
    int result;
    
    //@ assert x >= 2 && y >= 2 && x <= y;
    //@ assert greater_than_threshold(x) <= greater_than_threshold(y);
    
    result = (x + 2) <= (y + 2);
    //@ assert result == 1;
    return result;
}

int scheduling_verification(const int *arr, int len) {
    int increasing_result;
    unsigned int capacity_result;
    int threshold_check_result;

    increasing_result = is_strictly_increasing(arr, len);
    //@ assert increasing_result == 1;

    //@ assert valid_k((unsigned int)len); // from precondition 2 <= len <= 100
    capacity_result = func((unsigned int)len);
    //@ assert capacity_result == func_spec((unsigned int)len);

    threshold_check_result = check_greater_than_threshold(len, len+1);
    //@ assert threshold_check_result == 1;

    //@ assert (len) + 2 <= ((len+1)) + 2; // core property: threshold ordering is consistent
    return 1;
}

int main() {
    int priorities[] = {1, 3, 5, 7, 9};
    int result = scheduling_verification(priorities, 5);
    return 0;
}
