class RscText;
class RscTitle;
class RscEdit;
class RscButtonMenu;
class RscCombo;

class GVAR(submit_bugreport_sendBoxTitleBase): RscTitle {
    idc = -1;
    style = 0;
    text = "SUBMIT A MISSION BUG REPORT";
    colorBackground[] = {
        "(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
        "(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
        "(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
        "(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
    };
    x = QUOTE(gc_GCWEBSITEFUNCTIONS_TITLE_X);
    y = QUOTE(gc_GCWEBSITEFUNCTIONS_SUBMIT_BUGREPORT_TITLE_Y);
    w = QUOTE(gc_GCWEBSITEFUNCTIONS_TOTAL_W);
    h = QUOTE(gc_GCWEBSITEFUNCTIONS_ELEMENT_H);
};

class GVAR(submit_bugreport_sendBoxBGBase): RscText {
    idc = -1;
    colorBackground[] = {0, 0, 0, 0.700000};
    x = QUOTE(gc_GCWEBSITEFUNCTIONS_TITLE_X);
    y = QUOTE(gc_GCWEBSITEFUNCTIONS_SUBMIT_BUGREPORT_EDITBOX_BG_Y);
    w = QUOTE(gc_GCWEBSITEFUNCTIONS_TOTAL_W);
    h = QUOTE(gc_GCWEBSITEFUNCTIONS_EDITBOX_BG_H);
};

class GVAR(submit_bugreport_sendBoxBase): RscEdit {
    idc = -1;
    style = 16;
    autocomplete = "";
    shadow = 0;
    font = "EtelkaMonospacePro";
    sizeEx = "0.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
    onLoad = QUOTE(uiNamespace setVariable [ARR_2(QQGVAR(bugReportSendBoxCtrl), (_this select 0))]);
    onUnLoad = QUOTE(uiNamespace setVariable [ARR_2(QQGVAR(bugReportSendBoxCtrl), nil)]);
    onKeyDown = QUOTE(if ((_this select 1) isEqualTo 28 && !(_this select 2) && !(_this select 3) && !(_this select 4)) then {call FUNC(sendBugReport);};);
    x = QUOTE(gc_GCWEBSITEFUNCTIONS_EDITBOX_X);
    y = QUOTE(gc_GCWEBSITEFUNCTIONS_SUBMIT_BUGREPORT_EDITBOX_Y);
    w = QUOTE(gc_GCWEBSITEFUNCTIONS_EDITBOX_W);
    h = QUOTE(gc_GCWEBSITEFUNCTIONS_EDITBOX_H);
};

class GVAR(submit_bugreport_sendBoxButtonBase): RscButtonMenu {
    idc = gc_GCWEBSITEFUNCTIONS_IDC_SUBMIT_BUGREPORT_SENDBUTTON;
    text = "SEND BUG REPORT";
    action = QUOTE(call FUNC(sendBugReport));
    x = QUOTE(gc_GCWEBSITEFUNCTIONS_TITLE_X);
    y = QUOTE(gc_GCWEBSITEFUNCTIONS_SUBMIT_BUGREPORT_SENDBUTTON_Y);
    w = QUOTE(gc_GCWEBSITEFUNCTIONS_TOTAL_W);
    h = QUOTE(gc_GCWEBSITEFUNCTIONS_ELEMENT_H);
};

 