/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures ((\result) >= 0 &&
        (\result) <= (c) &&
        ((a) - (b) >= (c) ==> (\result) == 0) &&
        ((a) - (b) < (c) ==> (\result) == (c) - ((a) - (b))));
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    result = c - (a - b);
    
    if (result > 0)
    {
        //@ assert a - b < c;
        return result;
    }
    else
    {
        //@ assert a - b >= c;
        return 0;
    }
}
