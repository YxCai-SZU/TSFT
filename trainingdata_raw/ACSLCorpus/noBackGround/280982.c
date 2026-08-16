/*@
    requires (1 <= (a) <= 20) && (1 <= (b) <= 20);
    ensures ((1 <= (a) <= 9) && (1 <= (b) <= 9)) ==> \result == a * b;
    ensures (!(1 <= (a) <= 9) || !(1 <= (b) <= 9)) ==> \result == -1;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;

    //@ assert (1 <= (a) <= 20) && (1 <= (b) <= 20);
    if (a > 9 || b > 9)
    {
        //@ assert !(1 <= (a) <= 9) || !(1 <= (b) <= 9);
        result = -1;
        return result;
    }

    //@ assert (1 <= (a) <= 9) && (1 <= (b) <= 9);
    //@ assert 1 <= a * b <= 81;
    result = a * b;
    return result;
}
