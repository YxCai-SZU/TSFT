/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == (((n) / 500) * 1000 + ((n) % 500 / 5) * 5);
    assigns \nothing;
*/
int func(int n)
{
    int result;
    int temp_n;
    int five_hundreds;
    int fives;
    
    result = 0;
    temp_n = n;
    five_hundreds = 0;
    
    /*@
        loop invariant (1 <= (n) && (n) <= 10000);
        loop invariant 0 <= five_hundreds && five_hundreds <= n / 500;
        loop invariant temp_n == n - five_hundreds * 500;
        loop assigns temp_n, five_hundreds;
        loop variant temp_n;
    */
    while (temp_n >= 500)
    {
        //@ assert (1 <= (n) && (n) <= 10000);
        temp_n = temp_n - 500;
        //@ assert 0 <= five_hundreds + 1 && five_hundreds + 1 <= n / 500;
        five_hundreds = five_hundreds + 1;
        //@ assert temp_n == n - five_hundreds * 500;
    }
    
    result = five_hundreds * 1000;
    
    fives = 0;
    
    /*@
        loop invariant (1 <= (n) && (n) <= 10000);
        loop invariant 0 <= five_hundreds && five_hundreds <= n / 500;
        loop invariant 0 <= fives && fives <= (n - five_hundreds * 500) / 5;
        loop invariant temp_n == n - five_hundreds * 500 - fives * 5;
        loop invariant result == five_hundreds * 1000;
        loop assigns temp_n, fives;
        loop variant temp_n;
    */
    while (temp_n >= 5)
    {
        //@ assert (1 <= (n) && (n) <= 10000);
        temp_n = temp_n - 5;
        //@ assert 0 <= fives + 1 && fives + 1 <= (n - five_hundreds * 500) / 5;
        fives = fives + 1;
        //@ assert temp_n == n - five_hundreds * 500 - fives * 5;
        //@ assert result == five_hundreds * 1000;
    }
    
    result = result + fives * 5;
    
    return result;
}
