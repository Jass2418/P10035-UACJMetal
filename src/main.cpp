#define _TASK_SLEEP_ON_IDLE_RUN
#include "Global.h"
// Watchdog
Watchdog wd;
// Database
DbContext db;
// Tasks & Task Manager
Scheduler ts;
Task sTaskS(10,TASK_ONCE,&SystemTask::setup,&ts,true);
Task sTaskL(1000,TASK_FOREVER,&SystemTask::loop,&ts,true);
Task dpTaskS(10,TASK_ONCE,&DisplayTask::setup,&ts,true);
Task dpTaskL(500,TASK_FOREVER,&DisplayTask::loop,&ts,true);
Task btnTaskS(10,TASK_ONCE,&ButtonTask::setup,&ts,true);
Task btnTaskL(20,TASK_FOREVER,&ButtonTask::loop,&ts,true);
Task ledTaskS(10,TASK_ONCE,&LedTask::setup,&ts,true);
Task ledTaskL(100,TASK_FOREVER,&LedTask::loop,&ts,true);

void setup() {
  wd.setup(WDTO_15MS);
  ts.startNow();
}

void loop() {
  ts.execute();
  if(!wd.isRebootNeeded())
    wd.reset();
}