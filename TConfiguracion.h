#ifndef TCONFIGURACION_H
#define TCONFIGURACION_H

//(*Headers(TConfiguracion)
#include <wx/sizer.h>
#include <wx/msgdlg.h>
#include <wx/grid.h>
#include <wx/bmpbuttn.h>
#include <wx/dialog.h>
//*)

#include "wx/wxsqlite3.h"

class TConfiguracion: public wxDialog
{
	public:

		TConfiguracion(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~TConfiguracion();

		//(*Declarations(TConfiguracion)
		wxMessageDialog* DialogoError;
		wxBitmapButton* BotonBorrarCliente;
		wxGrid* Grid1;
		wxBitmapButton* BotonAgregarCliente;
		wxBitmapButton* BotonEditarCliente;
		wxMessageDialog* DialogoBorrado;
		//*)

	protected:

		//(*Identifiers(TConfiguracion)
		static const long ID_GRID1;
		static const long ID_BITMAPBUTTON1;
		static const long ID_BITMAPBUTTON2;
		static const long ID_BITMAPBUTTON3;
		static const long ID_MESSAGEDIALOG1;
		static const long ID_MESSAGEDIALOG2;
		//*)

	private:

		//(*Handlers(TConfiguracion)
		void OnBitmapButton2Click(wxCommandEvent& event);
		void OnBitmapButton1Click(wxCommandEvent& event);
		void OnBitmapButton2Click1(wxCommandEvent& event);
		void OnBotonAgregarClienteClick(wxCommandEvent& event);
		void OnBotonBorrarClienteClick(wxCommandEvent& event);
		void OnBotonEditarClienteClick(wxCommandEvent& event);
		void OnGrid1LabelLeftDClick(wxGridEvent& event);
		//*)

		void ClienteSelectAll();
		void ClienteSelectAll_Carga();
		void ClienteSelectAll_soloCarga();

		wxSQLite3Database* db;

		DECLARE_EVENT_TABLE()
};

#endif
