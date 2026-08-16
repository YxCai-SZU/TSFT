#include <stdbool.h>

/*@
  requires (1 <= (a) <= 100) && (1 <= (b) <= 100);
  ensures \result == a * b;
  assigns \nothing;
*/
int func(int a, int b)
{
    // Variable declarations at top of scope
    int result;
    
    //@ assert (1 <= (a) <= 100);
    //@ assert (1 <= (b) <= 100);
    //@ assert a * b <= 100 * 100;
    
    result = a * b;
    return result;
}

/*@
  assigns \nothing;
*/
void test_choose_axioms(void)
{
    // Variable declarations at top of scope
    bool contains_check;
    
    //@ assert ((1) == 1 || (1) == 2 || (1) == 3 || (1) == 4);
    //@ assert ((2) == 1 || (2) == 2 || (2) == 3 || (2) == 4);
    //@ assert ((3) == 1 || (3) == 2 || (3) == 3 || (3) == 4);
    //@ assert ((4) == 1 || (4) == 2 || (4) == 3 || (4) == 4);
    
    // Simulating set choose operation
    //@ assert ((1) == 1 || (1) == 2 || (1) == 3 || (1) == 4);
}
