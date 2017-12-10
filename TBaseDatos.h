#ifndef TBASEDATOS_H
#define TBASEDATOS_H

class TBaseDatos {

    public:
        TBaseDatos();
        float getValorDolar();

    private:
        wxSQLite3Database* db;

};

#endif // TBASEDATOS_H_INCLUDED
