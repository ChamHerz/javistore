#include "TProducto.h"
#include <wx/msgdlg.h>
#include "TProductoAdd.h"

//(*InternalHeaders(TProducto)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(TProducto)
const long TProducto::ID_GRID1 = wxNewId();
const long TProducto::ID_STATICTEXT1 = wxNewId();
const long TProducto::ID_TEXTCTRL2 = wxNewId();
const long TProducto::ID_BITMAPBUTTON1 = wxNewId();
const long TProducto::ID_BITMAPBUTTON3 = wxNewId();
const long TProducto::ID_BITMAPBUTTON2 = wxNewId();
const long TProducto::ID_MESSAGEDIALOG1 = wxNewId();
const long TProducto::ID_MESSAGEDIALOG2 = wxNewId();
//*)

const int TProducto::ID_CARGAR_ADD = 100;
const int TProducto::ID_CARGAR_EDIT = 101;

BEGIN_EVENT_TABLE(TProducto,wxDialog)
	//(*EventTable(TProducto)
	//*)
END_EVENT_TABLE()

TProducto::TProducto(float unValorDolar,wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
    valorDolar = unValorDolar;
	//(*Initialize(TProducto)
	wxStaticBoxSizer* LayerMedio;
	wxFlexGridSizer* FGS1;
	wxBoxSizer* LayerBotones;

	Create(parent, id, _("Productos"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX, _T("id"));
	SetClientSize(wxSize(750,311));
	Move(wxDefaultPosition);
	SetMinSize(wxSize(750,-1));
	FGS1 = new wxFlexGridSizer(3, 1, 0, 0);
	FGS1->AddGrowableCol(0);
	FGS1->AddGrowableRow(0);
	GridProductos = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER|wxTRANSPARENT_WINDOW, _T("ID_GRID1"));
	GridProductos->CreateGrid(0,6);
	GridProductos->EnableEditing(true);
	GridProductos->EnableGridLines(true);
	GridProductos->SetDefaultColSize(100, true);
	GridProductos->SetColLabelValue(0, _("ID_Producto"));
	GridProductos->SetColLabelValue(1, _("Desc"));
	GridProductos->SetColLabelValue(2, _("Descripcion"));
	GridProductos->SetColLabelValue(3, _("Precio USD"));
	GridProductos->SetColLabelValue(4, _("Precio ARG"));
	GridProductos->SetColLabelValue(5, _("Comision"));
	GridProductos->SetDefaultCellFont( GridProductos->GetFont() );
	GridProductos->SetDefaultCellTextColour( GridProductos->GetForegroundColour() );
	FGS1->Add(GridProductos, 1, wxALL|wxEXPAND, 5);
	LayerMedio = new wxStaticBoxSizer(wxHORIZONTAL, this, _("Configuracion Actual:"));
	TextDolar = new wxStaticText(this, ID_STATICTEXT1, _("Precio Dolar:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	LayerMedio->Add(TextDolar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	TextBoxDolar = new wxTextCtrl(this, ID_TEXTCTRL2, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
	TextBoxDolar->Disable();
	LayerMedio->Add(TextBoxDolar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FGS1->Add(LayerMedio, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5);
	LayerBotones = new wxBoxSizer(wxHORIZONTAL);
	BotonAgregar = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("C:\\Proyects\\javistore\\img\\ico-product-add.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	LayerBotones->Add(BotonAgregar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BotonEliminar = new wxBitmapButton(this, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("C:\\proyects\\javistore\\img\\ico-product-delete.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
	LayerBotones->Add(BotonEliminar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BotonEditar = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("C:\\proyects\\javistore\\img\\ico-product-edit.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
	LayerBotones->Add(BotonEditar, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FGS1->Add(LayerBotones, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FGS1);
	DialogoBorrado = new wxMessageDialog(this, wxEmptyString, _("Message"), wxYES_NO|wxICON_ERROR, wxDefaultPosition);
	DialogoError = new wxMessageDialog(this, wxEmptyString, _("Message"), wxOK|wxICON_ERROR, wxDefaultPosition);
	SetSizer(FGS1);
	Layout();
	Center();

	Connect(ID_GRID1,wxEVT_GRID_LABEL_LEFT_DCLICK,(wxObjectEventFunction)&TProducto::OnGridProductosLabelLeftDClick);
	GridProductos->Connect(wxEVT_SIZE,(wxObjectEventFunction)&TProducto::OnGridProductosResize,0,this);
	Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TProducto::OnBotonAgregarClick);
	Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TProducto::OnBotonEliminarClick);
	Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TProducto::OnBotonEditarClick);
	//*)

	db = new wxSQLite3Database();

    GridProductos->SetRowLabelSize(50);
	GridProductos->SetColSize(0,100);
	GridProductos->SetColSize(1,120);
	GridProductos->SetColSize(2,370);
	GridProductos->SetColSize(3,100);
	GridProductos->SetColSize(4,100);
	GridProductos->SetColSize(5,100);

	wxGridCellAttr* EstiloColumnaCentrada = new wxGridCellAttr();
	wxGridCellAttr* EstiloColumnaDerecha = new wxGridCellAttr();

    EstiloColumnaCentrada->SetAlignment(wxALIGN_CENTRE,wxALIGN_CENTRE);
    EstiloColumnaDerecha->SetAlignment(wxALIGN_RIGHT,wxALIGN_CENTRE);

    GridProductos->SetColAttr(0,EstiloColumnaCentrada);
    GridProductos->SetColAttr(3,EstiloColumnaDerecha);
    GridProductos->SetColAttr(4,EstiloColumnaDerecha->Clone());
    GridProductos->SetColAttr(5,EstiloColumnaDerecha->Clone());

	ProductoSelectAll(ID_CARGAR_ADD);

	wxString precioDolar = wxString::Format(_("%.2f"),valorDolar);
	TextBoxDolar->SetLabel(precioDolar);
}

TProducto::~TProducto()
{
	//(*Destroy(TProducto)
	//*)
}

void TProducto::ProductoSelectAll(int ACCION){
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery(wxString::Format(_("%s"),"SELECT * FROM producto"));

    if (ACCION == ID_CARGAR_ADD) {
        if (GridProductos->GetNumberRows() > 0) GridProductos->DeleteRows(0,GridProductos->GetNumberRows());
    }
    int count = 0;

    float precioFinal;
    while (Res.NextRow())
    {
        if (ACCION == ID_CARGAR_ADD) {
            GridProductos->AppendRows(1);
        }
        GridProductos->SetCellValue(count,0,wxString::Format(_("%i"),Res.GetInt(0)) ) ;
        GridProductos->SetCellValue(count,1,wxString::Format(_("%s"),Res.GetAsString(1)) ) ;
        GridProductos->SetCellValue(count,2,wxString::Format(_("%s"),Res.GetAsString(2)) ) ;
        GridProductos->SetCellValue(count,3,wxString::Format(_("%.2f"),Res.GetDouble(3)) ) ;
        precioFinal = Res.GetDouble(3) * valorDolar;
        GridProductos->SetCellValue(count,4,wxString::Format(_("%.2f"),precioFinal)) ;
        GridProductos->SetCellValue(count,5,wxString::Format(_("%.2f"),Res.GetDouble(4)) ) ;
        count++;
    }
    Res.Finalize();
    db->Close();
}

void TProducto::setValorDolar(float unValorDolar){
    valorDolar = unValorDolar;
}

void TProducto::OnGridProductosResize(wxSizeEvent& event)
{
    GridProductos->SetColSize(2,event.GetSize().GetWidth() - 580);
    GridProductos->ForceRefresh();
}

void TProducto::OnBotonAgregarClick(wxCommandEvent& event)
{
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery("SELECT max(ID_Producto) FROM producto");

    int idProducto = Res.GetInt(0);

    Res.Finalize();
    db->Close();

    TProductoAdd* tProductoAdd = new TProductoAdd(idProducto + 1,TProductoAdd::ID_FORMACTION_ADD, this);
    int resultado = tProductoAdd->ShowModal();
    if (resultado){
        ProductoSelectAll(ID_CARGAR_ADD);
    }
}

void TProducto::OnBotonEditarClick(wxCommandEvent& event)
{
    wxArrayInt rowsSelected = GridProductos->GetSelectedRows();
    if (rowsSelected.Count() == 0){
        wxMessageBox("No seleccion nada para editar");
        return;
    }

    int fila = rowsSelected[0];
    wxString Producto_ID = GridProductos->GetCellValue(fila,0);
    int idProducto = wxAtoi(Producto_ID);

    TProductoAdd* tProducAdd = new TProductoAdd(idProducto,TProductoAdd::ID_FORMACTION_EDIT, this);
    int resultado = tProducAdd->ShowModal();
    if (resultado){
        GridProductos->ClearGrid();
        ProductoSelectAll(ID_CARGAR_EDIT);
    }
}

void TProducto::OnGridProductosLabelLeftDClick(wxGridEvent& event)
{
    TProducto::OnBotonEditarClick(event);
}

void TProducto::OnBotonEliminarClick(wxCommandEvent& event)
{
    wxArrayInt rowsSelected = GridProductos->GetSelectedRows();
    if (rowsSelected.Count() == 0){
        wxMessageBox("No seleccion nada para borrar");
        return;
    }

    int fila = rowsSelected[0];
    wxString idProducto = GridProductos->GetCellValue(fila,0);
    wxString desc = GridProductos->GetCellValue(fila,1);

    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxString SQLQuery = wxString::Format(_("SELECT ID_Producto FROM pedido WHERE ID_Producto = %s LIMIT 1;"),idProducto);
    wxSQLite3ResultSet ResProducto = db->ExecuteQuery(SQLQuery);

    if (ResProducto.Eof() == false){
        DialogoError->SetMessage(wxString::Format(_("No se puede borrar %s, con Id %s, tiene Pedidos"),desc,idProducto));
        DialogoError->ShowModal();
        return;
    }

    ResProducto.Finalize();
    db->Close();

    DialogoBorrado->SetMessage(wxString::Format(_("Esta seguro de borrar %s, con Id %s"),desc,idProducto));

    if (DialogoBorrado->ShowModal() == wxID_YES){
        wxString testDBName = wxGetCwd() + wxT("/database.db");
        db->Open(testDBName);
        SQLQuery = wxString::Format(_("DELETE FROM producto WHERE ID_Producto = %s;"),idProducto);
        wxSQLite3ResultSet Res = db->ExecuteQuery(SQLQuery);

        Res.Finalize();
        db->Close();

        ProductoSelectAll(ID_CARGAR_ADD);
    }
}
