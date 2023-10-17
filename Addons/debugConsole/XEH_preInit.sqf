#include "script_component.hpp"
#include "\a3\editor_f\Data\Scripts\dikCodes.h"

ADDON = false;

PREP_RECOMPILE_START;
#include "XEH_PREP.hpp"
PREP_RECOMPILE_END;

if (isServer) then {
	GVAR(Admins) = ["_SP_PLAYER_"];

	[{!isNil "UO_admins_userconfig"}, {
		GVAR(Admins) append UO_admins_userconfig;
		publicVariable QGVAR(Admins);
	}, [], 15, {
		publicVariable QGVAR(Admins);
	}] call CBA_fnc_waitUntilAndExecute;
};

ADDON = true;
