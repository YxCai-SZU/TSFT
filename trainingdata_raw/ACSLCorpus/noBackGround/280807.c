#include <stdbool.h>

/*@
    requires x >= 0 && k >= 0;
    ensures \result == ((k) >= (x) ? (k) - (x) : (x) - (k));
*/
int compute_absolute_difference(int x, int k) {
    int result;
    //@ assert x >= 0 && k >= 0;
    if (k >= x) {
        result = k - x;
    } else {
        result = x - k;
    }
    //@ assert ((result) == ((k) >= (x) ? (k) - (x) : (x) - (k)));
    return result;
}

/*@
    requires x >= 0 && k >= 0;
    ensures \result == (2 * ((k) >= (x) ? (k) - (x) : (x) - (k)));
*/
int compute_double_difference(int x, int k) {
    int result;
    int temp;
    //@ assert x >= 0 && k >= 0;
    if (k >= x) {
        temp = k - x;
    } else {
        temp = x - k;
    }
    //@ assert temp == ((k) >= (x) ? (k) - (x) : (x) - (k));
    result = 2 * temp;
    //@ assert result == (2 * ((k) >= (x) ? (k) - (x) : (x) - (k)));
    return result;
}

/*@
    requires x >= 0 && k >= 0;
    ensures \result == ((k) - (x) + (k) + (x) - (k));
*/
int compute_factor_difference(int x, int k) {
    int result;
    //@ assert x >= 0 && k >= 0;
    result = k - x + k + x - k;
    //@ assert result == ((k) - (x) + (k) + (x) - (k));
    return result;
}

int main() {
    int test1, test2, test3;
    
    test1 = compute_absolute_difference(4, 10);
    //@ assert test1 == 6;
    
    test2 = compute_absolute_difference(4, 3);
    //@ assert test2 == 1;
    
    test1 = compute_double_difference(4, 10);
    //@ assert test1 == 12;
    
    test2 = compute_double_difference(4, 3);
    //@ assert test2 == 2;
    
    test1 = compute_factor_difference(4, 10);
    //@ assert test1 == 10;
    
    test2 = compute_factor_difference(4, 3);
    //@ assert test2 == 3;
    
    return 0;
}
