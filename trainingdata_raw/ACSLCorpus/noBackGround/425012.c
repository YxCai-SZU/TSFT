/*@
    requires (1 <= (a) && (a) <= 100) && (1 <= (b) && (b) <= 100) && (1 <= (c) && (c) <= 100);
    ensures \result <= b / a;
    ensures \result <= c;
    ensures \result == b / a || \result == c;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int ans;
    
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert 1 <= c && c <= 100;
    
    if (b / a < c) {
        ans = (unsigned int)(b / a);
        //@ assert ans == b / a;
    } else {
        ans = c;
        //@ assert ans == c;
    }
    
    //@ assert ans == b / a || ans == c;
    //@ assert ans <= b / a;
    //@ assert ans <= c;
    
    return ans;
}
