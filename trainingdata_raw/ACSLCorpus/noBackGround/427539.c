#include <stdbool.h>

/*@
    requires 1 <= a && a <= 100;
    requires 1 <= b && b <= 100;
    ensures \result == (a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0);
    assigns \nothing;
*/
bool func(int a, int b) {
    int a_signed;
    int b_signed;
    int modulo_a;
    int modulo_b;
    int modulo_sum;
    int sum;
    int temp;

    a_signed = a;
    b_signed = b;

    // Compute modulo_a
    temp = a_signed;
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant temp >= 0;
        loop invariant temp == a_signed || temp % 3 == a_signed % 3;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 3) {
        temp -= 3;
    }
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant temp < 3;
        loop invariant temp == a_signed % 3;
        loop assigns temp;
        loop variant -temp;
    */
    while (temp < 0) {
        temp += 3;
    }
    modulo_a = temp;

    // Compute modulo_b
    temp = b_signed;
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant temp >= 0;
        loop invariant temp == b_signed || temp % 3 == b_signed % 3;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 3) {
        temp -= 3;
    }
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant temp < 3;
        loop invariant temp == b_signed % 3;
        loop assigns temp;
        loop variant -temp;
    */
    while (temp < 0) {
        temp += 3;
    }
    modulo_b = temp;

    // Compute modulo_sum
    sum = a_signed + b_signed;
    temp = sum;
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant temp >= 0;
        loop invariant temp == sum || temp % 3 == sum % 3;
        loop invariant sum == a_signed + b_signed;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= 3) {
        temp -= 3;
    }
    /*@
        loop invariant 1 <= a && a <= 100;
        loop invariant 1 <= b && b <= 100;
        loop invariant temp < 3;
        loop invariant temp == sum % 3;
        loop invariant sum == a_signed + b_signed;
        loop assigns temp;
        loop variant -temp;
    */
    while (temp < 0) {
        temp += 3;
    }
    modulo_sum = temp;

    //@ assert modulo_a == a_signed % 3;
    //@ assert modulo_b == b_signed % 3;
    //@ assert modulo_sum == (a_signed + b_signed) % 3;

    if (modulo_a == 0 || modulo_b == 0 || modulo_sum == 0) {
        return true;
    } else {
        return false;
    }
}
