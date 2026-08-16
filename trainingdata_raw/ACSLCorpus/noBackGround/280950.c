/*@
    requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
    ensures \result == 1 <==> (a + b + c) % 2 == 0;
    ensures \result == 0 <==> (a + b + c) % 2 != 0;
*/
int func(unsigned int a, unsigned int b, unsigned int c)
{
    unsigned int sum;
    int is_even;
    
    sum = a + b + c;
    is_even = 0;
    
    /*@
        loop invariant 0 <= sum <= a + b + c;
        loop invariant sum % 2 == (a + b + c) % 2;
        loop invariant (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100);
        loop assigns sum;
        loop variant sum;
    */
    while (sum >= 2)
    {
        //@ assert sum % 2 == (a + b + c) % 2;
        sum = sum - 2;
    }
    
    if (sum == 0)
    {
        is_even = 1;
    }
    
    //@ assert is_even == 1 ==> (a + b + c) % 2 == 0;
    //@ assert is_even == 0 ==> (a + b + c) % 2 != 0;
    
    return is_even;
}
