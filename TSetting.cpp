#include "TSetting.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(TSetting)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(TSetting)
const long TSetting::ID_STATICTEXT1 = wxNewId();
const long TSetting::ID_TEXTCTRL1 = wxNewId();
const long TSetting::ID_BUTTON1 = wxNewId();
const long TSetting::ID_BUTTON2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TSetting,wxDialog)
	//(*EventTable(TSetting)
	//*)
END_EVENT_TABLE()

TSetting::TSetting(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(TSetting)
	wxFlexGridSizer* LayerGeneral;
	wxBoxSizer* LayerDolar;
	wxBoxSizer* LayerBottom;

	Create(parent, id, _("Configuracion"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	LayerGeneral = new wxFlexGridSizer(2, 1, 0, 0);
	LayerDolar = new wxBoxSizer(wxHORIZONTAL);
	TextoDolar = new wxStaticText(this, ID_STATICTEXT1, _("Precio del Dolar en Pesos Argentinos:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	LayerDolar->Add(TextoDolar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxPrecioDolar = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	LayerDolar->Add(TextBoxPrecioDolar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGeneral->Add(LayerDolar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerBottom = new wxBoxSizer(wxHORIZONTAL);
	BotonAceptar = new wxButton(this, ID_BUTTON1, _("Guardar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	LayerBottom->Add(BotonAceptar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BotonCancelar = new wxButton(this, ID_BUTTON2, _("Cancelar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	LayerBottom->Add(BotonCancelar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGeneral->Add(LayerBottom, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(LayerGeneral);
	LayerGeneral->Fit(this);
	LayerGeneral->SetSizeHints(this);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TSetting::OnBotonAceptarClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TSetting::OnBotonCancelarClick);
	//*)

	db = new wxSQLite3Database();

	SettingSelectAll();
}

TSetting::~TSetting()
{
	//(*Destroy(TSetting)
	//*)
}

void TSetting::SettingSelectAll(){
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery("SELECT * FROM setting");

    TextBoxPrecioDolar->Clear();

    int count = 0;
    while (Res.NextRow())
    {
        wxString precioDolar = wxString::Format(_("%.2f"),Res.GetDouble(1));
        TextBoxPrecioDolar->SetLabel(precioDolar);

        count++;
    }

    Res.Finalize();
    db->Close();
}

void TSetting::OnBotonCancelarClick(wxCommandEvent& event)
{
    this->EndModal(0);
}

void TSetting::OnBotonAceptarClick(wxCommandEvent& event)
{
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);

    wxString consulta = wxString::Format(_("UPDATE setting SET PrecioDolar=%s WHERE ID_Setting=1;"),TextBoxPrecioDolar->GetValue());
    wxSQLite3ResultSet Res = db->ExecuteQuery(consulta);

    db->Close();

    SettingSelectAll();

    this->EndModal(1);
}
