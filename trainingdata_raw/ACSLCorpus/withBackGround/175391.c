#include <stdbool.h>

/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;
*/

/*@
    lemma calc_example_2: \forall integer a, b; a < b ==> a <= b;
*/

/*@
    logic integer sum(integer a, integer b) = a + b;
*/

/*@
    requires is_valid_range(a, b);
    ensures \result >= 0;
    ensures \result <= a;
*/
int func(int a, int b) {
    int sum_val;
    int result;
    int remainder;
    int count;
    bool is_even;
    int temp_remainder;
    
    sum_val = a + b;
    result = 0;
    remainder = sum_val;
    count = 0;
    
    /*@
        loop invariant 0 <= remainder <= sum_val;
        loop invariant count >= 0;
        loop invariant count <= sum_val / 2;
        loop invariant remainder == sum_val - 2 * count;
        loop invariant is_valid_range(a, b);
        loop assigns remainder, count;
    */
    while (remainder >= 2) {
        remainder -= 2;
        count += 1;
    }
    
    result = count;
    is_even = true;
    temp_remainder = sum_val;
    
    /*@
        loop invariant 0 <= temp_remainder <= sum_val;
        loop invariant is_valid_range(a, b);
        loop assigns temp_remainder, is_even;
    */
    while (temp_remainder >= 2) {
        temp_remainder -= 2;
        is_even = !is_even;
    }
    
    if (is_even) {
        result = result * 2;
    } else {
        result = result * 2 + 1;
    }
    
    if (a < result) {
        //@ assert a >= 0;
        return a;
    } else {
        //@ assert a >= result;
        return result;
    }
}

int main() {
    return 0;
}
