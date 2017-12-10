#include "TBaseDato.h"
#include <wx/filefn.h>
#include <wx/intl.h>

TBaseDato::TBaseDato()
{
    db = new wxSQLite3Database();
}

TBaseDato::~TBaseDato()
{
    //dtor
}

float TBaseDato::getValorDolarBaseDatos(){
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery(wxString::Format(_("%s"),"SELECT * FROM setting"));

    int count = 0;
    float precioDolar;
    while (Res.NextRow())
    {
        precioDolar = Res.GetDouble(1);

        count++;
    }

    Res.Finalize();
    db->Close();

    return precioDolar;
}
