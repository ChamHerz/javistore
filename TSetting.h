#ifndef TSETTING_H
#define TSETTING_H

//(*Headers(TSetting)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "wx/wxsqlite3.h"

class TSetting: public wxDialog
{
	public:

		TSetting(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~TSetting();

		//(*Declarations(TSetting)
		wxStaticText* TextoDolar;
		wxButton* BotonAceptar;
		wxButton* BotonCancelar;
		wxTextCtrl* TextBoxPrecioDolar;
		//*)

	protected:

		//(*Identifiers(TSetting)
		static const long ID_STATICTEXT1;
		static const long ID_TEXTCTRL1;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		//*)

	private:

		//(*Handlers(TSetting)
		void OnBotonCancelarClick(wxCommandEvent& event);
		void OnBotonAceptarClick(wxCommandEvent& event);
		//*)

		void SettingSelectAll();

		wxSQLite3Database* db;

		DECLARE_EVENT_TABLE()
};

#endif
