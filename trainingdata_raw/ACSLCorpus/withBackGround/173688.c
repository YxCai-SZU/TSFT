/*@
    predicate is_valid_a(integer a) = 1 <= a && a <= 1000000000;
    predicate is_valid_temp(integer a, integer temp) = 
        temp <= a && temp >= 1;
    predicate is_valid_is_even(integer is_even) = 
        is_even == 0 || is_even == 1;
*/

/*@
    requires is_valid_a(a);
    ensures \result >= 0 || \result == -1;
    assigns \nothing;
*/
long long func(unsigned long long a)
{
    int is_even = 1;
    unsigned long long temp_a = a;
    
    /*@
        loop invariant is_valid_a(a);
        loop invariant is_valid_temp(a, temp_a);
        loop invariant is_valid_is_even(is_even);
        loop assigns is_even, temp_a;
        loop variant temp_a;
    */
    while (temp_a > 1)
    {
        if (temp_a % 2 == 1)
        {
            is_even = 0;
        }
        temp_a /= 2;
    }
    
    if (is_even)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}
