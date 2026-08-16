/*@
    requires 0 <= X <= 1;
    ensures (X == 0 ==> \result == 1) && (X == 1 ==> \result == 0);
*/
int func(int X)
{
    int ans;
    
    if (X == 0) {
        ans = 1;
        //@ assert ans == 1;
    } else {
        ans = 0;
        //@ assert ans == 0;
    }
    
    return ans;
}
