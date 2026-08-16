/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures ((\result) >= 0);
    ensures ((\result) == (a) - (b) * 2 || (\result) == 0);
    assigns \nothing;
*/
int func(int a, int b) {
    int res;
    
    //@ assert b * 2 <= 200;
    //@ assert a - b * 2 <= 100;
    
    res = a - b * 2;
    
    if (res > 0) {
        //@ assert res == a - b * 2;
        //@ assert res > 0;
        return res;
    } else {
        //@ assert 0 == 0;
        return 0;
    }
}
