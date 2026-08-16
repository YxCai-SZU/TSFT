// Generated C + ACSL

typedef struct {
    char* cooperativeCenterCode;
} Media;

Media* medias;
int medias_count;

/*@
    requires m != 0;
    requires \valid(medias + (0 .. medias_count));
    requires \valid(&medias_count);
    requires medias_count >= 0;
    assigns medias[medias_count].cooperativeCenterCode, medias_count;
    ensures medias_count == \old(medias_count) + 1;
    ensures medias[medias_count - 1].cooperativeCenterCode == m;
    ensures \forall integer i; 0 <= i < \old(medias_count) ==> medias[i].cooperativeCenterCode == \old(medias[i].cooperativeCenterCode);
*/
void AddMedia(char* m)
{
  medias[medias_count].cooperativeCenterCode = m;
  medias_count = medias_count + 1;
}

/*@
    requires centerCode != \null;
    requires centerCode_len >= 0;
    requires \valid_read(centerCode + (0 .. centerCode_len-1));
    requires medias != \null;
    requires medias_len >= 0;
    requires \valid_read(medias + (0 .. medias_len-1));
    requires \forall integer i; 0 <= i < medias_len ==>
        medias[i].cooperativeCenterCode != \null;
    assigns \nothing;
    ensures \result != \null;
*/
int* FilterByCooperativeCenter(char* centerCode, int centerCode_len, Media* medias, int medias_len)
{
  int result = 0;
  /*@ assert result >= 0 && result <= 2147483647; */
  int i = 0;
/*@
  loop invariant 0 <= i <= medias_len;
  loop invariant result <= i;
  loop invariant result >= 0;
  loop invariant result <= medias_len;
  loop invariant \forall integer j; 0 <= j < i ==>
    (medias[j].cooperativeCenterCode == centerCode ==> result >= 1);
  loop invariant \at(medias_len, LoopEntry) == medias_len;
  loop invariant \at(centerCode, LoopEntry) == centerCode;
  loop assigns i, result;
  loop variant medias_len - i;
*/
  while ((i < medias_len))
    {
      if ((medias[i].cooperativeCenterCode == centerCode))
      {
        result = (result + 1);
        /*@ assert result >= 1; */
        /*@ assert result <= i + 1; */
      }
      i = (i + 1);
      /*@ assert i <= medias_len; */
      /*@ assert result <= i; */
    }
  /*@ assert i == medias_len; */
  /*@ assert result >= 0; */
  /*@ assert result <= medias_len; */
  return &result;
}