#include <stdbool.h>

/*@
    predicate is_odd(integer x) = x % 2 == 1;
    predicate is_even(integer x) = x % 2 == 0;
    logic integer double_val(integer k) = k * 2;
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= k <= 100;
    ensures \result == true <==> 
            (is_odd(n) && n >= double_val(k) + 1) || 
            (is_even(n) && n >= double_val(k));
*/
bool func(int n, int k)
{
    unsigned int n_unsigned;
    unsigned int k_unsigned;
    unsigned int n_mod_2;
    bool condition;
    
    n_unsigned = (n < 0) ? (unsigned int)(-n) : (unsigned int)n;
    k_unsigned = (k < 0) ? (unsigned int)(-k) : (unsigned int)k;
    
    n_mod_2 = n_unsigned % 2;
    
    //@ assert n_mod_2 == 0 || n_mod_2 == 1;
    
    condition = (n_mod_2 == 1 && n_unsigned >= k_unsigned * 2 + 1) || 
                (n_mod_2 == 0 && n_unsigned >= k_unsigned * 2);
    
    if (condition) {
        return true;
    } else {
        return false;
    }
}

/*@
    lemma k_bound_implies_double_bound:
        \forall integer k; 1 <= k <= 100 ==> k * 2 <= 200;
*/
