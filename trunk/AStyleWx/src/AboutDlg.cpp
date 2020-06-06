// AboutDlg.cpp
// Copyright (c) 2018 by Jim Pattee <jimp03@email.com>.
// This code is licensed under the MIT License.
// License.md describes the conditions under which this software may be distributed.

//-----------------------------------------------------------------------------
// headers
//-----------------------------------------------------------------------------

#include <wx/dcclient.h>
#include <wx/fontmap.h>

#include "AboutDlg.h"

//-----------------------------------------------------------------------------
// AboutDlg class
//-----------------------------------------------------------------------------

AboutDlg::AboutDlg(wxWindow* parent) : AboutDlgBase(parent)
{
	// set the default button
	m_ok->SetDefault();
}

void AboutDlg::SetSystemInfo()
{
	const int lengthMax = 30;
	wxLocale loc;
	loc.Init();
	wxString osDesc = wxGetOsDescription();
#ifdef __WXGTK__
	if (osDesc.length() > lengthMax)
	{
		size_t end = osDesc.Find(' ', true);	// search from the end
		if (end != wxString::npos && end < lengthMax)
			osDesc = osDesc.Mid(0, end);
	}
#else
	size_t end = osDesc.Find('(');
	if (end != wxString::npos && end < lengthMax)
		osDesc = osDesc.Mid(0, end);
#endif
	wxString langDesc = wxLocale::GetLanguageName(loc.GetLanguage());
	wxString locName = loc.GetSysName();
	wxString langName = loc.GetCanonicalName();
	wxString fontCode = wxFontMapper::GetEncodingName(wxLocale::GetSystemEncoding()).Lower();
	wxFont sysGuiFont(*wxNORMAL_FONT);
	wxString guiFont = wxString::Format("%s, %d pt",
	                                    sysGuiFont.GetFaceName(), sysGuiFont.GetPointSize());
	bool isLittleEndian = wxIsPlatformLittleEndian();
	wxString endian = isLittleEndian ? "little endian" : "big endian";
	bool is64Bit = wxIsPlatform64Bit();
	wxString bits = is64Bit ? "64 bit" : "32 bit";

	wxString localeText =
	    "Operating system\n"
	    "System Language\n"
	    "Locale Name\n"
	    "Canonical Name\n"
	    "Default Font Encoding\n"
	    "Default GUI Font\n"
	    "System Endian\n"
	    "System Bits";

	m_localeText->SetLabel(localeText);

	wxString localeData =
	    osDesc + "\n" +
	    langDesc + "\n" +
	    locName + "\n" +
	    langName + "\n" +
	    fontCode + "\n" +
	    guiFont + "\n" +
	    endian + "\n" +
	    bits;

	m_localeData->SetLabel(localeData);
}

void AboutDlg::SetAboutDlgValues(wxString& astyleVersion, wxIconBundle* m_iconBundle)
// Dialog box is similar to wxWidgets src/generic/aboutdgg.cpp
// method wxGenericAboutDialog::Create.
{
	// set title1 font and text titles
	wxFont fontTitle1(*wxNORMAL_FONT);
	fontTitle1.SetPointSize(fontTitle1.GetPointSize() + 6);
	fontTitle1.SetWeight(wxFONTWEIGHT_BOLD);
	m_title1->SetFont(fontTitle1);
	m_title1->SetLabel("Artistic Style Wx");
	// set the icon
	wxIcon icon = m_iconBundle->GetIcon(wxSize(32, 32));
	m_icon->SetIcon(icon);
	// set title2 font and text titles
	wxFont fontTitle2(*wxNORMAL_FONT);
	fontTitle2.SetPointSize(fontTitle2.GetPointSize() + 3);
	fontTitle2.SetWeight(wxFONTWEIGHT_BOLD);
	m_title2->SetFont(fontTitle2);
	m_title2->SetLabel("Artistic Style");
	// set title3 font and text titles
	wxFont fontTitle3(*wxNORMAL_FONT);
	fontTitle3.SetPointSize(fontTitle3.GetPointSize() + 2);
	fontTitle3.SetWeight(wxFONTWEIGHT_BOLD);
	m_title3->SetFont(fontTitle3);
	m_title3->SetLabel("System");
	// set fonts
	wxFont fontBig(*wxNORMAL_FONT);
	fontBig.SetPointSize(fontBig.GetPointSize() + 1);
	fontBig.SetWeight(wxFONTWEIGHT_NORMAL);
	m_description->SetFont(fontBig);
	m_license->SetFont(fontBig);
	m_astylewxVersion->SetFont(fontBig);
	m_wxVersion->SetFont(fontBig);
	m_astyleVersion->SetFont(fontBig);
	m_astyleWeblabel->SetFont(fontBig);
	m_astyleWebsite->SetFont(fontBig);
	m_localeText->SetFont(fontBig);
	m_localeData->SetFont(fontBig);

	// set astylewx information
	m_description->SetLabel("A graphical user interface for the Artistic Style formatter.");
	m_license->SetLabel("This software is licensed under the MIT License.");
	wxString toolkit;
#ifdef __WXQT__
	toolkit = "qt";
#elif defined (__WXGTK__)
#ifdef __WXGTK3__
	toolkit = "gtk3";
#else
	toolkit = "gtk2";
#endif	// __WXGTK3__
#endif	// __WXQT__
	if (toolkit.empty())
		m_wxVersion->SetLabel(wxString::Format("Built with wxWidgets version  %d.%d.%d.",
		                                       wxMAJOR_VERSION, wxMINOR_VERSION, wxRELEASE_NUMBER));
	else
		m_wxVersion->SetLabel(wxString::Format("Built with wxWidgets version  %d.%d.%d, %s.",
		                                       wxMAJOR_VERSION, wxMINOR_VERSION, wxRELEASE_NUMBER,
		                                       toolkit));
	m_astylewxVersion->SetLabel(wxString::Format("Artistic Style Wx version  %s.", astyleVersion));
	// set astyle information
	m_astyleVersion->SetLabel(wxString::Format("Artistic Style version  %s.", astyleVersion));
	m_astyleWeblabel->SetLabel("Home Page");
	m_astyleWebsite->SetLabel("http://astyle.sourceforge.net/");
	m_astyleWebsite->SetURL("http://astyle.sourceforge.net/");
	// set locale information
	SetSystemInfo();

	// display
	m_ok->SetFocus();
	SetSizer(m_aboutDlgSizer);
	m_aboutDlgSizer->SetSizeHints(this);
}
