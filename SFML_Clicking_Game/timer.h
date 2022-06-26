#pragma once
#include <ctime>

class timer {
private:
    long long int start;
    int end, cur;
    bool stopped;

public:
    timer(int endp);

    void calcTime();

    void tContinue();

    void tStop();

    void reset();

    bool isFinish();
};

