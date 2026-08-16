/*@
    requires (1 <= (a) && (a) <= 10000 &&
        1 <= (b) && (b) <= 10000 &&
        1 <= (c) && (c) <= 10000 &&
        1 <= (d) && (d) <= 10000);
    ensures \result >= 0;
    ensures \result <= a * b || \result <= c * d;
*/
int func(int a, int b, int c, int d)
{
    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= b && b <= 10000;
    //@ assert 1 <= c && c <= 10000;
    //@ assert 1 <= d && d <= 10000;
    
    int product1;
    int product2;
    int res;
    
    //@ assert ((a) * (b)) <= 100000000;
    product1 = a * b;
    
    //@ assert ((c) * (d)) <= 100000000;
    product2 = c * d;
    
    if (product1 > product2) {
        res = product1 - product2;
    } else {
        res = product2 - product1;
    }
    
    //@ assert res >= 0;
    return res;
}
