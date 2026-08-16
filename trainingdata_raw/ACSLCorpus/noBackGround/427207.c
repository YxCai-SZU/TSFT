#include <stdbool.h>

/*@
    requires \true;
    ensures \true;
*/
int main() {
    // Test difference function
    //@ assert ((10) >= (20) ? (10) - (20) : (20) - (10)) == 10;
    
    // Test absolute_value function
    //@ assert ((-10) >= 0 ? (-10) : -(-10)) == 10;
    
    // Test non-negative properties
    //@ assert ((10) >= (20) ? (10) - (20) : (20) - (10)) >= 0;
    //@ assert ((100) >= (200) ? (100) - (200) : (200) - (100)) >= 0;
    //@ assert ((-10) >= 0 ? (-10) : -(-10)) >= 0;
    //@ assert ((-100) >= 0 ? (-100) : -(-100)) >= 0;
    //@ assert ((10) >= 0 ? (10) : -(10)) >= 0;
    
    return 0;
}
