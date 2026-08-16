#include <stdbool.h>
#include <stddef.h>

/*@
    requires ((len) % 2 == 0);
    requires ((len) >= 1);
    ensures \result == true;
*/
bool func(size_t len)
{
    //@ assert ((len) % 2 == 0);
    //@ assert ((len) >= 1);
    return true;
}

/*@
    requires ((len) % 2 == 0);
    requires ((len) >= 1);
    ensures \result == true;
*/
bool func2(size_t len)
{
    //@ assert ((len) % 2 == 0);
    //@ assert ((len) >= 1);
    return true;
}

/*@
    requires ((len) % 2 == 0);
    requires ((len) >= 1);
    ensures \result == true;
*/
bool func3(size_t len)
{
    //@ assert ((len) % 2 == 0);
    //@ assert ((len) >= 1);
    return true;
}

/*@
    requires ((len) % 2 == 0);
    requires ((len) >= 1);
    ensures \result == true;
*/
bool func4(size_t len)
{
    //@ assert ((len) % 2 == 0);
    //@ assert ((len) >= 1);
    return true;
}

int main()
{
    size_t v_len = 4;
    //@ assert ((v_len) % 2 == 0);
    //@ assert ((v_len) >= 1);
    
    bool result1 = func(v_len);
    bool result2 = func2(v_len);
    bool result3 = func3(v_len);
    bool result4 = func4(v_len);
    
    return 0;
}
