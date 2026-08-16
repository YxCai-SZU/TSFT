// Generated C + ACSL

/*@
    requires 1 <= dayNum <= 7;
    assigns \nothing;
    ensures (dayNum == 1 ==> \result == 0) &&
            (dayNum == 2 ==> \result == 1) &&
            (dayNum == 3 ==> \result == 2) &&
            (dayNum == 4 ==> \result == 3) &&
            (dayNum == 5 ==> \result == 4) &&
            (dayNum == 6 ==> \result == 5) &&
            (dayNum == 7 ==> \result == 6);
    ensures 0 <= \result <= 6;
*/
int IntToDay(int dayNum)
{
  int day;
  switch(dayNum) {
    case 1: day = 0; break;
    case 2: day = 1; break;
    case 3: day = 2; break;
    case 4: day = 3; break;
    case 5: day = 4; break;
    case 6: day = 5; break;
    case 7: day = 6; break;
  }
  return day;
}

int otQualified;
int ptQualified;
int stQualified;

/*@
    requires therapyType == 0 || therapyType == 1 || therapyType == 2;
    assigns otQualified, ptQualified, stQualified;
    behavior OT_case:
        assumes therapyType == 0;
        assigns otQualified;
        ensures otQualified == qualified;
        ensures ptQualified == \old(ptQualified);
        ensures stQualified == \old(stQualified);
    behavior PT_case:
        assumes therapyType == 1;
        assigns ptQualified;
        ensures ptQualified == qualified;
        ensures otQualified == \old(otQualified);
        ensures stQualified == \old(stQualified);
    behavior ST_case:
        assumes therapyType == 2;
        assigns stQualified;
        ensures stQualified == qualified;
        ensures otQualified == \old(otQualified);
        ensures ptQualified == \old(ptQualified);
    complete behaviors;
    disjoint behaviors;
*/
void SetQualification(int therapyType, int qualified)
{
  switch(therapyType) {
    case 0: otQualified = qualified; break;
    case 1: ptQualified = qualified; break;
    case 2: stQualified = qualified; break;
  }
}

/*@
    requires therapist != 0;
    requires therapyType == 0 || therapyType == 1 || therapyType == 2;
    assigns \nothing;
    ensures (therapyType == 0 ==> \result == otQualified) &&
            (therapyType == 1 ==> \result == ptQualified) &&
            (therapyType == 2 ==> \result == stQualified);
*/
int IsTherapistQualified(int therapist, int therapyType)
{
  int qualified;
  switch(therapyType) {
    case 0: qualified = otQualified; break;
    case 1: qualified = ptQualified; break;
    case 2: qualified = stQualified; break;
    default: qualified = 0; break;
  }
  return qualified;
}