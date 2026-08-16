#include <stdbool.h>

/*@
    predicate is_digit_seven(integer q100, integer q10, integer r10) =
        q100 == 7 || q10 == 7 || r10 == 7;
*/

/*@
    lemma division_property:
        \forall integer a, q, r, d;
            a >= 0 && d > 0 && q >= 0 && r >= 0 && r < d && a == d * q + r ==>
            q == a / d && r == a % d;
*/

/*@
    requires 100 <= a && a <= 999;
    ensures \result == true <==> (a / 100 == 7 || a / 10 % 10 == 7 || a % 10 == 7);
*/
bool func(int a) {
    int a_mut;
    bool res;
    int quotient_100;
    int temp;
    int quotient_10;
    int remainder_10;
    
    a_mut = a;
    res = false;
    quotient_100 = 0;
    temp = a_mut;
    
    /*@
        loop invariant 100 <= a && a <= 999;
        loop invariant 0 <= quotient_100;
        loop invariant temp >= 0;
        loop invariant temp == a_mut - 100 * quotient_100;
        loop assigns temp, quotient_100;
        loop variant temp;
    */
    while (temp >= 100) {
        temp -= 100;
        quotient_100 += 1;
    }
    a_mut = temp;
    
    quotient_10 = 0;
    temp = a_mut;
    
    /*@
        loop invariant 100 <= a && a <= 999;
        loop invariant 0 <= quotient_10;
        loop invariant temp >= 0;
        loop invariant temp == a_mut - 10 * quotient_10;
        loop assigns temp, quotient_10;
        loop variant temp;
    */
    while (temp >= 10) {
        temp -= 10;
        quotient_10 += 1;
    }
    a_mut = temp;
    
    remainder_10 = a_mut;
    
    //@ assert quotient_100 == a / 100;
    //@ assert quotient_10 == (a / 10) % 10;
    //@ assert remainder_10 == a % 10;
    
    if (quotient_100 == 7 || quotient_10 == 7 || remainder_10 == 7) {
        res = true;
    }
    
    //@ assert res == true <==> is_digit_seven(quotient_100, quotient_10, remainder_10);
    
    return res;
}

int main() {
    return 0;
}
