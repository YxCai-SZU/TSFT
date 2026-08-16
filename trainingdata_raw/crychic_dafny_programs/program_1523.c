// Generated C + ACSL

int wrongpincounter = 0;
int authentication = 0;
int insertcard = 1;

/*@
    requires wrongpincounter == 0;
    requires authentication == \false;
    requires insertcard == \true;
    assigns wrongpincounter, authentication, insertcard;
    ensures pin == 4 && \old(wrongpincounter) <= 2 ==> authentication == \true;
    ensures pin != 4 && \old(wrongpincounter) + 1 <= 2 ==>
            authentication == \false && wrongpincounter == \old(wrongpincounter) + 1;
    ensures pin != 4 && \old(wrongpincounter) + 1 >= 3 ==>
            insertcard == \false && authentication == \false;
*/
void enterpin(int pin)
{
  if ((pin != 4))
  {
    authentication = 0;
    /*@ assert authentication >= 0 && authentication <= 2147483647; */
    wrongpincounter = (wrongpincounter + 1);
    /*@ assert wrongpincounter >= 0 && wrongpincounter <= 2147483647; */
  }
  else
  {
    if ((wrongpincounter >= 3))
    {
      authentication = 0;
      insertcard = 0;
      /*@ assert insertcard >= 0 && insertcard <= 2147483647; */
    }
    else
    {
      authentication = 1;
    }
  }
}