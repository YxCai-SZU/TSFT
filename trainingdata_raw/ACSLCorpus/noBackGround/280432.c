#include <stdbool.h>

/*@
    requires (1 <= (a) <= 10000) && (1 <= (b) <= 10000);
    ensures \result == (a * b % 2 != 0);
    assigns \nothing;
*/
bool func(unsigned long long a, unsigned long long b) {
    unsigned long long c;
    bool is_odd = false;
    unsigned long long temp;
    unsigned long long two = 2;
    
    //@ assert (1 <= (((a)) * ((b))) <= 10000 * 10000);
    c = a * b;
    temp = c;
    
    /*@
        loop invariant 1 <= a <= 10000;
        loop invariant 1 <= b <= 10000;
        loop invariant 0 <= temp <= a * b;
        loop invariant temp <= c;
        loop invariant c == a * b;
        loop invariant 1 <= a * b <= 10000 * 10000;
        loop invariant temp % 2 == c % 2;
        loop assigns temp;
        loop variant temp;
    */
    while (temp >= two) {
        temp -= two;
    }
    
    if (temp == 1) {
        is_odd = true;
    }
    
    return is_odd;
}

int main() {
    return 0;
}
