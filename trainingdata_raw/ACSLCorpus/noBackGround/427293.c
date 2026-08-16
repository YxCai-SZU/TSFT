#include <stddef.h>

/*@
    requires (1 <= (X) && (X) <= 205) && (1 <= (Y) && (Y) <= 205);
    ensures \result == (((X) > 1 && (Y) > 1) ? ((X) - 2) * 100 + ((Y) - 2) * 100 + 100 :
        ((X) == 1 && (Y) == 1) ? 0 :
        ((X) == 1 && (Y) > 1) ? ((Y) - 2) * 100 + 100 :
        ((X) > 1 && (Y) == 1) ? ((X) - 2) * 100 + 100 : 0);
    ensures \result >= 0;
*/
size_t func(size_t X, size_t Y) {
    size_t money = 0;
    
    //@ assert money == 0;
    
    if (X > 1) {
        //@ assert X > 1;
        money += (X - 2) * 100;
        //@ assert money == (X - 2) * 100;
    }
    
    if (Y > 1) {
        //@ assert Y > 1;
        money += (Y - 2) * 100;
    }
    
    if (X == 1 && Y == 1) {
        //@ assert X == 1 && Y == 1;
        money = 0;
        //@ assert money == 0;
    } else if (X == 1) {
        //@ assert X == 1 && Y > 1;
        money += 100;
    } else if (Y == 1) {
        //@ assert X > 1 && Y == 1;
        money += 100;
    } else {
        //@ assert X > 1 && Y > 1;
        money += 100;
    }
    
    //@ assert money == (((X) > 1 && (Y) > 1) ? ((X) - 2) * 100 + ((Y) - 2) * 100 + 100 :         ((X) == 1 && (Y) == 1) ? 0 :         ((X) == 1 && (Y) > 1) ? ((Y) - 2) * 100 + 100 :         ((X) > 1 && (Y) == 1) ? ((X) - 2) * 100 + 100 : 0);
    return money;
}
