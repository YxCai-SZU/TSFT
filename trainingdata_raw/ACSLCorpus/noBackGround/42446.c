/*@
    requires (1 <= (n) <= 100);
    ensures \result == (((n) * 800) - ((((n)) / 15) * 200));
*/
int func(int n)
{
    int x;
    int quotient = 0;
    int temp_n = n;
    int count = 0;
    
    x = n * 800;
    
    /*@
        loop invariant 0 <= temp_n <= 100;
        loop invariant 0 <= quotient <= n / 15;
        loop invariant count == quotient;
        loop invariant temp_n == n - count * 15;
        loop invariant (1 <= (n) <= 100);
        loop assigns quotient, temp_n, count;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        quotient += 1;
        temp_n -= 15;
        count += 1;
    }
    
    //@ assert quotient == n / 15;
    //@ assert x - (quotient * 200) == (((n) * 800) - ((((n)) / 15) * 200));
    return x - (quotient * 200);
}

int main() {
    return 0;
}
