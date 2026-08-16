#include <stdbool.h>

/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 100000;

    logic integer mod_100(integer n) = n % 100;
    logic integer scaled_mod(integer n) = mod_100(n) * 21;

    lemma mod_bound: \forall integer n; is_valid_n(n) ==> 0 <= mod_100(n) && mod_100(n) <= 100;
    lemma scaled_bound: \forall integer n; is_valid_n(n) ==> 0 <= scaled_mod(n) && scaled_mod(n) <= 2100;
*/

/*@
    requires is_valid_n(n);
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> scaled_mod(n) >= n;
    ensures \result == 0 ==> scaled_mod(n) < n;
*/
int func(int n) {
    int ret;
    int mod_result;
    
    //@ assert is_valid_n(n);
    //@ assert 0 <= mod_100(n) && mod_100(n) <= 100;
    mod_result = n % 100;
    
    //@ assert mod_result == mod_100(n);
    //@ assert 0 <= scaled_mod(n) && scaled_mod(n) <= 2100;
    
    if (mod_result * 21 >= n) {
        ret = 1;
        //@ assert scaled_mod(n) >= n;
    } else {
        ret = 0;
        //@ assert scaled_mod(n) < n;
    }
    
    return ret;
}
