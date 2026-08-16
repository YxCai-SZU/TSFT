/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000) && (1 <= (c) <= 10000) && (1 <= (d) <= 10000);
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b;
    ensures \result >= c * d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    // Variable declarations at top of scope
    int result;
    
    // Precondition verification
    //@ assert (1 <= (a) <= 10000);
    //@ assert (1 <= (b) <= 10000);
    //@ assert (1 <= (c) <= 10000);
    //@ assert (1 <= (d) <= 10000);
    
    // Product bound verification
    //@ assert ((a) * (b)) <= 10000 * 10000;
    //@ assert ((c) * (d)) <= 10000 * 10000;
    
    if (a * b > c * d) {
        //@ assert a * b >= c * d;
        result = a * b;
    } else {
        //@ assert c * d >= a * b;
        result = c * d;
    }
    
    // Postcondition verification
    //@ assert result == a * b || result == c * d;
    //@ assert result >= a * b;
    //@ assert result >= c * d;
    
    return result;
}
