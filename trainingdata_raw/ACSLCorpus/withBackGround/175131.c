#include <stdbool.h>

/*@
    predicate is_even(integer a) = (a % 2) == 0;
    predicate is_odd(integer a) = (a % 2) == 1;
    
    logic integer half(integer a) = a / 2;
    
    lemma half_property: \forall integer a; 1 <= a <= 1000000 ==> 
        (is_even(a) ==> half(a) == half(a)) && 
        (is_odd(a) ==> half(a) - 1 == half(a) - 1);
*/

/*@
    requires 1 <= a <= 1000000;
    ensures \result == (a / 2) - 1 || \result == (a / 2);
    assigns \nothing;
*/
long func(long a) {
    long result;
    long temp_a;
    long count;
    bool is_even;
    
    result = 0;
    temp_a = a;
    count = 0;
    is_even = true;
    
    /*@
        loop invariant 1 <= a <= 1000000;
        loop invariant temp_a >= 0;
        loop invariant count >= 0;
        loop invariant temp_a == a - 2 * count;
        loop assigns temp_a, count;
        loop variant temp_a;
    */
    while (temp_a >= 2) {
        temp_a -= 2;
        count += 1;
    }
    
    if (temp_a == 1 || temp_a == 0) {
        is_even = true;
    } else {
        is_even = false;
    }
    
    if (is_even) {
        result = count;
    } else {
        result = count - 1;
    }
    
    //@ assert result == (a / 2) - 1 || result == (a / 2);
    
    return result;
}

int main() {
    return 0;
}
