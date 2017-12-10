#ifndef TPRODUCTOADD_H
#define TPRODUCTOADD_H

//(*Headers(TProductoAdd)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "wx/wxsqlite3.h"

class TProductoAdd: public wxDialog
{
	public:

		TProductoAdd(int idProducto,int actionForm,wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~TProductoAdd();

		//(*Declarations(TProductoAdd)
		wxTextCtrl* TextBoxComision;
		wxTextCtrl* TextBoxDescripcion;
		wxTextCtrl* TextBoxDesc;
		wxStaticText* StaticText2;
		wxButton* BotonAceptar;
		wxButton* BotonCancelar;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* TextBoxPrecioUSD;
		wxStaticText* StaticText5;
		wxTextCtrl* TextBoxIDProducto;
		wxStaticText* StaticText4;
		//*)

        static const int ID_FORMACTION_ADD;
		static const int ID_FORMACTION_EDIT;

	protected:

		//(*Identifiers(TProductoAdd)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL5;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(TProductoAdd)
		void OnBotonCancelarClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnBotonAceptarClick(wxCommandEvent& event);
		//*)

		wxSQLite3Database* db;

        int ID_ACTIONFORM_STATUS;
		int ID_Producto;

		DECLARE_EVENT_TABLE()
};

#endif
