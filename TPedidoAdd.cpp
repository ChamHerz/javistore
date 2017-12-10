#include "TPedidoAdd.h"

//(*InternalHeaders(TPedidoAdd)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(TPedidoAdd)
const long TPedidoAdd::ID_STATICTEXT17 = wxNewId();
const long TPedidoAdd::ID_TEXTCTRL12 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT1 = wxNewId();
const long TPedidoAdd::ID_CHOICE1 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT7 = wxNewId();
const long TPedidoAdd::ID_CHOICE2 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT2 = wxNewId();
const long TPedidoAdd::ID_TEXTCTRL1 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT3 = wxNewId();
const long TPedidoAdd::ID_TEXTCTRL2 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT4 = wxNewId();
const long TPedidoAdd::ID_TEXTCTRL3 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT5 = wxNewId();
const long TPedidoAdd::ID_TEXTCTRL4 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT6 = wxNewId();
const long TPedidoAdd::ID_TEXTCTRL5 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT8 = wxNewId();
const long TPedidoAdd::ID_TEXTCTRL6 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT9 = wxNewId();
const long TPedidoAdd::ID_TEXTCTRL7 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT10 = wxNewId();
const long TPedidoAdd::ID_TEXTCTRL8 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT11 = wxNewId();
const long TPedidoAdd::ID_TEXTCTRL9 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT12 = wxNewId();
const long TPedidoAdd::ID_TEXTCTRL10 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT13 = wxNewId();
const long TPedidoAdd::ID_TEXTCTRL11 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT14 = wxNewId();
const long TPedidoAdd::ID_CHECKBOX1 = wxNewId();
const long TPedidoAdd::ID_DATEPICKERCTRL1 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT15 = wxNewId();
const long TPedidoAdd::ID_CHECKBOX2 = wxNewId();
const long TPedidoAdd::ID_DATEPICKERCTRL2 = wxNewId();
const long TPedidoAdd::ID_STATICTEXT16 = wxNewId();
const long TPedidoAdd::ID_CHECKBOX3 = wxNewId();
const long TPedidoAdd::ID_DATEPICKERCTRL3 = wxNewId();
const long TPedidoAdd::ID_BUTTON1 = wxNewId();
const long TPedidoAdd::ID_BUTTON2 = wxNewId();
const long TPedidoAdd::ID_MESSAGEDIALOG1 = wxNewId();
//*)

const int TPedidoAdd::ID_FORMACTION_ADD = 1000;
const int TPedidoAdd::ID_FORMACTION_EDIT = 1001;

BEGIN_EVENT_TABLE(TPedidoAdd,wxDialog)
	//(*EventTable(TPedidoAdd)
	//*)
END_EVENT_TABLE()

