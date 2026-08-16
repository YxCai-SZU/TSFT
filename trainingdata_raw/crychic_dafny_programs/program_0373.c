// Generated C + ACSL

#include <assert.h>

void Sequences(void);
void Arrays(void);

/*@
    assigns \nothing;
*/
void Main(void)
{
  Sequences();;
  Arrays();;
  /* unsupported stmt: print "that's all, folks!\n"; */
}

/*@
    assigns \nothing;
*/
void Sequences(void)
{
  int a1 = 0;
  int a2 = 0;
  /*@ assert (a1 == a2); */
  assert(a1 == a2);;
}

/*@
    requires \true;
    assigns \nothing;
*/
void Arrays(void)
{
  int a1_vals[] = {42};
  int* a1 = a1_vals;
  int a1_len = 1;
  int a2_vals[] = {42};
  int* a2 = a2_vals;
  int a2_len = 1;
  /*@ assert (a1 != a2); */
  assert(a1 != a2);;
}