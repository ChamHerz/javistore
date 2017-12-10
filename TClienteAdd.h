#ifndef TCLIENTEADD_H
#define TCLIENTEADD_H

//(*Headers(TClienteAdd)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "wx/wxsqlite3.h"

class TClienteAdd: public wxDialog
{
	public:

		TClienteAdd(int idCliente,int actionForm,wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~TClienteAdd();

		//(*Declarations(TClienteAdd)
		wxTextCtrl* TextBoxTelefono;
		wxStaticText* StaticText2;
		wxButton* BotonAceptar;
		wxTextCtrl* TextBoxNombres;
		wxTextCtrl* TextBoxIdCliente;
		wxButton* BotonCancelar;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxTextCtrl* TextBoxEmail;
		wxStaticText* StaticText5;
		wxTextCtrl* TextBoxApellido;
		wxStaticText* StaticText4;
		//*)

		static const int ID_FORMACTION_ADD;
		static const int ID_FORMACTION_EDIT;

	protected:

		//(*Identifiers(TClienteAdd)
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

		//(*Handlers(TClienteAdd)
		void OnBotonCancelarClick(wxCommandEvent& event);
		void OnBotonAceptarClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		//*)

		wxSQLite3Database* db;

        int ID_ACTIONFORM_STATUS;
		int ID_Cliente;

		DECLARE_EVENT_TABLE()
};

#endif
