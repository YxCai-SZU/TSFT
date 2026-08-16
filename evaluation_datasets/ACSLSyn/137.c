#include <stdbool.h>

/*@
    predicate k_in_range(integer k) = 1 <= k && k <= 100;
    predicate x_in_range(integer x) = 1 <= x && x <= 100000;
    predicate temp_eq(integer temp, integer i) = temp == 500 * i;
    predicate result_def(integer temp, integer x, integer result) = result == (temp >= x ? 1 : 0);
*/

int func(int k, int x)
{
    int temp;
    int i;
    
    temp = 0;
    i = 0;
    
    while (i < k)
    {
        temp += 500;
        i += 1;
    }
    
    //@ assert temp == 500 * k;
    
    return temp >= x ? 1 : 0;
}

/*@
    predicate is_mod_in_range(integer n, integer a) =
        n % 500 <= a && n % 500 < 500;
*/

bool func2(unsigned int n, unsigned int a)
{
    unsigned int mod_result;
    bool comparison_result;
    bool final_result;
    
    mod_result = n % 500;
    
    //@ assert mod_result == n % 500;
    
    comparison_result = mod_result <= a;
    
    //@ assert comparison_result == (mod_result <= a);
    
    //@ assert mod_result < 500;
    
    final_result = comparison_result && (mod_result < 500);
    
    //@ assert final_result == true <==> is_mod_in_range(n, a);
    
    return final_result;
}

/*@
    predicate threshold_check_complete(integer k, integer x, unsigned int n, unsigned int a, int result1) =
        (result1 == 1 <==> 500 * k >= x);
*/

int process_threshold_and_modulo(int k, int x, unsigned int n, unsigned int a)
{
    int result1;
    bool result2;
    
    result1 = func(k, x);
    result2 = func2(n, a);
    
    //@ assert result1 == (500 * k >= x ? 1 : 0);
    //@ assert result2 == true <==> (n % 500 <= a);
    
    //@ assert (result1 == 1 && result2 == true) ==> (500 * k >= x && n % 500 <= a);
    
    return result1;
}
