/*@
    predicate strictly_increasing(integer a, integer b, integer c) =
        a < b && b < c;
    predicate strictly_decreasing(integer a, integer b, integer c) =
        a > b && b > c;
    predicate monotonic_sequence(integer a, integer b, integer c) =
        strictly_increasing(a, b, c) || strictly_decreasing(a, b, c);
*/

/*@
    requires 0 <= a <= 100;
    requires 0 <= b <= 100;
    requires 0 <= c <= 100;
    ensures \result == 1 <==> monotonic_sequence(a, b, c);
*/
int func(unsigned int a, unsigned int b, unsigned int c)
{
    int result;
    //@ ghost int condition_holds;

    if (a > b && b > c)
    {
        //@ assert strictly_decreasing(a, b, c);
        result = 1;
    }
    else if (a < b && b < c)
    {
        //@ assert strictly_increasing(a, b, c);
        result = 1;
    }
    else
    {
        //@ assert !strictly_decreasing(a, b, c) && !strictly_increasing(a, b, c);
        result = 0;
    }

    return result;
}
