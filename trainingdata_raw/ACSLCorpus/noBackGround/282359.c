/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
    ensures \result == a * b;
    ensures (1 <= (\result) <= 10000);
    assigns \nothing;
*/
int func(int a, int b)
{
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= a * b <= 10000;
    return a * b;
}

