#include <stdint.h>

/*@
    predicate valid_n(integer n) = 3 <= n && n <= 100;
*/

/*@
    logic integer func_spec(integer n) = 180 * (n - 2);
*/

/*@
    lemma func_bounds: 
        \forall integer n; valid_n(n) ==> 
            func_spec(n) <= 2147483647 && func_spec(n) >= -2147483648;
*/

/*@
    requires valid_n(n);
    ensures \result == func_spec(n);
    assigns \nothing;
*/
int32_t func(uint32_t n) {
    int32_t res;
    
    //@ assert valid_n(n);
    //@ assert func_spec(n) <= 2147483647 && func_spec(n) >= -2147483648;
    
    res = 180 * ((int32_t)n - 2);
    
    //@ assert res == func_spec(n);
    return res;
}

int main() {
    return 0;
}
