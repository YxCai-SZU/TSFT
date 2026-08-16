#include <stdbool.h>

/*@ assigns \nothing;
    ensures (((\result) == (x) || (\result) == (y)) && (\result) <= (x) && (\result) <= (y));
*/
int min_int(int x, int y) {
    int ret;
    //@ assert \true;
    if (x < y) {
        ret = x;
    } else {
        ret = y;
    }
    //@ assert (((ret) == (x) || (ret) == (y)) && (ret) <= (x) && (ret) <= (y));
    return ret;
}

/*@ requires 1 <= n <= 10000;
    requires 0 <= a <= 1000;
    assigns \nothing;
    ensures \result == ((n % 500) <= a);
*/
bool func(int n, int a) {
    int remainder = n;
    
    /*@ loop invariant ((remainder) >= 0 && (remainder) <= (n) &&
      ((remainder) == (n) || (remainder) == (n) - 500 || (remainder) == (n) - 1000 ||
       (remainder) == (n) - 1500 || (remainder) == (n) - 2000 || (remainder) == (n) - 2500 ||
       (remainder) == (n) - 3000 || (remainder) == (n) - 3500 || (remainder) == (n) - 4000 ||
       (remainder) == (n) - 4500 || (remainder) == (n) - 5000 || (remainder) == (n) - 5500 ||
       (remainder) == (n) - 6000 || (remainder) == (n) - 6500 || (remainder) == (n) - 7000 ||
       (remainder) == (n) - 7500 || (remainder) == (n) - 8000 || (remainder) == (n) - 8500 ||
       (remainder) == (n) - 9000 || (remainder) == (n) - 9500 || (remainder) == (n) - 10000));
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= a <= 1000;
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 500) {
        remainder -= 500;
    }
    
    bool result = (remainder <= a);
    //@ assert result == ((n % 500) <= a);
    return result;
}

/*@ assigns \nothing;
*/
int main() {
    return 0;
}
