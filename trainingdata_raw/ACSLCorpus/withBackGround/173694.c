#include <stddef.h>
/*@
    predicate valid_params(size_t k, size_t len, size_t threshold) =
        k < len && len > 0 && threshold >= 0;

    predicate loop_invariant(size_t i, size_t k, size_t count, size_t len, size_t threshold) =
        i <= k &&
        count <= i &&
        count >= 0 &&
        len > 0 &&
        threshold >= 0 &&
        k < len;
*/

/*@
    requires valid_params(k, \at(people_len, Pre), threshold);
    requires \valid_read(people + (0 .. \at(people_len, Pre)-1));
    assigns \nothing;
    ensures \result <= \at(people_len, Pre);
    ensures \result >= 0;
*/
size_t count_tall_enough(const size_t* people, size_t people_len, size_t k, size_t threshold) {
    size_t count = 0;
    size_t i = 0;
    //@ ghost size_t old_people_len = people_len;
    
    /*@
        loop invariant loop_invariant(i, k, count, old_people_len, threshold);
        loop assigns i, count;
        loop variant k - i;
    */
    while (i < k) {
        //@ assert i <= k && i < old_people_len;
        if (people[i] >= threshold) {
            count += 1;
        }
        i += 1;
    }
    return count;
}

int main() {
    return 0;
}
