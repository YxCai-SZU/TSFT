#include <stdbool.h>

/*@ predicate is_odd(integer n) = n % 2 != 0; */
/*@ predicate is_even(integer n) = n % 2 == 0; */

/*@ lemma odd_implies_not_even: \forall integer n; is_odd(n) ==> !is_even(n); */
/*@ lemma even_implies_not_odd: \forall integer n; is_even(n) ==> !is_odd(n); */

/*@
    requires n >= 0;
    ensures \result == true <==> n % 2 != 0;
    assigns \nothing;
*/
bool is_odd_func(unsigned int n) {
    return n % 2 != 0;
}

/*@
    requires n >= 0;
    ensures \result == true <==> n % 2 == 0;
    assigns \nothing;
*/
bool is_even_func(unsigned int n) {
    return n % 2 == 0;
}

/*@
    requires n >= 0 && n <= 1;
    ensures (n == 0 ==> \result == 0) && (n == 1 ==> \result == 32);
    assigns \nothing;
*/
unsigned int func(unsigned int n) {
    unsigned int result;
    bool condition;
    
    condition = is_odd_func(n);
    
    if (condition) {
        //@ assert n == 1;
        result = 32;
    } else {
        //@ assert n == 0;
        result = 0;
    }
    
    return result;
}
