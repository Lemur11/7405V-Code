#include "api.h"
#include <atomic>
#define autonSelector AutonSelector::getInstance()


class AutonSelector {
    private:
        //singleton stuff
        AutonSelector() = default;
        AutonSelector(const AutonSelector&) = delete;
        AutonSelector& operator=(AutonSelector&) = delete;

        std::atomic<int> auton = 0;
        void btnInit(int pos_x, int pos_y, int size_w, int size_h, void (*cb_func) (lv_event_t *), int*);
        static void btn_event_cb(lv_event_t * e);


    public:
        inline static AutonSelector& getInstance() {
            static AutonSelector INSTANCE;
            return INSTANCE;
        }
        // Auton getState();
        void setState(int a);
        void initialize();
        int getState();
        int LEFT = 1;
        int RIGHT = 2;
        int CARRY = 3;

};