/*@
    requires (2 <= (x) <= 100) && (2 <= (y) <= 100);
    ensures \result == ((x) * (y) - (x) - (y) + 1);
    ensures \result > 0;
*/
int func(int x, int y) {
    int res;
    
    //@ assert (2 <= (x) <= 100);
    //@ assert (2 <= (y) <= 100);
    //@ assert x > 0 && x <= 100;
    //@ assert y > 0 && y <= 100;
    //@ assert x * y <= 10000;
    
    res = x * y - x - y + 1;
    
    //@ assert res == ((x) * (y) - (x) - (y) + 1);
    //@ assert res > 0;
    
    return res;
}
