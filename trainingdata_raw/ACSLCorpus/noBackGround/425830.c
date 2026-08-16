/*@
    requires (1 <= (A) <= 9) && (1 <= (B) <= 9) && (1 <= (C) <= 9);
    ensures \result == (A + B + C) % 2;
    assigns \nothing;
*/
unsigned int func(unsigned int A, unsigned int B, unsigned int C)
{
    unsigned int ans;
    //@ assert (1 <= (A) <= 9);
    //@ assert (1 <= (B) <= 9);
    //@ assert (1 <= (C) <= 9);
    //@ assert 3 <= A + B + C <= 27;
    ans = (A + B + C) % 2;
    return ans;
}
