/*@
    requires (1 <= (n) <= 1000);
    ensures \result == ((n) / 3);
    assigns \nothing;
*/
int func(int n)
{
    int count;
    int temp;
    int is_negative;
    
    count = 0;
    temp = n;
    is_negative = 0;
    
    if (n < 0) {
        temp = -temp;
        is_negative = 1;
    }
    
    /*@
        loop invariant 1 <= n <= 1000;
        loop invariant 0 <= temp <= n;
        loop invariant count == (n - temp) / 3;
        loop invariant temp == n - 3 * count;
        loop invariant count >= 0;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 3) {
        temp -= 3;
        count += 1;
    }
    
    if (is_negative) {
        count = -count;
    }
    
    //@ assert count == ((n) / 3);
    return count;
}
