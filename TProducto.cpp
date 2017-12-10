#include "TProducto.h"
#include <wx/msgdlg.h>

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
//*)

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
	wxBoxSizer* BoxSizer1;

	Create(parent, id, _("Productos"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxRESIZE_BORDER|wxCLOSE_BOX|wxMAXIMIZE_BOX, _T("id"));
	SetClientSize(wxSize(750,311));
	Move(wxDefaultPosition);
	SetMinSize(wxSize(750,-1));
	FGS1 = new wxFlexGridSizer(3, 1, 0, 0);
	FGS1->AddGrowableCol(0);
	FGS1->AddGrowableRow(0);
	GridProductos = new wxGrid(this, ID_GRID1, wxDefaultPosition, wxDefaultSize, wxDOUBLE_BORDER|wxTRANSPARENT_WINDOW, _T("ID_GRID1"));
	GridProductos->CreateGrid(5,6);
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
	BoxSizer1 = new wxBoxSizer(wxHORIZONTAL);
	BitmapButton1 = new wxBitmapButton(this, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("C:\\Proyects\\javistore\\img\\ico-product-add.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
	BoxSizer1->Add(BitmapButton1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	FGS1->Add(BoxSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
	SetSizer(FGS1);
	SetSizer(FGS1);
	Layout();
	Center();

	GridProductos->Connect(wxEVT_SIZE,(wxObjectEventFunction)&TProducto::OnGridProductosResize,0,this);
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

	ClienteSelectAll();

	wxString precioDolar = wxString::Format(_("%.2f"),valorDolar);
	TextBoxDolar->SetLabel(precioDolar);
}

TProducto::~TProducto()
{
	//(*Destroy(TProducto)
	//*)
}

void TProducto::ClienteSelectAll(){
    wxString testDBName = wxGetCwd() + wxT("/database.db");
    db->Open(testDBName);
    wxSQLite3ResultSet Res = db->ExecuteQuery(wxString::Format(_("%s"),"SELECT * FROM producto"));
    GridProductos->ClearGrid();
    int count = 0;
    float precioFinal;
    while (Res.NextRow())
    {
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
