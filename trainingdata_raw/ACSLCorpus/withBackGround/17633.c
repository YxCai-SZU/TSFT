#include <stdbool.h>
#include <stddef.h>

/*@ predicate is_valid_range(integer r) = 1 <= r && r <= 100; */

/*@ lemma square_bound: 
      \forall integer r; is_valid_range(r) ==> r * r <= 10000; */

/*@ requires is_valid_range(r);
    ensures \result == r * r;
    assigns \nothing;
 */
unsigned int func(unsigned int r)
{
    // Variable declarations at top
    unsigned int res;
    
    //@ assert r * r <= 10000;
    
    res = r * r;
    return res;
}

/*@ assigns \nothing;
    ensures \result == \null;
 */
size_t* input_number(void)
{
    // Variable declarations at top
    size_t* result = NULL;
    return result;
}

/*@ assigns \nothing;
    ensures \true;
 */
struct input_result {
    char first;
    unsigned int second;
} input(void)
{
    // Variable declarations at top
    struct input_result result;
    result.first = ' ';
    result.second = 0;
    return result;
}

int main(void)
{
    return 0;
}
