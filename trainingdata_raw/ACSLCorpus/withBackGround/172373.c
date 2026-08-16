/*@
    predicate is_odd(integer x) = x % 2 != 0;
    predicate is_even(integer x) = x % 2 == 0;
    
    logic integer last_digit(integer x) = x % 10;
    
    lemma product_parity: \forall integer a, b;
        (is_even(last_digit(a)) || is_even(last_digit(b))) ==> is_even(a * b);
    lemma both_odd_implies_odd: \forall integer a, b;
        is_odd(last_digit(a)) && is_odd(last_digit(b)) ==> is_odd(a * b);
*/

#include <stdbool.h>

/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == ((a * b) % 2 != 0);
*/
bool func(unsigned int a, unsigned int b) {
    unsigned int a_last_digit;
    unsigned int b_last_digit;
    unsigned int product;
    unsigned int temp_product;
    
    a_last_digit = a % 10;
    b_last_digit = b % 10;
    
    //@ assert a_last_digit == a % 10;
    //@ assert b_last_digit == b % 10;
    
    if ((a_last_digit == 0 || a_last_digit == 2 || a_last_digit == 4 || a_last_digit == 6 || a_last_digit == 8) ||
        (b_last_digit == 0 || b_last_digit == 2 || b_last_digit == 4 || b_last_digit == 6 || b_last_digit == 8)) {
        //@ assert is_even(last_digit(a)) || is_even(last_digit(b));
    } else {
        //@ assert is_odd(last_digit(a)) && is_odd(last_digit(b));
    }
    
    //@ assert 1 <= a * b <= 10000 * 10000;
    
    product = a * b;
    temp_product = product;
    
    /*@
        loop invariant 0 <= temp_product <= product;
        loop invariant temp_product % 2 == product % 2;
        loop assigns temp_product;
        loop variant temp_product;
    */
    while (temp_product >= 2) {
        temp_product -= 2;
    }
    
    //@ assert temp_product == 0 || temp_product == 1;
    return temp_product != 0;
}
