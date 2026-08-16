/*@
    requires ((((a)) >= 1 && ((a)) <= 100) && (((b)) >= 0 && ((b)) <= ((a)) * ((a))));
    ensures \result == ((((a)) * ((a))) - (b));
    assigns \nothing;
*/
int func(int a, int b) {
    // Variable declarations at top of scope
    int res;
    
    //@ assert ((a) >= 1 && (a) <= 100);
    //@ assert ((b) >= 0 && (b) <= (a) * (a));
    //@ assert ((a) * (a)) <= 100 * 100;
    
    res = a * a - b;
    
    //@ assert res == ((((a)) * ((a))) - (b));
    return res;
}
