#include "timer.h"

timer::timer(int endp) {
    start = time(NULL);
    cur = 0;
    end = endp;
    stopped = false;
}

void timer::calcTime() {
    if (!stopped) {
        int tRange;
        if ((tRange = time(NULL) - start) > 0) {
            cur += tRange;
            start = time(NULL);
        }
    }
}

void timer::tContinue() {
    start = time(NULL);
    stopped = false;
}

void timer::tStop() {
    stopped = true;
}

void timer::reset() {
    start = time(NULL);
    cur = 0;
    stopped = false;
}

bool timer::isFinish() {
    if (cur >= end) {
        return true;
    }

    return false;
}