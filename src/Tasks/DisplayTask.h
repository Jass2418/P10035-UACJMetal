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

                display.setDisplay(db.plan,4,!isBlinking);
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