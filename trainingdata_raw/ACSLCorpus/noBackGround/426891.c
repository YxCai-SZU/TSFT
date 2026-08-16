/*@
    requires 1 <= x <= 10000;
    requires 1 <= a <= 10000;
    requires 1 <= b <= 10000;
    ensures \result == a * x || \result == b;
    ensures \result >= 0;
*/
int func(int x, int a, int b)
{
    int min_val;
    int product;

    //@ assert 1 <= a && a <= 10000;
    //@ assert 1 <= x && x <= 10000;
    //@ assert a * x >= 0;
    //@ assert a * x <= 10000 * 10000;
    
    product = a * x;
    
    if (product < b) {
        min_val = product;
    } else {
        min_val = b;
    }
    
    //@ assert min_val == a * x || min_val == b;
    //@ assert min_val >= 0;
    
    return min_val;
}
