// Generated C + ACSL

/*@
  predicate ItWasReal(real r) =
    r == 44.1985;
*/

/*@
    assigns \nothing;
*/
void AssignSuchThat(void)
{
  int a;
  a = 0;
  /*@ 
    loop invariant 0 <= a <= 35;
    loop invariant \forall integer k; 0 <= k < a ==> !(k % 5 == 0 && k % 7 == 0);
    loop assigns a;
    loop variant 35 - a;
  */
  while (!(a % 5 == 0 && a % 7 == 0)) {
    a++;
  }
  /*@ assert a % 5 == 0 && a % 7 == 0; */
  /*@ assert 0 <= a <= 35; */
  /*@ assert ItWasReal(44.1985); */
  int b;
  b = 44;
}

/*@
    assigns \nothing;
*/
void LetSuchThat(void)
{
  int a;
  a = 0;
  /*@ 
    loop invariant 0 <= a <= 30;
    loop invariant \forall integer k; 0 <= k < a ==> !(k % 5 == 0 && k % 7 == 0 && 0 <= k && k < 30);
    loop assigns a;
    loop variant 30 - a;
  */
  while (!(a % 5 == 0 && a % 7 == 0 && 0 <= a && a < 30)) {
    a++;
  }
  /*@ assert a % 5 == 0 && a % 7 == 0; */
  /*@ assert 0 <= a < 30; */
  int x = a;
  /*@ assert x >= 0 && x <= 2147483647; */
  /*@ assert x == a; */
  /*@ assert ItWasReal(44.1985); */
  int b;
  b = 44;
  int y = b;
  /*@ assert y >= 0 && y <= 2147483647; */
  /*@ assert y == 44; */
}