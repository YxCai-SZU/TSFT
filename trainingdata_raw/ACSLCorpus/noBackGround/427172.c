/*@
    requires x >= 0;
    ensures \result == ((x) * (x));
    ensures \result >= 0;
*/
int compute_square(int x)
{
    //@ assert x >= 0;
    int result = x * x;
    //@ assert result == ((x) * (x));
    //@ assert result >= 0;
    return result;
}

int main()
{
    int x = 5;
    int sq = compute_square(x);
    return 0;
}
