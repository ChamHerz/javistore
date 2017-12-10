#include "TClienteAdd.h"

//(*InternalHeaders(TClienteAdd)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(TClienteAdd)
const long TClienteAdd::ID_STATICTEXT1 = wxNewId();
const long TClienteAdd::ID_TEXTCTRL1 = wxNewId();
const long TClienteAdd::ID_STATICTEXT2 = wxNewId();
const long TClienteAdd::ID_TEXTCTRL2 = wxNewId();
const long TClienteAdd::ID_STATICTEXT3 = wxNewId();
const long TClienteAdd::ID_TEXTCTRL3 = wxNewId();
const long TClienteAdd::ID_STATICTEXT4 = wxNewId();
const long TClienteAdd::ID_TEXTCTRL4 = wxNewId();
const long TClienteAdd::ID_STATICTEXT5 = wxNewId();
const long TClienteAdd::ID_TEXTCTRL5 = wxNewId();
const long TClienteAdd::ID_BUTTON1 = wxNewId();
const long TClienteAdd::ID_BUTTON2 = wxNewId();
//*)

const int TClienteAdd::ID_FORMACTION_ADD = 1000;
const int TClienteAdd::ID_FORMACTION_EDIT = 1001;

BEGIN_EVENT_TABLE(TClienteAdd,wxDialog)
	//(*EventTable(TClienteAdd)
	//*)
END_EVENT_TABLE()

TClienteAdd::TClienteAdd(int idCliente,int accionForm,wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(TClienteAdd)
	wxBoxSizer* LayerNombres;
	wxBoxSizer* LayerApellido;
	wxBoxSizer* LayerEmail;
	wxFlexGridSizer* LayerGlobal;
	wxBoxSizer* LayerBottom;
	wxBoxSizer* LayerTelefono;
	wxBoxSizer* LayerIDCliente;

	Create(parent, id, _("Agregar Cliente"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX, _T("id"));
	SetClientSize(wxSize(600,340));
	Move(wxDefaultPosition);
	SetMinSize(wxSize(600,340));
	LayerGlobal = new wxFlexGridSizer(6, 1, 0, 0);
	LayerGlobal->AddGrowableCol(0);
	LayerGlobal->AddGrowableRow(5);
	LayerIDCliente = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("ID Cliente"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	LayerIDCliente->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxIdCliente = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxSize(200,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	TextBoxIdCliente->Disable();
	LayerIDCliente->Add(TextBoxIdCliente, 3, wxALL, 5);
	LayerGlobal->Add(LayerIDCliente, 1, wxALL|wxEXPAND, 5);
	LayerApellido = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Apellido"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	LayerApellido->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxApellido = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxSize(200,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	LayerApellido->Add(TextBoxApellido, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerApellido, 1, wxALL|wxEXPAND, 5);
	LayerNombres = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Nombres"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	LayerNombres->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxNombres = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxSize(200,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	LayerNombres->Add(TextBoxNombres, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerNombres, 1, wxALL|wxEXPAND, 5);
	LayerTelefono = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Telefono"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	LayerTelefono->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxTelefono = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxSize(200,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	LayerTelefono->Add(TextBoxTelefono, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerTelefono, 1, wxALL|wxEXPAND, 5);
	LayerEmail = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Email"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	LayerEmail->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxEmail = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxSize(200,30), 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	LayerEmail->Add(TextBoxEmail, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerEmail, 1, wxALL|wxEXPAND, 5);
	LayerBottom = new wxBoxSizer(wxHORIZONTAL);
	BotonAceptar = new wxButton(this, ID_BUTTON1, _("Aceptar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	LayerBottom->Add(BotonAceptar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BotonCancelar = new wxButton(this, ID_BUTTON2, _("Cancelar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	LayerBottom->Add(BotonCancelar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerBottom, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(LayerGlobal);
	SetSizer(LayerGlobal);
	Layout();
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TClienteAdd::OnBotonAceptarClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TClienteAdd::OnBotonCancelarClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&TClienteAdd::OnClose);
	//*)

	db = new wxSQLite3Database();

	ID_ACTIONFORM_STATUS = accionForm;
	ID_Cliente = idCliente;
	TextBoxIdCliente->SetValue(wxString::Format(_("%i"),ID_Cliente) ) ;

	if (ID_ACTIONFORM_STATUS == ID_FORMACTION_EDIT){
        SetTitle("Editar Cliente");

        wxString testDBName = wxGetCwd() + wxT("/database.db");
        db->Open(testDBName);
        wxString SQLQuery = wxString::Format(_("SELECT * FROM cliente WHERE ID_Cliente = %i LIMIT 1"),idCliente);
        wxSQLite3ResultSet Res = db->ExecuteQuery(SQLQuery);

        TextBoxApellido->SetValue(Res.GetAsString(1));
        TextBoxNombres->SetValue(Res.GetAsString(2));
        TextBoxTelefono->SetValue(Res.GetAsString(3));
        TextBoxEmail->SetValue(Res.GetAsString(4));

        Res.Finalize();
        db->Close();
	}
}

TClienteAdd::~TClienteAdd()
{
	//(*Destroy(TClienteAdd)
	//*)
}


void TClienteAdd::OnBotonCancelarClick(wxCommandEvent& event)
{
    this->EndModal(0);
}

void TClienteAdd::OnBotonAceptarClick(wxCommandEvent& event)
{
    if (ID_ACTIONFORM_STATUS == ID_FORMACTION_ADD){
        wxString testDBName = wxGetCwd() + wxT("/database.db");
        db->Open(testDBName);

        wxString consulta = wxString::Format(_("INSERT INTO cliente (ID_Cliente, Apellido, Nombre, Telefono, Email) VALUES (%s,'%s','%s','%s','%s');"),
                                             TextBoxIdCliente->GetValue(),
                                             TextBoxApellido->GetValue(),
                                             TextBoxNombres->GetValue(),
                                             TextBoxTelefono->GetValue(),
                                             TextBoxEmail->GetValue());
        wxSQLite3ResultSet Res = db->ExecuteQuery(consulta);

        db->Close();

        this->EndModal(1);
    }

    if (ID_ACTIONFORM_STATUS == ID_FORMACTION_EDIT){
        wxString testDBName = wxGetCwd() + wxT("/database.db");
        db->Open(testDBName);

        wxString consulta = wxString::Format(_("UPDATE cliente SET Apellido='%s',Nombre='%s',Telefono='%s',Email='%s' WHERE ID_Cliente=%S"),
                                             TextBoxApellido->GetValue(),
                                             TextBoxNombres->GetValue(),
                                             TextBoxTelefono->GetValue(),
                                             TextBoxEmail->GetValue(),
                                             TextBoxIdCliente->GetValue());
        wxSQLite3ResultSet Res = db->ExecuteQuery(consulta);

        db->Close();

        this->EndModal(1);
    }
}

void TClienteAdd::OnClose(wxCloseEvent& event)
{
    this->EndModal(0);
}
