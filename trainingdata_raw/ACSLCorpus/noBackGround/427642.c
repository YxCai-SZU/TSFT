/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result >= 0;
    ensures \result <= n + m;
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int min_val;
    int result;
    int i;
    
    // Precondition check
    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);
    
    // Manual min calculation
    if (n < m) {
        min_val = n;
    } else {
        min_val = m;
    }
    
    result = 0;
    i = 1;
    
    /*@
        loop invariant 1 <= i <= min_val + 1;
        loop invariant result >= 0;
        loop invariant result <= i - 1;
        loop invariant min_val == (n < m ? n : m);
        loop assigns i, result;
        loop variant min_val - i + 1;
    */
    while (i <= min_val) {
        if ((i * 2) < (n + m)) {
            result += 1;
        }
        i += 1;
    }
    
    // Postcondition verification
    //@ assert result >= 0;
    //@ assert result <= n + m;
    
    return result;
}

int main() {
    return 0;
}
