#include <stdint.h>

/*@ predicate valid_range(integer x, integer y) = 
      1 <= x && x <= 205 && 
      1 <= y && y <= 205 && 
      x <= y;
*/

/*@ logic integer calculate_money(integer x, integer y) = 
      x * 100 + (y - x) * 50;
*/

/*@ lemma money_formula: 
      \forall integer x, y; 
      valid_range(x, y) ==> 
      calculate_money(x, y) == x * 100 + (y - x) * 50;
*/

/*@
  requires valid_range(X, Y);
  ensures \result == calculate_money(X, Y);
*/
uint32_t func(uint32_t X, uint32_t Y)
{
    uint32_t money = 0;
    
    //@ assert money == 0;
    money += X * 100;
    //@ assert money == X * 100;
    money += (Y - X) * 50;
    //@ assert money == X * 100 + (Y - X) * 50;
    
    return money;
}
