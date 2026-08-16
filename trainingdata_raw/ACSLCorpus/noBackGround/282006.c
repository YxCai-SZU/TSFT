#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

/*@
  requires 100 <= n <= 999;
  ensures \result == 1 <==> ((n) / 100 == 7 ||
      (n) / 10 % 10 == 7 ||
      (n) % 10 == 7);
  assigns \nothing;
*/
bool func(unsigned int n)
{
    unsigned int n_100;
    unsigned int n_10;
    unsigned int n_1;
    bool result;

    n_100 = n / 100;
    n_10 = n / 10 % 10;
    n_1 = n % 10;
    result = (n_100 == 7) || (n_10 == 7) || (n_1 == 7);
    //@ assert result == 1 <==> ((n) / 100 == 7 ||       (n) / 10 % 10 == 7 ||       (n) % 10 == 7);
    return result;
}

/*@
  requires \valid(v);
  requires \freeable(v);
  assigns *v, *(v+1);
*/
void example7(unsigned int* v)
{
    unsigned int v_0;
    unsigned int v_1;
    unsigned int* s;
    size_t s_len;

    //@ assert v != \null;
    v[0] = 11;
    v[1] = 21;
    s = v;
    s_len = 2;
    //@ assert s[0] == 11;
    //@ assert s[1] == 21;
}
