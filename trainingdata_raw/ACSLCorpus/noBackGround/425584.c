/*@
    requires (1 <= (N) <= 100);
    requires (1 <= (i) <= (N));
    ensures (1 <= (\result) <= (N) && (\result) == (N) - (i) + 1);
*/
int func(int N, int i)
{
    int j;
    
    //@ assert N - i >= 0;
    //@ assert N - i + 1 <= 100;
    
    j = N - i + 1;
    return j;
}
