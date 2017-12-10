#ifndef TPEDIDOADD_H
#define TPEDIDOADD_H

//(*Headers(TPedidoAdd)
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/msgdlg.h>
#include <wx/checkbox.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/dialog.h>
//*)

#include "wx/wxsqlite3.h"
#include "TUtil.h"

class TPedidoAdd: public wxDialog
{
	public:

		TPedidoAdd(int idPedido,int accionForm,wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~TPedidoAdd();

		//(*Declarations(TPedidoAdd)
		wxStaticText* StaticText10;
		wxStaticText* StaticText9;
		wxMessageDialog* DialogoError;
		wxChoice* ComboProducto;
		wxTextCtrl* TextBoxPrecioARG;
		wxTextCtrl* TextBoxComision;
		wxTextCtrl* TextBoxDescripcion;
		wxChoice* ComboCliente;
		wxTextCtrl* TexBoxTelefono;
		wxStaticText* StaticText13;
		wxStaticText* StaticText2;
		wxButton* BotonAceptar;
		wxTextCtrl* TexBoxEmail;
		wxStaticText* StaticText14;
		wxDatePickerCtrl* TextBoxFechaPedido;
		wxStaticText* StaticText6;
		wxTextCtrl* TextBoxIDCliente;
		wxStaticText* StaticText8;
		wxStaticText* StaticText11;
		wxTextCtrl* TextBoxNombre;
		wxButton* BotonCancelar;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxCheckBox* CheckFechaCompra;
		wxDatePickerCtrl* TextBoxFechaCompra;
		wxCheckBox* CheckFechaPedido;
		wxTextCtrl* TextBoxPrecioUSD;
		wxStaticText* StaticText5;
		wxStaticText* StaticText7;
		wxStaticText* StaticText15;
		wxStaticText* StaticText12;
		wxTextCtrl* TextBoxPrecioDolar;
		wxTextCtrl* TextBoxApellido;
		wxTextCtrl* TextBoxIDProducto;
		wxStaticText* StaticText4;
		wxStaticText* StaticText17;
		wxCheckBox* CheckFechaEntrega;
		wxDatePickerCtrl* TextBoxFechaEntrega;
		wxStaticText* StaticText16;
		wxTextCtrl* TextBoxIDPedido;
		//*)

        static const int ID_FORMACTION_ADD;
		static const int ID_FORMACTION_EDIT;

	protected:

		//(*Identifiers(TPedidoAdd)
		static const long ID_STATICTEXT17;
		static const long ID_TEXTCTRL12;
		static const long ID_STATICTEXT1;
		static const long ID_CHOICE1;
		static const long ID_STATICTEXT7;
		static const long ID_CHOICE2;
		static const long ID_STATICTEXT2;
		static const long ID_TEXTCTRL1;
		static const long ID_STATICTEXT3;
		static const long ID_TEXTCTRL2;
		static const long ID_STATICTEXT4;
		static const long ID_TEXTCTRL3;
		static const long ID_STATICTEXT5;
		static const long ID_TEXTCTRL4;
		static const long ID_STATICTEXT6;
		static const long ID_TEXTCTRL5;
		static const long ID_STATICTEXT8;
		static const long ID_TEXTCTRL6;
		static const long ID_STATICTEXT9;
		static const long ID_TEXTCTRL7;
		static const long ID_STATICTEXT10;
		static const long ID_TEXTCTRL8;
		static const long ID_STATICTEXT11;
		static const long ID_TEXTCTRL9;
		static const long ID_STATICTEXT12;
		static const long ID_TEXTCTRL10;
		static const long ID_STATICTEXT13;
		static const long ID_TEXTCTRL11;
		static const long ID_STATICTEXT14;
		static const long ID_CHECKBOX1;
		static const long ID_DATEPICKERCTRL1;
		static const long ID_STATICTEXT15;
		static const long ID_CHECKBOX2;
		static const long ID_DATEPICKERCTRL2;
		static const long ID_STATICTEXT16;
		static const long ID_CHECKBOX3;
		static const long ID_DATEPICKERCTRL3;
		static const long ID_BUTTON1;
		static const long ID_BUTTON2;
		static const long ID_MESSAGEDIALOG1;
		//*)

	private:

		//(*Handlers(TPedidoAdd)
		void OnComboClienteSelect(wxCommandEvent& event);
		void OnComboProductoSelect(wxCommandEvent& event);
		void OnTextBoxPrecioDolarText(wxCommandEvent& event);
		void OnCheckFechaPedidoClick(wxCommandEvent& event);
		void OnCheckFechaCompraClick(wxCommandEvent& event);
		void OnCheckFechaEntregaClick(wxCommandEvent& event);
		void OnBitmapButton1Click(wxCommandEvent& event);
		void OnBotonAgregarPedidoClick(wxCommandEvent& event);
		void OnBotonAceptarClick(wxCommandEvent& event);
		void OnBotonCancelarClick(wxCommandEvent& event);
		void OnClose(wxCloseEvent& event);
		//*)

		void monstrarFecha(wxCommandEvent event, wxDatePickerCtrl* TextBoxFecha);
		void cargarUnaFecha(wxCheckBox* checkBox,wxDatePickerCtrl* TextBoxFecha,int fechaUnix);
		int getFecha(wxCheckBox* checkBox,wxDatePickerCtrl* TextBoxFecha);

		wxSQLite3Database* db;
		TUtil* util;

		int ID_ACTIONFORM_STATUS;

		int idPedido;
		float valorDolar;
		float precioUSD;
		float precioARG;

		DECLARE_EVENT_TABLE()
};

#endif
