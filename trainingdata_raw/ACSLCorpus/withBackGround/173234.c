#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate result_condition(integer a, integer b, bool result) =
        result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/

/*@
    logic integer modulo_3(integer x) = x % 3;
*/

/*@
    lemma modulo_property:
        \forall integer a, b;
        a_in_range(a) && b_in_range(b) ==>
        (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0) ==
        (modulo_3(a) == 0 || modulo_3(b) == 0 || modulo_3(a + b) == 0);
*/

/*@
    requires a_in_range(a) && b_in_range(b);
    ensures result_condition(a, b, \result);
    assigns \nothing;
*/
bool func(int a, int b) {
    int a_mod_3;
    int b_mod_3;
    int sum_mod_3;
    int abs_a;
    int abs_b;
    int abs_sum;
    int sum;
    
    // Calculate a_mod_3
    if (a < 0) {
        abs_a = -a;
    } else {
        abs_a = a;
    }
    
    /*@
        loop invariant 0 <= abs_a <= a;
        loop invariant abs_a % 3 == a % 3;
        loop assigns abs_a;
        loop variant abs_a;
    */
    while (abs_a >= 3) {
        abs_a -= 3;
    }
    
    if (a < 0) {
        a_mod_3 = -abs_a;
    } else {
        a_mod_3 = abs_a;
    }
    
    // Calculate b_mod_3
    if (b < 0) {
        abs_b = -b;
    } else {
        abs_b = b;
    }
    
    /*@
        loop invariant 0 <= abs_b <= b;
        loop invariant abs_b % 3 == b % 3;
        loop assigns abs_b;
        loop variant abs_b;
    */
    while (abs_b >= 3) {
        abs_b -= 3;
    }
    
    if (b < 0) {
        b_mod_3 = -abs_b;
    } else {
        b_mod_3 = abs_b;
    }
    
    // Calculate sum_mod_3
    sum = a + b;
    if (sum < 0) {
        abs_sum = -sum;
    } else {
        abs_sum = sum;
    }
    
    /*@
        loop invariant 0 <= abs_sum <= sum;
        loop invariant abs_sum % 3 == sum % 3;
        loop assigns abs_sum;
        loop variant abs_sum;
    */
    while (abs_sum >= 3) {
        abs_sum -= 3;
    }
    
    if (sum < 0) {
        sum_mod_3 = -abs_sum;
    } else {
        sum_mod_3 = abs_sum;
    }
    
    //@ assert a_mod_3 == a % 3;
    //@ assert b_mod_3 == b % 3;
    //@ assert sum_mod_3 == (a + b) % 3;
    
    return a_mod_3 == 0 || b_mod_3 == 0 || sum_mod_3 == 0;
}

int main() {
    return 0;
}
