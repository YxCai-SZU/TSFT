// Generated C + ACSL

#include <string.h>

#define Success 0
#define Failure(x) (x)
#define AssertionError(x) (-1)

/*@
    requires \true;
    assigns \nothing;
    ensures (expr != 0) ==> (\result == 0);
    ensures (expr == 0) ==> (\result != 0);
*/
int ok_(int expr, const char* msg)
{
  if (expr)
  {
    return Success;
  }
  else
  {
    const char* errorMsg = (msg != NULL) ? msg : "Assertion failed";
    return Failure(AssertionError(errorMsg));
  }
}

/*@
    assigns \nothing;
    ensures (a == b) ==> (\result == 0);
    ensures (a != b) ==> (\result != 0);
*/
int eq_(int a, int b, const char* msg)
{
  if (a == b)
  {
    return Success;
  }
  else
  {
    const char* errorMsg = (msg != NULL) ? msg : "Values not equal";
    return Failure(AssertionError(errorMsg));
  }
}