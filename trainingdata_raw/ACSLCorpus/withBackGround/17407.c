#include <stdbool.h>

/*@
    predicate is_mod_10(integer n, integer temp) =
        temp == n % 10;

    lemma mod_lemma:
        \forall integer n, temp;
            10 <= n <= 99 && 0 <= temp <= 9 && is_mod_10(n, temp) ==>
            (temp == 9 || n >= 90) == (n % 10 == 9 || n >= 90);
*/

/*@
    requires 10 <= n <= 99;
    ensures \result == (n % 10 == 9 || n >= 90);
    assigns \nothing;
*/
bool func(unsigned long n)
{
    unsigned long temp = n;

    /*@
        loop invariant 0 <= temp <= 99;
        loop invariant temp % 10 == n % 10;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 10)
    {
        temp -= 10;
    }

    //@ assert temp == n % 10;
    return temp == 9 || n >= 90;
}
