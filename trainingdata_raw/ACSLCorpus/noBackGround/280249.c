#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> (((a) % 3 == 0) || ((b) % 3 == 0) || (((a) + (b)) % 3 == 0) || ((a) % 5 == 0) || ((b) % 5 == 0));
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b)
{
    bool mod_a_3;
    bool mod_b_3;
    bool mod_a_b_3;
    bool mod_a_5;
    bool mod_b_5;
    bool result;

    //@ assert a + b <= 200;
    
    if (a % 3 == 0) {
        mod_a_3 = true;
    } else {
        mod_a_3 = false;
    }
    
    if (b % 3 == 0) {
        mod_b_3 = true;
    } else {
        mod_b_3 = false;
    }
    
    if ((a + b) % 3 == 0) {
        mod_a_b_3 = true;
    } else {
        mod_a_b_3 = false;
    }
    
    if (a % 5 == 0) {
        mod_a_5 = true;
    } else {
        mod_a_5 = false;
    }
    
    if (b % 5 == 0) {
        mod_b_5 = true;
    } else {
        mod_b_5 = false;
    }
    
    result = mod_a_3 || mod_b_3 || mod_a_b_3 || mod_a_5 || mod_b_5;
    
    return result;
}
