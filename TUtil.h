#ifndef TUTIL_H
#define TUTIL_H

#include <string>
#include <wx/datetime.h>

using namespace std;

class TUtil
{
    public:
        TUtil();
        virtual ~TUtil();

        string getFecha(int fechaUnix);
        wxDateTime getFechaWX(int fechaUnix);
        int getFechaUnix(wxDateTime fecha);

    protected:

    private:
};

#endif // TUTIL_H
