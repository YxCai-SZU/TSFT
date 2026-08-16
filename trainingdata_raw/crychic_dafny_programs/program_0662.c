// Generated C + ACSL

typedef struct {
  int *channels;
  int channels_len;
  char *sourcePath;
  int sourcePath_len;
  char *sourceType;
  int sourceType_len;
} AudioSource;

typedef struct {
  char *id;
  int id_len;
  AudioSource *sources;
  int sources_len;
  int samplingRate;
  int numSamples;
  double duration;
} Recording;

typedef struct {
  Recording *recordings;
  int recordings_len;
} RecordingSet;

/*@
  predicate IsValidAudioSource(AudioSource s) =
    s.channels_len > 0 &&
    \valid_read(s.channels + (0 .. s.channels_len-1)) &&
    (\forall integer i; 0 <= i < s.channels_len ==> s.channels[i] >= 0) &&
    s.sourcePath_len > 0 &&
    \valid_read(s.sourcePath + (0 .. s.sourcePath_len-1)) &&
    s.sourceType_len > 0 &&
    \valid_read(s.sourceType + (0 .. s.sourceType_len-1));
*/

/*@
  predicate IsValidRecording(Recording r) =
    r.id_len > 0 &&
    \valid_read(r.id + (0 .. r.id_len-1)) &&
    r.sources_len > 0 &&
    \valid_read(r.sources + (0 .. r.sources_len-1)) &&
    (\forall integer i; 0 <= i < r.sources_len ==>
      IsValidAudioSource(r.sources[i])) &&
    r.samplingRate > 0 &&
    r.numSamples >= 0 &&
    r.duration == (double)r.numSamples / (double)r.samplingRate;
*/

/*@
    requires recordings != \null;
    requires recordings_len >= 0;
    requires \valid_read(recordings + (0 .. recordings_len-1));
    requires \forall integer i; 0 <= i < recordings_len ==> IsValidRecording(recordings[i]);
    assigns \nothing;
    ensures \result == recordings_len;
*/
int CreateRecordingSet(Recording* recordings, int recordings_len)
{
  RecordingSet rs = {recordings, recordings_len};
  /*@ assert rs.recordings_len >= 0 && rs.recordings_len <= 2147483647; */
  return rs.recordings_len;
}

/*@
    requires targetRate > 0;
    requires \valid_read(&rs);
    requires \valid_read(rs.recordings + (0 .. rs.recordings_len-1));
    requires \forall integer i; 0 <= i < rs.recordings_len ==> IsValidRecording(rs.recordings[i]);
    assigns \nothing;
    ensures \result <= rs.recordings_len;
    ensures \result >= 0;
*/
int FilterBySamplingRate(RecordingSet rs, int targetRate)
{
  int matchingCount = 0;
  int i = 0;
/*@
  loop invariant 0 <= i <= rs.recordings_len;
  loop invariant matchingCount <= i;
  loop invariant matchingCount >= 0;
  loop assigns i, matchingCount;
  loop variant rs.recordings_len - i;
*/
  while ((i < rs.recordings_len))
    {
      if ((rs.recordings[i].samplingRate == targetRate))
      {
        matchingCount = (matchingCount + 1);
      }
      i = (i + 1);
    }
  /*@ assert matchingCount >= 0 && matchingCount <= 2147483647; */
  return matchingCount;
}