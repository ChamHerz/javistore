/***************************************************************
 * Name:      javistoreApp.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2017-11-04
 * Copyright:  ()
 * License:
 **************************************************************/

#include "javistoreApp.h"

//(*AppHeaders
#include "javistoreMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(javistoreApp);

bool javistoreApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	javistoreFrame* Frame = new javistoreFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
