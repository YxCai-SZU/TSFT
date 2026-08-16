#include <stdbool.h>

/*@
    predicate is_odd_property(integer n, bool ret) =
        ret == (n % 2 != 0);
*/

/*@
    lemma remainder_mod_preserved:
        \forall integer n, integer r;
            r >= 0 && r <= n && r % 2 == n % 2 ==>
                (r >= 2 ==> (r - 2) % 2 == n % 2);
*/

/*@
    requires n >= 0;
    ensures \result == (n % 2 != 0);
    assigns \nothing;
*/
bool is_odd(unsigned int n) {
    unsigned int remainder = n;
    
    /*@
        loop invariant 0 <= remainder <= n;
        loop invariant remainder % 2 == n % 2;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2) {
        //@ assert remainder % 2 == n % 2;
        remainder -= 2;
    }
    
    //@ assert remainder % 2 == n % 2;
    //@ assert remainder < 2;
    return remainder == 1;
}

int main() {
    return 0;
}
