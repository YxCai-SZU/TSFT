#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x && x <= 100000;
    
    logic integer compute_m(integer x) = 100 * (x / 100);
    
    lemma m_bound: \forall integer x; 1 <= x ==> compute_m(x) <= x;
*/

bool func1(unsigned int x)
{
    unsigned int n;
    unsigned int m;
    bool result;
    
    //@ assert is_valid_range(x);
    
    if (x >= 2000) {
        result = true;
        //@ assert result == (x >= 2000 || (100 * (x / 100) <= x));
        return result;
    } else {
        n = x / 100;
        m = 100 * n;
        
        //@ assert m == compute_m(x);
        //@ assert m <= x;
        
        if (m <= x) {
            result = true;
            //@ assert result == (x >= 2000 || (100 * (x / 100) <= x));
            return result;
        } else {
            result = false;
            //@ assert result == (x >= 2000 || (100 * (x / 100) <= x));
            return result;
        }
    }
}

/*@
    predicate in_range(integer x) = 1 <= x <= 100;

    logic integer state_logic(integer a, integer c) =
        a <= c ? 1 : 0;

    lemma state_bounds:
        \forall integer a, c;
        in_range(a) && in_range(c) ==>
        state_logic(a, c) == 0 || state_logic(a, c) == 1;
*/

bool func2(int a, int b, int c)
{
    int state = 0;

    //@ assert state == 0;

    if (a <= c)
    {
        state = 1;
    }

    //@ assert state == 0 || state == 1;

    if (state == 1 && c <= b)
    {
        return true;
    }
    else
    {
        //@ assert state == 0 || (state == 1 && c > b);
        if (state == 0)
        {
            //@ assert a > c;
        }
        else
        {
            //@ assert c > b;
        }
        return false;
    }
}

/*@
    predicate valid_request(unsigned int id, int min, int max, int size) =
        is_valid_range(id) && in_range(min) && in_range(max) && in_range(size) &&
        (id >= 2000 || (100 * (id / 100) <= id)) &&
        (size >= min && size <= max);
*/
bool resource_alloc_validator(unsigned int x, int a, int b, int c)
{
    bool step1_result;
    bool step2_result;

    step1_result = func1(x);

    step2_result = func2(a, b, c);

    bool final_result = step1_result && step2_result;

    return final_result;
}
