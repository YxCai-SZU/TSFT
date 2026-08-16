/*@
    requires (0 <= (x) && (x) <= 9) && (0 <= (a) && (a) <= 9);
    ensures (x >= a ==> \result == 10) && (x < a ==> \result == 0);
    assigns \nothing;
*/
int func(int x, int a)
{
    //@ assert (0 <= (x) && (x) <= 9) && (0 <= (a) && (a) <= 9);
    //@ assert x * a <= 81;
    int result;
    if (x >= a)
    {
        //@ assert x + a >= 0;
        result = 10;
    }
    else
    {
        result = 0;
    }
    return result;
}
