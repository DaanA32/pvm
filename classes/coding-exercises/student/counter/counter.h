#ifndef COUNTER_H
#define COUNTER_H

class Counter{
    unsigned int val;
public:
    Counter();
    unsigned int getValue() const;
    void increment();
    void reset();
    void setValue(unsigned int);
};

#endif