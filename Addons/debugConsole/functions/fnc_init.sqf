disableSerialization;
params ["_unit", "_display"];
UO_itemList = [
    ["ItemMap", "Map"],
    ["ItemCompass", "Compass"],
    ["ItemWatch", "Watch"],
	["ACE_MapTools", "Map Tools"],
	["binocular", "Binocular"],
	["ACE_Vector", "Vector"],
	["ACE_microDAGR", "Micro DAGR"],
    ["NVGoggles", "N.V Goggles"],
	["ACE_Flashlight_XL50", "Map Flashlight"],
	["ACE_IR_Strobe_Item", "IR Strobe"],
	["ACE_CableTie", "Cable Ties"],
	["ACE_EntrenchingTool", "E-Tool"],
	["ACE_Fortify", "ACE Fortify"],
	["ACE_wirecutter", "Wirecutters"],
	["DemoCharge_Remote_Mag", "Demo Charges"],
	["ACE_Clacker", "Clacker"],
	["ACE_DefusalKit", "Defuse kit"],
	["ACE_RangeCard", "ACE Range card"],
	["ACE_artilleryTable", "ACE Artillery Table"],
	["ACE_RangeTable_82mm", "ACE 82mm Table"],
    ["ACRE_PRC343", "AN/PRC-343"],
    ["ACRE_PRC148", "AN/PRC-148"],
	["ACRE_PRC152", "AN/PRC-152"],
	["ACRE_PRC77", "AN/PRC-77"],
    ["ACRE_PRC117F", "AN/PRC-117F"],
	["ACRE_SEM52SL", "SEM52"],
	["ACRE_SEM70", "SEM70"],
	["ACE_fieldDressing", "Field Dressing"],
	["ACE_elasticBandage", "Elastic Bandage"],
	["ACE_packingBandage", "Packing Bandage"],
	["ACE_quikclot", "Quickclot"],
	["ACE_morphine", "Morphine"],
    ["ACE_epinephrine", "Epinephrine"],
	["ACE_adenosine", "Adenosine"],
	["ACE_splint", "Splint"],
	["ACE_tourniquet", "Tourniquet"],
    ["ACE_surgicalKit", "Surgical Kit"],
    ["ACE_personalAidKit", "Personal Aid Kit"],
    ["ACE_salineIV", "1000ML Saline"],
    ["ACE_salineIV_500", "500ML Saline"],
    ["ACE_salineIV_250", "250ML Saline"],
	["B_Carryall_cbr", "Carryall Tan"],
	["B_Carryall_oli", "Carryall Olive"]
];

publicVariable "UO_itemList";

_sp_blacklistControls = [
    1600,
    1601,
    1603,
    1606,
    1607,
    1608,
    1610,
    1402
];

_mp_blacklistControls = [];

{
    _idc = 2800 + _forEachIndex;
    _state = switch (_x) do {
        case 0: {false};
        case 1: {true};
    };
    _control = (_display displayctrl _idc);
    _control cbSetChecked _state
} forEach (_unit getVariable "uogm_cbStates");

uo_tpGM = false;
uo_tpUser = false;
uo_tpAllToMap = false;
publicVariable "uo_tpGM";
publicVariable "uo_tpUser";
publicVariable "uo_tpAllToMap";


lbClear (_display displayCtrl 2100);
lbClear (_display displayCtrl 2101);

{
    _index = (_display displayCtrl 2101) lbAdd (_x select 1);
    (_display displayCtrl 2101) lbSetData [_index, _x select 0];
} forEach UO_itemList;
(_display displayCtrl 2101) lbSetCurSel 0;

if (!isMultiplayer) exitWith {
    _index = (_display displayCtrl 2100) lbAdd format [" [%2] %1", name _unit, side _unit];
    (_display displayCtrl 2100) lbSetData [_index, (name _unit)];
    (_display displayCtrl 2100) lbSetCurSel 0;

    {(_display displayctrl _x) ctrlEnable false} forEach _sp_blacklistControls;
    UOGM_Loaded = true;
    publicVariable "UOGM_Loaded";
};

{(_display displayctrl _x) ctrlEnable false;} foreach _mp_blacklistControls; //Temp disabe of remove gear buttons for lack of functions

{
    _index = (_display displayCtrl 2100) lbAdd format ["[%2] %1", name _x, side _x];
    (_display displayCtrl 2100) lbSetData [_index, (name _x)];
} forEach playableUnits;

lbSort (_display displayCtrl 2100);
(_display displayCtrl 2100) lbSetCurSel 0;


_msg = text format ["[UO ADMIN]: %1 has opened the GM console", name player];
_msg remoteExecCall ["diag_log", 2];

UOGM_Loaded = true;
publicVariable "UOGM_Loaded";