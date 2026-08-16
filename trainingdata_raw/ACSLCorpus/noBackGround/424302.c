#include <stdbool.h>

/*@ requires x >= 0 && y >= 0 && x <= 100 && y <= 100;
    ensures \result == ((x) == (y) ? 0 : ((x) > (y) ? (x) - (y) : (y) - (x)));
    assigns \nothing; */
unsigned int func(unsigned int x, unsigned int y) {
    unsigned int res;
    
    if (x == y) {
        res = 0;
    } else {
        if (x > y) {
            //@ assert x - y <= 100;
            res = x - y;
        } else {
            //@ assert y - x <= 100;
            res = y - x;
        }
    }
    
    //@ assert res == ((x) == (y) ? 0 : ((x) > (y) ? (x) - (y) : (y) - (x)));
    return res;
}

/*@ requires x >= 0 && y >= 0 && x <= 100 && y <= 100;
    ensures \result == ((x) == (y) ? 0 : ((x) > (y) ? (x) - (y) : (y) - (x)));
    assigns \nothing; */
unsigned int func_with_arithmetic(unsigned int x, unsigned int y) {
    unsigned int res;
    
    if (x == y) {
        res = 0;
    } else {
        if (x > y) {
            //@ assert x - y <= 100;
            res = x - y;
        } else {
            //@ assert y - x <= 100;
            res = y - x;
        }
    }
    
    //@ assert res == ((x) == (y) ? 0 : ((x) > (y) ? (x) - (y) : (y) - (x)));
    return res;
}

/*@ requires n >= 0;
    ensures \result == (n % 2 != 0);
    assigns \nothing; */
bool is_odd_func(unsigned int n) {
    bool ret;
    ret = (n % 2 != 0);
    
    //@ assert ret == (n % 2 != 0);
    return ret;
}
