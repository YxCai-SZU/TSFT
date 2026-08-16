#include <stdbool.h>

/*@
    predicate valid_range(integer n, integer m) =
        1 <= n <= 100 && 0 <= m <= n;
        
    predicate valid_range_v(integer v) = 1 <= v && v <= 10000;
    
    logic integer max(integer x, integer y) = x > y ? x : y;
    
    lemma n_m_relation:
        \forall integer n, m;
            valid_range(n, m) ==> (n == m || n != m);
    
    lemma sum_bound:
        \forall integer a, b, c, d;
        valid_range_v(a) && valid_range_v(b) && valid_range_v(c) && valid_range_v(d) ==>
        max(a, b) + max(c, d) >= 0 &&
        max(a, b) + max(c, d) <= a + b + c + d;
*/

bool func(int n, int m)
{
    int i = 0;
    
    while (i < 10)
    {
        i = i + 1;
    }
    
    if (n > 0 && m > 0)
    {
        //@ assert 1 <= n <= 100;
        //@ assert 0 <= m <= n;
        //@ assert n == m || n != m;
    }
    else
    {
        //@ assert n != m || n == m;
    }
    
    //@ assert n == m || n != m;
    
    return n == m;
}

long func2(long a, long b, long c, long d)
{
    long x = 0;
    
    //@ assert valid_range_v(a) && valid_range_v(b) && valid_range_v(c) && valid_range_v(d);
    
    if (a > b)
    {
        x += a;
        //@ assert x == max(a, b);
    }
    else
    {
        x += b;
        //@ assert x == max(a, b);
    }
    
    //@ assert x == max(a, b);
    //@ assert x >= 0;
    //@ assert x <= a + b;
    
    if (c > d)
    {
        x += c;
        //@ assert x == max(a, b) + max(c, d);
    }
    else
    {
        x += d;
        //@ assert x == max(a, b) + max(c, d);
    }
    
    //@ assert x == max(a, b) + max(c, d);
    //@ assert x >= 0;
    //@ assert x <= a + b + c + d;
    
    return x;
}

long process_resource_allocation(int n, int m, long a, long b, long c, long d)
{
    bool equal = func(n, m);
    
    long score = func2(a, b, c, d);
    
    //@ assert (score >= 0) && (score <= a + b + c + d) && (equal == (n == m));
    
    return score;
}
