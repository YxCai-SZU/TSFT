/*@
    predicate is_valid_input(integer x) = 1 <= x && x <= 100000;
    predicate valid_result(integer r) = r >= 0 || r == -1;
    predicate matches_input(integer r, integer inp) = r >= 0 ==> (r * 8) / 100 == inp;
*/

/*@
    requires is_valid_input(input);
    ensures valid_result(\result);
    ensures matches_input(\result, input);
*/
int func(int input)
{
    int n;
    int result;
    int ans;
    int div;
    int temp;

    n = 0;
    /*@
        loop invariant 0 <= n <= 100000;
        loop assigns n, result, ans, div, temp;
        loop variant 100000 - n;
    */
    while (n < 100000)
    {
        ans = n * 8;
        div = 0;
        temp = ans;
        /*@
            loop invariant temp >= 0;
            loop invariant div >= 0;
            loop invariant temp + 100 * div == ans;
            loop assigns temp, div;
            loop variant temp;
        */
        while (temp >= 100)
        {
            temp -= 100;
            div += 1;
        }
        //@ assert div == ans / 100;
        if (div == input)
        {
            result = n;
            //@ assert result >= 0;
            //@ assert (result * 8) / 100 == input;
            return result;
        }
        n += 1;
    }
    result = -1;
    //@ assert result == -1;
    return result;
}
