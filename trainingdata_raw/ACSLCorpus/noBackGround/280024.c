/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100);
    ensures \result == a * b;
    ensures \result >= 1 && \result <= 10000;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    unsigned int ans;

    //@ assert (1 <= (a) <= 100 && 1 <= (b) <= 100);
    //@ assert a * b <= 10000;
    //@ assert a * b >= 1;
    
    ans = a * b;
    return ans;
}
