#include <stdbool.h>
#include <stddef.h>

/* ========== Original functions with ACSL specs ========== */

/*@
    predicate valid_range(int *arr, integer len) =
        len > 0 && \valid(arr + (0 .. len-1));
    
    predicate all_equal(int *arr, integer len) =
        \forall integer i; 0 <= i < len ==> arr[i] == arr[i];
*/

bool func_array(int *s, size_t s_len, int v)
{
    //@ assert s_len > 0;
    
    for (size_t i = 0; i < s_len; ++i)
    {
        //@ assert s[i] == s[i];
    }
    
    //@ assert all_equal(s, s_len);
    
    return true;
}

/*@
    predicate is_heavy_load(integer load) = load > 5;
*/

struct Truck {
    unsigned int speed;
    unsigned int load;
};

struct Truck upgrade_speed(struct Truck *t, unsigned int new_speed) {
    struct Truck ret;
    ret.speed = new_speed;
    ret.load = t->load;
    //@ assert is_heavy_load(ret.load);
    return ret;
}

/*@ predicate in_range(integer val, integer low, integer high) =
      low <= val && val <= high;
*/

bool func_range(int a, int b, int x)
{
    int min;
    int max;
    bool result;

    min = 0;
    max = b;

    //@ assert in_range(a, 1, 100);
    //@ assert in_range(b, 1, 100);
    //@ assert in_range(x, 1, 200);
    //@ assert min == 0;
    //@ assert max == b;

    if (x - a < min || x - a > max)
    {
        result = false;
    }
    else
    {
        result = true;
    }

    //@ assert result == (x - a >= 0 && x - a <= b);

    return result;
}

/* ========== Synthesized complex function ========== */

bool process_truck_and_check(struct Truck *t, unsigned int new_speed, 
                              int *s, size_t s_len, int v,
                              int a, int b, int x)
{
    struct Truck upgraded = upgrade_speed(t, new_speed);
    
    bool array_ok = func_array(s, s_len, v);
    
    bool range_ok = func_range(a, b, x);
    
    //@ assert is_heavy_load(upgraded.load);
    //@ assert range_ok == (x - a >= 0 && x - a <= b);
    
    return range_ok;
}
