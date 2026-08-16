/*@
predicate valid_range(integer n) = 1 <= n <= 100;

logic integer calculate_result(integer n) = n * 2 * 3;

lemma result_correct: \forall integer n; valid_range(n) ==> calculate_result(n) == n * 2 * 3;
*/

/*@
requires valid_range(n);
ensures \result == calculate_result(n);
assigns \nothing;
*/
int func(int n)
{
    int pi_approx;
    int circumference;
    
    //@ assert valid_range(n);
    
    pi_approx = 3;
    //@ assert pi_approx == 3;
    
    circumference = n * 2 * pi_approx;
    //@ assert circumference == calculate_result(n);
    
    return circumference;
}
