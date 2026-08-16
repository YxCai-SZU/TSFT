#include <stdbool.h>

/*@ predicate is_even(integer n) = n % 2 == 0; */

/*@
    requires n <= 4294967295;
    ensures \result == (n % 2 == 0);
    assigns \nothing;
*/
bool is_even_c(unsigned int n)
{
    // Variable declarations at top of scope
    bool ret;

    //@ assert n <= 4294967295;
    
    ret = (n % 2 == 0);
    
    return ret;
}

/*@
    lemma test_even_10: is_even(10);
    lemma test_odd_11: !is_even(11);
*/
