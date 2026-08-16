/*@
    requires (1 <= (a) <= 10 && 1 <= (b) <= 10);
    ensures \result == a * b;
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert (1 <= (a) <= 10 && 1 <= (b) <= 10);
    //@ assert 1 <= a * b <= 100;
    return a * b;
}
