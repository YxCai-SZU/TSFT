#include <stdint.h>

/*@ predicate is_in_range(integer x) = 1 <= x <= 100; */
/*@ predicate result_in_range(integer r) = 0 <= r <= 1000; */

/*@ logic integer div3(integer x) = x / 3; */
/*@ logic integer mod3(integer x) = x % 3; */
/*@ logic integer div2(integer x) = x / 2; */

/*@ lemma div3_range: \forall integer x; is_in_range(x) ==> 0 <= div3(x) <= 33; */
/*@ lemma mod3_range: \forall integer x; is_in_range(x) ==> 0 <= mod3(x) <= 2; */

/*@
    requires is_in_range(x);
    ensures result_in_range(\result);
    assigns \nothing;
*/
int64_t func(int64_t x) {
    int64_t result = 0;
    int64_t temp_x = x;
    int64_t count = 0;
    
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= count <= div3(x);
        loop invariant temp_x == x - 3 * count;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 3) {
        //@ assert temp_x >= 3;
        temp_x -= 3;
        count += 1;
    }
    result += count;
    
    count = 0;
    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= count <= div2(mod3(x));
        loop invariant temp_x == mod3(x) - 2 * count;
        loop assigns temp_x, count;
        loop variant temp_x;
    */
    while (temp_x >= 2) {
        //@ assert temp_x >= 2;
        temp_x -= 2;
        count += 1;
    }
    result += count;
    
    //@ assert result_in_range(result);
    return result;
}

int main() {
    return 0;
}
