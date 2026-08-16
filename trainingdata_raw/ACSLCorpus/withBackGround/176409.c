#include <stdbool.h>

/*@
    predicate in_range(integer x) = 1 <= x <= 100;
    
    logic integer mod4(integer x) = x % 4;
    
    lemma mod4_range:
        \forall integer x; in_range(x) ==> 0 <= mod4(x) <= 3;
*/

/*@
    requires in_range(a) && in_range(b) && in_range(c);
    ensures \result == true <==> c >= a && c <= a + b;
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int min_val;
    unsigned int max_val;
    unsigned int c_mod_4;
    unsigned int a_mod_4;
    unsigned int b_mod_4;
    
    //@ assert in_range(a);
    //@ assert in_range(b);
    //@ assert in_range(c);
    
    min_val = (a < c) ? a : c;
    max_val = (a + b > c) ? a + b : c;
    
    c_mod_4 = c;
    /*@
        loop invariant 0 <= c_mod_4 <= c;
        loop invariant c_mod_4 % 4 == c % 4;
        loop assigns c_mod_4;
        loop variant c_mod_4;
    */
    while (c_mod_4 >= 4)
    {
        c_mod_4 -= 4;
    }
    //@ assert c_mod_4 == mod4(c);
    
    a_mod_4 = a;
    /*@
        loop invariant 0 <= a_mod_4 <= a;
        loop invariant a_mod_4 % 4 == a % 4;
        loop assigns a_mod_4;
        loop variant a_mod_4;
    */
    while (a_mod_4 >= 4)
    {
        a_mod_4 -= 4;
    }
    //@ assert a_mod_4 == mod4(a);
    
    b_mod_4 = b;
    /*@
        loop invariant 0 <= b_mod_4 <= b;
        loop invariant b_mod_4 % 4 == b % 4;
        loop assigns b_mod_4;
        loop variant b_mod_4;
    */
    while (b_mod_4 >= 4)
    {
        b_mod_4 -= 4;
    }
    //@ assert b_mod_4 == mod4(b);
    
    //@ assert c >= a && c <= a + b <==> c >= a && c <= a + b;
    return (c >= a && c <= a + b);
}
