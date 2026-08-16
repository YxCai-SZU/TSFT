/*@
    requires 1 <= a <= 9;
    requires 1 <= b <= 9;
    requires 1 <= c <= 9;
    ensures \result == 1 <==> ((a) < (b) && (b) < (c));
 */
int func(int a, int b, int c)
{
    int result;
    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;
    
    if (a < b && b < c) {
        //@ assert ((a) < (b) && (b) < (c));
        result = 1;
    } else {
        //@ assert !((a) < (b) && (b) < (c));
        result = 0;
    }
    
    return result;
}
