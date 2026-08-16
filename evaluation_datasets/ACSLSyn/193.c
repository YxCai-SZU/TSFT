#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 10000;
    
    predicate condition(integer x, integer y, integer z, integer a, integer b) =
        x + y + z >= a &&
        x + z + b >= a &&
        y + z + b >= a &&
        x + y + z + b >= a;
    
    logic integer abs_val(integer x) = x >= 0 ? x : -x;
    
    lemma abs_preserves_range:
        \forall integer x; in_range(x) ==> 0 <= abs_val(x) <= 10000;
    
    lemma multiplication_bound:
        \forall integer a, b; 
            0 <= a <= 10000 && 0 <= b <= 10000 ==> 
            0 <= a * b <= 10000 * 10000;
*/

bool func1(long d, long t, long s)
{
    long d_abs;
    long t_abs;
    long s_abs;
    bool result;

    //@ assert in_range(d);
    //@ assert in_range(t);
    //@ assert in_range(s);

    d_abs = d < 0 ? -d : d;
    t_abs = t < 0 ? -t : t;
    s_abs = s < 0 ? -s : s;

    //@ assert 0 <= d_abs <= 10000;
    //@ assert 0 <= t_abs <= 10000;
    //@ assert 0 <= s_abs <= 10000;

    //@ assert t_abs * s_abs <= 10000 * 10000;
    //@ assert t_abs * s_abs >= 0;

    result = (t_abs * s_abs >= d_abs);
    //@ assert result == (t_abs * s_abs >= d_abs);
    return result;
}

bool func2(long x, long y, long z, long a, long b)
{
    bool ans = false;

    //@ assert 1 <= x <= 10000;
    //@ assert 1 <= y <= 10000;
    //@ assert 1 <= z <= 10000;
    //@ assert 1 <= a <= 10000;
    //@ assert 1 <= b <= 10000;

    if (x + y + z >= a &&
        x + z + b >= a &&
        y + z + b >= a &&
        x + y + z + b >= a)
    {
        ans = true;
    }

    //@ assert ans == true <==> condition(x, y, z, a, b);
    return ans;
}

bool combined_resource_check(
    long distance, long time, long speed,
    long x, long y, long z, long threshold, long buffer)
{
    bool movement_ok = func1(distance, time, speed);
    bool resource_ok = func2(x, y, z, threshold, buffer);
    bool result = movement_ok && resource_ok;
    
    //@ assert result == true <==> (time * speed >= distance) && condition(x, y, z, threshold, buffer);
    return result;
}
