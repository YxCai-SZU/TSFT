#include <stdbool.h>
#include <stdint.h>


/*@
    predicate valid_params(integer A, integer B) =
        1 <= A <= 100 && 1 <= B <= 100;

    logic integer initial_sum(integer A, integer B) = A * 3 + B;

    logic integer target_result(integer A, integer B) = (A * 3 + B) / 2;
 */

unsigned int step1_process(unsigned int A, unsigned int B)
{
    unsigned int ans;
    unsigned int count;
    bool is_even;

    ans = A * 3 + B;
    count = 0;
    is_even = true;

    while (ans >= 2)
    {
        //@ assert ans >= 2;
        ans -= 2;
        count += 1;
        is_even = !is_even;
    }

    //@ assert count == target_result(A, B);
    return count;
}


/*@ predicate bounds(integer a, integer b, integer c, integer d) =
      1 <= a && a <= 100 &&
      1 <= b && b <= 100 &&
      1 <= c && c <= 100 &&
      1 <= d && d <= 100;
*/

/*@ logic integer max_of_four(integer a, integer b, integer c, integer d) =
      (a >= b && a >= c && a >= d) ? a :
      (b >= a && b >= c && b >= d) ? b :
      (c >= a && c >= b && c >= d) ? c : d;
*/

/*@ logic integer sum_of_four(integer a, integer b, integer c, integer d) =
      a + b + c + d;
*/

/*@ lemma max_tripled_bound: \forall integer a,b,c,d;
      bounds(a,b,c,d) ==> max_of_four(a,b,c,d) * 3 <= 300;
*/

/*@ lemma sum_bound: \forall integer a,b,c,d;
      bounds(a,b,c,d) ==> sum_of_four(a,b,c,d) <= 400;
*/

/*@ lemma result_bounds: \forall integer a,b,c,d;
      bounds(a,b,c,d) ==>
      (sum_of_four(a,b,c,d) > max_of_four(a,b,c,d) * 3 ?
       max_of_four(a,b,c,d) * 3 : sum_of_four(a,b,c,d)) >= 0;
*/

/*@ lemma result_upper_bound: \forall integer a,b,c,d;
      bounds(a,b,c,d) ==>
      (sum_of_four(a,b,c,d) > max_of_four(a,b,c,d) * 3 ?
       max_of_four(a,b,c,d) * 3 : sum_of_four(a,b,c,d)) <= sum_of_four(a,b,c,d);
*/

int step2_cap(int a, int b, int c, int d)
{
    int max_value = a;
    int sum = 0;
    int max_value_tripled = 0;
    int result = 0;
    
    //@ assert max_value == a;
    
    if (b > max_value) {
        max_value = b;
    }
    //@ assert max_value >= a && max_value >= b;
    
    if (c > max_value) {
        max_value = c;
    }
    //@ assert max_value >= a && max_value >= b && max_value >= c;
    
    if (d > max_value) {
        max_value = d;
    }
    //@ assert max_value >= a && max_value >= b && max_value >= c && max_value >= d;
    
    sum = a + b + c + d;
    //@ assert sum == a + b + c + d;
    
    max_value_tripled = max_value + max_value + max_value;
    //@ assert max_value_tripled == max_value * 3;
    
    //@ assert max_value_tripled <= 300;
    //@ assert sum <= 400;
    
    if (sum > max_value_tripled) {
        result = max_value * 3;
        //@ assert result == max_value * 3;
    } else {
        result = sum;
        //@ assert result == sum;
    }
    
    //@ assert result >= 0;
    //@ assert result <= sum;
    
    return result;
}


/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer division_15(integer n) = n / 15;
    
    logic integer expected_result(integer n) = 
        n * 800 - division_15(n) * 200;
*/

int64_t step3_adjust(int64_t n)
{
    int64_t x;
    int64_t quotient;
    int64_t remainder;
    int64_t divisor;
    int64_t y;
    int64_t ans;
    
    x = n * 800;
    
    quotient = 0;
    remainder = n;
    divisor = 15;
    
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }
    
    y = quotient * 200;
    ans = x - y;
    
    //@ assert ans == n * 800 - division_15(n) * 200;
    
    return ans;
}



int64_t process_packet(unsigned int A, unsigned int B, 
                        int a, int b, int c, int d, 
                        int64_t n)
{
    unsigned int token_fill_rate = step1_process(A, B);
    
    int capacity_limit = step2_cap(a, b, c, d);
    
    int64_t discount_factor = step3_adjust(n);
    
    int64_t effective_rate;
    
    if ((int64_t)token_fill_rate <= (int64_t)capacity_limit) {
        effective_rate = (int64_t)token_fill_rate * discount_factor;
    } else {
        effective_rate = (int64_t)capacity_limit * discount_factor;
    }
    
    //@ assert effective_rate >= 0 && effective_rate <= (int64_t)((A * 3 + B) / 2) * (n * 800 - (n / 15) * 200);
    
    return effective_rate;
}

int main()
{
    return 0;
}
