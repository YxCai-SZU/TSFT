#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a <= 100;
    predicate b_in_range(integer b) = 1 <= b <= 100;
    
    logic integer mod3(integer x) = x % 3;
    
    lemma mod_preservation:
        \forall integer x; x >= 3 ==> (x - 3) % 3 == x % 3;
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures \result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b) {
    bool is_divisible_by_3 = false;
    unsigned int temp_a;
    unsigned int temp_b;
    unsigned int temp_ab;
    
    // Check if a is divisible by 3
    temp_a = a;
    /*@
        loop invariant 0 <= temp_a <= a;
        loop invariant temp_a % 3 == a % 3;
        loop assigns temp_a;
    */
    while (temp_a >= 3) {
        //@ assert temp_a % 3 == a % 3;
        temp_a -= 3;
    }
    if (temp_a == 0) {
        is_divisible_by_3 = true;
    }
    
    // Check if b is divisible by 3
    temp_b = b;
    /*@
        loop invariant 0 <= temp_b <= b;
        loop invariant temp_b % 3 == b % 3;
        loop assigns temp_b;
    */
    while (temp_b >= 3) {
        //@ assert temp_b % 3 == b % 3;
        temp_b -= 3;
    }
    if (temp_b == 0) {
        is_divisible_by_3 = true;
    }
    
    // Check if (a + b) is divisible by 3
    temp_ab = a + b;
    /*@
        loop invariant 0 <= temp_ab <= a + b;
        loop invariant temp_ab % 3 == (a + b) % 3;
        loop assigns temp_ab;
    */
    while (temp_ab >= 3) {
        //@ assert temp_ab % 3 == (a + b) % 3;
        temp_ab -= 3;
    }
    if (temp_ab == 0) {
        is_divisible_by_3 = true;
    }
    
    return is_divisible_by_3;
}
