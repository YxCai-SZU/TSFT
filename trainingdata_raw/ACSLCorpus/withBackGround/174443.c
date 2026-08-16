#include <stdint.h>

/*@
    predicate is_divisible_by_5(integer n) =
        n % 5 == 0;

    predicate is_divisible_by_3(integer n) =
        n % 3 == 0;

    logic integer count_non_divisible(integer a) =
        a - (a/5 + a/3 - a/15);

    lemma count_bounds:
        \forall integer a; 1 <= a <= 1000000000000 ==>
        0 <= count_non_divisible(a) <= a;
*/

/*@
    requires 1 <= a <= 1000000000000;
    ensures \result >= 0;
    ensures \result <= a;
    ensures \result == count_non_divisible(a);
*/
int64_t func(int64_t a) {
    int64_t result = 0;
    int64_t i = 1;
    
    /*@
        loop invariant 1 <= i <= a + 1;
        loop invariant result >= 0;
        loop invariant result <= i - 1;
        loop invariant result == count_non_divisible(i - 1);
        loop assigns i, result;
        loop variant a - i + 1;
    */
    while (i <= a) {
        int64_t divisible_by_5 = 0;
        int64_t divisible_by_3 = 0;
        int64_t temp;
        
        // Check divisibility by 5
        temp = i;
        /*@
            loop invariant 0 <= temp <= i;
            loop invariant temp % 5 == i % 5;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 5) {
            temp -= 5;
        }
        //@ assert temp == i % 5;
        if (temp == 0) {
            divisible_by_5 = 1;
        }
        
        // Check divisibility by 3
        temp = i;
        /*@
            loop invariant 0 <= temp <= i;
            loop invariant temp % 3 == i % 3;
            loop assigns temp;
            loop variant temp;
        */
        while (temp >= 3) {
            temp -= 3;
        }
        //@ assert temp == i % 3;
        if (temp == 0) {
            divisible_by_3 = 1;
        }
        
        //@ assert divisible_by_5 == (i % 5 == 0);
        //@ assert divisible_by_3 == (i % 3 == 0);
        
        if (!divisible_by_5 && !divisible_by_3) {
            //@ assert !is_divisible_by_5(i) && !is_divisible_by_3(i);
            result += 1;
        }
        
        //@ assert result == count_non_divisible(i);
        i += 1;
    }
    
    //@ assert result == count_non_divisible(a);
    return result;
}
