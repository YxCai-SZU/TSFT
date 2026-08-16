/*@
    requires (1 <= (n) <= 20 && 1 <= (a) <= 50 && 1 <= (b) <= 50);
    ensures \result == b || \result == a * n;
    ensures \result <= b;
    ensures \result <= a * n;
*/
int func(int n, int a, int b)
{
    // Variable declarations at scope top
    int max_val;
    int min_val;
    
    //@ assert 1 <= a * n <= 1000;
    
    if (a * n < b) {
        max_val = a * n;
    } else {
        max_val = b;
    }
    
    min_val = b;
    if (a * n < min_val) {
        min_val = a * n;
    }
    
    //@ assert min_val == b || min_val == a * n;
    //@ assert min_val <= b;
    //@ assert min_val <= a * n;
    
    return min_val;
}
