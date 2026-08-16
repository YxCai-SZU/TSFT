/*@
    requires n < 0x100000000;
    ensures \result == 1 <==> ((n) % 2 == 0);
    assigns \nothing;
*/
int func(unsigned int n)
{
    int is_even_result = 0;
    unsigned int temp = n;
    
    /*@
        loop invariant 0 <= temp <= n;
        loop invariant temp % 2 == n % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 2)
    {
        temp -= 2;
    }
    
    if (temp == 0)
    {
        is_even_result = 1;
    }
    
    //@ assert is_even_result == 1 <==> ((n) % 2 == 0);
    return is_even_result;
}

int main()
{
    return 0;
}
