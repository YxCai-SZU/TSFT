/*@
    predicate maximum_post(integer a, integer b, integer ret) =
        (ret == a && a >= b) || (ret == b && b >= a);
 */

/*@
    requires \true;
    ensures maximum_post(a, b, \result);
    assigns \nothing;
 */
int maximum(int a, int b)
{
    int ret;
    //@ ghost int original_a = a;
    //@ ghost int original_b = b;
    
    if (a > b) {
        //@ assert a >= b;
        ret = a;
    } else {
        //@ assert b >= a;
        ret = b;
    }
    
    //@ assert maximum_post(original_a, original_b, ret);
    return ret;
}
