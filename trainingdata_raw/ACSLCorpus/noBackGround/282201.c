/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result >= 0 && \result <= a;
    assigns \nothing;
*/
int func(int a, int b) {
    int ans;
    
    //@ assert (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    
    if (a - b * 2 > 0) {
        ans = a - b * 2;
    } else {
        ans = 0;
    }
    
    //@ assert ans >= 0;
    //@ assert ans <= a;
    
    return ans;
}
