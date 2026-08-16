/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == ((n) * ((n) + 1)) / 2;
    assigns \nothing;
*/
int func(int n)
{
    // Variable declarations at top of scope
    int sum;
    int result = 0;
    int count = 0;
    int temp_sum;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    //@ assert 0 <= n * (n + 1) <= 10100;
    sum = n * (n + 1);
    temp_sum = sum;
    
    /*@
        loop invariant 0 <= count <= sum / 2;
        loop invariant temp_sum == sum - 2 * count;
        loop invariant sum == n * (n + 1);
        loop invariant 0 <= sum <= 10100;
        loop assigns temp_sum, count;
        loop variant temp_sum;
    */
    while (temp_sum >= 2)
    {
        temp_sum -= 2;
        count += 1;
    }
    
    result = count;
    
    //@ assert result * 2 == n * (n + 1);
    
    return result;
}

int main()
{
    return 0;
}
