#include <limits.h>

/*@
    predicate bounds(integer a) = -1290 <= a <= 1290;
    logic integer cube(integer a) = a * a * a;
*/

/*@
    requires bounds(a);
    ensures \result == cube(a);
    assigns \nothing;
*/
int func(int a)
{
    int a_2;
    int a_3;
    
    //@ assert bounds(a);
    
    //@ assert a * a >= -1290 * 1290 && a * a <= 1290 * 1290;
    a_2 = a * a;
    
    //@ assert a_2 * a >= -1290 * 1290 * 1290 && a_2 * a <= 1290 * 1290 * 1290;
    a_3 = a_2 * a;
    
    //@ assert a_3 >= -1290 * 1290 * 1290 && a_3 <= 1290 * 1290 * 1290;
    
    return a_3;
}
