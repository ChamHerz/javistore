#include "TProductoAdd.h"

//(*InternalHeaders(TProductoAdd)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(TProductoAdd)
const long TProductoAdd::ID_STATICTEXT1 = wxNewId();
const long TProductoAdd::ID_TEXTCTRL1 = wxNewId();
const long TProductoAdd::ID_STATICTEXT2 = wxNewId();
const long TProductoAdd::ID_TEXTCTRL2 = wxNewId();
const long TProductoAdd::ID_STATICTEXT3 = wxNewId();
const long TProductoAdd::ID_TEXTCTRL3 = wxNewId();
const long TProductoAdd::ID_STATICTEXT4 = wxNewId();
const long TProductoAdd::ID_TEXTCTRL4 = wxNewId();
const long TProductoAdd::ID_STATICTEXT5 = wxNewId();
const long TProductoAdd::ID_TEXTCTRL5 = wxNewId();
const long TProductoAdd::ID_BUTTON1 = wxNewId();
const long TProductoAdd::ID_BUTTON2 = wxNewId();
//*)

const int TProductoAdd::ID_FORMACTION_ADD = 1000;
const int TProductoAdd::ID_FORMACTION_EDIT = 1001;

BEGIN_EVENT_TABLE(TProductoAdd,wxDialog)
	//(*EventTable(TProductoAdd)
	//*)
END_EVENT_TABLE()

TProductoAdd::TProductoAdd(int idProducto,int actionForm,wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(TProductoAdd)
	wxBoxSizer* LayerDescripcion;
	wxBoxSizer* LayerPrecioUSD;
	wxFlexGridSizer* LayerGlobal;
	wxBoxSizer* LayerDesc;
	wxBoxSizer* LayerComision;
	wxBoxSizer* LayerIdProducto;
	wxBoxSizer* LayerBotones;

	Create(parent, id, _("Agregar Producto"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxDEFAULT_DIALOG_STYLE|wxSYSTEM_MENU|wxRESIZE_BORDER|wxCLOSE_BOX, _T("id"));
	SetClientSize(wxDefaultSize);
	Move(wxDefaultPosition);
	LayerGlobal = new wxFlexGridSizer(6, 1, 0, 0);
	LayerGlobal->AddGrowableCol(0);
	LayerGlobal->AddGrowableRow(2);
	LayerIdProducto = new wxBoxSizer(wxHORIZONTAL);
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("ID Producto:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	LayerIdProducto->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxIDProducto = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	LayerIdProducto->Add(TextBoxIDProducto, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerIdProducto, 1, wxALL|wxEXPAND, 5);
	LayerDesc = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Desc:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	LayerDesc->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxDesc = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	LayerDesc->Add(TextBoxDesc, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerDesc, 1, wxALL|wxEXPAND, 5);
	LayerDescripcion = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Descripcion:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	LayerDescripcion->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxDescripcion = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	LayerDescripcion->Add(TextBoxDescripcion, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerDescripcion, 1, wxALL|wxEXPAND, 5);
	LayerPrecioUSD = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Precio USD:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	LayerPrecioUSD->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxPrecioUSD = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	LayerPrecioUSD->Add(TextBoxPrecioUSD, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerPrecioUSD, 1, wxALL|wxEXPAND, 5);
	LayerComision = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Comision:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	LayerComision->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxComision = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	LayerComision->Add(TextBoxComision, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerComision, 1, wxALL|wxEXPAND, 5);
	LayerBotones = new wxBoxSizer(wxHORIZONTAL);
	BotonAceptar = new wxButton(this, ID_BUTTON1, _("Aceptar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	LayerBotones->Add(BotonAceptar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BotonCancelar = new wxButton(this, ID_BUTTON2, _("Cancelar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	LayerBotones->Add(BotonCancelar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerBotones, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(LayerGlobal);
	LayerGlobal->Fit(this);
	LayerGlobal->SetSizeHints(this);
	Center();

	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TProductoAdd::OnBotonAceptarClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TProductoAdd::OnBotonCancelarClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&TProductoAdd::OnClose);
	//*)

	ID_Producto = idProducto;
    ID_ACTIONFORM_STATUS = actionForm;

    db = new wxSQLite3Database();

    TextBoxIDProducto->SetValue(wxString::Format(_("%i"),ID_Producto));

    if (ID_ACTIONFORM_STATUS == ID_FORMACTION_EDIT){
        SetTitle("Editar Producto");

        wxString testDBName = wxGetCwd() + wxT("/database.db");
        db->Open(testDBName);
        wxString SQLQuery = wxString::Format(_("SELECT * FROM producto WHERE ID_Producto = %i LIMIT 1"),idProducto);
        wxSQLite3ResultSet ResProducto = db->ExecuteQuery(SQLQuery);

        TextBoxDesc->SetValue(ResProducto.GetAsString(1));
        TextBoxDescripcion->SetValue(ResProducto.GetAsString(2));
        TextBoxPrecioUSD->SetValue(wxString::Format(_("%.2f"),ResProducto.GetDouble(3)));
        TextBoxComision->SetValue(wxString::Format(_("%.2f"),ResProducto.GetDouble(4)));

        ResProducto.Finalize();
        db->Close();
	}
}

TProductoAdd::~TProductoAdd()
{
	//(*Destroy(TProductoAdd)
	//*)
}


void TProductoAdd::OnBotonCancelarClick(wxCommandEvent& event)
{
    this->EndModal(0);
}

void TProductoAdd::OnClose(wxCloseEvent& event)
{
    this->EndModal(0);
}

void TProductoAdd::OnBotonAceptarClick(wxCommandEvent& event)
{
    if (ID_ACTIONFORM_STATUS == ID_FORMACTION_ADD){
        wxString testDBName = wxGetCwd() + wxT("/database.db");
        db->Open(testDBName);

        wxString consulta = wxString::Format(_("INSERT INTO producto (ID_Producto,Desc,Descripcion,PrecioUSD,Comision) VALUES ('%s','%s','%s','%s','%s');"),
                                             TextBoxIDProducto->GetValue(),
                                             TextBoxDesc->GetValue(),
                                             TextBoxDescripcion->GetValue(),
                                             TextBoxPrecioUSD->GetValue(),
                                             TextBoxComision->GetValue());
        wxSQLite3ResultSet Res = db->ExecuteQuery(consulta);
        db->Close();
        this->EndModal(1);
    }
}
