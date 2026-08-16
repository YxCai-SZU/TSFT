/*@
    requires 1 <= A <= 3;
    requires 1 <= B <= 3;
    requires A != B;
    ensures \result == 6 - A - B;
    ensures \result == 1 || \result == 2 || \result == 3;
    ensures \result != A;
    ensures \result != B;
*/
int func(int A, int B)
{
    int ans;
    
    //@ assert (1 <= (A) <= 3);
    //@ assert (1 <= (B) <= 3);
    //@ assert A != B;
    
    ans = 6 - A - B;
    
    //@ assert ans == 6 - A - B;
    //@ assert ans == 1 || ans == 2 || ans == 3;
    //@ assert ans != A;
    //@ assert ans != B;
    
    return ans;
}
