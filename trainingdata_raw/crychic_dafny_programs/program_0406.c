// Generated C + ACSL

/*@
    requires i == 6;
    assigns \nothing;
*/
void m(int i)
{
  int j = 17;
  int value = 43;
  /*@ assert value >= 0 && value <= 2147483647; */
  /*@ assert value == 43; */
  /*@ assert j == 17; */
  L:;
  /*@ assert value == 43; */
  /*@ assert j == 17; */
  j = 18;
  /*@ assert value == 43; */
  /*@ assert j == 18; */
  value = 44;
  /*@ assert value == 44; */
  /*@ assert j == 18; */
  M:;
  /*@ assert value == 44; */
  /*@ assert j == 18; */
  /*@ assert (i == 6); */
  /*@ assert (j == 18); */
  /*@ assert (\at(j, L) == 17); */
  /*@ assert (\at(value, L) == 43); */
  /*@ assert ((\at(value, M) == 44) && (value == 44)); */
}