/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= 100 &&
        (m) % 2 == 0);
    ensures \result == n + ((m) / 2);
*/
int func(int n, int m)
{
    int half_m;
    int temp_m;
    
    half_m = 0;
    temp_m = m;
    
    /*@
        loop invariant 0 <= temp_m <= m;
        loop invariant half_m >= 0;
        loop invariant half_m * 2 == m - temp_m;
        loop invariant (1 <= (n) <= 100 &&
        1 <= (m) <= 100 &&
        (m) % 2 == 0);
        loop assigns temp_m, half_m;
    */
    while (temp_m >= 2)
    {
        //@ assert temp_m >= 2;
        temp_m -= 2;
        half_m += 1;
    }
    
    //@ assert half_m == ((m) / 2);
    return n + half_m;
}
