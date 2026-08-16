/*@
    requires (1 <= (b) && (b) <= (a) && (a) <= 20 &&
        1 <= (c) && (c) <= 20);
    ensures \result >= 0;
    ensures \result <= c;
    assigns \nothing;
*/
int func(int a, int b, int c)
{
    int min_val;
    int ans;

    //@ assert (1 <= (b) && (b) <= (a) && (a) <= 20 &&         1 <= (c) && (c) <= 20);
    
    if (a < b) {
        min_val = a;
    } else {
        min_val = b;
    }
    //@ assert min_val == ((a) < (b) ? (a) : (b));
    
    ans = c - (min_val - 1);
    //@ assert ans == ((c) - ((((a)) < ((b)) ? ((a)) : ((b))) - 1));
    
    if (ans < 0) {
        //@ assert ans < 0;
        return 0;
    } else {
        //@ assert ans >= 0;
        //@ assert ans <= c;
        return ans;
    }
}
