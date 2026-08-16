#include <stdbool.h>
#include <stddef.h>

/* ===== Provided predicates and lemmas ===== */

/* predicate from snippet 1 */
/*@ predicate is_positive_array(int *arr, integer len) =
    \forall integer i; 0 <= i < len ==> arr[i] > 0 && arr[i] <= 1000;
*/

/*@ predicate condition_holds(int *arr, integer len) =
    \forall integer i; 0 <= i < len && arr[i] % 2 == 0 ==> 
        arr[i] % 3 == 0 || arr[i] % 5 == 0;
*/


/* predicate from snippet 3 */
/*@ predicate numbers_in_range(int *arr, integer len) =
    \forall integer i; 0 <= i < len ==> 0 <= arr[i] <= 100;
*/

/*@ predicate is_sorted(int a, int b, int c) =
    a < b && b < c;
*/

/* predicate from snippet 4 */
/*@ predicate side_in_range(integer s) = 0 <= s && s <= 1000;

    logic integer volume_cube(integer side) = side * side * side;

    lemma volume_cube_lemma:
        \forall integer side;
            side_in_range(side) ==>
            volume_cube(side) == side * side * side &&
            volume_cube(side) >= 0;
*/

/* ===== Provided functions (adapted for real-world scenario) ===== */

/* Function 1: validate that array elements satisfy condition_holds */
bool validate_array(size_t n, int a[]) {
    size_t i = 0;
    while (i < n) {
        int value = a[i];
        bool is_even = (value % 2) == 0;
        bool is_divisible_by_3_or_5 = (value % 3) == 0 || (value % 5) == 0;
        
        //@ assert value > 0 && value <= 1000;
        
        if (is_even && !is_divisible_by_3_or_5) {
            //@ assert !condition_holds(a, n);
            return false;
        }
        
        i++;
    }
    
    //@ assert condition_holds(a, n);
    return true;
}

/* Function 2: check sorted order of three numbers */
bool check_sorted(int *numbers) {
    int a = numbers[0];
    int b = numbers[1];
    int c = numbers[2];
    
    //@ assert a <= 100;
    //@ assert b <= 100;
    //@ assert c <= 100;
    
    return (a < b && b < c);
}

/* Function 3: compute sum of cubes of two side lengths */
int sum_of_cubes(const int* a, const int* b) {
    int x = *a;
    int y = *b;
    
    //@ assert side_in_range(x);
    //@ assert side_in_range(y);
    
    int cube_x = x * x * x;
    int cube_y = y * y * y;
    
    //@ assert cube_x == volume_cube(x);
    //@ assert cube_y == volume_cube(y);
    
    return cube_x + cube_y;
}

/* ===== Synthesized complex function: Real-world scenario ===== */
/* 
 * Scenario: 3D shape data processing - given an array of shape descriptors,
 * validate the array, extract the first three values as side lengths,
 * check if they are sorted, and compute the sum of cubes of the first two.
 * This simulates a pipeline for processing a batch of cube measurements.
 */

int process_shape_data(size_t n, int arr[]) {
    int result;
    
    bool valid = validate_array(n, arr);
    
    if (!valid) {
        //@ assert !condition_holds(arr, n);
        return -1;
    }
    
    //@ assert condition_holds(arr, n);
    
    bool sorted = check_sorted(arr);
    
    if (!sorted) {
        //@ assert !is_sorted(arr[0], arr[1], arr[2]);
        return -1;
    }
    
    //@ assert is_sorted(arr[0], arr[1], arr[2]);
    
    result = sum_of_cubes(&arr[0], &arr[1]);
    
    //@ assert result == volume_cube(arr[0]) + volume_cube(arr[1]);
    
    //@ assert (result >= 0) ==> (condition_holds(arr, n) && is_sorted(arr[0], arr[1], arr[2]) && result == volume_cube(arr[0]) + volume_cube(arr[1]));
    
    return result;
}
