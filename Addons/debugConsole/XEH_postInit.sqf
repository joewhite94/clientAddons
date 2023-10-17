#include "\a3\editor_f\Data\Scripts\dikCodes.h"



 


UO_debugConsole = false;

if (hasInterface) then {
	[] spawn {
		waitUntil {!isNull player && {!isNil "UO_admins"}};

		player setVariable ["uogm_Spectator", false];
		player setVariable ["uogm_cbStates", [0,0,0,0,0]];
		player setVariable ["uogm_mapMonitor", false];

		//Add player settings
		["uogm_mapMon_enableGroupID", "CHECKBOX", "Enable Group ID (Map Monitor)", "United Operations", [true], nil, {
			params ["_value"];
			player setVariable ["uogm_mapMon_enableGroupID", _value];
		}] call CBA_Settings_fnc_init;
		["uogm_interfaceStyle", "CHECKBOX", "ACE Interaction Option", "United Operations", [true], nil, {
			params ["_value"];
			player setVariable ["uogm_interfaceStyle", _value];
		}] call CBA_Settings_fnc_init;

		_action = ["uo_admin_openGUI", "Open GM Menu", "", {createDialog "UOGM";}, {(call uo_fnc_hasGMAccess) && (player getVariable "uogm_interfaceStyle")}] call ace_interact_menu_fnc_createAction;
		[player, 1, ["ACE_SelfActions"], _action] call ace_interact_menu_fnc_addActionToObject;



		//Adding a button
		["United Operations", "uogm_openGUI", "Open GM Console", {if (call uo_fnc_hasGMAccess) then {createDialog "UOGM";}}, {}, [DIK_APPS, [false, false, false]]] call CBA_fnc_addKeybind;

		if (call uo_fnc_hasGMAccess) then {
			[missionNamespace,"OnGameInterrupt",{
				params ["_display"];
				private _ctrlHistory = _display ctrlCreate ["RscButtonMenu",-1];
				_ctrlHistory ctrlSetText "Open GM Menu";
				_ctrlHistory ctrlSetFont FONT_SEMIBOLD;
				_ctrlHistory ctrlSetBackgroundColor [0.73, 0.24, 0.11, 1];
				_ctrlHistory ctrlSetPosition [
					safezoneX + 0.011 * safeZoneW,
					safeZoneY + 0.75,
					0.45,0.04
					];
				_ctrlHistory ctrlAddEventHandler ["ButtonClick",{
					if (call uo_fnc_hasGMAccess) then {createDialog "UOGM";}
				}];
				_ctrlHistory ctrlCommit 0;

			}] call BIS_fnc_addScriptedEventHandler;




			[true, true] call acre_api_fnc_godModeConfigureAccess;

			private _gmPlayers = allPlayers select {
				(getPlayerUID _x) in (GETMVAR(Admins,[]))
			};
			[_gmPlayers, 2] call acre_api_fnc_godModeModifyGroup;

			addMissionEventHandler ["PlayerConnected",{
				params ["_id", "_uid", "_name", "_jip", "_owner", "_idstr"];

				if (_uid in (GETMVAR(Admins,[])) && {_jip}) then {
					[[_uid], 2, 1] call acre_api_fnc_godModeModifyGroup;
				};
			}];
		};

		sleep 10;

		while {true} do {
			_isGM = call uo_fnc_hasGMAccess;
			uiNamespace setVariable ["uogm_displayDebug", _isGM];

			if (!((player getVariable ["uogm_isGM", false]) isEqualTo _isGM)) then {
				player setVariable ["uogm_isGM", _isGM, true];
			};

			sleep 20;
		};
	};
};

UO_debugConsole = true;