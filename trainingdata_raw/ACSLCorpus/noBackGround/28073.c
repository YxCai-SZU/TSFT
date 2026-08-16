/*@
    requires (0 <= (A) && (A) <= 100 && 0 <= (P) && (P) <= 100);
    ensures \result == (((A) * 3 + (P)) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int A, unsigned int P)
{
    unsigned int ans;

    //@ assert 0 <= A && A <= 100;
    //@ assert 0 <= P && P <= 100;
    
    //@ assert A * 3 <= 300;
    //@ assert A * 3 + P <= 400;

    ans = (A * 3 + P) / 2;

    //@ assert ans >= 0;
    //@ assert A * 3 + P >= 0;

    return ans;
}
