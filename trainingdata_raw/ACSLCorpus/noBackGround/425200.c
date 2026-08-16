#include <stdbool.h>

/*@
  requires (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
  ensures \result == true <==> a > c;
  ensures \result == false <==> a <= c;
*/
bool func(long a, long b, long c, long d) {
    long max_val;
    long min_val;
    long diff;
    bool flag;
    long temp;

    //@ assert (1 <= (a) <= 100) && (1 <= (b) <= 100) && (1 <= (c) <= 100) && (1 <= (d) <= 100);
    
    // Implementing max function manually
    if (b > d) {
        max_val = b;
    } else {
        max_val = d;
    }
    
    // Implementing min function manually
    if (b < d) {
        min_val = b;
    } else {
        min_val = d;
    }

    if (a > c) {
        flag = true;
    } else {
        flag = false;
    }

    // Manually calculating the absolute value of the difference
    if (max_val - min_val < 0) {
        diff = -(max_val - min_val);
    } else {
        diff = max_val - min_val;
    }

    if (diff == 0) {
        return flag;
    } else {
        if (flag) {
            a += diff;
        } else {
            c += diff;
        }
    }

    if (a > c) {
        //@ assert a > c;
        return true;
    } else {
        //@ assert a <= c;
        return false;
    }
}
