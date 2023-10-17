class CfgPatches
{
	class grad_adminMessages_adminMessages
	{
		author="$STR_grad_Author";
		name="grad_adminMessages_adminMessages";
		url="$STR_grad_URL";
		requiredVersion=1;
		requiredAddons[]=
		{
			"grad_adminMessages_main",
			"A3_Ui_F"
		};
		units[]={};
		weapons[]={};
		version="1.1.1.0";
		versionStr="1.1.1.0";
		versionAr[]={1,1,1,0};
		authors[]=
		{
			"McDiod"
		};
	};
};
class Extended_PostInit_EventHandlers
{
	class grad_adminMessages_adminMessages
	{
		serverInit="call compile preprocessFileLineNumbers '\x\grad_adminMessages\addons\adminMessages\XEH_postInit.sqf'";
	};
};
class Extended_PreInit_EventHandlers
{
	class grad_adminMessages_adminMessages
	{
		clientInit="call compile preprocessFileLineNumbers '\x\grad_adminMessages\addons\adminMessages\XEH_preClientInit.sqf'";
		init="call compile preprocessFileLineNumbers '\x\grad_adminMessages\addons\adminMessages\XEH_preInit.sqf'";
	};
};
class Extended_PreStart_EventHandlers
{
	class grad_adminMessages_adminMessages
	{
		init="call compile preprocessFileLineNumbers '\x\grad_adminMessages\addons\adminMessages\XEH_preStart.sqf'";
	};
};
class RscText;
class RscTitle;
class RscEdit;
class RscButtonMenu;
class RscCombo;
class ga_adminMessages_sendBoxTitleBase: RscTitle
{
	idc=-1;
	style=0;
	onLoad="_this call grad_adminMessages_adminMessages_fnc_setTitle";
	text="ERROR ";
	colorBackground[]=
	{
		"(profilenamespace getvariable ['GUI_BCG_RGB_R',0.13])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_G',0.54])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_B',0.21])",
		"(profilenamespace getvariable ['GUI_BCG_RGB_A',0.8])"
	};
	x="(1 *  (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX))";
	y="(1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY))";
	w="(15 * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="(1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
};
class ga_adminMessages_sendBoxBGBase: RscText
{
	idc=-1;
	colorBackground[]={0,0,0,0.69999999};
	x="(1 *  (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX))";
	y="((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))";
	w="(15 * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55))";
};
class ga_adminMessages_sendBoxBase: RscEdit
{
	idc=-1;
	style=16;
	autocomplete="";
	shadow=0;
	font="EtelkaMonospacePro";
	sizeEx="0.7 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)";
	onLoad="uiNamespace setVariable [""grad_adminMessages_adminMessages_sendBoxCtrl"", (_this select 0)]";
	onUnLoad="uiNamespace setVariable [""grad_adminMessages_adminMessages_sendBoxCtrl"", nil]";
	onKeyDown="if ((_this select 1) isEqualTo 28 && !(_this select 2) && !(_this select 3) && !(_this select 4)) then {call grad_adminMessages_adminMessages_fnc_sendMessage;};";
	x="((1 *  (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX)) + (0.5 * (((safezoneW / safezoneH) min 1.2) / 40)))";
	y="(((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)))";
	w="((15 * (((safezoneW / safezoneH) min 1.2) / 40)) - 2 * (0.5 * (((safezoneW / safezoneH) min 1.2) / 40)))";
	h="(((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) - 2 * ((0.5 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)))";
};
class ga_adminMessages_sendBoxButtonBase: RscButtonMenu
{
	idc=33500;
	onLoad="_this call grad_adminMessages_adminMessages_fnc_setSendButtonPosition";
	onUnLoad="uiNamespace setVariable [""grad_adminMessages_adminMessages_sendBoxButtonCtrl"", nil]";
	text="$STR_grad_ADMINMESSAGES_SENDBOXBUTTON";
	action="call grad_adminMessages_adminMessages_fnc_sendMessage";
	x="(1 *  (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX))";
	y="(((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))";
	w="(15 * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="(1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
};
class ga_adminMessages_sendBoxListboxBase: RscCombo
{
	idc=-1;
	font="EtelkaMonospacePro";
	rowHeight=10;
	onLoad="_this call grad_adminMessages_adminMessages_fnc_initListbox";
	onUnLoad="uiNamespace setVariable [""grad_adminMessages_adminMessages_sendBoxListboxCtrl"", nil]";
	onLBSelChanged="_this call grad_adminMessages_adminMessages_fnc_onRecipientChanged";
	x="(1 *  (((safezoneW / safezoneH) min 1.2) / 40) + (safezoneX))";
	y="(((1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) + (safezoneY)) + (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) + ((8 * (1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))) / ((getResolution select 5)/0.55)) + (0.1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25)))";
	w="(15 * (((safezoneW / safezoneH) min 1.2) / 40))";
	h="(1 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
};
class RscStandardDisplay;
class RscDisplayMPInterrupt: RscStandardDisplay
{
	class controls
	{
		class ga_adminMessages_sendBoxTitle: ga_adminMessages_sendBoxTitleBase
		{
		};
		class ga_adminMessages_sendBoxBG: ga_adminMessages_sendBoxBGBase
		{
		};
		class ga_adminMessages_sendBox: ga_adminMessages_sendBoxBase
		{
		};
		class ga_adminMessages_sendBoxButton: ga_adminMessages_sendBoxButtonBase
		{
		};
		class ga_adminMessages_sendBoxListBox: ga_adminMessages_sendBoxListboxBase
		{
		};
	};
};
class RscDisplayInterruptEditorPreview: RscStandardDisplay
{
	class controls
	{
		class ga_adminMessages_sendBoxTitle: ga_adminMessages_sendBoxTitleBase
		{
		};
		class ga_adminMessages_sendBoxBG: ga_adminMessages_sendBoxBGBase
		{
		};
		class ga_adminMessages_sendBox: ga_adminMessages_sendBoxBase
		{
		};
		class ga_adminMessages_sendBoxButton: ga_adminMessages_sendBoxButtonBase
		{
		};
		class ga_adminMessages_sendBoxListBox: ga_adminMessages_sendBoxListboxBase
		{
		};
	};
};
class RscDisplayInterrupt: RscStandardDisplay
{
	class controls
	{
		class ga_adminMessages_sendBoxTitle: ga_adminMessages_sendBoxTitleBase
		{
		};
		class ga_adminMessages_sendBoxBG: ga_adminMessages_sendBoxBGBase
		{
		};
		class ga_adminMessages_sendBox: ga_adminMessages_sendBoxBase
		{
		};
		class ga_adminMessages_sendBoxButton: ga_adminMessages_sendBoxButtonBase
		{
		};
		class ga_adminMessages_sendBoxListBox: ga_adminMessages_sendBoxListboxBase
		{
		};
	};
};
class RscDisplayInterruptEditor3D: RscStandardDisplay
{
	class controls
	{
		class ga_adminMessages_sendBoxTitle: ga_adminMessages_sendBoxTitleBase
		{
		};
		class ga_adminMessages_sendBoxBG: ga_adminMessages_sendBoxBGBase
		{
		};
		class ga_adminMessages_sendBox: ga_adminMessages_sendBoxBase
		{
		};
		class ga_adminMessages_sendBoxButton: ga_adminMessages_sendBoxButtonBase
		{
		};
		class ga_adminMessages_sendBoxListBox: ga_adminMessages_sendBoxListboxBase
		{
		};
	};
};
class RscDisplayMovieInterrupt: RscStandardDisplay
{
	class controls
	{
		class ga_adminMessages_sendBoxTitle: ga_adminMessages_sendBoxTitleBase
		{
		};
		class ga_adminMessages_sendBoxBG: ga_adminMessages_sendBoxBGBase
		{
		};
		class ga_adminMessages_sendBox: ga_adminMessages_sendBoxBase
		{
		};
		class ga_adminMessages_sendBoxButton: ga_adminMessages_sendBoxButtonBase
		{
		};
		class ga_adminMessages_sendBoxListBox: ga_adminMessages_sendBoxListboxBase
		{
		};
	};
};
class RscStructuredText;
class RscTitles
{
	class grad_adminMessages_adminMessages_rscCustomChat
	{
		duration=20;
		enableSimulation=1;
		fadeIn=0.2;
		fadeOut=0.2;
		idd=-1;
		movingEnable=0;
		onLoad="uiNamespace setVariable [""grad_adminMessages_adminMessages_rscCustomChat"", _this select 0]";
		onUnload="uiNamespace setVariable [""grad_adminMessages_adminMessages_rscCustomChat"", nil]";
		class controls
		{
			class chatBox: RscStructuredText
			{
				idc=33601;
				colorBackground[]={0,0,0,0.30000001};
				font="RobotoCondensed";
				shadow=1;
				shadowColor[]={0,0,0,0.5};
				size="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
				x="(safezoneX + 1 * (((safezoneW / safezoneH) min 1.2) / 40))";
				y="(safezoneY + safezoneH - 10.5 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))";
				w="(20 *(((safezoneW / safezoneH) min 1.2) / 40))";
				h="(((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 0.8)";
			};
		};
	};
};
