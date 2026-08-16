/*@
    requires (0 <= (a) <= 23) && (0 <= (b) <= 23);
    requires ((a) >= 0) && ((b) >= 0);
    ensures (0 <= (\result) <= 23);
    assigns \nothing;
*/
int func(int a, int b)
{
    int c;
    int result;

    c = a + b;
    //@ assert ((c) >= 0);
    
    if (c < 24) {
        result = c;
    } else {
        result = c - 24;
    }
    
    //@ assert 0 <= result && result < 24;
    //@ assert (0 <= (result) <= 23);
    
    return result;
}
