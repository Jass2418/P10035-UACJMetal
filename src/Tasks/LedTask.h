#ifndef LED_TASK_H
#define LED_TASK_H
#include <SLED.h>
#include "Global.h"
class LedTask {
    public:
        static void setup(){

        };
        static void loop(){ 
            green.update();
            red.update();
            yellow.update();

            if(db.plan == db.actual){
                green.setOnSingle();
                red.setOffSingle();
                yellow.setOffSingle();
            }
            else if(db.actual > db.plan){
                yellow.setOnSingle();
                green.setOffSingle();
                red.setOffSingle();
            }
            else if(db.actual < db.plan){
                red.setOnSingle();
                yellow.setOffSingle();
                green.setOffSingle();
            }
        };
    private:
        static SLED green;
        static SLED red;
        static SLED yellow;
};

SLED LedTask::green(A1);
SLED LedTask::red(A2);
SLED LedTask::yellow(A3);

#endif