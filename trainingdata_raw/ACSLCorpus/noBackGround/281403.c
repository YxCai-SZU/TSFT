/*@
    requires (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100);
    ensures \result == ((a) >= (b) ? 0 : (a) - (b));
    ensures (a >= b ==> \result == 0);
    ensures (a < b ==> \result == a - b);
*/
int func(int a, int b)
{
    int ans;
    //@ assert (-100 <= (a) && (a) <= 100) && (-100 <= (b) && (b) <= 100);
    
    if (a >= b) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        ans = a - b;
        //@ assert ans == a - b;
    }
    
    //@ assert ans == ((a) >= (b) ? 0 : (a) - (b));
    return ans;
}
