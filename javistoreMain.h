/***************************************************************
 * Name:      javistoreMain.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2017-11-04
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef JAVISTOREMAIN_H
#define JAVISTOREMAIN_H

//(*Headers(javistoreFrame)
#include <wx/menu.h>
#include <wx/toolbar.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class javistoreFrame: public wxFrame
{
    public:

        javistoreFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~javistoreFrame();
        void setValorDolar(float unValorDolar);

    private:
        //MIS PROPIEDADES
        float ValorDolar;
        float cargarValorDolarDataBase();

        //(*Handlers(javistoreFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnDialog(wxCommandEvent& event);
        void OnCliente(wxCommandEvent& event);
        //*)
        void OnProducto(wxCommandEvent& event);
        void OnSetting(wxCommandEvent& event);
        void OnPedidos(wxCommandEvent& event);

        //(*Identifiers(javistoreFrame)
        static const long ID_MENUITEM1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TOOLBAR1;
        //*)

        static const long idCliente;
        static const long idProducto;
        static const long idSetting;
        static const long idPedido;

        //(*Declarations(javistoreFrame)
        wxToolBar* ToolBar1;
        wxMenuItem* MenuItem3;
        wxStatusBar* StatusBar1;
        //*)

        wxToolBarToolBase* ToolBarItem1;
        wxToolBarToolBase* ToolBarItem2;
        wxToolBarToolBase* ToolBarItem3;
        wxToolBarToolBase* ToolBarItem4;

        DECLARE_EVENT_TABLE()
};

#endif // JAVISTOREMAIN_H
