#pragma once

#include "HtmlWindow.h"

class InstallerWindow : public HtmlWindow, public ThreadComponent, 
	public InstallerUI, public IExecuteCallback, public IDownloadCallback
{
private:
	DownloadDialogPtr m_downloaddialog;
	htmlayout::dom::element components;
	htmlayout::dom::element button_install;
	htmlayout::dom::element button_uninstall;
	htmlayout::dom::element button_skip;
	htmlayout::dom::element button_cancel;
	htmlayout::dom::element status;
	htmlayout::dom::element error;
	htmlayout::dom::element progress;
	void SetControlValues();
	void ExtractCab(const std::wstring& id, bool display_dialog);
	// IExecuteCallback
	int ExecOnThread();
	void OnExecBegin();
	bool OnComponentExecBegin(const ComponentPtr& component);
	bool OnComponentExecWait(const ComponentPtr& component);
	bool OnComponentExecSuccess(const ComponentPtr& component);
	bool OnComponentExecError(const ComponentPtr& component, std::exception& ex);
	// IDownloadCallback
	void DownloadingFile(const std::wstring& filename);
	void CopyingFile(const std::wstring& filename);
	void Connecting(const std::wstring& host);
	void SendingRequest(const std::wstring& host);
	void Status(ULONG progress_current, ULONG progress_max, const std::wstring& description);
	void DownloadComplete();
	void DownloadError(const std::wstring& message);
	bool IsDownloadCancelled() const;
protected:
	void AddComponent(const ComponentPtr& component, const std::wstring& description, bool checked, bool disabled);
	bool Run();
	HINSTANCE GetInstance() const;
	HWND GetHwnd() const;
	void StartInstall();
	void Stop();
public:
	bool RunDownloadConfiguration(const DownloadDialogPtr& p_Configuration);
	void Create(int x, int y, int width, int height, const wchar_t * caption = 0);
	void ResetContent();
	void DoModal();
	BOOL on_event(HELEMENT he, HELEMENT target, BEHAVIOR_EVENTS type, UINT_PTR reason);
	int OnMessage(UINT message, WPARAM wParam, LPARAM lParam);
public:
	void OnInstall();
	void OnOK();
	void ShowError(const std::wstring&);
	void ClearError();
	// progress
	void SetProgress(int pc);
	void SetProgressTotal(int pc);
	void ClearProgress();
	void SetStatus(const std::wstring& msg);
public:
	InstallerWindow();
};
