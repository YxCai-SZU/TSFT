/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    ensures \result >= 0;
    ensures \result <= a;
    ensures \result == a - (b * 2) || \result == 0;
*/
int func(int a, int b)
{
    int ans;
    
    //@ assert (1 <= (a) && (a) <= 100);
    //@ assert (1 <= (b) && (b) <= 100);
    
    if (b * 2 > a) {
        ans = 0;
        //@ assert ans == 0;
    } else {
        ans = a - b * 2;
        //@ assert ans == a - b * 2;
    }
    
    //@ assert ans >= 0 && ans <= a;
    return ans;
}
