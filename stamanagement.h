#ifndef STAMANAGEMENT_H
#define STAMANAGEMENT_H
#include"management.h"









class stamanagement:public management{
public:
    friend class staDialog;
    void stuinput();
};










#endif // STAMANAGEMENT_H
