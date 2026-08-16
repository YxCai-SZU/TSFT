#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> (((a) + (b) == (c)) || ((b) + (c) == (a)) || ((c) + (a) == (b)));
    assigns \nothing;
*/
bool func(unsigned int a, unsigned int b, unsigned int c) {
    bool result = false;
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    if (a + b == c || b + c == a || c + a == b) {
        result = true;
    }
    return result;
}

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == a * b || \result == c * d;
    ensures \result >= a * b;
    ensures \result >= c * d;
    assigns \nothing;
*/
int func2(int a, int b, int c, int d) {
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    //@ assert 1 <= d <= 100;
    //@ assert a * b <= 10000;
    //@ assert c * d <= 10000;
    
    int product1 = a * b;
    int product2 = c * d;
    int max_value;
    
    if (product1 > product2) {
        max_value = product1;
    } else {
        max_value = product2;
    }
    return max_value;
}
