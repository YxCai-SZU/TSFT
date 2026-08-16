#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result == true <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b) {
    bool is_divisible = false;
    unsigned int a_copy = a;
    unsigned int b_copy = b;
    unsigned int sum = a + b;
    
    // Check divisibility by 3 for a
    /*@
        loop invariant 0 <= a_copy <= a;
        loop invariant a_copy % 3 == a % 3;
        loop assigns a_copy;
        loop variant a_copy;
    */
    while (a_copy >= 3) {
        a_copy -= 3;
    }
    
    //@ assert a_copy == 0 ==> a % 3 == 0;
    if (a_copy == 0) {
        is_divisible = true;
    }
    
    // Check divisibility by 3 for b
    /*@
        loop invariant 0 <= b_copy <= b;
        loop invariant b_copy % 3 == b % 3;
        loop assigns b_copy;
        loop variant b_copy;
    */
    while (b_copy >= 3) {
        b_copy -= 3;
    }
    
    //@ assert b_copy == 0 ==> b % 3 == 0;
    if (b_copy == 0) {
        is_divisible = true;
    }
    
    // Check divisibility by 3 for a + b
    /*@
        loop invariant 0 <= sum <= a + b;
        loop invariant sum % 3 == (a + b) % 3;
        loop assigns sum;
        loop variant sum;
    */
    while (sum >= 3) {
        sum -= 3;
    }
    
    //@ assert sum == 0 ==> (a + b) % 3 == 0;
    if (sum == 0) {
        is_divisible = true;
    }
    
    //@ assert is_divisible <==> (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    return is_divisible;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
