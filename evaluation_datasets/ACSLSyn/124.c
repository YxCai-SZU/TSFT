#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_range(int *arr, integer n) =
        n > 0 &&
        \forall integer i; 0 <= i < n ==> 1 <= arr[i] <= 1000;

    predicate condition_holds(int *arr, integer n) =
        \forall integer i; 0 <= i < n ==> 
            (arr[i] % 2 == 0 ==> (arr[i] % 3 == 0 || arr[i] % 5 == 0));
*/

bool check_array_condition(size_t n, int *arr) {
    size_t index = 0;
    while (index < n) {
        int value = arr[index];
        if (value % 2 == 0) {
            if (value % 3 != 0 && value % 5 != 0) {
                return false;
            }
        }
        index++;
    }
    return true;
}

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate result_in_range(integer r) = 0 <= r && r <= 1000;
*/

/*@
    logic integer compute_result(integer a) = (a * 3) / 2;
    
    lemma multiplication_bound: \forall integer a; a_in_range(a) ==> a * 3 <= 300;
    lemma division_bound: \forall integer a; a_in_range(a) && a * 3 <= 300 ==> (a * 3) / 2 <= 150;
*/

int32_t compute_value(uint32_t a)
{
    int32_t result;
    
    result = ((a * 3) / 2);
    
    return result;
}

int32_t process_configuration_data(size_t n, int *arr) {
    bool is_valid = check_array_condition(n, arr);
    
    int32_t derived_value;
    if (is_valid) {
        derived_value = compute_value((uint32_t)arr[0]);
    } else {
        derived_value = compute_value((uint32_t)arr[0]);
    }
    
    return derived_value;
}
