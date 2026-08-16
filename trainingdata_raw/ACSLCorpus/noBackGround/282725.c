/*@
    requires 1 <= r <= 100;
    ensures \result == 3 * r * r;
    assigns \nothing;
*/
int func(int r)
{
    //@ assert 1 <= r <= 100;
    return 3 * r * r;
}
