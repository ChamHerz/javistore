/***************************************************************
 * Name:      javistoreMain.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2017-11-04
 * Copyright:  ()
 * License:
 **************************************************************/

#include "javistoreMain.h"
#include <wx/msgdlg.h>
#include <wx/aboutdlg.h>
#include "TConfiguracion.h"
#include "TProducto.h"
#include "TSetting.h"
#include "TBaseDato.h"
#include "TPedido.h"

//(*InternalHeaders(javistoreFrame)
#include <wx/artprov.h>
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(javistoreFrame)
const long javistoreFrame::ID_MENUITEM1 = wxNewId();
const long javistoreFrame::idMenuQuit = wxNewId();
const long javistoreFrame::idMenuAbout = wxNewId();
const long javistoreFrame::ID_STATUSBAR1 = wxNewId();
const long javistoreFrame::ID_TOOLBAR1 = wxNewId();
//*)
const long javistoreFrame::idProducto = wxNewId();
const long javistoreFrame::idCliente = wxNewId();
const long javistoreFrame::idSetting = wxNewId();
const long javistoreFrame::idPedido = wxNewId();

BEGIN_EVENT_TABLE(javistoreFrame,wxFrame)
    //(*EventTable(javistoreFrame)
    //*)
END_EVENT_TABLE()

javistoreFrame::javistoreFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(javistoreFrame)
    wxMenuItem* MenuItem2;
    wxMenuItem* MenuItem1;
    wxMenu* Menu1;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;

    Create(parent, wxID_ANY, _("Sin título: Bloc de notas"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxSYSTEM_MENU|wxCLOSE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(773,484));
    Move(wxPoint(-1,-1));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxArtProvider::GetBitmap(wxART_MAKE_ART_ID_FROM_STR(_T("wxART_CDROM")),wxART_FRAME_ICON));
    	SetIcon(FrameIcon);
    }
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Abrir Dialogo\tAlt-F2"), _("Abre un Dialogo"), wxITEM_NORMAL);
    Menu1->Append(MenuItem3);
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Salir\tAlt-F4"), _("Salir de la Aplicacion"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&JaviStore"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("A&cerca De...\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("&Ayuda"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&javistoreFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&javistoreFrame::OnAbout);
    //*)
    ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER, _T("ID_TOOLBAR1"));
    ToolBarItem1 = ToolBar1->AddTool(idCliente, _("Cliente"), wxBitmap(wxImage(_T("img\\ico-client-48.png"))), wxNullBitmap, wxITEM_NORMAL, _("Cliente"), _("Cliente"));
    ToolBarItem2 = ToolBar1->AddTool(idProducto, _("Producto"), wxBitmap(wxImage(_T("img\\ico-product-48.png"))), wxNullBitmap, wxITEM_NORMAL, _("Producto"), _("Producto"));
    ToolBarItem3 = ToolBar1->AddTool(idSetting, _("Configuracion"), wxBitmap(wxImage(_T("img\\ico-setting-48.png"))), wxNullBitmap, wxITEM_NORMAL, _("Configuracion"), _("Configuracion"));
    ToolBarItem4 = ToolBar1->AddTool(idPedido, _("Pedido"), wxBitmap(wxImage(_T("img\\ico-pedidos-48.png"))), wxNullBitmap, wxITEM_NORMAL, _("Pedido"), _("Pedido"));

    ToolBar1->Realize();
    SetToolBar(ToolBar1);

    Connect(idCliente,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&javistoreFrame::OnCliente);
    Connect(idProducto,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&javistoreFrame::OnProducto);
    Connect(idSetting,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&javistoreFrame::OnSetting);
    Connect(idPedido,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&javistoreFrame::OnPedidos);

    ValorDolar = cargarValorDolarDataBase();
}

javistoreFrame::~javistoreFrame()
{
    //(*Destroy(javistoreFrame)
    //*)
}

void javistoreFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void javistoreFrame::setValorDolar(float unValorDolar){
    ValorDolar = unValorDolar;
}

void javistoreFrame::OnAbout(wxCommandEvent& event)
{
    wxAboutDialogInfo info;
    info.SetName(_("Javi Store"));
    info.SetVersion(_("1.0.1 Beta"));
    info.SetDescription(_("Aplicacion Desarrollada por ChamHerz."));
    info.SetCopyright(wxT("(C) 2017 ChamHerz <adrielchambers@gmail.com>"));
    wxAboutBox(info);
}

void javistoreFrame::OnCliente(wxCommandEvent& event)
{
    TConfiguracion* dlgConfiguracion;
    dlgConfiguracion = new TConfiguracion (this);

    dlgConfiguracion->ShowModal();
}

void javistoreFrame::OnProducto(wxCommandEvent& event)
{
    TProducto* dlgProducto;
    dlgProducto = new TProducto (ValorDolar,this);

    dlgProducto->ShowModal();
}

void javistoreFrame::OnSetting(wxCommandEvent& event)
{
    TSetting* dlgSetting;
    dlgSetting = new TSetting (this);

    dlgSetting->ShowModal();

    ValorDolar = cargarValorDolarDataBase();
}

float javistoreFrame::cargarValorDolarDataBase(){
    TBaseDato* tBaseDato = new TBaseDato();
    return tBaseDato->getValorDolarBaseDatos();
}

void javistoreFrame::OnPedidos(wxCommandEvent& event){
    TPedido* dlgPedidos = new TPedido(this);
    dlgPedidos->ShowModal();
}
