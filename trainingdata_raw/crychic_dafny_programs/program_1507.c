#include <assert.h>

typedef struct {
    int val;
    int mod;
} ModField;

/*@
  predicate members_of_same_field(ModField m, ModField n) =
    m.mod == n.mod;
*/

/*@
  logic ModField canonical_logic(ModField m) =
    (ModField){m.val % m.mod, m.mod};
*/

/*@
    assigns \nothing;
    ensures \result.val == m.val % m.mod;
    ensures \result.mod == m.mod;
*/
ModField canonical(ModField m)
{
  ModField result;
  result.val = m.val % m.mod;
  result.mod = m.mod;
  return result;
}

/*@
  predicate congruent(ModField m, ModField n) =
    members_of_same_field(m, n) && canonical_logic(m).val == canonical_logic(n).val;
*/

/*@
    requires members_of_same_field(m, n);
    assigns \nothing;
    ensures \result.val == m.val + n.val;
    ensures \result.mod == m.mod;
*/
ModField add(ModField m, ModField n)
{
  assert(m.mod == n.mod);
  ModField result;
  result.val = m.val + n.val;
  result.mod = m.mod;
  return result;
}

/*@
    assigns \nothing;
    ensures \result.val == -m.val;
    ensures \result.mod == m.mod;
*/
ModField additiveInverse(ModField m)
{
  ModField result;
  result.val = -m.val;
  result.mod = m.mod;
  return result;
}