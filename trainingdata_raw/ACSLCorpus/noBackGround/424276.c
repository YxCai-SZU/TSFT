/*@
    requires 1 <= a <= 100;
    ensures \result == a * a;
    assigns \nothing;
*/
int func(int a)
{
    //@ assert 1 <= a && a <= 100;
    //@ assert a * a <= 10000;
    return a * a;
}
