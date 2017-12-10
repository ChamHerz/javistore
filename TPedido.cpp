#include "TPedido.h"
#include "TPedidoAdd.h"

//(*InternalHeaders(TPedido)
#include <wx/bitmap.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//(*IdInit(TPedido)
const long TPedido::ID_GRID1 = wxNewId();
const long TPedido::ID_BITMAPBUTTON1 = wxNewId();
const long TPedido::ID_BITMAPBUTTON2 = wxNewId();
//*)

const int TPedido::ID_CARGAR_ADD = 100;
const int TPedido::ID_CARGAR_EDIT = 101;

BEGIN_EVENT_TABLE(TPedido,wxDialog)
	//(*EventTable(TPedido)
	//*)
END_EVENT_TABLE()

TPedido::TPedido(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(TPedido)
	wxFlexGridSizer* LayerGlobal;
	wxBoxSizer* LayerBottom;

	Create(parent, id, _("Pedidos"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX, _T("id"));
	SetClientSize(wxSize(1300,600));
	Move(wxDefaultPosition);
	SetMinSize(wxSize(800,600));
	LayerGlobal = new wxFlexGridSizer(3, 1, 0, 0);
	LayerGlobal->AddGrowableCol(0);
	LayerGlobal->AddGrowableRow(0);
	GridPedidos = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, 0, _T("ID_GRID1"));
	GridPedidos->CreateGrid(0,11);
	GridPedidos->EnableEditing(true);
	GridPedidos->EnableGridLines(true);
	GridPedidos->SetColLabelValue(0, _("ID"));
	GridPedidos->SetColLabelValue(1, _("Apellido"));
	GridPedidos->SetColLabelValue(2, _("Nombre"));
	GridPedidos->SetColLabelValue(3, _("Descripcion"));
	GridPedidos->SetColLabelValue(4, _("PrecioUSD"));
	GridPedidos->SetColLabelValue(5, _("PrecioARG"));
	GridPedidos->SetColLabelValue(6, _("Comision"));
	GridPedidos->SetColLabelValue(7, _("Fe Pedido"));
	GridPedidos->SetColLabelValue(8, _("Fe Compra"));
	GridPedidos->SetColLabelValue(9, _("Fe Entregado"));
	GridPedidos->SetColLabelValue(10, _("Entregado"));
	GridPedidos->SetDefaultCellFont( GridPedidos->GetFont() );
	GridPedidos->SetDefaultCellTextColour( GridPedidos->GetForegroundColour() );
	LayerGlobal->Add(GridPedidos, 1, wxALL|wxEXPAND, 5);
	LayerBottom = new wxBoxSizer(wxHORIZONTAL);
	BotonAgregarPedido = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("C:\\Proyects\\javistore\\bin\\Release\\img\\ico-pedidos-add-boton.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	LayerBottom->Add(BotonAgregarPedido, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	BotonModificarPedido = new wxBitmapButton(this, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("C:\\Proyects\\javistore\\img\\ico-pedido-edit-button.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
	LayerBottom->Add(BotonModificarPedido, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	LayerGlobal->Add(LayerBottom, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(LayerGlobal);
	SetSizer(LayerGlobal);
	Layout();
	Center();

	Connect(ID_GRID1,wxEVT_GRID_LABEL_LEFT_DCLICK,(wxObjectEventFunction)&TPedido::OnGridPedidosLabelLeftDClick);
	Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TPedido::OnBotonAgregarPedidoClick);
	Connect(ID_BITMAPBUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&TPedido::OnBotonModificarPedidoClick);
	//*)

	util = new TUtil();
	db = new wxSQLite3Database();

	GridPedidos->SetRowLabelSize(50);
    GridPedidos->SetColSize(0,50);
	GridPedidos->SetColSize(1,100);
	GridPedidos->SetColSize(2,100);
	GridPedidos->SetColSize(3,300);
	GridPedidos->SetColSize(4,80);
	GridPedidos->SetColSize(5,80);
	GridPedidos->SetColSize(6,80);
	GridPedidos->SetColSize(7,100);
	GridPedidos->SetColSize(8,100);
	GridPedidos->SetColSize(9,100);

	wxGridCellAttr* EstiloColumnaCentrada = new wxGridCellAttr();
	wxGridCellAttr* EstiloColumnaDerecha = new wxGridCellAttr();

    EstiloColumnaCentrada->SetAlignment(wxALIGN_CENTRE,wxALIGN_CENTRE);
    EstiloColumnaDerecha->SetAlignment(wxALIGN_RIGHT,wxALIGN_CENTRE);

    GridPedidos->SetColAttr(0,EstiloColumnaCentrada);
    GridPedidos->SetColAttr(4,EstiloColumnaDerecha);
    GridPedidos->SetColAttr(5,EstiloColumnaDerecha->Clone());
    GridPedidos->SetColAttr(6,EstiloColumnaDerecha->Clone());
    GridPedidos->SetColAttr(7,EstiloColumnaCentrada->Clone());
    GridPedidos->SetColAttr(8,EstiloColumnaCentrada->Clone());
    GridPedidos->SetColAttr(9,EstiloColumnaCentrada->Clone());

	this->PepidoSelectAll(ID_CARGAR_ADD);
}

TPedido::~TPedido()
{
	//(*Destroy(TPedido)
	//*)
}

void TPedido::PepidoSelectAll(int ACCION){
wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxString SQLQuery = wxString::Format(_("%s%s%s%s"),"SELECT p.ID_Pedido,c.Apellido,c.Nombre,pr.Descripcion,p.PrecioUSD,p.PrecioARG,",
                                                       "p.Comision,p.Fecha_Pedido,p.Fecha_Compra,p.Fecha_Entregado,p.Entregado ",
                                                       "FROM	pedido p INNER JOIN cliente c ON p.ID_Cliente = c.ID_Cliente ",
                                                       "INNER JOIN producto pr ON p.ID_Producto = pr.ID_Producto");

    wxSQLite3ResultSet Res = db->ExecuteQuery(SQLQuery);

    if (ACCION == ID_CARGAR_ADD) {
        if (GridPedidos->GetNumberRows() > 0) GridPedidos->DeleteRows(0,GridPedidos->GetNumberRows());
    }

    int count = 0;

    while (Res.NextRow())
    {
        if (ACCION == ID_CARGAR_ADD) {
            GridPedidos->AppendRows(1);
        }
        GridPedidos->SetCellValue(count,0,wxString::Format(_("%i"),Res.GetInt(0)) ) ;
        GridPedidos->SetCellValue(count,1,wxString::Format(_("%s"),Res.GetAsString(1)) ) ;
        GridPedidos->SetCellValue(count,2,wxString::Format(_("%s"),Res.GetAsString(2)) ) ;
        GridPedidos->SetCellValue(count,3,wxString::Format(_("%s"),Res.GetAsString(3)) ) ;
        GridPedidos->SetCellValue(count,4,wxString::Format(_("%s"),Res.GetAsString(4)) ) ;
        GridPedidos->SetCellValue(count,5,wxString::Format(_("%s"),Res.GetAsString(5)) ) ;
        GridPedidos->SetCellValue(count,6,wxString::Format(_("%s"),Res.GetAsString(6)) ) ;
        GridPedidos->SetCellValue(count,7,wxString::Format(_("%s"),util->getFecha(Res.GetInt(7)))) ;
        GridPedidos->SetCellValue(count,8,wxString::Format(_("%s"),util->getFecha(Res.GetInt(8)))) ;
        GridPedidos->SetCellValue(count,9,wxString::Format(_("%s"),util->getFecha(Res.GetInt(9)))) ;
        GridPedidos->SetCellValue(count,10,wxString::Format(_("%s"),Res.GetAsString(10)) ) ;
        count++;

    }
    Res.Finalize();
    db->Close();
}

void TPedido::OnBotonAgregarPedidoClick(wxCommandEvent& event)
{
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery("SELECT max(ID_Pedido) FROM pedido");

    int idPedido = Res.GetInt(0);

    Res.Finalize();
    db->Close();

    TPedidoAdd* dlgPedidoAdd = new TPedidoAdd(idPedido + 1,TPedidoAdd::ID_FORMACTION_ADD,this);
//    TClienteAdd* tClienteAdd = new TClienteAdd(idCliente + 1,TClienteAdd::ID_FORMACTION_ADD, this);
    int resultado = dlgPedidoAdd->ShowModal();
    if (resultado){
        PepidoSelectAll(ID_CARGAR_ADD);
    }
}

void TPedido::OnBotonModificarPedidoClick(wxCommandEvent& event)
{
    wxArrayInt rowsSelected = GridPedidos->GetSelectedRows();
    if (rowsSelected.Count() == 0){
        wxMessageBox("No seleccion nada para editar");
        return;
    }

    int fila = rowsSelected[0];
    wxString Pedido_ID = GridPedidos->GetCellValue(fila,0);
    int idPedido = wxAtoi(Pedido_ID);

    TPedidoAdd* tPedidoAdd = new TPedidoAdd(idPedido,TPedidoAdd::ID_FORMACTION_EDIT, this);
    int resultado = tPedidoAdd->ShowModal();
    if (resultado){
        GridPedidos->ClearGrid();
        PepidoSelectAll(ID_CARGAR_EDIT);
    }
}

void TPedido::OnGridPedidosLabelLeftDClick(wxGridEvent& event)
{
    TPedido::OnBotonModificarPedidoClick(event);
}
