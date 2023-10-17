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
