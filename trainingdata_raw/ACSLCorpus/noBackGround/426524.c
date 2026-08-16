/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100);
    ensures \result >= 0;
    ensures \result == ((a) > (b) ? (a) - (b) : 0);
*/
int func(int a, int b)
{
    int ans;
    
    if (a > b) {
        ans = a - b;
    } else {
        ans = 0;
    }
    
    //@ assert ans >= 0;
    //@ assert ans == ((a) > (b) ? (a) - (b) : 0);
    
    return ans;
}
