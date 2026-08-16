/*@
    requires (1 <= (N) && (N) <= 1000000);
    ensures \result == ((((N)) / 2) + (((N)) % 2));
    assigns \nothing;
*/
unsigned int func(unsigned int N)
{
    unsigned int half;
    unsigned int remainder;
    unsigned int ans;

    half = N / 2;
    remainder = N % 2;

    //@ assert half == N / 2;
    //@ assert remainder == N % 2;
    //@ assert half + remainder <= 1000000;

    ans = half + remainder;

    return ans;
}
