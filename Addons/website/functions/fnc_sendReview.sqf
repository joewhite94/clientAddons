#include "script_component.hpp"

private _hasSentReview = GETMVAR(hasSentReview,false);
private _sendingInProgress = GETMVAR(sendingInProgress,false);

if (_hasSentReview) exitWith {
	playSoundUI ["a3\sounds_f\debugsound.wss"];
	[] spawn {
		[{
			["GC Mission Review ", "You already submited a review.", {true}] call ace_common_fnc_errorMessage;
		}, [] ] call CBA_fnc_execNextFrame;
	};
};

if (_sendingInProgress) exitWith {
	playSoundUI ["a3\sounds_f\debugsound.wss"];
	[] spawn {
		[{
			["GC Mission Review ", "Please wait, your previous request is being processed.", {true}] call ace_common_fnc_errorMessage;
		}, [] ] call CBA_fnc_execNextFrame;
	};
};

private _editBox = uiNamespace getVariable [QGVAR(reviewSendBoxCtrl), controlNull];

if (isNull _editBox) exitWith {};

SETMVAR(missionReviewText,""); // resets the text
private _message = ctrlText _editBox;
if (_message == "") exitWith {};
SETMVAR(missionReviewText, _message); // sets the text to the player vars so I can get it inside the callback of the BIS_fnc_3DENShowMessage

private _isSpectating = ["IsSpectating"] call BIS_fnc_EGSpectator;
private _missionDisplay = if (_isSpectating) then {
	["GetDisplay"] call BIS_fnc_EGSpectator
} else {
	findDisplay 49
};

[_missionDisplay] spawn {
	params ["_missionDisplay"];
	[{
		params ["_missionDisplay"];
		[
			"You won't be able to send a new review during this playthrough of this mission.",
			"Are you sure?",
			[
				"Yes",
				{
					BIS_Message_Confirmed = true;
					SETMVAR(sendingInProgress,true);
					private _message = GETMVAR(missionReviewText,"");
					["GC_serverSide_website_onSubmitReview", [_message, player]] call CBA_fnc_serverEvent;
				}
			],
			[
				"No",
				{
					BIS_Message_Confirmed = false
				}
			],
			"x\gc_clientSide\addons\website\data\gc_logo.paa",
			_missionDisplay
		] call BIS_fnc_3DENShowMessage;
	}, [_missionDisplay] ] call CBA_fnc_execNextFrame;
};

playSoundUI ["a3\sounds_f\sfx\beep_target.wss"];