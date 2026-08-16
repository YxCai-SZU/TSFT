#include <stdbool.h>

/*@
    requires (10 <= (n) && (n) <= 99);
    ensures \result == (n % 10 == 7 || n / 10 == 7);
    assigns \nothing;
*/
bool func(int n) {
    int n_mod;
    int n_div;
    bool last_digit_is_7;
    bool first_digit_is_7;
    
    n_mod = n % 10;
    n_div = n / 10;
    
    last_digit_is_7 = (n_mod == 7);
    first_digit_is_7 = (n_div == 7);
    
    if (last_digit_is_7 || first_digit_is_7) {
        return true;
    } else {
        //@ assert n_mod != 7 && n_div != 7;
        return false;
    }
}
