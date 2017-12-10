#ifndef TPEDIDO_H
#define TPEDIDO_H

//(*Headers(TPedido)
#include <wx/sizer.h>
#include <wx/grid.h>
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
//*)

#include "wx/wxsqlite3.h"
#include "TUtil.h"

class TPedido: public wxDialog
{
	public:

		TPedido(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~TPedido();

		//(*Declarations(TPedido)
		wxGrid* GridPedidos;
		wxBitmapButton* BotonAgregarPedido;
		wxBitmapButton* BotonModificarPedido;
		//*)

	protected:

		//(*Identifiers(TPedido)
		static const long ID_GRID1;
		static const long ID_BITMAPBUTTON1;
		static const long ID_BITMAPBUTTON2;
		//*)

	private:

		//(*Handlers(TPedido)
		void OnBotonAgregarPedidoClick(wxCommandEvent& event);
		void OnBotonModificarPedidoClick(wxCommandEvent& event);
		void OnGridPedidosLabelLeftDClick(wxGridEvent& event);
		//*)

		static const int ID_CARGAR_ADD;
		static const int ID_CARGAR_EDIT;

		wxSQLite3Database* db;
		TUtil* util;

		void PepidoSelectAll(int ACCION);

		DECLARE_EVENT_TABLE()
};

#endif
