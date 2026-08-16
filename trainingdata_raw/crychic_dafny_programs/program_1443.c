// Generated C + ACSL

/*@
    requires 2 * x + y <= 98;
    assigns \nothing;
*/
void a_2_26(int x, int y)
{
  x = (x + 1);
  y = (x + y);
}

/*@
    requires 2 * x + y <= 99;
    assigns \nothing;
    ensures \result <= 100;
*/
int b_2_26(int x, int y)
{
  /*@ assert 2 * x + y <= 99; */
  int x_orig = x;
  int y_orig = y;
  y = (x + y);
  /*@ assert y == x_orig + y_orig; */
  /*@ assert 2 * x_orig + y_orig <= 99; */
  x = (x + 1);
  /*@ assert x == x_orig + 1; */
  /*@ assert y == x_orig + y_orig; */
  int z = (x + y);
  /*@ assert z == x_orig + 1 + x_orig + y_orig; */
  /*@ assert z == 2 * x_orig + y_orig + 1; */
  /*@ assert 2 * x_orig + y_orig <= 99; */
  /*@ assert z <= 100; */
  return z;  // Dafny implicit return
}

/*@
    requires 2 * x + y <= 99;
    assigns \nothing;
*/
void c_2_26(int x, int y)
{
  x = (x + 1);
  y = (x + y);
}

/*@
    requires x + y < 100;
    assigns \nothing;
*/
void exerciseA(int x, int y)
{
  x = 0;
  y = 0;
  x = 32;
  y = 40;
}

/*@
    requires -2 * x + y - 4 < 100;
    assigns \nothing;
*/
void exerciseB(int x, int y)
{
  x = 0;
  y = 0;
  x = (x + 2);
  y = (y - (3 * x));
}

/*@
    requires x < 10;
    assigns \nothing;
*/
void a_2_30(int x, int y)
{
  if (((x % 2) == 0))
  {
    y = (y + 3);
  }
  else
  {
    y = 4;
  }
}