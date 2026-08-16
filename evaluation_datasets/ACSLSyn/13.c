#include <stdbool.h>
#include <stdint.h>

/*@
    predicate in_range(integer x) = -100 <= x <= 100;
    predicate leq(integer a, integer b) = a <= b;
    predicate a_in_range(integer a) =
        -0x7fffffffffffffff <= a <= 0x7fffffffffffffff;
    logic integer get_lsb(integer a) = a & 0x1;
*/

bool compare_func(long a, long b)
{
    long aa = a;
    long bb = b;
    //@ assert in_range(aa) && in_range(bb);
    
    if (aa < bb) {
        //@ assert aa <= bb;
        return true;
    } else if (aa == bb) {
        //@ assert aa <= bb;
        return true;
    }
    
    //@ assert !(aa <= bb);
    return false;
}

int64_t lsb_func(int64_t a)
{
    int64_t result;
    
    //@ assert a_in_range(a);
    
    result = a & 0x1;
    
    //@ assert result == get_lsb(a);
    return result;
}

bool conditional_compare(int64_t x, int64_t y, int64_t z)
{
    int64_t lsb = lsb_func(z);
    //@ assert lsb == get_lsb(z);
    
    bool result;
    
    if (lsb == 0) {
        result = compare_func(x, y);
        //@ assert result == (x <= y);
    } else {
        result = !compare_func(x, y);
        //@ assert result == !(x <= y);
    }
    
    //@ assert result == (get_lsb(z) == 0 ? (x <= y) : !(x <= y));
    return result;
}
