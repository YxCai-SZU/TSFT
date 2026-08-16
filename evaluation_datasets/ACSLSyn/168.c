#include <stdbool.h>
#include <stdint.h>

/* First underlying function: checks if a voucher covers the remaining amount */
/*@
    predicate is_enough(integer n, integer a, bool res) =
        res == (n % 500 <= a);
*/

bool func_voucher(unsigned int n, unsigned int a)
{
    unsigned int res;
    bool is_enough;
    unsigned int remaining;

    res = n / 500;
    is_enough = false;

    if (res == 0)
    {
        //@ assert res == 0;
        is_enough = (a >= n);
    }
    else
    {
        //@ assert res > 0;
        remaining = n - res * 500;
        //@ assert remaining == n % 500;
        is_enough = (a >= remaining);
    }

    //@ assert is_enough == (n % 500 <= a);
    return is_enough;
}

/* Second underlying function: checks if a+b is divisible by 3 */
/*@ predicate valid_range(integer x) = 1 <= x <= 100; */

int32_t func_mod3(uint32_t a, uint32_t b)
{
    uint32_t remainder;
    int32_t result;

    if (a % 3 == 0 || b % 3 == 0)
    {
        result = 0;
    }
    else
    {
        remainder = a + b;
        while (remainder >= 3)
        {
            //@ assert remainder >= 3;
            remainder -= 3;
        }
        //@ assert 0 <= remainder < 3;
        result = (remainder == 0) ? 0 : 1;
    }
    //@ assert result == 0 || result == 1;
    return result;
}

/* Synthesized function: Payment processing for a vending machine
 * - total: total bill amount (1..10000 cents)
 * - voucher_balance: voucher balance (0..1000 cents)
 * - coin1, coin2: two coin denominations (1..100 cents each)
 *
 * The function determines if payment can be made using either:
 *   (a) voucher alone, or
 *   (b) coins that sum to a multiple of 3 (to use a special discount)
 * Returns: 1 if payment possible, 0 otherwise
 */

int32_t process_payment(unsigned int total, unsigned int voucher_balance, 
                        uint32_t coin1, uint32_t coin2)
{
    int32_t result;
    bool voucher_ok;
    int32_t coin_ok;

    voucher_ok = func_voucher(total, voucher_balance);
    
    coin_ok = func_mod3(coin1, coin2);

    if (voucher_ok || coin_ok == 0)
    {
        result = 1;
    }
    else
    {
        result = 0;
    }

    //@ assert (result == 1) <==> (voucher_ok == 1 || coin_ok == 0);
    return result;
}
