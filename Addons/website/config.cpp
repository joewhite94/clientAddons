class CfgPatches
{
	class gc_websiteFunctionsClient_gcWebsiteFunctions
	{
		author="W-Cephei";
		name="gc_websiteFunctionsClient_gcWebsiteFunctions";
		requiredVersion=1;
		requiredAddons[]=
		{
			"gc_websiteFunctionsClient_main",
			"A3_Ui_F"
		};
		units[]={};
		weapons[]={};
	};
};
class Extended_PostInit_EventHandlers
{
	class gc_websiteFunctionsClient_gcWebsiteFunctions
	{
		clientInit="call compile preprocessFileLineNumbers '\x\gc_websiteFunctionsClient\addons\gcWebsiteFunctions\XEH_postInit.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class gc_websiteFunctionsClient_gcWebsiteFunctions
	{
		clientInit="call compile preprocessFileLineNumbers '\x\gc_websiteFunctionsClient\addons\gcWebsiteFunctions\XEH_preClientInit.sqf'";
		init="call compile preprocessFileLineNumbers '\x\gc_websiteFunctionsClient\addons\gcWebsiteFunctions\XEH_preInit.sqf'";
	};
};
class Extended_PreStart_EventHandlers
{
	class gc_websiteFunctionsClient_gcWebsiteFunctions
	{
		init="call compile preprocessFileLineNumbers '\x\gc_websiteFunctionsClient\addons\gcWebsiteFunctions\XEH_preStart.sqf'";
	};
};
class RscText;
class RscTitle;
class RscEdit;
class RscButtonMenu;
class RscCombo;
class gc_gcWebsiteFunctions_submit_review_sendBoxTitleBase: RscTitle
{
	idc=-1;
	style=0;
	text="SUBMIT A MISSION REVIEW";
	colorBackground[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
	};
	x="(safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)) + 24 * (((safezoneW / safezoneH) min 1.2) / 40)";
	y="(1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY))";
	w="(15 * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="(1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
};
class gc_gcWebsiteFunctions_submit_review_sendBoxBGBase: RscText
{
	idc=-1;
	colorBackground[]={0,0,0,0.69999999};
	x="((safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)) + 24 * (((safezoneW / safezoneH) min 1.2) / 40))";
	y="((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))";
	w="(15 * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55))";
};
class gc_gcWebsiteFunctions_submit_review_sendBoxBase: RscEdit
{
	idc=-1;
	style=16;
	autocomplete="";
	shadow=0;
	font="EtelkaMonospacePro";
	sizeEx="0.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	onLoad="uiNamespace setVariable [""gc_websiteFunctionsClient_gcWebsiteFunctions_reviewSendBoxCtrl"", (_this select 0)]";
	onUnLoad="uiNamespace setVariable [""gc_websiteFunctionsClient_gcWebsiteFunctions_reviewSendBoxCtrl"", nil]";
	onKeyDown="if ((_this select 1) isEqualTo 28 && !(_this select 2) && !(_this select 3) && !(_this select 4)) then {call gc_websiteFunctionsClient_gcWebsiteFunctions_fnc_sendReview;};";
	x="(((safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)) + 24 * (((safezoneW / safezoneH) min 1.2) / 40)) + (0.5 * (((safezoneW / safezoneH) min 1.2) / 40)))";
	y="(((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)))";
	w="((15 * (((safezoneW / safezoneH) min 1.2) / 40)) - 2 * (0.5 * (((safezoneW / safezoneH) min 1.2) / 40)))";
	h="(((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) - 2 * ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)))";
};
class gc_gcWebsiteFunctions_submit_review_sendBoxButtonBase: RscButtonMenu
{
	idc=33500;
	text="SEND REVIEW";
	action="call gc_websiteFunctionsClient_gcWebsiteFunctions_fnc_sendReview";
	x="((safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)) + 24 * (((safezoneW / safezoneH) min 1.2) / 40))";
	y="(((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))";
	w="(15 * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="(1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
};
class RscText;
class RscTitle;
class RscEdit;
class RscButtonMenu;
class RscCombo;
class gc_gcWebsiteFunctions_submit_rating_sendBoxTitleBase: RscTitle
{
	idc=-1;
	style=0;
	text="SUBMIT A MISSION RATING";
	colorBackground[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
	};
	x="((safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)) + 24 * (((safezoneW / safezoneH) min 1.2) / 40))";
	y="((((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)))";
	w="(15 * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="(1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
};
class gc_gcWebsiteFunctions_submit_rating_sendBoxListboxBase: RscCombo
{
	idc=-1;
	font="RobotoCondensed";
	sizeEx=0.035;
	rowHeight=10;
	onLoad="_this call gc_websiteFunctionsClient_gcWebsiteFunctions_fnc_initListbox";
	onUnLoad="uiNamespace setVariable [""gc_websiteFunctionsClient_gcWebsiteFunctions_sendBoxListboxCtrl"", nil]";
	onLBSelChanged="_this call gc_websiteFunctionsClient_gcWebsiteFunctions_fnc_onRecipientChanged";
	x="((safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)) + 24 * (((safezoneW / safezoneH) min 1.2) / 40))";
	y="(((((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))";
	w="(15 * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="(1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
};
class gc_gcWebsiteFunctions_submit_rating_sendBoxButtonBase: RscButtonMenu
{
	idc=33501;
	text="SEND RATING";
	action="call gc_websiteFunctionsClient_gcWebsiteFunctions_fnc_sendRating";
	x="((safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)) + 24 * (((safezoneW / safezoneH) min 1.2) / 40))";
	y="((((((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))";
	w="(15 * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="(1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
};
class RscText;
class RscTitle;
class RscEdit;
class RscButtonMenu;
class RscCombo;
class gc_gcWebsiteFunctions_submit_bugreport_sendBoxTitleBase: RscTitle
{
	idc=-1;
	style=0;
	text="SUBMIT A MISSION BUG REPORT";
	colorBackground[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
	};
	x="((safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)) + 24 * (((safezoneW / safezoneH) min 1.2) / 40))";
	y="(((((((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)))";
	w="(15 * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="(1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
};
class gc_gcWebsiteFunctions_submit_bugreport_sendBoxBGBase: RscText
{
	idc=-1;
	colorBackground[]={0,0,0,0.69999999};
	x="((safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)) + 24 * (((safezoneW / safezoneH) min 1.2) / 40))";
	y="((((((((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))";
	w="(15 * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55))";
};
class gc_gcWebsiteFunctions_submit_bugreport_sendBoxBase: RscEdit
{
	idc=-1;
	style=16;
	autocomplete="";
	shadow=0;
	font="EtelkaMonospacePro";
	sizeEx="0.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	onLoad="uiNamespace setVariable [""gc_websiteFunctionsClient_gcWebsiteFunctions_bugReportSendBoxCtrl"", (_this select 0)]";
	onUnLoad="uiNamespace setVariable [""gc_websiteFunctionsClient_gcWebsiteFunctions_bugReportSendBoxCtrl"", nil]";
	onKeyDown="if ((_this select 1) isEqualTo 28 && !(_this select 2) && !(_this select 3) && !(_this select 4)) then {call gc_websiteFunctionsClient_gcWebsiteFunctions_fnc_sendBugReport;};";
	x="(((safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)) + 24 * (((safezoneW / safezoneH) min 1.2) / 40)) + (0.5 * (((safezoneW / safezoneH) min 1.2) / 40)))";
	y="(((((((((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)))";
	w="((15 * (((safezoneW / safezoneH) min 1.2) / 40)) - 2 * (0.5 * (((safezoneW / safezoneH) min 1.2) / 40)))";
	h="(((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) - 2 * ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)))";
};
class gc_gcWebsiteFunctions_submit_bugreport_sendBoxButtonBase: RscButtonMenu
{
	idc=33502;
	text="SEND BUG REPORT";
	action="call gc_websiteFunctionsClient_gcWebsiteFunctions_fnc_sendBugReport";
	x="((safeZoneX + safeZoneW - ((safezoneW / safezoneH) min 1.2)) + 24 * (((safezoneW / safezoneH) min 1.2) / 40))";
	y="(((((((((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55))) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))";
	w="(15 * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="(1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
};
class RscStandardDisplay;
class RscDisplayMPInterrupt: RscStandardDisplay
{
	class controls
	{
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxTitle: gc_gcWebsiteFunctions_submit_bugreport_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxBG: gc_gcWebsiteFunctions_submit_bugreport_sendBoxBGBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBox: gc_gcWebsiteFunctions_submit_bugreport_sendBoxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxButton: gc_gcWebsiteFunctions_submit_bugreport_sendBoxButtonBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxTitle: gc_gcWebsiteFunctions_submit_review_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxBG: gc_gcWebsiteFunctions_submit_review_sendBoxBGBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBox: gc_gcWebsiteFunctions_submit_review_sendBoxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxButton: gc_gcWebsiteFunctions_submit_review_sendBoxButtonBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxTitle: gc_gcWebsiteFunctions_submit_rating_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxListbox: gc_gcWebsiteFunctions_submit_rating_sendBoxListboxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxButton: gc_gcWebsiteFunctions_submit_rating_sendBoxButtonBase
		{
		};
	};
};
class RscDisplayInterruptEditorPreview: RscStandardDisplay
{
	class controls
	{
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxTitle: gc_gcWebsiteFunctions_submit_bugreport_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxBG: gc_gcWebsiteFunctions_submit_bugreport_sendBoxBGBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBox: gc_gcWebsiteFunctions_submit_bugreport_sendBoxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxButton: gc_gcWebsiteFunctions_submit_bugreport_sendBoxButtonBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxTitle: gc_gcWebsiteFunctions_submit_review_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxBG: gc_gcWebsiteFunctions_submit_review_sendBoxBGBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBox: gc_gcWebsiteFunctions_submit_review_sendBoxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxButton: gc_gcWebsiteFunctions_submit_review_sendBoxButtonBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxTitle: gc_gcWebsiteFunctions_submit_rating_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxListbox: gc_gcWebsiteFunctions_submit_rating_sendBoxListboxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxButton: gc_gcWebsiteFunctions_submit_rating_sendBoxButtonBase
		{
		};
	};
};
class RscDisplayInterrupt: RscStandardDisplay
{
	class controls
	{
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxTitle: gc_gcWebsiteFunctions_submit_bugreport_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxBG: gc_gcWebsiteFunctions_submit_bugreport_sendBoxBGBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBox: gc_gcWebsiteFunctions_submit_bugreport_sendBoxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxButton: gc_gcWebsiteFunctions_submit_bugreport_sendBoxButtonBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxTitle: gc_gcWebsiteFunctions_submit_review_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxBG: gc_gcWebsiteFunctions_submit_review_sendBoxBGBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBox: gc_gcWebsiteFunctions_submit_review_sendBoxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxButton: gc_gcWebsiteFunctions_submit_review_sendBoxButtonBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxTitle: gc_gcWebsiteFunctions_submit_rating_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxListbox: gc_gcWebsiteFunctions_submit_rating_sendBoxListboxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxButton: gc_gcWebsiteFunctions_submit_rating_sendBoxButtonBase
		{
		};
	};
};
class RscDisplayInterruptEditor3D: RscStandardDisplay
{
	class controls
	{
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxTitle: gc_gcWebsiteFunctions_submit_bugreport_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxBG: gc_gcWebsiteFunctions_submit_bugreport_sendBoxBGBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBox: gc_gcWebsiteFunctions_submit_bugreport_sendBoxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxButton: gc_gcWebsiteFunctions_submit_bugreport_sendBoxButtonBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxTitle: gc_gcWebsiteFunctions_submit_review_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxBG: gc_gcWebsiteFunctions_submit_review_sendBoxBGBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBox: gc_gcWebsiteFunctions_submit_review_sendBoxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxButton: gc_gcWebsiteFunctions_submit_review_sendBoxButtonBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxTitle: gc_gcWebsiteFunctions_submit_rating_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxListbox: gc_gcWebsiteFunctions_submit_rating_sendBoxListboxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxButton: gc_gcWebsiteFunctions_submit_rating_sendBoxButtonBase
		{
		};
	};
};
class RscDisplayMovieInterrupt: RscStandardDisplay
{
	class controls
	{
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxTitle: gc_gcWebsiteFunctions_submit_bugreport_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxBG: gc_gcWebsiteFunctions_submit_bugreport_sendBoxBGBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBox: gc_gcWebsiteFunctions_submit_bugreport_sendBoxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_bugreport_sendBoxButton: gc_gcWebsiteFunctions_submit_bugreport_sendBoxButtonBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxTitle: gc_gcWebsiteFunctions_submit_review_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxBG: gc_gcWebsiteFunctions_submit_review_sendBoxBGBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBox: gc_gcWebsiteFunctions_submit_review_sendBoxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_review_sendBoxButton: gc_gcWebsiteFunctions_submit_review_sendBoxButtonBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxTitle: gc_gcWebsiteFunctions_submit_rating_sendBoxTitleBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxListbox: gc_gcWebsiteFunctions_submit_rating_sendBoxListboxBase
		{
		};
		class gc_gcWebsiteFunctions_submit_rating_sendBoxButton: gc_gcWebsiteFunctions_submit_rating_sendBoxButtonBase
		{
		};
	};
};
class RscStructuredText;
class RscTitles
{
	class gc_websiteFunctionsClient_gcWebsiteFunctions_rscCustomChat
	{
		duration=20;
		enableSimulation=1;
		fadeIn=0.2;
		fadeOut=0.2;
		idd=-1;
		movingEnable=0;
		onLoad="uiNamespace setVariable [""gc_websiteFunctionsClient_gcWebsiteFunctions_rscCustomChat"", _this select 0]";
		onUnload="uiNamespace setVariable [""gc_websiteFunctionsClient_gcWebsiteFunctions_rscCustomChat"", nil]";
		class controls
		{
			class chatBox: RscStructuredText
			{
				idc="gc_GCWEBSITEFUNCTIONS_IDC_CUSTOMCHATTEXT";
				colorBackground[]={0,0,0,0.30000001};
				font="RobotoCondensed";
				shadow=1;
				shadowColor[]={0,0,0,0.5};
				size="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
				x="(safeZoneW + 1 * (((safezoneW / safezoneH) min 1.2) / 40))";
				y="(safezoneY + safezoneH - 10.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				w="(20 *(((safezoneW / safezoneH) min 1.2) / 40))";
				h="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			};
		};
	};
};
