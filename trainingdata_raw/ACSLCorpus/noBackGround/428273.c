#include <stdbool.h>
#include <stddef.h>

/*@
    requires \valid_read(v + (0 .. len-1));
    requires (\forall size_t i; 0 <= i < (len) ==> (v)[i] % 2 == 0);
    ensures \result == true;
*/
bool test_all_even(unsigned int *v, size_t len)
{
    //@ assert (\forall size_t i; 0 <= i < (len) ==> (v)[i] % 2 == 0);
    return true;
}

/*@
    requires \valid_read(v + (0 .. len-1));
    requires (\exists size_t i; 0 <= i < (len) && (v)[i] % 2 != 0);
    ensures \result == true;
*/
bool test_any_odd(unsigned int *v, size_t len)
{
    //@ assert (\exists size_t i; 0 <= i < (len) && (v)[i] % 2 != 0);
    return true;
}

int main()
{
    unsigned int v[3];
    size_t len = 3;
    
    v[0] = 2;
    v[1] = 4;
    v[2] = 6;
    
    //@ assert (\forall size_t i; 0 <= i < (len) ==> (&v[0])[i] % 2 == 0);
    return 0;
}
