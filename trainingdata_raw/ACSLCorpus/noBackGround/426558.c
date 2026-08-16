/*@
    requires (3 <= (a) && (a) <= 20) && (3 <= (b) && (b) <= 20);
    ensures \result == ((a) + (b)) || \result == ((b) * 2 - 1) || \result == ((a) * 2 - 1);
    ensures \result >= ((a) + (b));
    ensures \result >= ((b) * 2 - 1);
    ensures \result >= ((a) * 2 - 1);
*/
int func(int a, int b) {
    int max_val;
    
    //@ assert (3 <= (a) && (a) <= 20);
    //@ assert (3 <= (b) && (b) <= 20);
    
    if (a + b > b * 2 - 1) {
        if (a + b > a * 2 - 1) {
            max_val = a + b;
        } else {
            max_val = a * 2 - 1;
        }
    } else {
        if (b * 2 - 1 > a * 2 - 1) {
            max_val = b * 2 - 1;
        } else {
            max_val = a * 2 - 1;
        }
    }
    
    //@ assert max_val >= a + b;
    //@ assert max_val >= b * 2 - 1;
    //@ assert max_val >= a * 2 - 1;
    //@ assert max_val == a + b || max_val == b * 2 - 1 || max_val == a * 2 - 1;
    
    return max_val;
}
