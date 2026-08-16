#include <stdbool.h>

/*@
    predicate diff_in_range(integer n, integer a, integer b, integer diff) =
        2 <= n <= 100 && 1 <= a < b <= n && diff == b - a;

    logic integer mod_two(integer x) = x % 2;

    lemma mod_preservation:
        \forall integer diff, temp;
        diff >= 1 && temp >= 2 && temp <= diff &&
        temp % 2 == (diff - 1) % 2 ==>
        (temp - 2) % 2 == (diff - 1) % 2;
*/

/*@
    requires 2 <= n <= 100;
    requires 1 <= a < b <= n;
    ensures \result == ((b - a - 1) % 2 == 1);
    assigns \nothing;
*/
bool func(unsigned int n, unsigned int a, unsigned int b)
{
    unsigned int diff;
    bool is_odd = false;
    unsigned int temp;

    //@ assert 2 <= n <= 100;
    //@ assert 1 <= a < b <= n;
    
    diff = b - a;
    //@ assert diff_in_range(n, a, b, diff);
    //@ assert diff >= 1;
    
    temp = diff - 1;
    
    /*@
        loop invariant 0 <= temp <= diff;
        loop invariant temp % 2 == (diff - 1) % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        //@ assert temp % 2 == (diff - 1) % 2;
        temp -= 2;
        //@ assert temp % 2 == (diff - 1) % 2;
    }
    
    //@ assert temp == 0 || temp == 1;
    if (temp == 1)
    {
        is_odd = true;
    }
    
    //@ assert is_odd == ((diff - 1) % 2 == 1);
    //@ assert (b - a - 1) == (diff - 1);
    return is_odd;
}
