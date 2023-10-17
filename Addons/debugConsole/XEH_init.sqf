[] spawn {
	if (isServer) then {
		if (is3DEN || is3DENMultiplayer) exitwith {};
		sleep 5;
		while {true} do {
			{
				_admin = admin owner _x;
				if (_x getVariable ["administratorLevel", 0] != _admin) then {
					_x setVariable ["administratorLevel", _admin, true];
				};
			} forEach playableUnits;

			sleep 10;
		};
	};
};
