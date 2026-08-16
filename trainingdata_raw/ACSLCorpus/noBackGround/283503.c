#include <stdbool.h>

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  ensures \result == a * b;
  assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b)
{
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert a * b <= 10000;
    return a * b;
}

/*@
  requires 1 <= a <= 100;
  requires 1 <= b <= 100;
  ensures \result == a + b;
  assigns \nothing;
*/
unsigned int func2(unsigned int a, unsigned int b)
{
    //@ assert 1 <= a && a <= 100;
    //@ assert 1 <= b && b <= 100;
    //@ assert a + b <= 200;
    return a + b;
}

int main()
{
    return 0;
}
