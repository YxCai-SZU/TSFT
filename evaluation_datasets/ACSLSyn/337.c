#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* First function: square computation */
/*@ predicate square_precondition(integer x) = x <= 46340; */
/*@ predicate square_postcondition(integer x, integer result) = result == x * x; */

uint32_t square_fn(uint32_t x) {
    //@ assert x * x <= 2147395600;
    return x * x;
}

/* Second function: range analysis */
/*@ predicate is_valid_range(int* arr, integer len) =
        len >= 1 &&
        \forall integer i; 0 <= i < len ==> arr[i] >= 1 && arr[i] <= 100;
*/

/*@ predicate max_ge_upto(int* arr, integer len, integer idx, int max_val) =
        \forall integer j; 0 <= j < idx ==> max_val >= arr[j];
*/

/*@ predicate min_le_upto(int* arr, integer len, integer idx, int min_val) =
        \forall integer j; 0 <= j < idx ==> min_val <= arr[j];
*/

/*@ lemma diff_bound: \forall int max_val, min_val;
        max_val >= 1 && max_val <= 100 && min_val >= 1 && min_val <= 100 ==> 
        max_val - min_val <= 100 - 1;
*/

int func(int* arr, size_t len) {
    int max_value;
    int min_value;
    size_t i;
    
    max_value = arr[0];
    min_value = arr[0];
    i = 1;
    
    while (i < len) {
        if (arr[i] > max_value) {
            max_value = arr[i];
        }
        if (arr[i] < min_value) {
            min_value = arr[i];
        }
        i++;
    }
    
    //@ assert max_value - min_value <= 100 - 1;
    
    return max_value - min_value;
}

/* Third function: triangle validation */
/*@ predicate is_valid_triangle(integer a, integer b, integer c) =
      a > 0 && b > 0 && c > 0 &&
      a <= 100 && b <= 100 && c <= 100 &&
      (a + b == c || b + c == a || c + a == b);
*/

bool func_triangle(unsigned long v[3]) {
    unsigned long a;
    unsigned long b;
    unsigned long c;
    bool result;

    //@ assert v[0] > 0 && v[1] > 0 && v[2] > 0;
    a = v[0];
    b = v[1];
    c = v[2];

    if (a + b == c || b + c == a || c + a == b) {
        result = true;
    } else {
        result = false;
    }

    //@ assert result == (a + b == c || b + c == a || c + a == b);
    return result;
}

/* Synthesized function: process triangle data and compute square of range */
uint32_t process_triangle_data(int* arr, size_t len) {
    int range_diff;
    unsigned long triangle_sides[3];
    bool is_valid;
    uint32_t result;
    
    range_diff = func(arr, len);
    
    triangle_sides[0] = (unsigned long)arr[0];
    triangle_sides[1] = (unsigned long)arr[1];
    triangle_sides[2] = (unsigned long)arr[2];
    is_valid = func_triangle(triangle_sides);
    
    if (is_valid) {
        //@ assert range_diff <= 46340;
        result = square_fn((uint32_t)range_diff);
    } else {
        result = 0;
    }
    
    //@ assert (is_valid ==> result == (uint32_t)(range_diff * range_diff)) && (!is_valid ==> result == 0);
    
    return result;
}

int main() {
    int v[3] = {1, 2, 3};
    uint32_t final_result;
    
    //@ assert is_valid_range(&v[0], 3);
    final_result = process_triangle_data(&v[0], 3);
    
    return 0;
}
