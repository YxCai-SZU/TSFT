#include <limits.h>

/*@
  requires -100 <= x <= 100;
  ensures \result == -x || \result == x;
*/
int abs_val_nonlinear(int x) {
    int x_abs;
    
    if (x < 0) {
        x_abs = -x;
    } else {
        x_abs = x;
    }
    
    //@ assert x_abs == -x || x_abs == x;
    return x_abs;
}

/*@
  requires -100 <= x <= 100;
  ensures \result == -x || \result == x;
*/
int abs_val_nonlinear_example_2(int x) {
    int x_abs;
    
    if (x < 0) {
        x_abs = -x;
    } else {
        x_abs = x;
    }
    
    //@ assert x_abs == -x || x_abs == x;
    return x_abs;
}

/*@
  requires -100 <= x <= 100;
  ensures \result == -x || \result == x;
*/
int abs_val_nonlinear_example_3(int x) {
    int x_abs;
    
    if (x < 0) {
        x_abs = -x;
    } else {
        x_abs = x;
    }
    
    //@ assert x_abs == -x || x_abs == x;
    return x_abs;
}

/*@
  requires -100 <= x <= 100;
  ensures \result == -x || \result == x;
*/
int abs_val_nonlinear_example_4(int x) {
    int x_abs;
    
    if (x < 0) {
        x_abs = -x;
    } else {
        x_abs = x;
    }
    
    //@ assert x_abs == -x || x_abs == x;
    return x_abs;
}

int main() {
    return 0;
}
