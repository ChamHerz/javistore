#ifndef TPRODUCTO_H
#define TPRODUCTO_H

//(*Headers(TProducto)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/msgdlg.h>
#include <wx/grid.h>
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
//*)

#include "wx/wxsqlite3.h"

class TProducto: public wxDialog
{
	public:

		TProducto(float unValorDolar,wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~TProducto();
		void setValorDolar(float unValorDolar);

		//(*Declarations(TProducto)
		wxMessageDialog* DialogoError;
		wxStaticText* TextDolar;
		wxTextCtrl* TextBoxDolar;
		wxBitmapButton* BotonAgregar;
		wxGrid* GridProductos;
		wxBitmapButton* BotonEliminar;
		wxMessageDialog* DialogoBorrado;
		wxBitmapButton* BotonEditar;
		//*)

	protected:

		//(*Identifiers(TProducto)
		static const long ID_GRID1;
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL2;
		static const long ID_BITMAPBUTTON1;
		static const long ID_BITMAPBUTTON3;
		static const long ID_BITMAPBUTTON2;
		static const long ID_MESSAGEDIALOG1;
		static const long ID_MESSAGEDIALOG2;
		//*)

	private:

		//(*Handlers(TProducto)
		void OnResize(wxSizeEvent& event);
		void OnResize2(wxSizeEvent& event);
		void OnGridProductosResize(wxSizeEvent& event);
		void OnBotonAgregarClick(wxCommandEvent& event);
		void OnBotonEditarClick(wxCommandEvent& event);
		void OnGridProductosLabelLeftDClick(wxGridEvent& event);
		void OnBotonEliminarClick(wxCommandEvent& event);
		//*)

        float valorDolar;
		void ProductoSelectAll(int ACCION);

        static const int ID_CARGAR_ADD;
		static const int ID_CARGAR_EDIT;

		wxSQLite3Database* db;

		DECLARE_EVENT_TABLE()
};

#endif
