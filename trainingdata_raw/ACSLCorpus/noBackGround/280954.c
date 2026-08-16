/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == (a < b);
*/
int func(int a, int b) {
    // Variable declarations at scope top
    int scaled;
    int result;
    
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    
    //@ assert a * 100 <= 10000;
    //@ assert a * 100 >= 100;
    
    scaled = a * 100 / 100;
    
    //@ assert scaled <= 100;
    //@ assert scaled >= 1;
    //@ assert scaled == a;
    
    if (scaled < b) {
        result = 1;
    } else {
        result = 0;
    }
    
    //@ assert result == (a < b);
    return result;
}
