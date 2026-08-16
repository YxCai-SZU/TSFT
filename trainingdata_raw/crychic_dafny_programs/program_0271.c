// Generated C + ACSL

/*@ axiomatic Power {
  @   logic integer Potencia(integer x, integer y);
  @   
  @   axiom Potencia_base: \forall integer x; Potencia(x, 0) == 1;
  @   
  @   axiom Potencia_step: \forall integer x, y; y > 0 ==> 
  @     Potencia(x, y) == x * Potencia(x, y - 1);
  @ }
  */

/*@
  requires y >= 0;
  decreases y;
  ensures y == 0 ==> \result == 1;
  ensures y > 0 ==> \result == x * Potencia(x, y - 1);
  ensures \result == Potencia(x, y);
*/
int Potencia(int x, int y)
{
  return ((y == 0)) ? (1) : ((x * Potencia(x, (y - 1))));
}

/*@ logic integer Pot(integer x, integer y); */
/*@
  requires y >= 0;
  ensures \result == Potencia(x, y);
*/
int Pot(int x, int y)
{
  int r = 1;
  /*@ assert r == 1; */
  /*@ assert r == Potencia(x, 0); */
  int b = x;
  int e = y;
  /*@ assert e == y; */
  /*@ assert b == x; */
  /*@ assert r * Potencia(b, e) == Potencia(x, y); */
/*@
  loop invariant 0 <= e <= y;
  loop invariant b == x;
  loop invariant r * Potencia(b, e) == Potencia(x, y);
  loop assigns r, e;
  loop variant e;
*/
  while ((e > 0))
    {
      /*@ assert e > 0; */
      /*@ assert r * Potencia(b, e) == Potencia(x, y); */
      /*@ assert Potencia(b, e) == b * Potencia(b, e - 1); */
      r = (r * b);
      /*@ assert r == \at(r, LoopCurrent) * b; */
      e = (e - 1);
      /*@ assert e == \at(e, LoopCurrent) - 1; */
      /*@ assert r * Potencia(b, e) == Potencia(x, y); */
    }
  /*@ assert e == 0; */
  /*@ assert Potencia(b, 0) == 1; */
  /*@ assert r * 1 == Potencia(x, y); */
  /*@ assert r == Potencia(x, y); */
  return r;
}