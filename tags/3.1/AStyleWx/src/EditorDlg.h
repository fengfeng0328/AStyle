//  EditorDlg.h
// Copyright (c) 2018 by Jim Pattee <jimp03@email.com>.
// This code is licensed under the MIT License.
// License.md describes the conditions under which this software may be distributed.

#ifndef _EDITORDLG_H_
#define _EDITORDLG_H_

//-----------------------------------------------------------------------------
// headers
//-----------------------------------------------------------------------------

#include "AStyleWx.h"
#include "Constants.h"
#include "EditorDlgBase.h"

//-----------------------------------------------------------------------------
// definitions
//-----------------------------------------------------------------------------

// Define the page changed event for the selected book type.
// This must agree with the type in the generated EditorDlgBase.h.
// May be a Choicebook, Listbook, Notebook, or Treebook.
// Since Notebook is always defined it must be the default.
// This fixes a problem with the event in Linux.
#ifndef wxBOOKCTRL_EVENT
	#if defined(EVT_CHOICEBOOK_PAGE_CHANGED)
		#define wxBOOKCTRL_EVENT wxChoicebookEvent
	#elif defined(EVT_LISTBOOK_PAGE_CHANGED)
		#define wxBOOKCTRL_EVENT wxListbookEvent
	#elif defined(EVT_TREEBOOK_PAGE_CHANGED)
		#define wxBOOKCTRL_EVENT wxTreebookEvent
	#else
		// this MUST be the default
		#define wxBOOKCTRL_EVENT wxNotebookEvent
	#endif
#endif	// wxBOOKCTRL_EVENT

//-----------------------------------------------------------------------------
// EditorDlg Class
// The inherited EditorDlgBase class is generated by wsFormBuilder
//-----------------------------------------------------------------------------

class EditorDlg: public EditorDlgBase
{
public:
	/// Constructors
	EditorDlg(ASFrame* frame, int page);
	~EditorDlg();

	wxFont GetCommentFont() const;
	wxFont GetDefaultFont() const;
	bool GetHideFind() const;
	vector<TextStyle>& GetNewStyleVector();
	int  GetPage();
	bool GetShowDialogTooltips() const;
	bool GetShowToolbarTooltips() const;
	bool GetUseBottomTabs() const;
	bool GetUseSmallToolbar() const;
	bool GetWrapSearch() const;

protected:
	// Event Handler overrides for EditorDlgBase events.
	// There is an implementation in EditorDlgBase because
	// some events (OnNotebookPageChanged) are called from
	// the EditorDlgBase constructor. The wxFormBuilder project
	// event handler definition must be "impl_virtual".
	void OnBoldClick(wxCommandEvent& event);
	void OnForegroundClick(wxMouseEvent& event);
	void OnItalicClick(wxCommandEvent& event);
	void OnListboxSelected(wxCommandEvent& event);
	void OnResetClick(wxCommandEvent& event);
	// May be a Choicebook, Listbook, Notebook, or Treebook.
	void OnNotebookPageChanged(wxBOOKCTRL_EVENT& event);

private:
	void BuildDialogTips() const;
	void GetExcludedFonts(wxArrayString& excludedFonts) const;
	void SetCommentFontOptions() const;
	void SetDefaultFontOptions() const;
	void SetFontNames(wxArrayString& fontNamesAll, wxArrayString& fontNames) const;
	void SetFontSizes(wxComboBox* fontSizeList) const;
	void SetResetButton() const;
	void SetStcStyleOptions(const vector<TextStyle>& styleVector);

private:

	ASFrame* m_frame;
	ASEditor* m_editor;
	vector<TextStyle> m_newStyleVector;     // element for each text style
	bool m_showDialogTips;                  // show or don't show dialog tips
	int  m_page;							// currently selected notebook page
	static int m_ix;                        // currently selected style
};

#endif	// _EDITORDLG_H_
