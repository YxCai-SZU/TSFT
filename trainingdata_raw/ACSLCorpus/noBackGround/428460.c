/*@
    requires (1 <= (a) && (a) <= 20) && (1 <= (b) && (b) <= 20);
    ensures (a <= 9 && b <= 9) ==> \result == ((a) * (b));
    ensures (a > 9 || b > 9) ==> \result == -1;
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    int result;
    
    //@ assert (1 <= (a) && (a) <= 20) && (1 <= (b) && (b) <= 20);
    
    if (a > 9) {
        result = -1;
        //@ assert a > 9 || b > 9;
    } else if (b > 9) {
        result = -1;
        //@ assert a > 9 || b > 9;
    } else {
        //@ assert (1 <= (a) && (a) <= 9) && (1 <= (b) && (b) <= 9);
        //@ assert ((a) * (b)) <= 81;
        result = a * b;
        //@ assert a <= 9 && b <= 9;
    }
    
    return result;
}
