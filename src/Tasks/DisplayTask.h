#ifndef DISPLAY_TASK_H
#define DISPLAY_TASK_H
#include <Display7.h>
#include "Global.h"
class DisplayTask {
    public:
        static void setup(){
            display.begin();
            display.setBrightness(254);
        };
        static void loop(){
                display.clear();
                // Display
                if(db.isOnProgramming)
                    isBlinking = !isBlinking;
                else
                    isBlinking = false;
                // Cluster Output
                display.setDisplayRaw(db.cluster);
                // Display Values
                display.setDigit(db.plan / 1000,false,(db.isOnProgramming && db.digitPosition==4) ? isBlinking : true);
                display.setDigit((db.plan / 100) % 10 ,false,(db.isOnProgramming && db.digitPosition==3) ? isBlinking : true);
                display.setDigit((db.plan / 10) % 10,false,(db.isOnProgramming && db.digitPosition==2) ? isBlinking : true);
                display.setDigit(db.plan % 10,false,(db.isOnProgramming && db.digitPosition==1) ? isBlinking : true);
                display.setDisplay(db.actual,4);
                if(db.plan >= db.actual)
                    display.setDisplay(db.plan - db.actual,4);
                else
                    display.setDisplay(0,4);
                display.show();
            lastPlan = db.plan;
            lastActual = db.actual;
        };
    private:
        static Display7 display;
        static bool isBlinking;
        static uint16_t lastPlan;
        static uint16_t lastActual;
};

Display7 DisplayTask::display(4,5,7,9); // Strobe,Data,Clock,OE
bool DisplayTask::isBlinking = false;
uint16_t DisplayTask::lastPlan = 0;
uint16_t DisplayTask::lastActual = 0;
#endif