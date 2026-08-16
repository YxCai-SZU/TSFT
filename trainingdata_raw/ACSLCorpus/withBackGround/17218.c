/*@
    predicate multiple_of_3_and_5(integer n) = n % 3 == 0 && n % 5 == 0;
    predicate is_between(integer a, integer b, integer c) = a <= c && c <= b;
*/

/*@
    lemma multiple_of_3_and_5_15: multiple_of_3_and_5(15);
    lemma not_multiple_of_3_and_5_3: !multiple_of_3_and_5(3);
    lemma not_multiple_of_3_and_5_5: !multiple_of_3_and_5(5);
    lemma is_between_1_10_5: is_between(1, 10, 5);
    lemma not_is_between_1_10_15: !is_between(1, 10, 15);
*/

#include <stdbool.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= a <= 50;
    requires 1 <= b <= 50;
    ensures \result == a * n || \result == b;
    ensures \result <= b;
*/
int func(int n, int a, int b)
{
    //@ assert 1 <= n && n <= 20;
    //@ assert 1 <= a && a <= 50;
    //@ assert 1 <= b && b <= 50;
    
    //@ assert a * n <= 50 * 20;
    
    int product = a * n;
    
    if (product < b) {
        return product;
    } else {
        return b;
    }
}
