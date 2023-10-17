#include "script_component.hpp"

params [["_ctrl",controlNull]];

private _text = if ([] call FUNC(isAdminOrZeus)) then {
    localize "STR_GC_ADMINMESSAGES_SENDBOXTITLEADMIN"
} else {
    localize "STR_GC_ADMINMESSAGES_SENDBOXTITLEPLAYER"
};

_ctrl ctrlSetText _text
