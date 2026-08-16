/* Scenario: Financial transaction fee calculation system
 * 
 * This system processes transaction amounts and applies tiered fee structures.
 * The data flow is:
 * 1. First, validate the transaction amount is in a valid range and check if it's a clean amount (no cents)
 * 2. Then, compute the applicable fee based on two different fee schedules
 * 3. Finally, combine the fee with the transaction amount to produce the final charge
 *
 * The final assertion verifies that the total charge is always greater than or equal to the original amount
 * plus a minimum fee, ensuring the system never loses money on a transaction.
 */

#include <stdbool.h>

/* Original function 1: Transaction amount validation */
/*@
    predicate is_in_range(integer x) = 1 <= x && x <= 100000;
    
    logic integer division_result(integer x) = x / 100;
    logic integer no_carry_value(integer x) = x - division_result(x) * 100;
    
    lemma division_property:
        \forall integer x; is_in_range(x) ==> 
            division_result(x) * 100 <= x;
*/

bool validate_amount(unsigned long x) {
    unsigned long n;
    unsigned long no_carry;
    bool result;
    
    n = x / 100;
    no_carry = x - n * 100;
    
    if (no_carry == x) {
        //@ assert no_carry == x;
        result = true;
    } else {
        //@ assert no_carry != x;
        result = (n * 100 <= x);
    }
    
    return result;
}

/* Original function 2: Fee calculation based on two schedules */
/*@
    predicate valid_range(integer a) = 2 <= a && a <= 100;

    logic integer double_a(integer a) = a * 2;
    logic integer double_b_minus_one(integer b) = b * 2 - 1;

    lemma result_nonnegative:
        \forall integer a, b, res;
            valid_range(a) && valid_range(b) &&
            (res == double_a(a) || res == double_b_minus_one(b)) ==>
            res >= 0;
*/

int calculate_fee(int a, int b)
{
    int res;
    //@ assert valid_range(a) && valid_range(b);
    
    if (a * 2 < b * 2 - 1)
    {
        res = a * 2;
        //@ assert res == double_a(a);
    }
    else
    {
        res = b * 2 - 1;
        //@ assert res == double_b_minus_one(b);
    }
    
    //@ assert res == double_a(a) || res == double_b_minus_one(b);
    //@ assert res >= 0;
    
    return res;
}

/* Original function 3: Transaction digit processing and maximum charge computation */
/*@
    predicate sorted_range(int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> 1 <= arr[i] <= 9;

    logic integer max_of_three(integer a, integer b, integer c) =
        (a * 10 + b + c) > (a + b * 10 + c) ?
            ((a * 10 + b + c) > (a + b + c * 10) ? (a * 10 + b + c) : (a + b + c * 10))
        :
            ((a + b * 10 + c) > (a + b + c * 10) ? (a + b * 10 + c) : (a + b + c * 10));

    lemma max_result_relation:
        \forall integer a, b, c;
            1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9 ==>
            max_of_three(a, b, c) == (a * 10 + b + c) ||
            max_of_three(a, b, c) == (a + b * 10 + c) ||
            max_of_three(a, b, c) == (a + b + c * 10);

    lemma min_value_bound:
        \forall integer a, b, c;
            1 <= a <= 9 && 1 <= b <= 9 && 1 <= c <= 9 ==>
            max_of_three(a, b, c) >= 11;
*/

int compute_max_charge(int a, int b, int c)
{
    int max1;
    int max2;
    int sorted[3];
    int i;
    int j;
    int current;
    int next;

    if (a * 10 + b + c > a + b * 10 + c)
    {
        max1 = a * 10 + b + c;
    }
    else
    {
        max1 = a + b * 10 + c;
    }

    if (max1 > a + b + c * 10)
    {
        max2 = max1;
    }
    else
    {
        max2 = a + b + c * 10;
    }

    sorted[0] = a;
    sorted[1] = b;
    sorted[2] = c;

    //@ assert sorted_range(&sorted[0], 3);

    i = 0;
    while (i < 2)
    {
        j = 0;
        while (j < 2 - i)
        {
            current = sorted[j];
            next = sorted[j + 1];
            if (current > next)
            {
                sorted[j] = next;
                sorted[j + 1] = current;
            }
            j = j + 1;
        }
        i = i + 1;
    }

    //@ assert sorted_range(&sorted[0], 3);
    //@ assert max2 == max_of_three(a, b, c);

    if (sorted[0] == sorted[1] && sorted[1] == sorted[2])
    {
        return max2;
    }
    else if (sorted[0] == sorted[1] || sorted[1] == sorted[2])
    {
        return max2;
    }
    else
    {
        return max2;
    }
}

/* Synthesized function: Process financial transaction with fee calculation
 * 
 * This function processes a transaction amount and computes the total charge:
 * 1. Validates the transaction amount is in valid range and checks if it's a clean amount
 * 2. Calculates the applicable fee based on tiered fee schedules
 * 3. Computes the maximum possible charge using the transaction digits
 * 4. Returns the total charge (original amount + fee + additional charge)
 *
 * @param amount - The transaction amount (1 to 100000)
 * @param fee_tier1 - First fee schedule parameter (2 to 100)
 * @param fee_tier2 - Second fee schedule parameter (2 to 100)
 * @param digit1 - First digit of transaction code (1 to 9)
 * @param digit2 - Second digit of transaction code (1 to 9)
 * @param digit3 - Third digit of transaction code (1 to 9)
 * @return The total charge amount
 */
int process_transaction(unsigned long amount, int fee_tier1, int fee_tier2, 
                        int digit1, int digit2, int digit3)
{
    bool is_clean;
    int fee;
    int max_charge;
    int total_charge;
    
    is_clean = validate_amount(amount);
    
    fee = calculate_fee(fee_tier1, fee_tier2);
    
    max_charge = compute_max_charge(digit1, digit2, digit3);
    
    total_charge = (int)amount + fee + max_charge;
    
    //@ assert total_charge >= amount + 11;
    
    return total_charge;
}
