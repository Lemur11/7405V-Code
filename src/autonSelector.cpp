#include "autonSelector.h"


void AutonSelector::setState(int a) {
    this->auton.store(a);
}

int AutonSelector::getState() {
    return this->auton.load();
}

void AutonSelector::initialize() {
    this->btnInit(10, 10, 120, 50, AutonSelector::btn_event_cb, &LEFT);
    this->btnInit(140, 10, 120, 50, AutonSelector::btn_event_cb, &RIGHT);
    this->btnInit(270, 10, 120, 50, AutonSelector::btn_event_cb, &CARRY);
}

void AutonSelector::btnInit(int pos_x, int pos_y, int size_w, int size_h, void (*cb_func) (lv_event_t *), int* a){
    lv_obj_t * btn = lv_btn_create(lv_scr_act());     /*Add a button the current screen*/
    lv_obj_set_pos(btn, pos_x, pos_y);                            /*Set its position*/
    lv_obj_set_size(btn, size_w, size_h);                          /*Set its size*/
    lv_obj_add_event_cb(btn, *cb_func, LV_EVENT_ALL, a);           /*Assign a callback to the button*/
    std::string text;
    lv_obj_t * label = lv_label_create(btn);          /*Add a label to the button*/
    if (*a == 2) {
        text = "BlueNEG/RedPOS";
    }
    else if (*a == 3) {
        text = "BluePOS/RedNEG";
    }
    const char * c = text.c_str();
    lv_label_set_text(label, c);                     /*Set the labels text*/
    lv_obj_center(label);
    // while (true) {
    //     pros::delay(20);
    // }
}

void AutonSelector::btn_event_cb(lv_event_t * e) {
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * btn = lv_event_get_target(e);
    if(code == LV_EVENT_CLICKED) {
        int* autonptr = (int *)lv_event_get_user_data(e);
        autonSelector.setState(*autonptr);
        lv_obj_t * label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Button: %d", *autonptr);
        // lv_obj_clean(lv_scr_act());
    }
}