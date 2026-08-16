#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

/*@ predicate is_sum(integer a, integer b, integer c) =
      a == b + c || b == a + c || c == a + b;
*/

/*@ predicate all_equal(integer a, integer b, integer c) =
      a == b && b == c;
*/

/*@ lemma sum_bounds:
      \forall integer a, b, c;
        1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9 ==>
        a + b <= 18 && a + c <= 18 && b + c <= 18;
*/

bool func1(unsigned int a, unsigned int b, unsigned int c)
{
    bool result;
    result = (a == b + c || b == a + c || c == a + b) || (a == b && b == c);
    return result;
}

/*@
    predicate f(integer seq, integer i) = seq >= i;
    logic integer seq_at{L}(uint64_t *arr, integer i) = arr[i];
*/

uint64_t get_element_check_property(uint64_t *arr, size_t len, size_t i) {
    uint64_t ret;
    ret = arr[i];
    return ret;
}

/*@ predicate is_mod_three(integer x) = x % 3 == 0; */

bool func3(unsigned int a, unsigned int b)
{
    return (a % 3 == 0) || (b % 3 == 0) || ((a + b) % 3 == 0);
}

bool validate_digit_array(uint64_t *arr) {
    uint64_t a, b, c;
    bool sum_check, mod_check;
    
    a = get_element_check_property(arr, 3, 0);
    b = get_element_check_property(arr, 3, 1);
    c = get_element_check_property(arr, 3, 2);
    
    sum_check = func1((unsigned int)a, (unsigned int)b, (unsigned int)c);
    mod_check = func3((unsigned int)a, (unsigned int)b);
    
    return sum_check && mod_check;
}
