/*@
    requires 1 <= a <= 20;
    requires 1 <= b <= 20;
    ensures (a <= 9 && b <= 9 ==> \result == a * b);
    ensures (a > 9 || b > 9 ==> \result == -1);
*/
int func(int a, int b) {
    int result;
    
    if (a <= 9 && b <= 9) {
        //@ assert 1 <= a <= 9;
        //@ assert 1 <= b <= 9;
        //@ assert 1 <= a * b <= 81;
        result = a * b;
    } else {
        //@ assert a > 9 || b > 9;
        result = -1;
    }
    
    return result;
}
