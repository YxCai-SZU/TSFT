#include <stdint.h>

/*@
  requires (1 <= (a) && (a) <= 100 &&
      1 <= (b) && (b) <= 100);
  ensures \result >= 0;
  ensures \result == a - b * 2 || \result == 0;
  assigns \nothing;
*/
int64_t func(int64_t a, int64_t b)
{
    int64_t result;
    //@ assert (1 <= (a) && (a) <= 100 &&       1 <= (b) && (b) <= 100);
    
    if (a > b * 2) {
        result = a - b * 2;
        //@ assert result >= 0;
        //@ assert result == a - b * 2;
    } else {
        result = 0;
        //@ assert result == 0;
        //@ assert result >= 0;
    }
    
    return result;
}

/*@
  requires (1 <= (a) && (a) <= 100 &&
      1 <= (b) && (b) <= 100);
  ensures \result >= 0;
  ensures \result == a - b * 2 || \result == 0;
  assigns \nothing;
*/
int64_t func2(int64_t a, int64_t b)
{
    int64_t result;
    int64_t temp;
    //@ assert (1 <= (a) && (a) <= 100 &&       1 <= (b) && (b) <= 100);
    
    temp = a - b * 2;
    
    //@ assert temp == a - b * 2;
    if (temp < 0) {
        //@ assert temp < 0;
        result = 0;
        //@ assert result == 0;
    } else {
        //@ assert temp >= 0;
        result = temp;
        //@ assert result == a - b * 2;
    }
    
    //@ assert result >= 0;
    return result;
}
