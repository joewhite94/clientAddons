class CfgPatches {
    class uo_briefingkit {
        units[]={};
        weapons[]={};
        requiredVersion=1.62;
        requiredAddons[]= {"cba_main"};
    };
};

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
