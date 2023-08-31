#ifndef BUTTON_TASK_H
#define BUTTON_TASK_H
#include <Button.h>
#include "Global.h"

#define MIN_VALUE 0
#define MAX_VALUE 9999
#define MAX_DIGIT_POS 4
class ButtonTask {
    public:
        static void setup(){
            incrementExtBtn.begin();
            decrementExtBtn.begin();
            resetExtBtn.begin();
            programBtn.begin();
            incrementBtn.begin();
            decrementBtn.begin();
        };
        static void loop(){
            if (incrementExtBtn.pressed())
                db.actual++;
            if (decrementExtBtn.pressed())
                db.actual--;
            if (resetExtBtn.pressed())
                db.actual = 0;

            if (programBtn.pressed()){
                if(db.digitPosition >= MAX_DIGIT_POS){
                    db.isOnProgramming = false;
                    db.digitPosition = 0;
                    db.planEEPROM.add(db.plan);
                }
                else {
                    db.isOnProgramming = true;
                    db.digitPosition++;
                }
            }
            if (incrementBtn.pressed() && db.isOnProgramming){
                uint16_t multipler = 1;
                for (int i = 0; i < db.digitPosition - 1; i++)
                    multipler *= 10;
                if(((db.plan / multipler) % 10) != 9)
                    db.plan += multipler;
                else
                    db.plan -= (multipler * 9);
            }
            if (decrementBtn.pressed() && db.isOnProgramming) {
                uint16_t multipler = 1;
                for (int i = 0; i < db.digitPosition - 1; i++)
                    multipler *= 10;
                if(((db.plan / multipler) % 10) != 0)
                    db.plan -= multipler;
                else
                    db.plan += (multipler * 9);
            }
            // Validation Values
            if(db.plan <= MIN_VALUE)
                db.plan = MIN_VALUE;
            else if(db.plan > MAX_VALUE)
                db.plan = MAX_VALUE;

            if(db.actual <= MIN_VALUE)
                db.actual = MIN_VALUE;
            else if(db.actual > MAX_VALUE)
                db.actual = MAX_VALUE;
        };
    private:
        static Button incrementExtBtn;
        static Button decrementExtBtn;
        static Button resetExtBtn;
        static Button programBtn;
        static Button incrementBtn;
        static Button decrementBtn;
};

Button ButtonTask::incrementExtBtn(8);
Button ButtonTask::decrementExtBtn(6);
Button ButtonTask::resetExtBtn(10);
Button ButtonTask::programBtn(11);
Button ButtonTask::incrementBtn(12);
Button ButtonTask::decrementBtn(13);
#endif