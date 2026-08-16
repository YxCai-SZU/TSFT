/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures \result >= 1 && \result <= 3;
    ensures \result == 1 ==> (a == b && b == c);
    ensures \result == 2 ==> ((a == b && a != c) || (a != b && a == c) || (b == c && b != a));
    ensures \result == 3 ==> (a != b && b != c && a != c);
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int result;
    
    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100);
    
    if (a == b && b == c) {
        result = 1;
        //@ assert result == 1 && a == b && b == c;
    } else if (a != b && b != c && a != c) {
        result = 3;
        //@ assert result == 3 && a != b && b != c && a != c;
    } else {
        result = 2;
        //@ assert result == 2 && ((a == b && a != c) || (a != b && a == c) || (b == c && b != a));
    }
    
    //@ assert result >= 1 && result <= 3;
    return result;
}
