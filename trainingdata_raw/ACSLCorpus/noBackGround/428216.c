/*@
    requires ((a) >= 1) && ((b) >= (a) && (b) <= 1000000) && ((c) >= 1 && (c) <= 1000000);
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b, int c) {
    int ans = 0;
    int x = 1;
    
    /*@
        loop invariant 1 <= x <= b + 1;
        loop invariant ans >= 0;
        loop invariant ans <= x - 1;
        loop assigns ans, x;
        loop variant b - x + 1;
    */
    while (x <= b) {
        int r = x;
        
        /*@
            loop invariant r >= 0;
            loop invariant r <= x;
            loop invariant r - a >= c ==> r >= c;
            loop assigns r;
            loop variant r;
        */
        while (r - a >= c) {
            //@ assert r >= c;
            r -= c;
        }
        
        //@ assert r >= 0 && r <= x;
        ans += (r == 0) ? 1 : 0;
        x += 1;
    }
    
    return ans;
}
