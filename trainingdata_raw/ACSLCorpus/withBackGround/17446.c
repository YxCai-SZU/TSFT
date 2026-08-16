/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 10;
    logic integer cube(integer a) = a * a * a;
*/

/*@
    requires a_in_range(a);
    ensures \result == cube(a);
    assigns \nothing;
*/
int func(int a)
{
    int b;

    //@ assert a >= 1 && a <= 10;
    //@ assert a * a <= 100;
    //@ assert a * a * a <= 1000;

    b = a * a * a;

    return b;
}
