#include <stdbool.h>

/*@
    requires (0 <= (a) && (a) <= 100 &&
        0 <= (b) && (b) <= 100 &&
        0 <= (x) && (x) <= 100);
    ensures ((\result) == ((a) <= (x) && (a) + (b) >= (x)));
*/
bool is_possible_x_cats(int a, int b, int x)
{
    //@ assert 0 <= a && a <= 100;
    //@ assert 0 <= b && b <= 100;
    //@ assert 0 <= x && x <= 100;
    
    bool result = (a <= x) && (a + b >= x);
    
    //@ assert result == (a <= x && a + b >= x);
    return result;
}

#ifdef TESTING
#include <assert.h>

int main()
{
    bool result;
    
    result = is_possible_x_cats(1, 2, 3);
    //@ assert result == true;
    assert(result == true);
    
    result = is_possible_x_cats(1, 2, 5);
    //@ assert result == false;
    assert(result == false);
    
    result = is_possible_x_cats(5, 2, 3);
    //@ assert result == false;
    assert(result == false);
    
    return 0;
}
#endif
