#include <stdbool.h>

/*@
    ensures \result == true;
*/
bool test_contains_even(void)
{
    int v[3];
    bool result;
    
    v[0] = 2;
    v[1] = 4;
    v[2] = 6;
    
    //@ assert (\exists integer i; 0 <= i < (3) && (&v[0])[i] % 2 == 0);
    result = true;
    return result;
}

/*@
    ensures \result == true;
*/
bool test_contains_odd(void)
{
    int v[3];
    bool result;
    
    v[0] = 1;
    v[1] = 3;
    v[2] = 5;
    
    //@ assert (\exists integer i; 0 <= i < (3) && (&v[0])[i] % 2 != 0);
    result = true;
    return result;
}

/*@
    ensures \result == true;
*/
bool test_all_even(void)
{
    int v[3];
    bool result;
    
    v[0] = 2;
    v[1] = 4;
    v[2] = 6;
    
    //@ assert (\forall integer i; 0 <= i < (3) ==> (&v[0])[i] % 2 == 0);
    result = true;
    return result;
}

/*@
    ensures \result == true;
*/
bool test_all_odd(void)
{
    int v[3];
    bool result;
    
    v[0] = 1;
    v[1] = 3;
    v[2] = 5;
    
    //@ assert (\forall integer i; 0 <= i < (3) ==> (&v[0])[i] % 2 != 0);
    result = true;
    return result;
}

int main(void)
{
    return 0;
}
