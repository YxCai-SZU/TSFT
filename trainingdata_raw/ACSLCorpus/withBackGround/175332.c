#include <stdbool.h>

/*@
    predicate is_mod_32(integer a) = a % 32 == 0;
*/

/*@
    requires 1 <= a <= 100000;
    ensures \result == (a % 32 == 0);
    assigns \nothing;
*/
bool func(unsigned long long a) {
    unsigned long long temp;
    
    temp = a;
    
    /*@
        loop invariant 0 <= temp <= a;
        loop invariant temp % 32 == a % 32;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 32) {
        temp -= 32;
    }
    
    //@ assert temp == a % 32;
    
    return temp == 0;
}

int main() {
    return 0;
}
