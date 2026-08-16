#include <stdbool.h>

/*@
    requires (\valid((coins) + (0..5)) &&
        (\forall integer i; 0 <= i < 6 ==> 0 <= (coins)[i] && (coins)[i] <= 100));
    ensures \result == (((coins)[0] + (coins)[1] * 5 + (coins)[2] * 10 + 
        (coins)[3] * 50 + (coins)[4] * 100 + (coins)[5] * 500) >= 1000);
    assigns \nothing;
*/
bool can_buy_candy(int coins[6])
{
    int total;
    
    total = coins[0] + coins[1] * 5 + coins[2] * 10 + 
            coins[3] * 50 + coins[4] * 100 + coins[5] * 500;
    
    //@ assert total == ((coins)[0] + (coins)[1] * 5 + (coins)[2] * 10 +          (coins)[3] * 50 + (coins)[4] * 100 + (coins)[5] * 500);
    
    return total >= 1000;
}
