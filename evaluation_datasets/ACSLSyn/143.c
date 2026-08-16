#include <stdbool.h>

/*@ predicate conjunction(integer a, integer b, integer c) = 
      a != 0 && b != 0 && c != 0; */

/*@ predicate disjunction(integer a, integer b, integer c) = 
      a != 0 || b != 0 || c != 0; */

/*@ lemma conjunction_true: 
      conjunction(1, 1, 1); */

/*@ lemma conjunction_false: 
      !conjunction(1, 0, 1); */

/*@ lemma disjunction_true: 
      disjunction(0, 1, 0); */

bool func(unsigned int n)
{
    bool is_even;
    bool is_five;
    bool result;
    
    is_even = false;
    if (n % 2 == 0) {
        is_even = true;
    }
    
    is_five = false;
    if (n % 5 == 0) {
        is_five = true;
    }
    
    //@ assert is_even == (n % 2 == 0);
    //@ assert is_five == (n % 5 == 0);
    
    result = is_even || is_five;
    return result;
}

/*@
    predicate is_valid_params(integer N, integer A) =
        1 <= N <= 1000 && 0 <= A <= 1000;

    logic integer mod_500(integer N) = N % 500;

    lemma mod_500_range: \forall integer N; 1 <= N <= 1000 ==> 0 <= mod_500(N) < 500;
*/

bool func2(unsigned int N, unsigned int A)
{
    bool result;
    unsigned int mod_result;

    //@ assert 0 <= N % 500 < 500;
    
    mod_result = N % 500;
    result = mod_result < A + 1;
    
    //@ assert result == (N % 500 < A + 1);
    return result;
}

/*@
    predicate valid_input(integer n, integer N, integer A) =
        2 <= n <= 100000 && 1 <= N <= 1000 && 0 <= A <= 1000;
    
    predicate divisible_by_2_or_5(integer n) = (n % 2 == 0 || n % 5 == 0);
    
    predicate remainder_less_than_A_plus_1(integer N, integer A) = (N % 500 < A + 1);
*/

bool check_divisible_and_remainder(unsigned int n, unsigned int N, unsigned int A)
{
    bool cond1;
    bool cond2;
    bool final_result;
    
    cond1 = func(n);
    
    cond2 = func2(N, A);
    
    final_result = cond1 && cond2;
    
    //@ assert final_result <==> ((n % 2 == 0 || n % 5 == 0) && (N % 500 < A + 1));
    
    return final_result;
}
