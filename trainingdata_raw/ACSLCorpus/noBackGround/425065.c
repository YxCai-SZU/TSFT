/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result >= 0;
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
*/
int func(int a, int b)
{
    int min_a;
    int max_a;
    int res;

    //@ assert (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    
    if (a < b) {
        min_a = a;
    } else {
        min_a = b;
    }
    
    if (a > b) {
        max_a = a;
    } else {
        max_a = b;
    }
    
    //@ assert min_a == ((a) < (b) ? (a) : (b));
    //@ assert max_a == ((a) > (b) ? (a) : (b));
    
    res = max_a * 2 - 1;
    
    if (res > min_a + max_a) {
        //@ assert res > a + b;
        return min_a + max_a;
    } else {
        //@ assert res <= a + b;
        //@ assert res == 2 * max_a - 1;
        //@ assert max_a == a || max_a == b;
        //@ assert min_a == a || min_a == b;
        //@ assert 3 <= a && a <= 20;
        //@ assert 3 <= b && b <= 20;
        //@ assert res == 2 * a - 1 || res == 2 * b - 1;
        return res;
    }
}
