/*@
    predicate is_valid_n(integer n) = 1 <= n && n <= 1000000000;

    logic integer func_result(integer n) = (n - 1) / 2;

    lemma func_lemma:
        \forall integer n;
        is_valid_n(n) ==>
        func_result(n) >= 0 &&
        func_result(n) <= (n - 1) / 2;
*/

/*@
    requires is_valid_n(n);
    ensures \result == func_result(n);
    assigns \nothing;
*/
long func(long n)
{
    long result = 0;
    long temp = n - 1;
    long count = 0;

    /*@
        loop invariant 1 <= n && n <= 1000000000;
        loop invariant temp >= 0;
        loop invariant temp == n - 1 - 2 * count;
        loop invariant count >= 0;
        loop invariant count <= (n - 1) / 2;
        loop assigns temp, count;
        loop variant temp;
    */
    while (temp >= 2)
    {
        //@ assert temp >= 2;
        temp -= 2;
        count += 1;
    }

    result = count;
    //@ assert result == func_result(n);
    return result;
}

int main(void)
{
    return 0;
}
