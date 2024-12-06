#include "dllyact_def.h"

DW FixResHandle(DW Handle);
#define DEFINE_FUNC_RES1(name) 	\
EXTERN_C DW STUB_IMPORT name(DW);	\
EXTERN_C DW STUB_EXPORT yact_##name(DW *R)		\
{	\
  DW r=name(FixResHandle(p1));	\
  LEAVE(1);		\
  return r;		\
}

#define DEFINE_FUNC_RES2(name) 	\
EXTERN_C DW STUB_IMPORT name(DW,DW);	\
EXTERN_C DW STUB_EXPORT yact_##name(DW *R)		\
{	\
  DW r=name(FixResHandle(p1),p2);	\
  LEAVE(2);		\
  return r;		\
}

#define DEFINE_FUNC_RES3(name) 	\
EXTERN_C DW STUB_IMPORT name(DW,DW,DW);	\
EXTERN_C DW STUB_EXPORT yact_##name(DW *R)		\
{	\
  DW r=name(FixResHandle(p1),p2,p3);	\
  LEAVE(3);		\
  return r;		\
}

#define DEFINE_FUNC_RES4(name) 	\
EXTERN_C DW STUB_IMPORT name(DW,DW,DW,DW);	\
EXTERN_C DW STUB_EXPORT yact_##name(DW *R)		\
{	\
  DW r=name(FixResHandle(p1),p2,p3,p4);	\
  LEAVE(4);		\
  return r;		\
}

#define DEFINE_FUNC_RES6(name) 	\
EXTERN_C DW STUB_IMPORT name(DW,DW,DW,DW,DW,DW);	\
EXTERN_C DW STUB_EXPORT yact_##name(DW *R)		\
{	\
  DW r=name(FixResHandle(p1),p2,p3,p4,p5,p6);	\
  LEAVE(4);		\
  return r;		\
}

