params ["_ctrl", "_key", "_shift", "_ctrl", "_alt"];

if (_key in [28, 156]) then {
	private _message = toLower(ctrlText ((_this select 0) displayCtrl 101));

	if (_message find "#" == 0) then {
		private _messageArray = _message splitString " ";

		_messageArray params["_command","_maxNumberString"];

		if (_command == "#lottery" && {serverCommandAvailable "#kick"}) then {
			private _maxNumber = parseNumber _maxNumberString;

			if (_maxNumber != 0) then {
				private _randomNumber = 1 + (floor(random _maxNumber));

				systemChat format["Lottery 1-%1!  Winner: %2", _maxNumber, _randomNumber];
			} else {
				systemChat "Incorrect formatting: Please use '#lottery <integer>'";
			};
		};
	};
};