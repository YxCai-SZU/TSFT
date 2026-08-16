/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * (314)/ 100);
    assigns \nothing;
*/
long func(long r) {
    long pi_approx;
    long ans;
    long div;
    long temp;
    
    pi_approx = 314;
    ans = 2 * r * pi_approx;
    div = 0;
    temp = ans;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant (314)== 314;
        loop invariant ans == 2 * r * (314);
        loop invariant temp >= 0;
        loop invariant temp <= ans;
        loop invariant div >= 0;
        loop invariant div * 100 + temp == ans;
        loop assigns temp, div;
        loop variant temp;
    */
    while (temp >= 100) {
        //@ assert temp >= 100;
        temp -= 100;
        div += 1;
    }
    
    //@ assert div == (2 * (r) * (314)/ 100);
    return div;
}