DEFINE_FUNC2(ActivateKeyboardLayout)
DEFINE_FUNC3(AdjustWindowRect)
DEFINE_FUNC4(AdjustWindowRectEx)
DEFINE_FUNC1(AllowSetForegroundWindow)
DEFINE_FUNC3(AnimateWindow)
DEFINE_FUNC0(AnyPopup)
DEFINE_FUNC4(AppendMenuA)
DEFINE_FUNC4(AppendMenuW)
DEFINE_FUNC1(ArrangeIconicWindows)
DEFINE_FUNC3(AttachThreadInput)
DEFINE_FUNC1(BeginDeferWindowPos)
DEFINE_FUNC2(BeginPaint)
DEFINE_FUNC1(BlockInput)
DEFINE_FUNC1(BringWindowToTop)
DEFINE_FUNC5(BroadcastSystemMessage)
DEFINE_FUNC5(BroadcastSystemMessageA)
DEFINE_FUNC6(BroadcastSystemMessageExA)
DEFINE_FUNC6(BroadcastSystemMessageExW)
DEFINE_FUNC5(BroadcastSystemMessageW)
DEFINE_FUNC2(CallMsgFilter)
DEFINE_FUNC2(CallMsgFilterA)
DEFINE_FUNC2(CallMsgFilterW)
DEFINE_FUNC4(CallNextHookEx)
//DEFINE_FUNC5(CallWindowProcA)
//DEFINE_FUNC5(CallWindowProcW)
DEFINE_FUNC2(CascadeChildWindows)
DEFINE_FUNC5(CascadeWindows)
DEFINE_FUNC2(ChangeClipboardChain)
DEFINE_FUNC2(ChangeDisplaySettingsA)
DEFINE_FUNC2(ChangeDisplaySettingsW)
DEFINE_FUNC5(ChangeDisplaySettingsExA)
DEFINE_FUNC5(ChangeDisplaySettingsExW)
DEFINE_FUNC5(ChangeMenuA)
DEFINE_FUNC5(ChangeMenuW)
DEFINE_FUNC1(CharLowerA)
DEFINE_FUNC2(CharLowerBuffA)
DEFINE_FUNC2(CharLowerBuffW)
DEFINE_FUNC1(CharLowerW)
DEFINE_FUNC1(CharNextA)
DEFINE_FUNC3(CharNextExA)
DEFINE_FUNC1(CharNextW)
DEFINE_FUNC2(CharPrevA)
DEFINE_FUNC4(CharPrevExA)
DEFINE_FUNC2(CharPrevW)
DEFINE_FUNC2(CharToOemA)
DEFINE_FUNC3(CharToOemBuffA)
DEFINE_FUNC3(CharToOemBuffW)
DEFINE_FUNC2(CharToOemW)
DEFINE_FUNC1(CharUpperA)
DEFINE_FUNC2(CharUpperBuffA)
DEFINE_FUNC2(CharUpperBuffW)
DEFINE_FUNC1(CharUpperW)
DEFINE_FUNC3(CheckDlgButton)
DEFINE_FUNC3(CheckMenuItem)
DEFINE_FUNC5(CheckMenuRadioItem)
DEFINE_FUNC4(CheckRadioButton)
DEFINE_FUNC3(ChildWindowFromPoint)
DEFINE_FUNC4(ChildWindowFromPointEx)
DEFINE_FUNC2(ClientToScreen)
DEFINE_FUNC1(ClipCursor)
DEFINE_FUNC0(CloseClipboard)
DEFINE_FUNC1(CloseDesktop)
DEFINE_FUNC1(CloseWindow)
DEFINE_FUNC1(CloseWindowStation)
DEFINE_FUNC3(CopyAcceleratorTableA)
DEFINE_FUNC3(CopyAcceleratorTableW)
DEFINE_FUNC1(CopyIcon)
DEFINE_FUNC5(CopyImage)
DEFINE_FUNC2(CopyRect)
DEFINE_FUNC0(CountClipboardFormats)
DEFINE_FUNC2(CreateAcceleratorTableA)
DEFINE_FUNC2(CreateAcceleratorTableW)
DEFINE_FUNC4(CreateCaret)
DEFINE_FUNC7(CreateCursor)
DEFINE_FUNC6(CreateDesktopA)
DEFINE_FUNC6(CreateDesktopW)
/*
DEFINE_FUNC5(CreateDialogIndirectParamA)
DEFINE_FUNC5(CreateDialogIndirectParamW)
DEFINE_FUNC5(CreateDialogParamA)
DEFINE_FUNC5(CreateDialogParamW)
*/
DEFINE_FUNC7(CreateIcon)
DEFINE_FUNC4(CreateIconFromResource)
DEFINE_FUNC7(CreateIconFromResourceEx)
DEFINE_FUNC1(CreateIconIndirect)
DEFINE_FUNC10(CreateMDIWindowA)
DEFINE_FUNC10(CreateMDIWindowW)
DEFINE_FUNC0(CreateMenu)
DEFINE_FUNC0(CreatePopupMenu)
DEFINE_FUNC4(CreateWindowStationA)
DEFINE_FUNC4(CreateWindowStationW)
DEFINE_FUNC3(DdeAbandonTransaction)
DEFINE_FUNC2(DdeAccessData)
DEFINE_FUNC4(DdeAddData)
DEFINE_FUNC8(DdeClientTransaction)
DEFINE_FUNC2(DdeCmpStringHandles)
DEFINE_FUNC4(DdeConnect)
DEFINE_FUNC5(DdeConnectList)
DEFINE_FUNC7(DdeCreateDataHandle)
DEFINE_FUNC3(DdeCreateStringHandleA)
DEFINE_FUNC3(DdeCreateStringHandleW)
DEFINE_FUNC1(DdeDisconnect)
DEFINE_FUNC1(DdeDisconnectList)
DEFINE_FUNC3(DdeEnableCallback)
DEFINE_FUNC1(DdeFreeDataHandle)
DEFINE_FUNC2(DdeFreeStringHandle)
DEFINE_FUNC4(DdeGetData)
DEFINE_FUNC1(DdeGetLastError)
DEFINE_FUNC1(DdeImpersonateClient)
DEFINE_FUNC_CB4(DdeInitializeA,2,8)
DEFINE_FUNC_CB4(DdeInitializeW,2,8)
DEFINE_FUNC2(DdeKeepStringHandle)
DEFINE_FUNC4(DdeNameService)
DEFINE_FUNC3(DdePostAdvise)
DEFINE_FUNC3(DdeQueryConvInfo)
DEFINE_FUNC2(DdeQueryNextServer)
DEFINE_FUNC5(DdeQueryStringA)
DEFINE_FUNC5(DdeQueryStringW)
DEFINE_FUNC1(DdeReconnect)
DEFINE_FUNC3(DdeSetQualityOfService)
DEFINE_FUNC3(DdeSetUserHandle)
DEFINE_FUNC1(DdeUnaccessData)
DEFINE_FUNC1(DdeUninitialize)
DEFINE_FUNC4(DefDlgProcA)
DEFINE_FUNC4(DefDlgProcW)
DEFINE_FUNC5(DefFrameProcA)
DEFINE_FUNC5(DefFrameProcW)
DEFINE_FUNC4(DefMDIChildProcA)
DEFINE_FUNC4(DefMDIChildProcW)
DEFINE_FUNC3(DefRawInputProc)
DEFINE_FUNC4(DefWindowProcA)
DEFINE_FUNC4(DefWindowProcW)
DEFINE_FUNC8(DeferWindowPos)
DEFINE_FUNC3(DeleteMenu)
DEFINE_FUNC1(DeregisterShellHookWindow)
DEFINE_FUNC1(DestroyAcceleratorTable)
DEFINE_FUNC0(DestroyCaret)
DEFINE_FUNC1(DestroyCursor)
DEFINE_FUNC1(DestroyIcon)
DEFINE_FUNC1(DestroyMenu)
DEFINE_FUNC1(DestroyWindow)
/*
DEFINE_FUNC5(DialogBoxIndirectParamA)
DEFINE_FUNC5(DialogBoxIndirectParamW)
DEFINE_FUNC5(DialogBoxParamA)
DEFINE_FUNC5(DialogBoxParamW)
*/
DEFINE_FUNC1(DispatchMessageA)
DEFINE_FUNC1(DispatchMessageW)
DEFINE_FUNC5(DlgDirListA)
DEFINE_FUNC5(DlgDirListComboBoxA)
DEFINE_FUNC5(DlgDirListComboBoxW)
DEFINE_FUNC5(DlgDirListW)
DEFINE_FUNC4(DlgDirSelectComboBoxExA)
DEFINE_FUNC4(DlgDirSelectComboBoxExW)
DEFINE_FUNC4(DlgDirSelectExA)
DEFINE_FUNC4(DlgDirSelectExW)
DEFINE_FUNC3(DragDetect)
DEFINE_FUNC5(DragObject)
DEFINE_FUNC4(DrawAnimatedRects)
DEFINE_FUNC4(DrawCaption)
DEFINE_FUNC4(DrawEdge)
DEFINE_FUNC2(DrawFocusRect)
DEFINE_FUNC4(DrawFrame)
DEFINE_FUNC4(DrawFrameControl)
DEFINE_FUNC4(DrawIcon)
DEFINE_FUNC9(DrawIconEx)
DEFINE_FUNC1(DrawMenuBar)
DEFINE_FUNC_CB10(DrawStateA,3,5)
DEFINE_FUNC_CB10(DrawStateW,3,5)
DEFINE_FUNC5(DrawTextA)
DEFINE_FUNC6(DrawTextExA)
DEFINE_FUNC6(DrawTextExW)
DEFINE_FUNC5(DrawTextW)
DEFINE_FUNC4(EditWndProc)
DEFINE_FUNC0(EmptyClipboard)
DEFINE_FUNC3(EnableMenuItem)
DEFINE_FUNC3(EnableScrollBar)
DEFINE_FUNC2(EnableWindow)
DEFINE_FUNC1(EndDeferWindowPos)
DEFINE_FUNC2(EndDialog)
DEFINE_FUNC0(EndMenu)
DEFINE_FUNC2(EndPaint)
DEFINE_FUNC3(EndTask)
DEFINE_FUNC_CB3(EnumChildWindows,2,2)
DEFINE_FUNC1(EnumClipboardFormats)
DEFINE_FUNC_CB3(EnumDesktopWindows,2,2)
DEFINE_FUNC_CB3(EnumDesktopsA,2,2)
DEFINE_FUNC_CB3(EnumDesktopsW,2,2)
DEFINE_FUNC4(EnumDisplayDevicesA)
DEFINE_FUNC4(EnumDisplayDevicesW)
DEFINE_FUNC_CB4(EnumDisplayMonitors,3,4)
DEFINE_FUNC3(EnumDisplaySettingsA)
DEFINE_FUNC4(EnumDisplaySettingsExA)
DEFINE_FUNC4(EnumDisplaySettingsExW)
DEFINE_FUNC3(EnumDisplaySettingsW)
DEFINE_FUNC_CB2(EnumPropsA,2,3)
DEFINE_FUNC_CB3(EnumPropsExA,2,4)
DEFINE_FUNC_CB3(EnumPropsExW,2,4)
DEFINE_FUNC_CB2(EnumPropsW,2,3)
DEFINE_FUNC_CB3(EnumThreadWindows,2,2)
DEFINE_FUNC_CB2(EnumWindowStationsA,1,2)
DEFINE_FUNC_CB2(EnumWindowStationsW,1,2)
DEFINE_FUNC_CB2(EnumWindows,1,2)
DEFINE_FUNC2(EqualRect)
DEFINE_FUNC2(ExcludeUpdateRgn)
DEFINE_FUNC2(ExitWindowsEx)
DEFINE_FUNC3(FillRect)
DEFINE_FUNC2(FindWindowA)
DEFINE_FUNC4(FindWindowExA)
DEFINE_FUNC4(FindWindowExW)
DEFINE_FUNC2(FindWindowW)
DEFINE_FUNC2(FlashWindow)
DEFINE_FUNC1(FlashWindowEx)
DEFINE_FUNC3(FrameRect)
DEFINE_FUNC2(FreeDDElParam)
DEFINE_FUNC0(GetActiveWindow)
DEFINE_FUNC5(GetAltTabInfo)
DEFINE_FUNC5(GetAltTabInfoA)
DEFINE_FUNC5(GetAltTabInfoW)
DEFINE_FUNC2(GetAncestor)
DEFINE_FUNC1(GetAsyncKeyState)
DEFINE_FUNC0(GetCapture)
DEFINE_FUNC0(GetCaretBlinkTime)
DEFINE_FUNC1(GetCaretPos)
//DEFINE_FUNC3(GetClassInfoA)
//DEFINE_FUNC3(GetClassInfoExA)
//DEFINE_FUNC3(GetClassInfoExW)
//DEFINE_FUNC3(GetClassInfoW)
DEFINE_FUNC3(GetClassNameA)
DEFINE_FUNC3(GetClassNameW)
DEFINE_FUNC2(GetClientRect)
DEFINE_FUNC1(GetClipCursor)
DEFINE_FUNC1(GetClipboardData)
DEFINE_FUNC3(GetClipboardFormatNameA)
DEFINE_FUNC3(GetClipboardFormatNameW)
DEFINE_FUNC0(GetClipboardOwner)
DEFINE_FUNC0(GetClipboardSequenceNumber)
DEFINE_FUNC0(GetClipboardViewer)
DEFINE_FUNC2(GetComboBoxInfo)
DEFINE_FUNC0(GetCursor)
DEFINE_FUNC1(GetCursorInfo)
DEFINE_FUNC1(GetCursorPos)
DEFINE_FUNC1(GetDC)
DEFINE_FUNC3(GetDCEx)
DEFINE_FUNC0(GetDesktopWindow)
DEFINE_FUNC0(GetDialogBaseUnits)
DEFINE_FUNC1(GetDlgCtrlID)
DEFINE_FUNC2(GetDlgItem)
DEFINE_FUNC4(GetDlgItemInt)
DEFINE_FUNC4(GetDlgItemTextA)
DEFINE_FUNC4(GetDlgItemTextW)
DEFINE_FUNC0(GetDoubleClickTime)
DEFINE_FUNC0(GetFocus)
DEFINE_FUNC0(GetForegroundWindow)
DEFINE_FUNC2(GetGUIThreadInfo)
DEFINE_FUNC2(GetGuiResources)
DEFINE_FUNC2(GetIconInfo)
DEFINE_FUNC0(GetInputDesktop)
DEFINE_FUNC0(GetInputState)
DEFINE_FUNC0(GetKBCodePage)
DEFINE_FUNC3(GetKeyNameTextA)
DEFINE_FUNC3(GetKeyNameTextW)
DEFINE_FUNC1(GetKeyState)
DEFINE_FUNC1(GetKeyboardLayout)
DEFINE_FUNC2(GetKeyboardLayoutList)
DEFINE_FUNC1(GetKeyboardLayoutNameA)
DEFINE_FUNC1(GetKeyboardLayoutNameW)
DEFINE_FUNC1(GetKeyboardState)
DEFINE_FUNC1(GetKeyboardType)
DEFINE_FUNC1(GetLastActivePopup)
DEFINE_FUNC1(GetLastInputInfo)
DEFINE_FUNC4(GetLayeredWindowAttributes)
DEFINE_FUNC1(GetListBoxInfo)
DEFINE_FUNC1(GetMenu)
DEFINE_FUNC4(GetMenuBarInfo)
DEFINE_FUNC0(GetMenuCheckMarkDimensions)
DEFINE_FUNC1(GetMenuContextHelpId)
DEFINE_FUNC3(GetMenuDefaultItem)
DEFINE_FUNC2(GetMenuInfo)
DEFINE_FUNC1(GetMenuItemCount)
DEFINE_FUNC2(GetMenuItemID)
DEFINE_FUNC4(GetMenuItemInfoA)
DEFINE_FUNC4(GetMenuItemInfoW)
DEFINE_FUNC4(GetMenuItemRect)
DEFINE_FUNC3(GetMenuState)
DEFINE_FUNC5(GetMenuStringA)
DEFINE_FUNC5(GetMenuStringW)
DEFINE_FUNC4(GetMessageA)
DEFINE_FUNC0(GetMessageExtraInfo)
DEFINE_FUNC0(GetMessagePos)
DEFINE_FUNC0(GetMessageTime)
DEFINE_FUNC4(GetMessageW)
DEFINE_FUNC2(GetMonitorInfoA)
DEFINE_FUNC2(GetMonitorInfoW)
DEFINE_FUNC5(GetMouseMovePointsEx)
DEFINE_FUNC3(GetNextDlgGroupItem)
DEFINE_FUNC3(GetNextDlgTabItem)
DEFINE_FUNC0(GetOpenClipboardWindow)
DEFINE_FUNC1(GetParent)
DEFINE_FUNC2(GetPriorityClipboardFormat)
DEFINE_FUNC1(GetProcessDefaultLayout)
DEFINE_FUNC0(GetProcessWindowStation)
DEFINE_FUNC2(GetPropA)
DEFINE_FUNC2(GetPropW)
DEFINE_FUNC3(GetRawInputBuffer)
DEFINE_FUNC5(GetRawInputData)
DEFINE_FUNC4(GetRawInputDeviceInfoA)
DEFINE_FUNC4(GetRawInputDeviceInfoW)
DEFINE_FUNC3(GetRawInputDeviceList)
DEFINE_FUNC3(GetRegisteredRawInputDevices)
DEFINE_FUNC1(GetQueueStatus)
DEFINE_FUNC3(GetScrollBarInfo)
DEFINE_FUNC3(GetScrollInfo)
DEFINE_FUNC2(GetScrollPos)
DEFINE_FUNC4(GetScrollRange)
DEFINE_FUNC0(GetShellWindow)
DEFINE_FUNC2(GetSubMenu)
DEFINE_FUNC1(GetSysColor)
DEFINE_FUNC1(GetSysColorBrush)
DEFINE_FUNC2(GetSystemMenu)
DEFINE_FUNC1(GetSystemMetrics)
DEFINE_FUNC5(GetTabbedTextExtentA)
DEFINE_FUNC5(GetTabbedTextExtentW)
DEFINE_FUNC1(GetThreadDesktop)
DEFINE_FUNC2(GetTitleBarInfo)
DEFINE_FUNC1(GetTopWindow)
DEFINE_FUNC3(GetUpdateRect)
DEFINE_FUNC3(GetUpdateRgn)
DEFINE_FUNC5(GetUserObjectInformationA)
DEFINE_FUNC5(GetUserObjectInformationW)
DEFINE_FUNC5(GetUserObjectSecurity)
DEFINE_FUNC2(GetWindow)
DEFINE_FUNC1(GetWindowContextHelpId)
DEFINE_FUNC1(GetWindowDC)
DEFINE_FUNC2(GetWindowInfo)
//DEFINE_FUNC2(GetWindowLongA)
//DEFINE_FUNC2(GetWindowLongW)
DEFINE_FUNC3(GetWindowModuleFileName)
DEFINE_FUNC3(GetWindowModuleFileNameA)
DEFINE_FUNC3(GetWindowModuleFileNameW)
DEFINE_FUNC2(GetWindowPlacement)
DEFINE_FUNC2(GetWindowRect)
DEFINE_FUNC2(GetWindowRgn)
DEFINE_FUNC3(GetWindowTextA)
DEFINE_FUNC1(GetWindowTextLengthA)
DEFINE_FUNC1(GetWindowTextLengthW)
DEFINE_FUNC3(GetWindowTextW)
DEFINE_FUNC2(GetWindowThreadProcessId)
DEFINE_FUNC2(GetWindowWord)
DEFINE_FUNC_CB9(GrayStringA,3,3)
DEFINE_FUNC_CB9(GrayStringW,3,3)
DEFINE_FUNC1(HideCaret)
DEFINE_FUNC4(HiliteMenuItem)
DEFINE_FUNC2(ImpersonateDdeClientWindow)
DEFINE_FUNC0(InSendMessage)
DEFINE_FUNC1(InSendMessageEx)
DEFINE_FUNC3(InflateRect)
DEFINE_FUNC5(InsertMenuA)
DEFINE_FUNC4(InsertMenuItemA)
DEFINE_FUNC4(InsertMenuItemW)
DEFINE_FUNC5(InsertMenuW)
DEFINE_FUNC3(InternalGetWindowText)
DEFINE_FUNC3(IntersectRect)
DEFINE_FUNC3(InvalidateRect)
DEFINE_FUNC3(InvalidateRgn)
DEFINE_FUNC2(InvertRect)
DEFINE_FUNC1(IsCharAlphaA)
DEFINE_FUNC1(IsCharAlphaNumericA)
DEFINE_FUNC1(IsCharAlphaNumericW)
DEFINE_FUNC1(IsCharAlphaW)
DEFINE_FUNC1(IsCharLowerA)
DEFINE_FUNC1(IsCharLowerW)
DEFINE_FUNC1(IsCharUpperA)
DEFINE_FUNC1(IsCharUpperW)
DEFINE_FUNC2(IsChild)
DEFINE_FUNC1(IsClipboardFormatAvailable)
DEFINE_FUNC2(IsDialogMessage)
DEFINE_FUNC2(IsDialogMessageA)
DEFINE_FUNC2(IsDialogMessageW)
DEFINE_FUNC2(IsDlgButtonChecked)
DEFINE_FUNC1(IsGUIThread)
DEFINE_FUNC1(IsHungAppWindow)
DEFINE_FUNC1(IsIconic)
DEFINE_FUNC1(IsMenu)
DEFINE_FUNC1(IsRectEmpty)
DEFINE_FUNC1(IsWinEventHookInstalled)
DEFINE_FUNC1(IsWindow)
DEFINE_FUNC1(IsWindowEnabled)
DEFINE_FUNC1(IsWindowUnicode)
DEFINE_FUNC1(IsWindowVisible)
DEFINE_FUNC1(IsZoomed)
DEFINE_FUNC2(KillTimer)
DEFINE_FUNC_RES2(LoadAcceleratorsA)
DEFINE_FUNC_RES2(LoadAcceleratorsW)
DEFINE_FUNC_RES2(LoadBitmapA)
DEFINE_FUNC_RES2(LoadBitmapW)
DEFINE_FUNC_RES2(LoadCursorA)
DEFINE_FUNC1(LoadCursorFromFileA)
DEFINE_FUNC1(LoadCursorFromFileW)
DEFINE_FUNC_RES2(LoadCursorW)
DEFINE_FUNC_RES2(LoadIconA)
DEFINE_FUNC_RES2(LoadIconW)
DEFINE_FUNC_RES6(LoadImageA)
DEFINE_FUNC_RES6(LoadImageW)
DEFINE_FUNC2(LoadKeyboardLayoutA)
DEFINE_FUNC2(LoadKeyboardLayoutW)
DEFINE_FUNC_RES2(LoadMenuA)
DEFINE_FUNC1(LoadMenuIndirectA)
DEFINE_FUNC1(LoadMenuIndirectW)
DEFINE_FUNC_RES2(LoadMenuW)
DEFINE_FUNC_RES4(LoadStringA)
DEFINE_FUNC_RES4(LoadStringW)
DEFINE_FUNC1(LockSetForegroundWindow)
DEFINE_FUNC1(LockWindowUpdate)
DEFINE_FUNC0(LockWorkStation)
DEFINE_FUNC2(LookupIconIdFromDirectory)
DEFINE_FUNC5(LookupIconIdFromDirectoryEx)
DEFINE_FUNC2(MapDialogRect)
DEFINE_FUNC2(MapVirtualKeyA)
DEFINE_FUNC3(MapVirtualKeyExA)
DEFINE_FUNC3(MapVirtualKeyExW)
DEFINE_FUNC2(MapVirtualKeyW)
DEFINE_FUNC4(MapWindowPoints)
DEFINE_FUNC4(MenuItemFromPoint)
DEFINE_FUNC1(MessageBeep)
DEFINE_FUNC4(MessageBoxA)
DEFINE_FUNC5(MessageBoxExA)
DEFINE_FUNC5(MessageBoxExW)
DEFINE_FUNC1(MessageBoxIndirectA)
DEFINE_FUNC1(MessageBoxIndirectW)
DEFINE_FUNC4(MessageBoxW)
DEFINE_FUNC5(ModifyMenuA)
DEFINE_FUNC5(ModifyMenuW)
DEFINE_FUNC3(MonitorFromPoint)
DEFINE_FUNC2(MonitorFromRect)
DEFINE_FUNC2(MonitorFromWindow)
DEFINE_FUNC6(MoveWindow)
DEFINE_FUNC5(MsgWaitForMultipleObjects)
DEFINE_FUNC5(MsgWaitForMultipleObjectsEx)
DEFINE_FUNC4(NotifyWinEvent)
DEFINE_FUNC1(OemKeyScan)
DEFINE_FUNC2(OemToCharA)
DEFINE_FUNC3(OemToCharBuffA)
DEFINE_FUNC3(OemToCharBuffW)
DEFINE_FUNC2(OemToCharW)
DEFINE_FUNC3(OffsetRect)
DEFINE_FUNC1(OpenClipboard)
DEFINE_FUNC4(OpenDesktopA)
DEFINE_FUNC4(OpenDesktopW)
DEFINE_FUNC1(OpenIcon)
DEFINE_FUNC3(OpenInputDesktop)
DEFINE_FUNC3(OpenWindowStationA)
DEFINE_FUNC3(OpenWindowStationW)
DEFINE_FUNC3(PackDDElParam)
DEFINE_FUNC1(PaintDesktop)
DEFINE_FUNC5(PeekMessageA)
DEFINE_FUNC5(PeekMessageW)
//DEFINE_FUNC4(PostMessageA)
//DEFINE_FUNC4(PostMessageW)
DEFINE_FUNC1(PostQuitMessage)
DEFINE_FUNC4(PostThreadMessageA)
DEFINE_FUNC4(PostThreadMessageW)
DEFINE_FUNC3(PrintWindow)
DEFINE_FUNC8(PrivateExtractIconsA)
DEFINE_FUNC8(PrivateExtractIconsW)
DEFINE_FUNC3(PtInRect)
DEFINE_FUNC3(RealChildWindowFromPoint)
DEFINE_FUNC3(RealGetWindowClassA)
DEFINE_FUNC3(RealGetWindowClassW)
DEFINE_FUNC4(RedrawWindow)
DEFINE_FUNC1(RegisterClipboardFormatA)
DEFINE_FUNC1(RegisterClipboardFormatW)
DEFINE_FUNC3(RegisterDeviceNotificationA)
DEFINE_FUNC3(RegisterDeviceNotificationW)
DEFINE_FUNC3(RegisterPowerSettingNotification)
DEFINE_FUNC4(RegisterHotKey)
DEFINE_FUNC3(RegisterRawInputDevices)
DEFINE_FUNC1(RegisterWindowMessageA)
DEFINE_FUNC1(RegisterWindowMessageW)
DEFINE_FUNC0(ReleaseCapture)
DEFINE_FUNC2(ReleaseDC)
DEFINE_FUNC3(RemoveMenu)
DEFINE_FUNC2(RemovePropA)
DEFINE_FUNC2(RemovePropW)
DEFINE_FUNC1(ReplyMessage)
DEFINE_FUNC5(ReuseDDElParam)
DEFINE_FUNC2(ScreenToClient)
DEFINE_FUNC7(ScrollDC)
DEFINE_FUNC5(ScrollWindow)
DEFINE_FUNC8(ScrollWindowEx)
//DEFINE_FUNC5(SendDlgItemMessageA)
//DEFINE_FUNC5(SendDlgItemMessageW)
DEFINE_FUNC3(SendInput)
//DEFINE_FUNC4(SendMessageA)
DEFINE_FUNC_CB6(SendMessageCallbackA,5,4)
DEFINE_FUNC_CB6(SendMessageCallbackW,5,4)
DEFINE_FUNC7(SendMessageTimeoutA)
DEFINE_FUNC7(SendMessageTimeoutW)
//DEFINE_FUNC4(SendMessageW)
DEFINE_FUNC4(SendNotifyMessageA)
DEFINE_FUNC4(SendNotifyMessageW)
DEFINE_FUNC1(SetActiveWindow)
DEFINE_FUNC1(SetCapture)
DEFINE_FUNC1(SetCaretBlinkTime)
DEFINE_FUNC2(SetCaretPos)
DEFINE_FUNC2(SetClipboardData)
DEFINE_FUNC1(SetClipboardViewer)
DEFINE_FUNC1(SetCursor)
DEFINE_FUNC2(SetCursorPos)
DEFINE_FUNC1(SetDebugErrorLevel)
DEFINE_FUNC1(SetDeskWallpaper)
DEFINE_FUNC4(SetDlgItemInt)
DEFINE_FUNC3(SetDlgItemTextA)
DEFINE_FUNC3(SetDlgItemTextW)
DEFINE_FUNC1(SetDoubleClickTime)
DEFINE_FUNC1(SetFocus)
DEFINE_FUNC1(SetForegroundWindow)
DEFINE_FUNC1(SetKeyboardState)
DEFINE_FUNC2(SetLastErrorEx)
DEFINE_FUNC4(SetLayeredWindowAttributes)
DEFINE_FUNC2(SetMenu)
DEFINE_FUNC2(SetMenuContextHelpId)
DEFINE_FUNC3(SetMenuDefaultItem)
DEFINE_FUNC2(SetMenuInfo)
DEFINE_FUNC5(SetMenuItemBitmaps)
DEFINE_FUNC4(SetMenuItemInfoA)
DEFINE_FUNC4(SetMenuItemInfoW)
DEFINE_FUNC1(SetMessageExtraInfo)
DEFINE_FUNC1(SetMessageQueue)
DEFINE_FUNC2(SetParent)
DEFINE_FUNC1(SetProcessDefaultLayout)
DEFINE_FUNC1(SetProcessWindowStation)
DEFINE_FUNC3(SetPropA)
DEFINE_FUNC3(SetPropW)
DEFINE_FUNC5(SetRect)
DEFINE_FUNC1(SetRectEmpty)
DEFINE_FUNC4(SetScrollInfo)
DEFINE_FUNC4(SetScrollPos)
DEFINE_FUNC5(SetScrollRange)
DEFINE_FUNC1(SetShellWindow)
DEFINE_FUNC3(SetSysColors)
DEFINE_FUNC2(SetSystemCursor)
DEFINE_FUNC1(SetThreadDesktop)
DEFINE_FUNC4(SetUserObjectInformationA)
DEFINE_FUNC4(SetUserObjectInformationW)
DEFINE_FUNC3(SetUserObjectSecurity)
DEFINE_FUNC_CB7(SetWinEventHook,4,7)
DEFINE_FUNC2(SetWindowContextHelpId)
//DEFINE_FUNC3(SetWindowLongA)
//DEFINE_FUNC3(SetWindowLongW)
DEFINE_FUNC2(SetWindowPlacement)
DEFINE_FUNC7(SetWindowPos)
DEFINE_FUNC3(SetWindowRgn)
DEFINE_FUNC2(SetWindowTextA)
DEFINE_FUNC2(SetWindowTextW)
DEFINE_FUNC3(SetWindowWord)
DEFINE_FUNC_CB2(SetWindowsHookA,2,3)
DEFINE_FUNC_CB4(SetWindowsHookExA,2,3)
DEFINE_FUNC_CB4(SetWindowsHookExW,2,3)
DEFINE_FUNC_CB2(SetWindowsHookW,2,3)
DEFINE_FUNC1(ShowCaret)
DEFINE_FUNC1(ShowCursor)
DEFINE_FUNC2(ShowOwnedPopups)
DEFINE_FUNC3(ShowScrollBar)
DEFINE_FUNC2(ShowWindow)
DEFINE_FUNC2(ShowWindowAsync)
DEFINE_FUNC3(SubtractRect)
DEFINE_FUNC1(SwapMouseButton)
DEFINE_FUNC1(SwitchDesktop)
DEFINE_FUNC2(SwitchToThisWindow)
DEFINE_FUNC4(SystemParametersInfoA)
DEFINE_FUNC4(SystemParametersInfoW)
DEFINE_FUNC8(TabbedTextOutA)
DEFINE_FUNC8(TabbedTextOutW)
DEFINE_FUNC2(TileChildWindows)
DEFINE_FUNC5(TileWindows)
DEFINE_FUNC5(ToAscii)
DEFINE_FUNC6(ToAsciiEx)
DEFINE_FUNC6(ToUnicode)
DEFINE_FUNC7(ToUnicodeEx)
DEFINE_FUNC1(TrackMouseEvent)
DEFINE_FUNC7(TrackPopupMenu)
DEFINE_FUNC6(TrackPopupMenuEx)
DEFINE_FUNC3(TranslateAccelerator)
DEFINE_FUNC3(TranslateAcceleratorA)
DEFINE_FUNC3(TranslateAcceleratorW)
DEFINE_FUNC2(TranslateMDISysAccel)
DEFINE_FUNC1(TranslateMessage)
DEFINE_FUNC1(UnhookWinEvent)
DEFINE_FUNC_CB2(UnhookWindowsHook,2,2)
DEFINE_FUNC1(UnhookWindowsHookEx)
DEFINE_FUNC3(UnionRect)
DEFINE_FUNC1(UnloadKeyboardLayout)
DEFINE_FUNC4(UnpackDDElParam)
DEFINE_FUNC2(UnregisterClassA)
DEFINE_FUNC2(UnregisterClassW)
DEFINE_FUNC1(UnregisterDeviceNotification)
DEFINE_FUNC1(UnregisterPowerSettingNotification)
DEFINE_FUNC2(UnregisterHotKey)
DEFINE_FUNC9(UpdateLayeredWindow)
DEFINE_FUNC1(UpdateWindow)
DEFINE_FUNC3(UserHandleGrantAccess)
DEFINE_FUNC2(ValidateRect)
DEFINE_FUNC2(ValidateRgn)
DEFINE_FUNC1(VkKeyScanA)
DEFINE_FUNC2(VkKeyScanExA)
DEFINE_FUNC2(VkKeyScanExW)
DEFINE_FUNC1(VkKeyScanW)
DEFINE_FUNC2(WaitForInputIdle)
DEFINE_FUNC0(WaitMessage)
DEFINE_FUNC4(WinHelpA)
DEFINE_FUNC4(WinHelpW)
DEFINE_FUNC1(WindowFromDC)
DEFINE_FUNC2(WindowFromPoint)
DEFINE_FUNC4(keybd_event)
DEFINE_FUNC5(mouse_event)
DEFINE_FUNC3(wvsprintfA)
DEFINE_FUNC3(wvsprintfW)
//DEFINE_FUNC2(GetClassLongA)
//DEFINE_FUNC2(GetClassLongW)
//DEFINE_FUNC3(SetClassLongA)
//DEFINE_FUNC3(SetClassLongW)
DEFINE_FUNC3(SetClassWord)
DEFINE_FUNC2(GetClassWord)
