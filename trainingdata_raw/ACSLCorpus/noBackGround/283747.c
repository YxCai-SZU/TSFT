/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result <= a && \result <= b && \result >= 1;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b) {
    unsigned int i;
    unsigned int ans;
    
    i = 1;
    ans = 0;
    
    /*@
        loop invariant 1 <= i <= 101;
        loop invariant ans <= a && ans <= b && ans >= 0;
        loop invariant i > 1 ==> ans >= 1;
        loop invariant (1 <= (a) <= 100 && 1 <= (b) <= 100);
        loop assigns i, ans;
        loop variant ((a) + 1 - (i));
    */
    while (i <= a && i <= b) {
        //@ assert i <= a && i <= b;
        ans = i;
        i = i + 1;
    }
    
    //@ assert ans >= 1;
    return ans;
}
