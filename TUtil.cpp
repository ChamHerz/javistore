#include "TUtil.h"
#include <time.h>
#include <string.h>

TUtil::TUtil()
{
    //ctor
}

TUtil::~TUtil()
{
    //dtor
}

wxDateTime TUtil::getFechaWX(int fechaUnix){
    time_t timeGMT = (time_t)fechaUnix;
    return wxDateTime(timeGMT);
}

string TUtil::getFecha(int fechaUnix){
    char tiempo_string[20];
    if (fechaUnix > 0){
        time_t timeGMT = (time_t)fechaUnix;
        strftime(tiempo_string, sizeof(tiempo_string), "%Y-%m-%d", localtime(&timeGMT));
    }
    else{
        strcpy(tiempo_string, "");
    }
    return tiempo_string;
}

int TUtil::getFechaUnix(wxDateTime fecha){
    time_t timeGMT = fecha.GetTicks();
    struct tm * timeinfo;
    timeinfo = localtime ( &timeGMT );
    return mktime ( timeinfo );
}
