if ((uiNamespace getVariable ["uogm_endAttemptTime", -6]) + 5 <= time) exitWith {
	uiNamespace setVariable ["uogm_endAttemptTime", time];
	hint "Press again within 5 seconds to confirm.";
};

switch (true) do {
	case (!isNil "FW_fnc_EndMission"): {
		hint "Mission ending...";

		"The mission was ended by a GM" remoteExec ["FW_fnc_EndMission", 2];
	};

	case (!isNil "FNC_EndMission"): {
		hint "Mission ending...";

		"The mission was ended by a GM" remoteExec ["FNC_EndMission", 2];
	};

	default {
		hint "Mission ending...";

		["UO_GMEND", true] remoteExec ["BIS_fnc_endMission", 0];
	};
};