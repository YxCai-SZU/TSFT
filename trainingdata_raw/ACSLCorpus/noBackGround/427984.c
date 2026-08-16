/*@
    requires ((a) >= 1 && (b) >= 1 && (c) >= 1 && (d) >= 1 &&
        (a) <= 20 && (b) <= 20 && (c) <= 20 && (d) <= 20);
    ensures \result >= 0;
    ensures \result <= a + b + c + d;
    assigns \nothing;
*/
int func(int a, int b, int c, int d)
{
    int ans;
    int tmp1;
    int tmp2;

    //@ assert ((a) >= 1 && (b) >= 1 && (c) >= 1 && (d) >= 1 &&         (a) <= 20 && (b) <= 20 && (c) <= 20 && (d) <= 20);
    
    tmp1 = a < b ? a : b;
    tmp2 = c < d ? c : d;
    ans = tmp1 + tmp2;

    //@ assert ans >= 0;
    //@ assert ans <= a + b + c + d;
    
    return ans;
}
