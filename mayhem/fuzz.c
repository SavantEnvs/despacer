// libFuzzer harness for despacer's despace(), ported verbatim from the
// mayhemheroes fork's fuzz/fuzz.c (26b1125819cc). despace() mutates its
// buffer argument in place, and the original harness hands it libFuzzer's
// own read-only input buffer directly (no copy) — the exact shape that made
// the original run trip libFuzzer's CrashOnOverwrittenData check.
#include <stddef.h>

#include "despacer.c"

int LLVMFuzzerTestOneInput(char *data, size_t size) {
  despace(data, size);
  return 0;
}
