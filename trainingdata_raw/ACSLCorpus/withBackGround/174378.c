/*@
    predicate in_range(integer x) = 400 <= x && x <= 1999;
    
    predicate ans_range(integer a) = a >= 0 && a <= 8;
    
    predicate ans_correct(integer x, integer a) =
        (x <= 600 ==> a == 8) &&
        (600 < x && x <= 800 ==> a == 7) &&
        (800 < x && x <= 1000 ==> a == 6) &&
        (1000 < x && x <= 1200 ==> a == 5) &&
        (1200 < x && x <= 1400 ==> a == 4) &&
        (1400 < x && x <= 1600 ==> a == 3) &&
        (1600 < x && x <= 1800 ==> a == 2) &&
        (1800 < x && x <= 1999 ==> a == 1);
*/

/*@
    requires in_range(x);
    ensures ans_range(\result);
    ensures ans_correct(x, \result);
*/
long func(long x)
{
    long ans = -1;
    
    //@ assert in_range(x);
    
    if (x <= 600) {
        ans = 8;
        //@ assert ans == 8;
    } else if (x <= 800) {
        ans = 7;
        //@ assert ans == 7;
    } else if (x <= 1000) {
        ans = 6;
        //@ assert ans == 6;
    } else if (x <= 1200) {
        ans = 5;
        //@ assert ans == 5;
    } else if (x <= 1400) {
        ans = 4;
        //@ assert ans == 4;
    } else if (x <= 1600) {
        ans = 3;
        //@ assert ans == 3;
    } else if (x <= 1800) {
        ans = 2;
        //@ assert ans == 2;
    } else if (x <= 1999) {
        ans = 1;
        //@ assert ans == 1;
    }
    
    //@ assert ans_range(ans);
    //@ assert ans_correct(x, ans);
    
    return ans;
}
