#include <stdbool.h>

/*@
    requires 1 <= a <= 100;
    requires 1 <= b <= 100;
    requires 1 <= c <= 100;
    requires 1 <= d <= 100;
    ensures \result == true <==> (((c) - (b) <= 1 && (b) - (a) >= 2) || ((a) - (c) <= 1 && (c) - (b) >= 2));
 */
bool func(int a, int b, int c, int d)
{
    int count = 0;
    int temp_a = a;
    int temp_b = b;
    int temp_c = c;
    int temp_d = d;

    //@ assert 1 <= temp_a <= 100;
    //@ assert 1 <= temp_b <= 100;
    //@ assert 1 <= temp_c <= 100;
    //@ assert 1 <= temp_d <= 100;

    if (temp_a < 0) {
        temp_a = -temp_a;
    }
    if (temp_b < 0) {
        temp_b = -temp_b;
    }
    if (temp_c < 0) {
        temp_c = -temp_c;
    }
    if (temp_d < 0) {
        temp_d = -temp_d;
    }

    //@ assert 0 <= temp_a <= 100;
    //@ assert 0 <= temp_b <= 100;
    //@ assert 0 <= temp_c <= 100;
    //@ assert 0 <= temp_d <= 100;

    if ((temp_c - temp_b <= 1 && temp_b - temp_a >= 2) || 
        (temp_a - temp_c <= 1 && temp_c - temp_b >= 2)) {
        count += 1;
    }
    
    if (count > 0) {
        //@ assert (((c) - (b) <= 1 && (b) - (a) >= 2) || ((a) - (c) <= 1 && (c) - (b) >= 2));
        return true;
    } else {
        //@ assert !(((c) - (b) <= 1 && (b) - (a) >= 2) || ((a) - (c) <= 1 && (c) - (b) >= 2));
        return false;
    }
}
