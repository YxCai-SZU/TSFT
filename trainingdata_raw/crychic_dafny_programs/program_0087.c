// Generated C + ACSL

/*@
    requires \true;
    assigns \nothing;
    ensures \result == 3 * x;
*/
int Triple(int x)
{
  int r;
  if (x < 18) {
    int a = 2 * x;
    int b = 4 * x;
    r = (a + b) / 2;
  } else if (0 <= x) {
    int y = 2 * x;
    r = x + y;
  } else {
    r = 3 * x;
  }
  return r;
}