#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
*/
bool func(long a, long b) {
    long a_mod_3;
    long b_mod_3;
    long sum_mod_3;
    long abs_a;
    long abs_b;
    long abs_sum;
    
    // Calculate a_mod_3
    if (a < 0) {
        abs_a = -a;
    } else {
        abs_a = a;
    }
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (0 <= (abs_a) <= 100);
    //@ assert abs_a % 3 == a % 3;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 0 <= abs_a <= 100;
        loop invariant abs_a % 3 == a % 3;
        loop assigns abs_a;
    */
    while (abs_a >= 3) {
        abs_a -= 3;
        //@ assert (0 <= (abs_a) <= 100);
        //@ assert abs_a % 3 == a % 3;
    }
    
    if (a < 0) {
        a_mod_3 = -abs_a;
    } else {
        a_mod_3 = abs_a;
    }
    
    // Calculate b_mod_3
    if (b < 0) {
        abs_b = -b;
    } else {
        abs_b = b;
    }
    
    //@ assert (1 <= (b) <= 100);
    //@ assert (0 <= (abs_b) <= 100);
    //@ assert abs_b % 3 == b % 3;
    
    /*@
        loop invariant 1 <= b <= 100;
        loop invariant 0 <= abs_b <= 100;
        loop invariant abs_b % 3 == b % 3;
        loop assigns abs_b;
    */
    while (abs_b >= 3) {
        abs_b -= 3;
        //@ assert (0 <= (abs_b) <= 100);
        //@ assert abs_b % 3 == b % 3;
    }
    
    if (b < 0) {
        b_mod_3 = -abs_b;
    } else {
        b_mod_3 = abs_b;
    }
    
    // Calculate sum_mod_3
    if (a + b < 0) {
        abs_sum = -(a + b);
    } else {
        abs_sum = a + b;
    }
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert (0 <= (abs_sum) <= 200);
    //@ assert abs_sum % 3 == (a + b) % 3;
    
    /*@
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 0 <= abs_sum <= 200;
        loop invariant abs_sum % 3 == (a + b) % 3;
        loop assigns abs_sum;
    */
    while (abs_sum >= 3) {
        abs_sum -= 3;
        //@ assert (0 <= (abs_sum) <= 200);
        //@ assert abs_sum % 3 == (a + b) % 3;
    }
    
    if (a + b < 0) {
        sum_mod_3 = -abs_sum;
    } else {
        sum_mod_3 = abs_sum;
    }
    
    //@ assert a_mod_3 == a % 3;
    //@ assert b_mod_3 == b % 3;
    //@ assert sum_mod_3 == (a + b) % 3;
    
    if (a_mod_3 == 0 || b_mod_3 == 0 || sum_mod_3 == 0) {
        //@ assert (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
        return true;
    } else {
        //@ assert !(a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
        return false;
    }
}
