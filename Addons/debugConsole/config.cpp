#include "script_component.hpp"

class CfgPatches {
	class ADDON {
		author = "Global Conflicts";
		name = QUOTE(ADDON);
		requiredVersion = 1.0;
		requiredAddons[] = {"gc_clientSide_main"};
		units[] = {};
		weapons[] = {};
	};
};

#include "CfgEventHandlers.hpp"
#include "RscTitles.hpp"

class CfgFunctions {
	class A3 {
		class Debug {
			class isDebugConsoleAllowed {
				file = "\x\gc_clientSide\addons\debugConsole\fn_isDebugConsoleAllowed.sqf";
			};
		};
	};
};

class CfgDebriefing {
	class GVAR(GMEnd) {
		subtitle="The mission was ended by a GM";
		pictureBackground="";
		picture="mil_objective";
		pictureColor[]={0.69999999,0.60000002,0,1};
	};
};
