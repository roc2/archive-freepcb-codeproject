#pragma once
#include "afxwin.h"
#include "afxcmn.h"


// CDlgGroupPaste dialog

class CDlgGroupPaste : public CDialog
{
	DECLARE_DYNAMIC(CDlgGroupPaste)

public:
	CDlgGroupPaste(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgGroupPaste();
	void Initialize( CNetList *grp_nlist );
	void SetFields();
	void PreserveState();					// CPT2 new, so that we wake up in the same state as last time...
	bool RestoreState();					// Ditto

	int m_units;
	int m_ref_option;
	int m_ref_offset;
	int m_net_name_option;		// 0=group names, 1=rename
	int m_net_rename_option;	// 0=use suffix, 1=next Nnnnnn
	int m_position_option;
	int m_pin_net_option;	// 0=retain all, 1=only for pins with traces
	double m_dx, m_dy;
	int m_sort_type;
	CNetList *m_grp_nlist;
	int m_num_copies;			// CPT2 new
	int m_flags;

// Dialog Data
	enum { IDD = IDD_GROUP_PASTE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CButton m_radio_use_group_ref;
	CButton m_radio_use_next_ref;
	CButton m_radio_add_ref_offset;
	CEdit m_edit_offset;
	CButton m_radio_use_group_nets;
	CButton m_radio_use_selected_nets;
	CListCtrl m_list_ctrl;
	CButton m_radio_use_suffix;
	CButton m_radio_make_new_names;
	CButton m_check_ignore_empty_nets;
	CButton m_check_multiple;
	CEdit m_edit_num_copies;
	CButton m_radio_drag;
	CButton m_radio_offset;
	CEdit m_edit_x;
	CEdit m_edit_y;
	CComboBox m_combo_units;
	afx_msg void OnBnClickedRadioUseGroupRef();
	afx_msg void OnBnClickedRadioUseNextRef();
	afx_msg void OnBnClickedRadioAddRefOffset();
	afx_msg void OnBnClickedRadioUseGroupNets();
	afx_msg void OnBnClickedRadioUseSelectedNets();
	afx_msg void OnBnClickedRadioUseSuffix();
	afx_msg void OnBnClickedRadioMakeNewNames();
	afx_msg void OnBnClickedRadioDrag();
	afx_msg void OnBnClickedRadioOffset();
	afx_msg void OnCbnSelchangeComboGroupUnits();
	afx_msg void OnLvnColumnClickListSelectGroupNets(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheckAt();
	afx_msg void OnBnClickedCheckIgnoreEmptyNets();
	afx_msg void OnEnChangeEditGroupX();
	afx_msg void OnBnClickedCheckMultiple();
};
