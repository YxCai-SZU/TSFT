#include <limits.h>

/*@
  requires (1 <= (x) <= 179);
  ensures ((\result) >= 1 && (\result) <= 360 && 
      ((\result) == 360 - (x) || (\result) == 360 - (x) - 1 || (\result) == 360 - (x) + 1));
*/
int func(int x) {
    int result;
    
    //@ assert (1 <= (x) <= 179);
    if (x >= 1 && x <= 179) {
        result = 360 - x;
        
        if (result == 1 || result == 2 || result == 3 || result == 4 || 
            result == 5 || result == 6 || result == 7 || result == 8 || 
            result == 9 || result == 10 || result == 11 || result == 12) {
            //@ assert result >= 1 && result <= 12;
            //@ assert result + 1 >= 2 && result + 1 <= 13;
            //@ assert result + 1 == 360 - x + 1;
            return result + 1;
        } else {
            //@ assert result >= 13;
            //@ assert result == 360 - x;
            //@ assert result >= 1 && result <= 360;
            return result;
        }
    } else {
        return -1;
    }
}
