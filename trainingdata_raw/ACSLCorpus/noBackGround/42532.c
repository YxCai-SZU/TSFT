/*@
    requires (1 <= (n) && (n) <= 1000000000);
    ensures \result == (((n) - 1) / 2);
    assigns \nothing;
*/
unsigned int func(unsigned int n)
{
    unsigned int count;
    unsigned int temp;
    
    count = 0;
    temp = n - 1;
    
    /*@
        loop invariant 1 <= n && n <= 1000000000;
        loop invariant 0 <= temp;
        loop invariant temp == n - 1 - 2 * count;
        loop invariant 0 <= count;
        loop invariant count <= (n - 1) / 2;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
        //@ assert temp == n - 1 - 2 * count;
    }
    
    //@ assert count == (n - 1) / 2;
    return count;
}

int main(void)
{
    return 0;
}
