#include "TConfiguracion.h"
#include "TClienteAdd.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(TConfiguracion)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(TConfiguracion)
const long TConfiguracion::ID_GRID1 = wxNewId();
const long TConfiguracion::ID_BITMAPBUTTON1 = wxNewId();
const long TConfiguracion::ID_BITMAPBUTTON2 = wxNewId();
const long TConfiguracion::ID_BITMAPBUTTON3 = wxNewId();
const long TConfiguracion::ID_MESSAGEDIALOG1 = wxNewId();
const long TConfiguracion::ID_MESSAGEDIALOG2 = wxNewId();
//*)

BEGIN_EVENT_TABLE(TConfiguracion,wxDialog)
	//(*EventTable(TConfiguracion)
	//*)
END_EVENT_TABLE()

TConfiguracion::TConfiguracion(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(TConfiguracion)
	wxBoxSizer* BoxSizer1;
	wxFlexGridSizer* FlexGridSizer1;

	Create(parent, wxID_ANY, _("Clientes"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX, _T("wxID_ANY"));
	SetClientSize(wxSize(750,389));
	SetMinSize(wxSize(600,500));
	FlexGridSizer1 = new wxFlexGridSizer(3, 1, 0, 0);
	FlexGridSizer1->AddGrowableCol(0);
	FlexGridSizer1->AddGrowableRow(0);
	Grid1 = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER|wxTRANSPARENT_WINDOW, _T("ID_GRID1"));
	Grid1->CreateGrid(5,5);
	Grid1->EnableEditing(true);
	Grid1->EnableGridLines(true);
	Grid1->SetDefaultColSize(100, true);
	Grid1->SetColLabelValue(0, _("ID_Cliente"));
	Grid1->SetColLabelValue(1, _("Apellido"));
	Grid1->SetColLabelValue(2, _("Nombre"));
	Grid1->SetColLabelValue(3, _("Telefono"));
	Grid1->SetColLabelValue(4, _("Email"));
	Grid1->SetDefaultCellFont( Grid1->GetFont() );
	Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
	FlexGridSizer1->Add(Grid1, 1, wxALL|wxEXPAND, 5);
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	BotonAgregarCliente = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("C:\\Proyects\\javistore\\bin\\Release\\img\\ico-user-add-button.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	BoxSizer1->Add(BotonAgregarCliente, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BotonBorrarCliente = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("C:\\Proyects\\javistore\\bin\\Release\\img\\ico-user-delete.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
	BoxSizer1->Add(BotonBorrarCliente, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BotonEditarCliente = new wxBitmapButton(this, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("C:\\Proyects\\javistore\\bin\\Release\\img\\ico-user-edit-button.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
	BoxSizer1->Add(BotonEditarCliente, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FlexGridSizer1->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FlexGridSizer1);
	DialogoBorrado = new wxMessageDialog(this, wxEmptyString, _("Message"), wxYES_NO|wxICON_ERROR, wxDefaultPosition);
	DialogoError = new wxMessageDialog(this, wxEmptyString, _("Message"), wxOK|wxICON_ERROR, wxDefaultPosition);
	SetSizer(FlexGridSizer1);
	Layout();
	Center();

	Connect(ID_GRID1,wxEVT_GRID_LABEL_LEFT_DCLICK,(wxObjectEventFunction)&TConfiguracion::OnGrid1LabelLeftDClick);
	Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TConfiguracion::OnBotonAgregarClienteClick);
	Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TConfiguracion::OnBotonBorrarClienteClick);
	Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TConfiguracion::OnBotonEditarClienteClick);
	//*)
	db = new wxSQLite3Database();

	Grid1->SetRowLabelSize(50);
	Grid1->SetColSize(0,80);
	Grid1->SetColSize(1,150);
	Grid1->SetColSize(2,150);
	Grid1->SetColSize(3,100);
	Grid1->SetColSize(4,200);

	wxGridCellAttr* EstiloColumnaIzquierda = new wxGridCellAttr();

    EstiloColumnaIzquierda->SetAlignment(wxALIGN_CENTRE,wxALIGN_CENTRE);

	Grid1->SetColAttr(0,EstiloColumnaIzquierda);
	Grid1->SetColAttr(3,EstiloColumnaIzquierda->Clone());

    ClienteSelectAll();
}

TConfiguracion::~TConfiguracion()
{
	//(*Destroy(TConfiguracion)
	//*)
}

void TConfiguracion::ClienteSelectAll(){
    if (Grid1->GetNumberRows() > 0) Grid1->DeleteRows(0,Grid1->GetNumberRows());
    this->ClienteSelectAll_Carga();
}

void TConfiguracion::ClienteSelectAll_soloCarga(){
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery("SELECT * FROM cliente");

    int count = 0;
    while (Res.NextRow())
    {
        Grid1->SetCellValue(count,0,wxString::Format(_("%i"),Res.GetInt(0)) ) ;
        Grid1->SetCellValue(count,1,wxString::Format(_("%s"),Res.GetAsString(1)) ) ;
        Grid1->SetCellValue(count,2,wxString::Format(_("%s"),Res.GetAsString(2)) ) ;
        Grid1->SetCellValue(count,3,wxString::Format(_("%s"),Res.GetAsString(3)) ) ;
        Grid1->SetCellValue(count,4,wxString::Format(_("%s"),Res.GetAsString(4)) ) ;
        count++;
    }
    Res.Finalize();
    db->Close();
}

void TConfiguracion::ClienteSelectAll_Carga(){
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery("SELECT * FROM cliente");

    int count = 0;
    while (Res.NextRow())
    {
        Grid1->AppendRows(1);
        Grid1->SetCellValue(count,0,wxString::Format(_("%i"),Res.GetInt(0)) ) ;
        Grid1->SetCellValue(count,1,wxString::Format(_("%s"),Res.GetAsString(1)) ) ;
        Grid1->SetCellValue(count,2,wxString::Format(_("%s"),Res.GetAsString(2)) ) ;
        Grid1->SetCellValue(count,3,wxString::Format(_("%s"),Res.GetAsString(3)) ) ;
        Grid1->SetCellValue(count,4,wxString::Format(_("%s"),Res.GetAsString(4)) ) ;
        count++;
    }
    Res.Finalize();
    db->Close();
}

void TConfiguracion::OnBotonAgregarClienteClick(wxCommandEvent& event)
{
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery("SELECT max(ID_Cliente) FROM cliente");

    int idCliente = Res.GetInt(0);

    Res.Finalize();
    db->Close();

    TClienteAdd* tClienteAdd = new TClienteAdd(idCliente + 1,TClienteAdd::ID_FORMACTION_ADD, this);
    int resultado = tClienteAdd->ShowModal();
    if (resultado){
        ClienteSelectAll();
    }
}

void TConfiguracion::OnBotonBorrarClienteClick(wxCommandEvent& event)
{
    wxArrayInt rowsSelected = Grid1->GetSelectedRows();
    if (rowsSelected.Count() == 0){
        wxMessageBox("No seleccion nada para borrar");
        return;
    }

    int fila = rowsSelected[0];
    wxString idCliente = Grid1->GetCellValue(fila,0);
    wxString apellido = Grid1->GetCellValue(fila,1);
    wxString nombre = Grid1->GetCellValue(fila,2);

    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxString SQLQuery = wxString::Format(_("SELECT ID_Pedido FROM pedido WHERE ID_Cliente = %s LIMIT 1;"),idCliente);
    wxSQLite3ResultSet ResCliente = db->ExecuteQuery(SQLQuery);

    if (ResCliente.Eof() == false){
        DialogoError->SetMessage(wxString::Format(_("No se puede borrar %s, %s con Id %s, tiene Pedidos"),apellido,nombre,idCliente));
        DialogoError->ShowModal();
        return;
    }

    ResCliente.Finalize();
    db->Close();

    DialogoBorrado->SetMessage(wxString::Format(_("Esta seguro de borrar %s, %s con Id %s"),apellido,nombre,idCliente));

    if (DialogoBorrado->ShowModal() == wxID_YES){
        wxString testDBName = wxGetCwd() + wxT("/database.db");
        db->Open(testDBName);
        SQLQuery = wxString::Format(_("DELETE FROM cliente WHERE ID_Cliente=%s;"),idCliente);
        wxSQLite3ResultSet Res = db->ExecuteQuery(SQLQuery);

        Res.Finalize();
        db->Close();

        ClienteSelectAll();
    }
}

void TConfiguracion::OnBotonEditarClienteClick(wxCommandEvent& event)
{
    wxArrayInt rowsSelected = Grid1->GetSelectedRows();
    if (rowsSelected.Count() == 0){
        wxMessageBox("No seleccion nada para editar");
        return;
    }

    int fila = rowsSelected[0];
    wxString Cliente_ID = Grid1->GetCellValue(fila,0);
    int idCliente = wxAtoi(Cliente_ID);

    TClienteAdd* tClienteAdd = new TClienteAdd(idCliente,TClienteAdd::ID_FORMACTION_EDIT, this);
    int resultado = tClienteAdd->ShowModal();
    if (resultado){
        Grid1->ClearGrid();
        ClienteSelectAll_soloCarga();
    }
}

void TConfiguracion::OnGrid1LabelLeftDClick(wxGridEvent& event)
{
    TConfiguracion::OnBotonEditarClienteClick(event);
}
