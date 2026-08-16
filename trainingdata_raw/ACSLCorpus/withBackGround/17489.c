#include <limits.h>

/*@
    predicate is_min(integer a, integer b, integer c, integer ret) =
        ret <= a && ret <= b && ret <= c;
*/

/*@
    requires \true;
    ensures is_min(a, b, c, \result);
    assigns \nothing;
*/
int min_numbers(int a, int b, int c)
{
    int ret;
    //@ ghost int proof_case;

    if (a <= b && a <= c)
    {
        //@ assert a <= b && a <= c;
        ret = a;
        //@ ghost proof_case = 1;
    }
    else if (b <= a && b <= c)
    {
        //@ assert b <= a && b <= c;
        ret = b;
        //@ ghost proof_case = 2;
    }
    else
    {
        //@ assert c <= a && c <= b;
        ret = c;
        //@ ghost proof_case = 3;
    }

    //@ assert is_min(a, b, c, ret);
    return ret;
}
