/*@
    predicate in_range(integer v) = 0 <= v <= 9;
*/

/*@
    requires in_range(x) && in_range(a);
    ensures (x < a ==> \result == 0) && (x >= a ==> \result == 10);
    assigns \nothing;
*/
int func(int x, int a)
{
    //@ assert in_range(x);
    //@ assert in_range(a);
    
    if (x < a) {
        return 0;
    } else {
        return 10;
    }
}
