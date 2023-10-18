#include "script_component.hpp"

private _sendingInProgress = GETMVAR(sendingInProgress,false);

if (_sendingInProgress) exitWith {
	playSoundUI ["a3\sounds_f\debugsound.wss"];
	[] spawn {
		[{
			["GC Mission Rating", "Please wait, your previous request is being processed.", {true}] call ace_common_fnc_errorMessage;
		}, [] ] call CBA_fnc_execNextFrame;
	};
};

private _listbox = uiNamespace getVariable [QGVAR(sendBoxListboxCtrl), controlNull];

private _lbCurSel = lbCurSel _listbox;
private _rating = _listbox lbData _lbCurSel;
private _lbText = _listbox lbText _lbCurSel;
private _receiveConditionParams = [];

SETMVAR(missionRating,_rating); // sets the text to the player vars so I can get it inside the callback of the BIS_fnc_3DENShowMessage

if (_rating == "negative") then {
	private _isSpectating = ["IsSpectating"] call BIS_fnc_EGSpectator;
	private _missionDisplay = if (_isSpectating) then {
		findDisplay 49
	} else {
		[] call BIS_fnc_displayMission 
	};
	[_missionDisplay] spawn {
		params ["_missionDisplay"];
		[{
			params ["_missionDisplay"];
			[
				"Please consider writing a constructive review for the mission maker.",
				"You are sending a negative rating",
				[
					"Confirm",
					{
						BIS_Message_Confirmed = true;
						SETMVAR(sendingInProgress,true);
						private _rating = GETMVAR(missionRating,"");
						["GC_serverSide_website_onSubmitRating", [_rating, player]] call CBA_fnc_serverEvent;
					}
				],
				[
					"No",
					{
						BIS_Message_Confirmed = false
					}
				],
				"\x\gc_websiteFunctionsClient\addons\gcWebsiteFunctions\data\gc_logo.paa",
				_missionDisplay
			] call BIS_fnc_3DENShowMessage;
		}, [_missionDisplay]] call CBA_fnc_execNextFrame;
	};
} else {
	SETMVAR(sendingInProgress,true);
	[QGVAR(onSubmitRating), [_rating, player]] call CBA_fnc_serverEvent;
};



