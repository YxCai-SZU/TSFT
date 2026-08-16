#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;

    logic integer compute_n(integer x) = x / 100;
    logic integer compute_m(integer x) = x % 100;

    predicate condition_holds(integer x) = 
        x >= 2000 || 
        (x >= 100 && compute_m(x) <= 5 * compute_n(x));

    lemma arithmetic_bound: 
        \forall integer x; 
        is_valid_range(x) ==> 5 * compute_n(x) <= 50000;
*/

/*@
    requires is_valid_range(x);
    ensures \result == (x >= 2000 || (x >= 100 && (x % 100) <= 5 * (x / 100)));
    assigns \nothing;
*/
bool func(unsigned int x) {
    // Variable declarations at scope top
    unsigned int n;
    unsigned int m;
    bool result;

    if (x >= 2000) {
        result = true;
        //@ assert x >= 2000 || (x >= 100 && (x % 100) <= 5 * (x / 100));
        return result;
    }

    n = x / 100;
    m = x % 100;

    //@ assert 5 * n <= 50000;

    if (x >= 100 && m <= 5 * n) {
        result = true;
        //@ assert x >= 100 && (x % 100) <= 5 * (x / 100);
        return result;
    } else {
        result = false;
        //@ assert !(x >= 2000 || (x >= 100 && (x % 100) <= 5 * (x / 100)));
        return result;
    }
}
