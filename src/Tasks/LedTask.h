#ifndef LED_TASK_H
#define LED_TASK_H
#include <SLED.h>
#include "Global.h"
class LedTask {
    public:
        static void setup(){
            db.cluster = 0;
        };
        static void loop(){ 
            if(db.plan == db.actual){
                db.cluster = DisplaySegment::F;
            }
            else if(db.actual > db.plan){
                db.cluster = DisplaySegment::G;
            }
            else if(db.actual < db.plan){
                db.cluster = DisplaySegment::dot;
            }
        };
    private:
};

#endif