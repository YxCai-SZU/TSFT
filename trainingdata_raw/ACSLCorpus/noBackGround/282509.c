#include <stdbool.h>

/*@ requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    ensures \result == true <==> (a + b == c || a + c == b || b + c == a);
*/
bool func(int a, int b, int c) {
    int min1;
    int mid;
    int max;

    if (a <= b && a <= c) {
        if (b <= c) {
            min1 = a;
            mid = b;
            max = c;
        } else {
            min1 = a;
            mid = c;
            max = b;
        }
    } else if (b <= a && b <= c) {
        if (a <= c) {
            min1 = b;
            mid = a;
            max = c;
        } else {
            min1 = b;
            mid = c;
            max = a;
        }
    } else {
        if (a <= b) {
            min1 = c;
            mid = a;
            max = b;
        } else {
            min1 = c;
            mid = b;
            max = a;
        }
    }

    //@ assert ((min1) <= (mid) && (mid) <= (max));

    if (min1 + mid == max || min1 + max == mid || mid + max == min1) {
        return true;
    } else {
        return false;
    }
}

int main() {
    return 0;
}
