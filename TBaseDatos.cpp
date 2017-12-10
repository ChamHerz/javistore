#include "TBaseDatos.h"

TBaseDatos::TBaseDatos(){
    //db = new wxSQLite3Database();
}

float TBaseDatos::getValorDolar(){
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery(wxString::Format(_("%s"),"SELECT * FROM setting"));

    float precioDolar;
    int count = 0;
    while (Res.NextRow())
    {
        precioDolar = wxString::Format(_("%.2f"),Res.GetDouble(1));
        count++;
    }

    Res.Finalize();
    db->Close();

    return precioDolar;
}
