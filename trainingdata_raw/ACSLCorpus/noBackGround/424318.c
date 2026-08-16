#include <stdbool.h>

/*@ requires (0 <= (a) <= 23 &&
      0 <= (b) <= 59 &&
      0 <= (c) <= 23 &&
      0 <= (d) <= 59 &&
      0 <= (e) <= 59 &&
      ((a) == (c) || (a) == (c) + 1 || (c) == (a) + 1) &&
      ((b) == (d) || (b) == (d) + 1 || (d) == (b) + 1));
    ensures \result == ((((e) < 0) ? (60 + (e)) : (e)) <= (((b) < 0) ? (60 + (b)) : (b)) + (((d) < 0) ? (60 + (d)) : (d)));
    assigns \nothing;
*/
bool func(int a, int b, int c, int d, int e) {
    int b_adjusted;
    int d_adjusted;
    int e_adjusted;
    
    //@ assert 0 <= b <= 59;
    b_adjusted = (b < 0) ? (60 + b) : b;
    //@ assert 0 <= b_adjusted <= 60;
    
    //@ assert 0 <= d <= 59;
    d_adjusted = (d < 0) ? (60 + d) : d;
    //@ assert 0 <= d_adjusted <= 60;
    
    //@ assert 0 <= e <= 59;
    e_adjusted = (e < 0) ? (60 + e) : e;
    //@ assert 0 <= e_adjusted <= 60;
    
    if (e_adjusted <= b_adjusted + d_adjusted) {
        return true;
    } else {
        return false;
    }
}
