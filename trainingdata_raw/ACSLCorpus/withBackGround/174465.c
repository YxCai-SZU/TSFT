#include <stdbool.h>

/*@
    predicate remainder_invariant(integer r, integer a, integer b) =
        0 <= r <= a &&
        b == a / 100 &&
        r % 100 == a % 100;

    predicate remainder_invariant2(integer r, integer a, integer b) =
        -100 < r < 100 &&
        b == a / 100 &&
        r % 100 == a % 100;

    lemma remainder_mod: \forall integer a, r;
        (0 <= r < 100 && r % 100 == a % 100) ==> r == a % 100;
*/

/*@
    requires 1 <= a <= 1000000000000000000;
    ensures \result == ((a / 100) % 5 == 0 || (a / 100) % 5 == 1);
    assigns \nothing;
*/
bool func(unsigned long long a)
{
    unsigned long long b;
    long long remainder;
    
    b = a / 100;
    remainder = (long long)a;
    
    /*@
        loop invariant remainder_invariant(remainder, a, b);
        loop assigns remainder;
    */
    while (remainder >= 100)
    {
        //@ assert remainder % 100 == a % 100;
        remainder -= 100;
    }
    
    /*@
        loop invariant remainder_invariant2(remainder, a, b);
        loop assigns remainder;
    */
    while (remainder < 0)
    {
        //@ assert remainder % 100 == a % 100;
        remainder += 100;
    }
    
    //@ assert remainder == a % 100;
    
    return (b % 5 == 0 || b % 5 == 1);
}
