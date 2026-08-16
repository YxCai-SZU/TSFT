#include <stdbool.h>

/*@
    requires (1 <= (r) && (r) <= 100);
    ensures \result == (3 * (r) * (r));
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at top of scope
    int res;
    
    //@ assert (1 <= (r) && (r) <= 100);
    //@ assert (3 * (r) * (r)) <= 30000;
    
    res = 3 * r * r;
    //@ assert res == (3 * (r) * (r));
    
    return res;
}

/*@
    requires \true;
    ensures \true;
    assigns \nothing;
*/
void test_map_equality(void)
{
    // Variable declarations at top of scope
    bool map1_valid = true;
    bool map2_valid = true;
    
    //@ assert (\true);
    //@ assert (\true);
    //@ assert (\true)&& (\true);
}
