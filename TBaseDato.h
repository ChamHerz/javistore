#ifndef TBASEDATO_H
#define TBASEDATO_H

#include "wx/wxsqlite3.h"

class TBaseDato
{
    public:
        TBaseDato();
        virtual ~TBaseDato();
        float getValorDolarBaseDatos();

    protected:

    private:
        wxSQLite3Database* db;
};

#endif // TBASEDATO_H
