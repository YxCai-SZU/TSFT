#include <stdbool.h>

/*@ predicate is_valid_params(integer d, integer t, integer s) =
      1 <= d && d <= 10000 &&
      1 <= t && t <= 10000 &&
      1 <= s && s <= 10000;
*/

/*@ lemma product_bounds: \forall integer t, s;
      is_valid_params(1, t, s) ==> t * s <= 10000 * 10000;
*/

bool func1(long d, long t, long s) {
    bool r;
    long distance;
    long time;
    long speed;
    bool is_distance_negative;
    bool is_time_negative;
    bool is_speed_negative;
    long product;
    
    r = false;
    distance = d;
    time = t;
    speed = s;
    is_distance_negative = false;
    is_time_negative = false;
    is_speed_negative = false;
    
    if (distance < 0) {
        is_distance_negative = true;
        distance = -distance;
    }
    if (time < 0) {
        is_time_negative = true;
        time = -time;
    }
    if (speed < 0) {
        is_speed_negative = true;
        speed = -speed;
    }
    
    //@ assert distance <= 10000;
    //@ assert time <= 10000;
    //@ assert speed <= 10000;
    
    //@ assert time * speed <= 10000 * 10000;
    
    product = time * speed;
    
    if ((is_distance_negative && is_time_negative && is_speed_negative) || 
        (product >= distance)) {
        r = true;
    } else {
        r = false;
    }
    
    //@ assert r == (d <= t * s);
    return r;
}

/*@
    predicate is_valid_params2(integer a, integer b, integer c, integer k) =
        1 <= a <= 7 &&
        1 <= b <= 7 &&
        1 <= c <= 7 &&
        1 <= k <= 7;
*/

int func2(int a, int b, int c, int k)
{
    int r = 0;
    
    //@ assert is_valid_params2(a, b, c, k);
    
    if (k - a - b >= 0)
    {
        r = 1;
    }
    
    //@ assert r == 0 || r == 1;
    //@ assert r == 1 ==> k - a - b >= 0;
    //@ assert r == 0 ==> k - a - b < 0;
    
    return r;
}

/*@
    predicate valid_input(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100;

    logic integer min_val(integer a, integer b, integer c) =
        c < a + b ? c : a + b;
*/

int func3(int a, int b, int c)
{
    int min_val;
    int ans;
    int cnt;
    int tmp;

    //@ assert valid_input(a, b, c);
    
    min_val = (c < a + b) ? c : (a + b);
    ans = 0;
    cnt = 0;
    tmp = min_val;

    while (tmp >= 2)
    {
        tmp -= 2;
        cnt += 1;
    }
    ans += cnt;

    if (tmp == 1)
    {
        ans += 1;
    }

    //@ assert ans >= 0;
    //@ assert ans <= c;
    //@ assert ans <= a + b;

    return ans;
}


int func4(int x)
{
    int i;
    int result;

    i = 1;
    while (i < x)
    {
        //@ assert i * 7 <= 2 * x + 7;
        if (i * 7 >= x)
        {
            //@ assert i >= 1 && i <= x;
            return i;
        }
        i = i + 1;
    }
    result = x;
    //@ assert result >= 1 && result <= x;
    return result;
}


/*@
    predicate resource_valid(integer d, integer t, integer s, integer a, integer b, integer c, integer k, integer x) =
        is_valid_params(d, t, s) &&
        is_valid_params2(a, b, c, k) &&
        valid_input(a, b, c) &&
        1 <= x && x <= 1000;

    predicate allocation_feasible(integer d, integer t, integer s, integer a, integer b, integer c, integer k, integer x, 
                                  bool feasible, int alloc, int multiplier) =
        (feasible == (d <= t * s && k - a - b >= 0)) &&
        (alloc >= 0 && alloc <= c && alloc <= a + b) &&
        (multiplier >= 1 && multiplier <= x && multiplier * 7 <= 2 * x + 7);
*/

struct ResourcePlan {
    bool feasible;
    int alloc;
    int multiplier;
} synthesize_resource_plan(long d, long t, long s, int a, int b, int c, int k, int x)
{
    struct ResourcePlan plan;
    bool feasibility;
    int allocation;
    int multiplier;
    
    feasibility = func1(d, t, s);
    
    int resource_avail = func2(a, b, c, k);
    
    allocation = func3(a, b, c);
    
    multiplier = func4(x);
    
    plan.feasible = feasibility && (resource_avail == 1);
    plan.alloc = allocation;
    plan.multiplier = multiplier;
    
    return plan;
}
