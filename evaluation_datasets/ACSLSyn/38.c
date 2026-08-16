#include <stdbool.h>

/*@ predicate a_in_range(integer a) = 1 <= a <= 16; */
/*@ predicate b_in_range(integer b) = 1 <= b <= 16; */
/*@ predicate sum_in_range(integer a, integer b) = a + b <= 16; */
/*@ predicate valid_range(integer x) = 1 <= x <= 10000; */
/*@ logic integer sum3(integer b, integer c, integer d) = b + c + d; */

bool func1(long a, long b)
{
    long a_result;
    long b_result;
    bool result;
    
    //@ assert 1 <= a <= 16;
    //@ assert 1 <= b <= 16;
    //@ assert a + b <= 16;
    
    a_result = (a > 8) ? 0 : 1;
    b_result = (b > 8) ? 0 : 1;
    
    //@ assert a_result == 1 ==> a <= 8;
    //@ assert b_result == 1 ==> b <= 8;
    
    result = (a_result * b_result == 1);
    
    //@ assert result == (a <= 8 && b <= 8);
    return result;
}

bool func2(unsigned long long a, unsigned long long b, unsigned long long c, unsigned long long d)
{
    //@ assert a > sum3(b, c, d) ==> a > sum3(b, c, d);
    return a > (b + c + d);
}

bool resource_allocator(long a, long b, unsigned long long c, unsigned long long d, unsigned long long e, unsigned long long f)
{
    
    bool small_resources_ok = func1(a, b);
    bool large_resource_ok = func2(c, d, e, f);
    
    //@ assert small_resources_ok == (a <= 8 && b <= 8);
    //@ assert large_resource_ok == (c > sum3(d, e, f));
    
    bool allocation_possible = small_resources_ok && large_resource_ok;
    
    //@ assert allocation_possible == ((a <= 8 && b <= 8) && (c > sum3(d, e, f)));
    return allocation_possible;
}
