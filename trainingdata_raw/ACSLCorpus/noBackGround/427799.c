/*@
    requires (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
    ensures \result >= 0;
    ensures \result <= ((A) * 3 + (P));
*/
int func(int A, int P)
{
    int sum;
    int ans;
    int count;

    //@ assert (0 <= (A) && (A) <= 100 &&         0 <= (P) && (P) <= 100);
    
    sum = A * 3 + P;
    ans = 0;
    count = 0;

    /*@
        loop invariant sum >= 0;
        loop invariant sum <= ((A) * 3 + (P));
        loop invariant ans >= 0;
        loop invariant ans <= (((A) * 3 + (P)) - sum) / 2;
        loop invariant (0 <= (A) && (A) <= 100 &&
        0 <= (P) && (P) <= 100);
        loop assigns sum, ans, count;
        loop variant sum;
    */
    while (sum >= 2)
    {
        sum -= 2;
        ans += 1;
        //@ assert ans <= (((A) * 3 + (P)) - sum) / 2;
    }

    //@ assert ans <= (((A) * 3 + (P)) - sum) / 2;
    //@ assert ans <= ((A) * 3 + (P));
    
    return ans;
}

int main()
{
    return 0;
}
