#include <limits.h>

/*@
  requires -100 <= a <= 100;
  requires -100 <= b <= 100;
  requires -100 <= c <= 100;
  requires -100 <= d <= 100;
  ensures \result == a || \result == b || \result == c || \result == d;
  ensures \result >= a || \result >= b || \result >= c || \result >= d;
*/
int func(int a, int b, int c, int d) {
    int max_val = a;
    int min_val = a;
    int res = 0;

    if (b > max_val) {
        max_val = b;
    }
    //@ assert max_val >= a && max_val >= b;
    
    if (c > max_val) {
        max_val = c;
    }
    //@ assert max_val >= a && max_val >= b && max_val >= c;
    
    if (d > max_val) {
        max_val = d;
    }
    //@ assert max_val >= a && max_val >= b && max_val >= c && max_val >= d;
    
    if (b < min_val) {
        min_val = b;
    }
    //@ assert min_val <= a && min_val <= b;
    
    if (c < min_val) {
        min_val = c;
    }
    //@ assert min_val <= a && min_val <= b && min_val <= c;
    
    if (d < min_val) {
        min_val = d;
    }
    //@ assert min_val <= a && min_val <= b && min_val <= c && min_val <= d;
    
    if (max_val == a) {
        if (min_val == b || min_val == c || min_val == d) {
            res = a;
        } else {
            res = min_val;
        }
    } else if (max_val == b) {
        if (min_val == a || min_val == c || min_val == d) {
            res = b;
        } else {
            res = min_val;
        }
    } else if (max_val == c) {
        if (min_val == a || min_val == b || min_val == d) {
            res = c;
        } else {
            res = min_val;
        }
    } else if (max_val == d) {
        if (min_val == a || min_val == b || min_val == c) {
            res = d;
        } else {
            res = min_val;
        }
    }
    
    //@ assert res == a || res == b || res == c || res == d;
    //@ assert res >= a || res >= b || res >= c || res >= d;
    
    return res;
}