TPedidoAdd::TPedidoAdd(int idPedido,int accionForm,wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(TPedidoAdd)
	wxBoxSizer* BoxSizer4;
	wxBoxSizer* BoxSizer6;
	wxBoxSizer* BoxSizer15;
	wxBoxSizer* BoxSizer5;
	wxBoxSizer* BoxSizer10;
	wxBoxSizer* BoxSizer7;
	wxBoxSizer* BoxSizer8;
	wxStaticBoxSizer* LayerDatosCliente;
	wxBoxSizer* BoxSizer13;
	wxStaticBoxSizer* LayerPedido;
	wxFlexGridSizer* LayerContenido;
	wxFlexGridSizer* LayerGlobal;
	wxBoxSizer* BoxSizer2;
	wxBoxSizer* BoxSizer11;
	wxBoxSizer* LayerSubBotones;
	wxBoxSizer* BoxSizer12;
	wxBoxSizer* BoxSizer14;
	wxStaticBoxSizer* LayerCliente;
	wxBoxSizer* BoxSizer1;
	wxBoxSizer* BoxSizer9;
	wxStaticBoxSizer* LayerProducto;
	wxBoxSizer* BoxSizer3;
	wxStaticBoxSizer* LayerDatosProducto;

	Create(parent, wxID_ANY, _("Agregar Pedido"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	LayerGlobal = new wxFlexGridSizer(3, 1, 0, 0);
	LayerPedido = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Pedido:"));
	StaticText17 = new wxStaticText(this, ID_STATICTEXT17, _("ID Pedido:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT17"));
	LayerPedido->Add(StaticText17, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxIDPedido = new wxTextCtrl(this, ID_TEXTCTRL12, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL12"));
	LayerPedido->Add(TextBoxIDPedido, 5, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerPedido, 1, wxALL|wxEXPAND, 5);
	LayerContenido = new wxFlexGridSizer(2, 2, 2, 0);
	LayerCliente = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Cliente:"));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Seleccione Cliente:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	LayerCliente->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboCliente = new wxChoice(this, ID_CHOICE1, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
	LayerCliente->Add(ComboCliente, 2, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerContenido->Add(LayerCliente, 1, wxALL, 5);
	LayerProducto = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Producto:"));
	StaticText7 = new wxStaticText(this, ID_STATICTEXT7, _("Seleccione Producto:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT7"));
	LayerProducto->Add(StaticText7, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	ComboProducto = new wxChoice(this, ID_CHOICE2, wxDefaultPosition, wxDefaultSize, 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
	LayerProducto->Add(ComboProducto, 2, wxALL|wxFIXED_MINSIZE, 5);
	LayerContenido->Add(LayerProducto, 1, wxALL, 5);
	LayerDatosCliente = new wxStaticBoxSizer(wxVERTICAL, this, _("Datos de Cliente:"));
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("ID Cliente:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	BoxSizer1->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxIDCliente = new wxTextCtrl(this, ID_TEXTCTRL1, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL1"));
	BoxSizer1->Add(TextBoxIDCliente, 3, wxALL, 5);
	LayerDatosCliente->Add(BoxSizer1, 1, wxALL|wxEXPAND, 5);
	BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Apellido:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	BoxSizer2->Add(StaticText3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxApellido = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	BoxSizer2->Add(TextBoxApellido, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerDatosCliente->Add(BoxSizer2, 1, wxALL|wxEXPAND, 5);
	BoxSizer3 = new wxBoxSizer(wxHORIZONTAL);
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Nombre:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT4"));
	BoxSizer3->Add(StaticText4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxNombre = new wxTextCtrl(this, ID_TEXTCTRL3, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL3"));
	BoxSizer3->Add(TextBoxNombre, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerDatosCliente->Add(BoxSizer3, 1, wxALL|wxEXPAND, 5);
	BoxSizer4 = new wxBoxSizer(wxHORIZONTAL);
	StaticText5 = new wxStaticText(this, ID_STATICTEXT5, _("Telefono:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT5"));
	BoxSizer4->Add(StaticText5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TexBoxTelefono = new wxTextCtrl(this, ID_TEXTCTRL4, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL4"));
	BoxSizer4->Add(TexBoxTelefono, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerDatosCliente->Add(BoxSizer4, 1, wxALL|wxEXPAND, 5);
	BoxSizer5 = new wxBoxSizer(wxHORIZONTAL);
	StaticText6 = new wxStaticText(this, ID_STATICTEXT6, _("Email:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT6"));
	BoxSizer5->Add(StaticText6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TexBoxEmail = new wxTextCtrl(this, ID_TEXTCTRL5, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY, wxDefaultValidator, _T("ID_TEXTCTRL5"));
	BoxSizer5->Add(TexBoxEmail, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerDatosCliente->Add(BoxSizer5, 1, wxALL|wxEXPAND, 5);
	BoxSizer12 = new wxBoxSizer(wxHORIZONTAL);
	LayerDatosCliente->Add(BoxSizer12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerContenido->Add(LayerDatosCliente, 1, wxALL|wxEXPAND|wxSHAPED, 5);
	LayerDatosProducto = new wxStaticBoxSizer(wxVERTICAL, this, _("Datos de Producto:"));
	BoxSizer6 = new wxBoxSizer(wxHORIZONTAL);
	StaticText8 = new wxStaticText(this, ID_STATICTEXT8, _("ID Producto:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT8"));
	BoxSizer6->Add(StaticText8, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxIDProducto = new wxTextCtrl(this, ID_TEXTCTRL6, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL6"));
	TextBoxIDProducto->Disable();
	BoxSizer6->Add(TextBoxIDProducto, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerDatosProducto->Add(BoxSizer6, 1, wxALL|wxEXPAND, 5);
	BoxSizer7 = new wxBoxSizer(wxHORIZONTAL);
	StaticText9 = new wxStaticText(this, ID_STATICTEXT9, _("Descripcion:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT9"));
	BoxSizer7->Add(StaticText9, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxDescripcion = new wxTextCtrl(this, ID_TEXTCTRL7, wxEmptyString, wxDefaultPosition, wxSize(233,58), wxTE_MULTILINE, wxDefaultValidator, _T("ID_TEXTCTRL7"));
	BoxSizer7->Add(TextBoxDescripcion, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerDatosProducto->Add(BoxSizer7, 2, wxALL|wxEXPAND, 5);
	BoxSizer8 = new wxBoxSizer(wxHORIZONTAL);
	StaticText10 = new wxStaticText(this, ID_STATICTEXT10, _("Precio USD:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT10"));
	BoxSizer8->Add(StaticText10, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxPrecioUSD = new wxTextCtrl(this, ID_TEXTCTRL8, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL8"));
	BoxSizer8->Add(TextBoxPrecioUSD, 3, wxALL, 5);
	LayerDatosProducto->Add(BoxSizer8, 1, wxALL|wxEXPAND, 5);
	BoxSizer9 = new wxBoxSizer(wxHORIZONTAL);
	StaticText11 = new wxStaticText(this, ID_STATICTEXT11, _("Valor Dolar:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT11"));
	BoxSizer9->Add(StaticText11, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxPrecioDolar = new wxTextCtrl(this, ID_TEXTCTRL9, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL9"));
	BoxSizer9->Add(TextBoxPrecioDolar, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerDatosProducto->Add(BoxSizer9, 1, wxALL|wxEXPAND, 5);
	BoxSizer10 = new wxBoxSizer(wxHORIZONTAL);
	StaticText12 = new wxStaticText(this, ID_STATICTEXT12, _("Precio ARG:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT12"));
	BoxSizer10->Add(StaticText12, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxPrecioARG = new wxTextCtrl(this, ID_TEXTCTRL10, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL10"));
	BoxSizer10->Add(TextBoxPrecioARG, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerDatosProducto->Add(BoxSizer10, 1, wxALL|wxEXPAND, 5);
	BoxSizer11 = new wxBoxSizer(wxHORIZONTAL);
	StaticText13 = new wxStaticText(this, ID_STATICTEXT13, _("Comision:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT13"));
	BoxSizer11->Add(StaticText13, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxComision = new wxTextCtrl(this, ID_TEXTCTRL11, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_RIGHT, wxDefaultValidator, _T("ID_TEXTCTRL11"));
	BoxSizer11->Add(TextBoxComision, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerDatosProducto->Add(BoxSizer11, 1, wxALL|wxEXPAND, 5);
	BoxSizer13 = new wxBoxSizer(wxHORIZONTAL);
	StaticText14 = new wxStaticText(this, ID_STATICTEXT14, _("Pedido:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT14"));
	BoxSizer13->Add(StaticText14, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckFechaPedido = new wxCheckBox(this, ID_CHECKBOX1, _("Activar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
	CheckFechaPedido->SetValue(false);
	BoxSizer13->Add(CheckFechaPedido, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxFechaPedido = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL1, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL1"));
	BoxSizer13->Add(TextBoxFechaPedido, 3, wxALL|wxALIGN_CENTER_VERTICAL, 5);
	LayerDatosProducto->Add(BoxSizer13, 1, wxALL|wxALIGN_LEFT|wxFIXED_MINSIZE, 5);
	BoxSizer14 = new wxBoxSizer(wxHORIZONTAL);
	StaticText15 = new wxStaticText(this, ID_STATICTEXT15, _("Compra:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT15"));
	BoxSizer14->Add(StaticText15, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckFechaCompra = new wxCheckBox(this, ID_CHECKBOX2, _("Activar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX2"));
	CheckFechaCompra->SetValue(false);
	BoxSizer14->Add(CheckFechaCompra, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxFechaCompra = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL2, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL2"));
	BoxSizer14->Add(TextBoxFechaCompra, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerDatosProducto->Add(BoxSizer14, 1, wxALL|wxALIGN_LEFT, 5);
	BoxSizer15 = new wxBoxSizer(wxHORIZONTAL);
	StaticText16 = new wxStaticText(this, ID_STATICTEXT16, _("Entrega:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT16"));
	BoxSizer15->Add(StaticText16, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	CheckFechaEntrega = new wxCheckBox(this, ID_CHECKBOX3, _("Activar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX3"));
	CheckFechaEntrega->SetValue(false);
	BoxSizer15->Add(CheckFechaEntrega, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxFechaEntrega = new wxDatePickerCtrl(this, ID_DATEPICKERCTRL3, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN|wxDP_SHOWCENTURY, wxDefaultValidator, _T("ID_DATEPICKERCTRL3"));
	BoxSizer15->Add(TextBoxFechaEntrega, 3, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerDatosProducto->Add(BoxSizer15, 1, wxALL|wxALIGN_LEFT, 5);
	LayerContenido->Add(LayerDatosProducto, 1, wxALL|wxEXPAND, 5);
	LayerGlobal->Add(LayerContenido, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
	LayerSubBotones = new wxBoxSizer(wxHORIZONTAL);
	BotonAceptar = new wxButton(this, ID_BUTTON1, _("Aceptar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
	LayerSubBotones->Add(BotonAceptar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BotonCancelar = new wxButton(this, ID_BUTTON2, _("Cancelar"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
	LayerSubBotones->Add(BotonCancelar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerSubBotones, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(LayerGlobal);
	DialogoError = new wxMessageDialog(this, wxEmptyString, _("Message"), wxOK|wxICON_ERROR, wxDefaultPosition);
	LayerGlobal->Fit(this);
	LayerGlobal->SetSizeHints(this);
	Center();

	Connect(ID_CHOICE1,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&TPedidoAdd::OnComboClienteSelect);
	Connect(ID_CHOICE2,wxEVT_COMMAND_CHOICE_SELECTED,(wxObjectEventFunction)&TPedidoAdd::OnComboProductoSelect);
	Connect(ID_TEXTCTRL9,wxEVT_COMMAND_TEXT_UPDATED,(wxObjectEventFunction)&TPedidoAdd::OnTextBoxPrecioDolarText);
	Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&TPedidoAdd::OnCheckFechaPedidoClick);
	Connect(ID_CHECKBOX2,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&TPedidoAdd::OnCheckFechaCompraClick);
	Connect(ID_CHECKBOX3,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&TPedidoAdd::OnCheckFechaEntregaClick);
	Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TPedidoAdd::OnBotonAceptarClick);
	Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TPedidoAdd::OnBotonCancelarClick);
	Connect(wxID_ANY,wxEVT_CLOSE_WINDOW,(wxObjectEventFunction)&TPedidoAdd::OnClose);
	//*)

	ID_ACTIONFORM_STATUS = accionForm;

    util = new TUtil();
	this->idPedido = idPedido;

	TextBoxIDPedido->SetValue(wxString::Format(_("%i"),idPedido) ) ;

	db = new wxSQLite3Database();

	//Cargar ComboBox de Clientes
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery(wxString::Format(_("%s"),"SELECT Apellido || ', ' || Nombre FROM cliente"));

    while (Res.NextRow())
    {
        ComboCliente->Append(wxString::Format(_("%s"),Res.GetAsString(0)));
    }
    Res.Finalize();

    //Carga ComboBox de Productos
    wxSQLite3ResultSet Res2 = db->ExecuteQuery(wxString::Format(_("%s"),"SELECT Desc, Descripcion, PrecioUSD, Comision FROM producto ORDER BY Descripcion"));
    while (Res2.NextRow())
    {
        ComboProducto->Append(wxString::Format(_("%s"),Res2.GetAsString(0)));
    }
    Res2.Finalize();

    wxSQLite3ResultSet conf = db->ExecuteQuery("SELECT * FROM setting");
    TextBoxPrecioDolar->SetValue(wxString::Format(_("%.2f"),conf.GetDouble(1)));
    valorDolar = conf.GetDouble(1);

    conf.Finalize();

    db->Close();

    TextBoxFechaPedido->Show(false);
    TextBoxFechaCompra->Show(false);
    TextBoxFechaEntrega->Show(false);

    if (ID_ACTIONFORM_STATUS == ID_FORMACTION_ADD){
        CheckFechaPedido->SetValue(true);
        TextBoxFechaPedido->Show(true);
    }

    if (ID_ACTIONFORM_STATUS == ID_FORMACTION_EDIT){
        SetTitle("Modificar Pedido");

        wxString testDBName = wxGetCwd() + wxT("/database.db");
        db->Open(testDBName);
        wxString SQLQuery = wxString::Format(_("SELECT * FROM pedido WHERE ID_Pedido = %i LIMIT 1"),idPedido);
        wxSQLite3ResultSet ResPedido = db->ExecuteQuery(SQLQuery);

        TextBoxIDCliente->SetValue(ResPedido.GetAsString(1));
        TextBoxIDProducto->SetValue(ResPedido.GetAsString(2));
        TextBoxPrecioUSD->SetValue(wxString::Format(_("%.2f"),ResPedido.GetDouble(3)));
        TextBoxPrecioARG->SetValue(wxString::Format(_("%.2f"),ResPedido.GetDouble(4)));
        TextBoxComision->SetValue(wxString::Format(_("%.2f"),ResPedido.GetDouble(5)));

        //cargar fechas
        cargarUnaFecha(CheckFechaPedido,TextBoxFechaPedido,ResPedido.GetInt(6));
        cargarUnaFecha(CheckFechaCompra,TextBoxFechaCompra,ResPedido.GetInt(7));
        cargarUnaFecha(CheckFechaEntrega,TextBoxFechaEntrega,ResPedido.GetInt(8));

        ResPedido.Finalize();

        SQLQuery = wxString::Format(_("SELECT *,Apellido || ', ' || Nombre FROM cliente WHERE ID_Cliente = %s LIMIT 1"),TextBoxIDCliente->GetValue());
        wxSQLite3ResultSet ResCliente = db->ExecuteQuery(SQLQuery);

        TextBoxApellido->SetValue(ResCliente.GetAsString(1));
        TextBoxNombre->SetValue(ResCliente.GetAsString(2));
        TexBoxTelefono->SetValue(ResCliente.GetAsString(3));
        TexBoxEmail->SetValue(ResCliente.GetAsString(4));
        ComboCliente->SetSelection(ComboCliente->FindString(ResCliente.GetAsString(5)));

        ResCliente.Finalize();

        SQLQuery = wxString::Format(_("SELECT * FROM producto WHERE ID_Producto = %s LIMIT 1"),TextBoxIDProducto->GetValue());
        wxSQLite3ResultSet ResProducto = db->ExecuteQuery(SQLQuery);

        TextBoxDescripcion->SetValue(ResProducto.GetAsString(2));
        ComboProducto->SetSelection(ComboProducto->FindString(ResProducto.GetAsString(1)));

        ResProducto.Finalize();
        db->Close();
    }
}

TPedidoAdd::~TPedidoAdd()
{
	//(*Destroy(TPedidoAdd)
	//*)
}

void TPedidoAdd::cargarUnaFecha(wxCheckBox* checkBox,wxDatePickerCtrl* TextBoxFecha,int fechaUnix){
    if (fechaUnix == 0) {
        checkBox->SetValue(false);
    }
    else{
        checkBox->SetValue(true);
        TextBoxFecha->Show(true);
        TextBoxFecha->SetValue(util->getFechaWX(fechaUnix));
    }
}

void TPedidoAdd::OnComboClienteSelect(wxCommandEvent& event)
{
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxString SQLQuery = wxString::Format(_("SELECT Apellido || ', ' || Nombre AS Name,ID_Cliente,Apellido,Nombre,Telefono,Email FROM cliente Where Name = '%s'"),event.GetString());
    wxSQLite3ResultSet Res = db->ExecuteQuery(SQLQuery);

    TextBoxIDCliente->SetValue(Res.GetAsString(1));
    TextBoxApellido->SetValue(Res.GetAsString(2));
    TextBoxNombre->SetValue(Res.GetAsString(3));
    TexBoxTelefono->SetValue(Res.GetAsString(4));
    TexBoxEmail->SetValue(Res.GetAsString(5));

    Res.Finalize();
    db->Close();
}

void TPedidoAdd::OnComboProductoSelect(wxCommandEvent& event)
{
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);

    wxSQLite3ResultSet conf = db->ExecuteQuery("SELECT * FROM setting");
    TextBoxPrecioDolar->SetValue(wxString::Format(_("%.2f"),conf.GetDouble(1)));
    valorDolar = conf.GetDouble(1);

    conf.Finalize();

    wxString SQLQuery = wxString::Format(_("SELECT * FROM producto WHERE Desc = '%s'"),event.GetString());
    wxSQLite3ResultSet Res = db->ExecuteQuery(SQLQuery);

    TextBoxIDProducto->SetValue(Res.GetAsString(0));
    TextBoxDescripcion->SetValue(Res.GetAsString(2));
    precioUSD = Res.GetDouble(3);
    TextBoxPrecioUSD->SetValue(wxString::Format(_("%.2f"),Res.GetDouble(3)));
    precioARG = Res.GetDouble(3) * valorDolar;
    TextBoxPrecioARG->SetValue(wxString::Format(_("%.2f"),precioARG));
    TextBoxComision->SetValue(wxString::Format(_("%.2f"),Res.GetDouble(4)));

    Res.Finalize();
    db->Close();
}

void TPedidoAdd::OnTextBoxPrecioDolarText(wxCommandEvent& event)
{
    double valorDolarDouble;
    wxString dolarString = event.GetString();
    if (dolarString.IsEmpty())
        return;

    if( dolarString.ToDouble(&valorDolarDouble) ){
        valorDolar = (float)valorDolarDouble;
    }
    else{
        DialogoError->SetMessage(wxString::Format(_("Error al convertir %s"),event.GetString()) ) ;
        DialogoError->ShowModal();
        TextBoxPrecioDolar->SetFocus();
        TextBoxPrecioDolar->SelectAll();
        return;
    }
    precioARG = precioUSD * valorDolar;
    TextBoxPrecioARG->SetValue(wxString::Format(_("%.2f"),precioARG));

}

void TPedidoAdd::OnCheckFechaPedidoClick(wxCommandEvent& event)
{
    TPedidoAdd::monstrarFecha(event, TextBoxFechaPedido);
}

void TPedidoAdd::monstrarFecha(wxCommandEvent event,wxDatePickerCtrl* TextBoxFecha){
    if (event.IsChecked()){
        TextBoxFecha->Show(true);
    }
    else {
        TextBoxFecha->Show(false);
    }
}

void TPedidoAdd::OnCheckFechaCompraClick(wxCommandEvent& event)
{
    TPedidoAdd::monstrarFecha(event, TextBoxFechaCompra);
}

void TPedidoAdd::OnCheckFechaEntregaClick(wxCommandEvent& event)
{
    TPedidoAdd::monstrarFecha(event, TextBoxFechaEntrega);
}

int TPedidoAdd::getFecha(wxCheckBox* checkBox,wxDatePickerCtrl* TextBoxFecha){
    if (checkBox->GetValue()){
        return util->getFechaUnix(TextBoxFecha->GetValue());
    }
    else{
        return 0;
    }
}

void TPedidoAdd::OnBotonAceptarClick(wxCommandEvent& event)
{
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);

    if (ID_ACTIONFORM_STATUS == ID_FORMACTION_ADD){
        wxString consulta = wxString::Format(_("INSERT INTO pedido (ID_Pedido,ID_Cliente,ID_Producto,PrecioUSD,PrecioARG,Comision,Fecha_Pedido,Fecha_Compra,Fecha_Entregado,Entregado) VALUES (%s,%s,%s,%s,%s,%s,%i,%i,%i,%s);"),
                                               TextBoxIDPedido->GetValue(),
                                               TextBoxIDCliente->GetValue(),
                                               TextBoxIDProducto->GetValue(),
                                               TextBoxPrecioUSD->GetValue(),
                                               TextBoxPrecioARG->GetValue(),
                                               TextBoxComision->GetValue(),
                                               TPedidoAdd::getFecha(CheckFechaPedido,TextBoxFechaPedido),
                                               TPedidoAdd::getFecha(CheckFechaCompra,TextBoxFechaCompra),
                                               TPedidoAdd::getFecha(CheckFechaEntrega,TextBoxFechaEntrega),
                                               "0");
        wxSQLite3ResultSet Res = db->ExecuteQuery(consulta);

        db->Close();

        this->EndModal(1);
    }
    if (ID_ACTIONFORM_STATUS == ID_FORMACTION_EDIT){
      wxString consulta = wxString::Format(_("UPDATE pedido SET ID_Cliente=%s,ID_Producto=%s,PrecioUSD=%s,PrecioARG=%s,Comision=%s,Fecha_Pedido=%i,Fecha_Compra=%i,Fecha_Entregado=%i,Entregado=%i WHERE ID_Pedido=%S"),
                                           TextBoxIDCliente->GetValue(),
                                           TextBoxIDProducto->GetValue(),
                                           TextBoxPrecioUSD->GetValue(),
                                           TextBoxPrecioARG->GetValue(),
                                           TextBoxComision->GetValue(),
                                           TPedidoAdd::getFecha(CheckFechaPedido,TextBoxFechaPedido),
                                           TPedidoAdd::getFecha(CheckFechaCompra,TextBoxFechaCompra),
                                           TPedidoAdd::getFecha(CheckFechaEntrega,TextBoxFechaEntrega),
                                           0,
                                           TextBoxIDPedido->GetValue());
        wxSQLite3ResultSet Res = db->ExecuteQuery(consulta);
        db->Close();
        this->EndModal(1);
    }
}

void TPedidoAdd::OnBotonCancelarClick(wxCommandEvent& event)
{
    this->EndModal(0);
}

void TPedidoAdd::OnClose(wxCloseEvent& event)
{
    this->EndModal(0);
}
