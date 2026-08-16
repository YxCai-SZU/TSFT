/*@
    predicate is_between(integer a, integer b, integer c) =
        (a < c && c < b) || (a > c && c > b);
 */

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == 1 <==> is_between(a, b, c);
    ensures \result == 0 <==> !is_between(a, b, c);
 */
int func(int a, int b, int c)
{
    int result;
    //@ ghost int ghost_a = a;
    //@ ghost int ghost_b = b;
    //@ ghost int ghost_c = c;

    if ((a < c && c < b) || (a > c && c > b))
    {
        //@ assert is_between(ghost_a, ghost_b, ghost_c);
        result = 1;
    }
    else
    {
        //@ assert !is_between(ghost_a, ghost_b, ghost_c);
        result = 0;
    }

    return result;
}
