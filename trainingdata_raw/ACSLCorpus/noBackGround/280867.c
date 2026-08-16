#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  requires 1 <= c <= 100;
  ensures \result == true <==> (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
*/
bool func(int a, int b, int c)
{
    bool ans;
    //@ assert 1 <= a <= 100;
    //@ assert 1 <= b <= 100;
    //@ assert 1 <= c <= 100;
    ans = (a < c && c < b) || (a > c && c > b);
    //@ assert ans == true <==> (((a) < (c) && (c) < (b)) || ((a) > (c) && (c) > (b)));
    return ans;
}

#ifdef TEST
#include <assert.h>
int main()
{
    bool result;
    
    result = func(1, 3, 2);
    //@ assert result == true;
    assert(result == true);
    
    result = func(3, 2, 1);
    //@ assert result == false;
    assert(result == false);
    
    result = func(1, 2, 3);
    //@ assert result == false;
    assert(result == false);
    
    result = func(3, 1, 2);
    //@ assert result == false;
    assert(result == false);
    
    return 0;
}
#endif
