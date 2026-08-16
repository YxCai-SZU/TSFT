#include <stdbool.h>

/*@ predicate valid_range(integer val) = 0 <= val && val <= 100; */

/*@ predicate vector_conditions(int *v) =
      \valid(v + (0..2)) &&
      valid_range(v[0]) &&
      valid_range(v[1]) &&
      valid_range(v[2]); */

/*@ logic integer vector_len(int *v) = 3; */

/*@ lemma length_lemma: 
      \forall int *v; vector_conditions(v) ==> vector_len(v) == 3; */

/*@ requires vector_conditions(v);
    ensures \result == (v[0] <= v[2] && v[0] + v[1] >= v[2]); */
bool func(int *v)
{
    //@ assert vector_len(v) == 3;
    bool result;
    result = v[0] <= v[2] && v[0] + v[1] >= v[2];
    //@ assert result == (v[0] <= v[2] && v[0] + v[1] >= v[2]);
    return result;
}
