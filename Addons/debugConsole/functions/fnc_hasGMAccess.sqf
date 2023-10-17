if (!isMultiplayer || isServer || (getPlayerUID player) in (GETMVAR(Admins,[])) || (toLower serverName) find "test" != -1 || (player getVariable ["administratorLevel", 0]) == 2) exitwith {true};
false;
