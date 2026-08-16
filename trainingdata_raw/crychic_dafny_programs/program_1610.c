// Generated C + ACSL

typedef struct {
    int noticeBbs;
    int noticeComment;
    int noticeLike;
} Profile;

/*@
    requires profile != \null;
    requires \valid(profile);
    assigns profile->noticeBbs, profile->noticeComment, profile->noticeLike;
    ensures profile->noticeBbs == 0;
    ensures profile->noticeComment == 0;
    ensures profile->noticeLike == 0;
*/
void MigrateProfile(Profile* profile)
{
  profile->noticeBbs = 0;
  profile->noticeComment = 0;
  profile->noticeLike = 0;
}

/*@
    requires profiles != \null;
    requires profiles_len >= 0;
    requires \valid(profiles + (0 .. profiles_len-1));
    requires \forall integer i; 0 <= i < profiles_len ==> \valid(&profiles[i]);
    assigns profiles[0 .. profiles_len-1];
    ensures \forall integer i; 0 <= i < profiles_len ==>
        profiles[i].noticeBbs == 0 &&
        profiles[i].noticeComment == 0 &&
        profiles[i].noticeLike == 0;
*/
void MigrateProfiles(Profile* profiles, int profiles_len)
{
  int i = 0;
/*@
  loop invariant 0 <= i <= profiles_len;
  loop invariant \forall integer j; 0 <= j < i ==>
      profiles[j].noticeBbs == 0;
  loop invariant \forall integer j; 0 <= j < i ==>
      profiles[j].noticeComment == 0;
  loop invariant \forall integer j; 0 <= j < i ==>
      profiles[j].noticeLike == 0;
  loop assigns i, profiles[0..profiles_len-1];
  loop variant profiles_len - i;
*/
  while ((i < profiles_len))
    {
      MigrateProfile(&profiles[i]);
      //@ assert profiles[i].noticeBbs == 0;
      //@ assert profiles[i].noticeComment == 0;
      //@ assert profiles[i].noticeLike == 0;
      i = (i + 1);
    }
}