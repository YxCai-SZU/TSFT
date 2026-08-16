/*@
    requires (1 <= (a) && (a) <= 20) && (1 <= (b) && (b) <= 20);
    ensures (a <= 9 && b <= 9 ==> \result == a * b) && 
            (a > 9 || b > 9 ==> \result == -1);
    assigns \nothing;
*/
int func(unsigned int a, unsigned int b)
{
    // Variable declarations at scope top
    int result;
    
    if (a <= 9 && b <= 9) {
        //@ assert 1 <= a && a <= 9;
        //@ assert 1 <= b && b <= 9;
        //@ assert a * b <= 81;
        result = a * b;
    } else {
        result = -1;
    }
    
    return result;
}
