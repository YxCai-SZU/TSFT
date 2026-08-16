#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) + (((a)) * ((a))) + (((a)) * ((a)) * ((a))));
    assigns \nothing;
*/
int64_t func(int64_t a) {
    // Variable declarations at top of scope
    int64_t a_2;
    int64_t a_3;
    int64_t result;
    
    //@ assert 1 <= a && a <= 10;
    
    // Verify a * a bounds
    //@ assert 1 <= a * a && a * a <= 100;
    a_2 = a * a;
    
    // Verify a * a * a bounds  
    //@ assert 1 <= a * a * a && a * a * a <= 1000;
    a_3 = a * a * a;
    
    result = a;
    
    // The if-else structure is preserved but both branches are identical
    if (a_2 >= 0) {
        result += a_2;
        if (a_3 >= 0) {
            result += a_3;
        } else {
            result += a_3;
        }
    } else {
        result += a_2;
        if (a_3 >= 0) {
            result += a_3;
        } else {
            result += a_3;
        }
    }
    
    // Final verification property
    //@ assert result == a + a * a + a * a * a;
    return result;
}
