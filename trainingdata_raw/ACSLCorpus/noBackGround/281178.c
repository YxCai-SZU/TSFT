/*@
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    requires 1 <= c <= 10000;
    requires 1 <= d <= 10000;
    ensures \result == a * b || \result == c * d;
    ensures \result >= 1;
*/
int func(int a, int b, int c, int d)
{
    int sa;
    int sc;
    int res;
    
    //@ assert (1 <= (a) && (a) <= 10000);
    //@ assert (1 <= (b) && (b) <= 10000);
    //@ assert ((a) * (b)) <= 10000 * 10000;
    
    //@ assert (1 <= (c) && (c) <= 10000);
    //@ assert (1 <= (d) && (d) <= 10000);
    //@ assert ((c) * (d)) <= 10000 * 10000;
    
    sa = a * b;
    sc = c * d;
    
    //@ assert sa >= 1;
    //@ assert sc >= 1;
    
    if (sa > sc) {
        res = sa;
    } else {
        res = sc;
    }
    
    //@ assert res == sa || res == sc;
    //@ assert res >= 1;
    
    return res;
}
