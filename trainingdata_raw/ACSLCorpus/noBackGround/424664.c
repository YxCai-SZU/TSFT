/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    ensures (\result == c && a > b + c) || (\result == c - (a - b) && a <= b + c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    if (a > b + c) {
        result = c;
    } else {
        result = c - (a - b);
    }

    //@ assert result == ((a) > (b) + (c) ? (c) : (c) - ((a) - (b)));
    
    if (result < 0) {
        //@ assert result >= 0;
        return 0;
    } else {
        //@ assert result >= 0;
        return result;
    }
}
