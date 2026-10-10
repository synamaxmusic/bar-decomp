#ifndef UV_PROFILER_H
#define UV_PROFILER_H
s32 uvProfilerCreate(char *label);
void uvProfilerReset(s32 id);
void uvProfilerResetEntry(s32 id);
void uvProfilerGetProps(s32 id, ...);
void uvProfilerInit(void);
#endif /* UV_PROFILER_H */

