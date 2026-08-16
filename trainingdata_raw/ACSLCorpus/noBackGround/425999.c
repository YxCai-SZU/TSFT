/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result >= 0;
    ensures \result <= 3;
    ensures \result == 3 ==> (a == b && b == c);
    ensures \result == 2 ==> (a == b || b == c || c == a);
    ensures \result == 1 ==> (a != b && b != c && c != a);
*/
int func(int a, int b, int c)
{
    int result;
    
    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    
    if (a == b && b == c) {
        result = 3;
        //@ assert result == 3;
        //@ assert a == b && b == c;
    } else if (a != b && b != c && c != a) {
        result = 1;
        //@ assert result == 1;
        //@ assert a != b && b != c && c != a;
    } else {
        result = 2;
        //@ assert result == 2;
        //@ assert a == b || b == c || c == a;
    }
    
    //@ assert result >= 0;
    //@ assert result <= 3;
    
    return result;
}
