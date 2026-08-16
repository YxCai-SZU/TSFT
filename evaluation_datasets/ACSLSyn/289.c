/* Merged functions with ACSL specifications and a complex synthesized function */

/* First code snippet */
/*@
    predicate a_times_2_equals_2_times_a(integer a) =
        a * 2 == 2 * a;

    lemma calc_example_6: \forall integer a; a_times_2_equals_2_times_a(a);
*/

void test_example_6(void) {
    //@ assert 1 <= 2;
    //@ assert 2 <= 3;
    //@ assert 3 <= 4;
    int a = 2;
    int b = 5;
    //@ assert 2 <= 3;
    //@ assert 3 <= 4;
    //@ assert 4 <= 5;
}

void test_example_7(int a, int b) {
    //@ assert a <= b;
    //@ assert b <= a + 2;
}

/* Second code snippet */
/*@
    predicate is_valid_range(integer x) = 1 <= x <= 100000;

    logic integer mod_100(integer x) = x % 100;
    logic integer div_100(integer x) = x / 100;

    lemma mod_bound: \forall integer x; is_valid_range(x) ==> 0 <= mod_100(x) <= 99;
    lemma mult_bound: \forall integer x; is_valid_range(x) ==> mod_100(x) * 21 <= 2079;
    lemma nonneg_mult: \forall integer x; is_valid_range(x) ==> mod_100(x) * 21 >= 0;
*/

int func(unsigned int x)
{
    int n;
    int q;
    int n_2;

    //@ assert is_valid_range(x);
    n = x % 100;
    q = x / 100;

    //@ assert 0 <= n <= 99;
    //@ assert n * 21 <= 2079;
    //@ assert n * 21 >= 0;

    if (n * 21 < (int)x)
    {
        n_2 = 1;
    }
    else
    {
        n_2 = 0;
    }

    //@ assert n_2 == 0 || n_2 == 1;
    //@ assert n_2 == 1 ==> n * 21 < x;
    return n_2;
}

/* Third code snippet */
/*@
    predicate is_in_range(integer v) = 0 <= v <= 100;
    predicate is_integer(integer v) = v == (integer)(long long)v;
    
    lemma func_lemma:
        \forall integer a, b, x;
        is_in_range(a) && is_in_range(b) && is_in_range(x) &&
        is_integer(a) && is_integer(b) && is_integer(x) ==>
        (x >= 0 && x <= a && a + b >= x ==> (x >= 0 && x <= a && a + b >= x));
*/

#include <stdbool.h>

bool func2(long long a, long long b, long long x) {
    bool result;
    
    //@ assert x >= 0 && x <= a && a + b >= x ==> (x >= 0 && x <= a && a + b >= x);
    
    result = (x >= 0 && x <= a && a + b >= x);
    return result;
}

/* Complex synthesized function: Payment Amount Validator
 *
 * Scenario: A payment processing system validates a transaction amount.
 * The input 'amount' (1..100000) is checked for a special condition: 
 * if the remainder (amount % 100) * 21 < amount, the transaction qualifies 
 * for a discount. Additionally, the discount percentage (discount_pct, 0..100) 
 * and the discount cap (discount_cap, 0..100) must be such that the discount 
 * amount (amount * discount_pct / 100) is within the cap (i.e., <= discount_cap). 
 * The system also runs a basic sanity check using test_example_6 and test_example_7.
 *
 * High-level property: The final decision (approve or deny) correctly reflects
 * that the discount amount does not exceed the cap when the transaction qualifies.
 */

int validate_payment(unsigned int amount, long long discount_pct, long long discount_cap) {
    test_example_6();
    test_example_7(1, 3);  // a <= b and b <= a+2 holds: 1 <= 3 <= 3

    int qualifies = func(amount);
    
    long long discount_amt = (long long)amount * discount_pct / 100;
    bool within_cap;
    if (discount_amt <= discount_cap) {
        within_cap = true;
    } else {
        within_cap = false;
    }
    
    int decision;
    if (qualifies && within_cap) {
        decision = 1;
    } else {
        decision = 0;
    }
    
    //@ assert decision == 1 ==> ((amount % 100) * 21 < amount) && (discount_amt <= discount_cap);
    return decision;
}

int main() {
    return 0;
}
