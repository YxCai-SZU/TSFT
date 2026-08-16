/*@
    predicate valid_range(integer r) = 1 <= r && r <= 100;
    logic integer ans_value(integer r) = 2 * r * 314;
    logic integer final_result(integer r) = ans_value(r) / 100;
    
    lemma ans_non_negative: \forall integer r; valid_range(r) ==> ans_value(r) >= 0;
    lemma division_correct: \forall integer r; valid_range(r) ==> final_result(r) == 2 * r * 314 / 100;
*/

/*@
    requires valid_range(r);
    ensures \result == final_result(r);
    assigns \nothing;
*/
long func(long r)
{
    long pi = 314;
    long ans = 2 * r * pi;
    long result = 0;
    long temp = ans;
    long count = 0;
    
    /*@
        loop invariant 1 <= r && r <= 100;
        loop invariant pi == 314;
        loop invariant ans == 2 * r * pi;
        loop invariant temp >= 0;
        loop invariant temp == ans - 100 * count;
        loop invariant result == count;
        loop assigns temp, result, count;
        loop variant temp;
    */
    while (temp >= 100)
    {
        //@ assert temp >= 100;
        temp -= 100;
        result += 1;
        count += 1;
    }
    
    //@ assert result == final_result(r);
    return result;
}
