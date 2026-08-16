/*@
    requires (400 <= (x) && (x) < 2000);
    ensures (((\result) == 8 || (\result) == 10 || (\result) == 12) &&
        (400 <= (x) && (x) < 600 ==> (\result) == 8) &&
        (600 <= (x) && (x) < 800 ==> (\result) == 10) &&
        (800 <= (x) && (x) < 2000 ==> (\result) == 12));
    assigns \nothing;
*/
int func(int x)
{
    int ans;
    //@ assert (400 <= (x) && (x) < 2000);
    
    if (400 <= x && x < 600) {
        ans = 8;
    } else if (600 <= x && x < 800) {
        ans = 10;
    } else {
        ans = 12;
    }
    
    //@ assert (400 <= x && x < 600 ==> ans == 8);
    //@ assert (600 <= x && x < 800 ==> ans == 10);
    //@ assert (800 <= x && x < 2000 ==> ans == 12);
    
    return ans;
}
