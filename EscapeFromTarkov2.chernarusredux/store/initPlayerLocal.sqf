["InitializePlayer", [player]] call BIS_fnc_dynamicGroups;
sleep 0.2;
player setPosASL (getPosASL (player getVariable "stash") vectorAdd [0,0,0.2]);
[player] call mp_load_player;


[
    hub,                                            // Object the action is attached to
    "Enter Raid",                                        // Title of the action
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",    // Idle icon shown on screen
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",    // Progress icon shown on screen
    "_this distance doorObj < 3.5 && _this != leader group _this && (leader group _this) getVariable ['inRaid',false]",                        // Condition for the action to be shown
    "_caller distance doorObj < 3.5",                        // Condition for the action to progress
    {},                                                    // Code executed when action starts
    {},                                                    // Code executed on every progress tick
    {
		[3,15,3,"","Deploying (Again...)","",_caller] spawn KEK_fnc_fade;
		sleep 5;
		_spawn = selectRandom[
                "spawn1",
                "spawn2",
                "spawn3",
                "spawn4",
                "spawn5",
                "spawn6",
                "spawn7",
                "spawn8",
                "spawn9",
                "spawn10",
                "spawn11",
                "spawn12"
            ];
        _pos = getMarkerPos _spawn;
        {
            _x setPosATL [_pos select 0,_pos select 1,0];
            _x setDir markerDir _spawn;
			raidPlayerCount = raidPlayerCount + 1;
			publicVariable "raidPlayerCount";
			[_x,["inRaid",true]] remoteExecCall ["setVariable",0];
			enableEnvironment [true, true];
        } forEach  [_caller];
    },                                                    // Code executed on completion
    {},                                                    // Code executed on interrupted
    [],                                                    // Arguments passed to the scripts as _this select 3
    2,                                                    // Action duration [s]
    100,                                                // Priority
    false,                                                // Remove on completion
    false                                                // Show in unconscious state
] call BIS_fnc_holdActionAdd;
[
    hub,                                            // Object the action is attached to
    "Enter Raid",                                        // Title of the action
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",    // Idle icon shown on screen
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",    // Progress icon shown on screen
    "_this distance doorObj < 3.5 && _this == leader group _this",                        // Condition for the action to be shown
    "_caller distance doorObj < 3.5",                        // Condition for the action to progress
    {},                                                    // Code executed when action starts
    {},                                                    // Code executed on every progress tick
    {
		if (raidPlayerCount == 0) then
		{
			{
				clearWeaponCargoGlobal _x;
				clearMagazineCargoGlobal _x;
				clearItemCargoGlobal _x;
				clearBackpackCargoGlobal _x;
				_boxType = typeOf _x;
				switch _boxType do
				{
					case "plp_ct_MilBoxMediumOlive":
					{
						_items = ["arifle_AKM_F", "rhs_weap_aks74u", "rhs_weap_akms", "rhs_weap_ak74n", "rhs_weap_ak74m", "rhs_weap_m70b1", "rhs_weap_m70ab2", "hlc_rifle_aek971worn", "hlc_rifle_saiga12k"];
						for "_i" from 1 to 1 + round random 1 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_MilBoxMediumBlack":
					{
						_items = ["arifle_AKM_F", "rhs_weap_aks74u", "rhs_weap_akms", "rhs_weap_ak74n", "rhs_weap_ak74m", "rhs_weap_m70b1", "rhs_weap_m70ab2", "hlc_rifle_aek971worn", "hlc_rifle_saiga12k"];
						for "_i" from 1 to 1 + round random 1 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_FootlockerBrown":
					{
						_items = ["arifle_AKM_F", "rhs_weap_aks74u", "rhs_weap_akms", "rhs_weap_ak74n", "rhs_weap_ak74m", "rhs_weap_m70b1", "rhs_weap_m70ab2", "hlc_rifle_aek971worn", "hlc_rifle_saiga12k", "30Rnd_762x39_Mag_F"];
						for "_i" from 1 to 1 + round random 1 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_MilBoxSmallOlive":
					{
						_items = ["30Rnd_762x39_Mag_F", "rhs_30Rnd_762x39mm", "rhs_30Rnd_545x39_7N6M_AK", "rhs_30Rnd_545x39_7N10_AK", "rhssaf_30Rnd_762x39mm_M67", "hlc_10rnd_12g_buck_S12", "hlc_10rnd_12g_slug_S12", "hlc_30Rnd_545x39_B_AK"];
						for "_i" from 1 to 1 + round random 9 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_MilBoxSmallBlack":
					{
						_items = ["30Rnd_762x39_Mag_F", "rhs_30Rnd_762x39mm", "rhs_30Rnd_545x39_7N6M_AK", "rhs_30Rnd_545x39_7N10_AK", "rhssaf_30Rnd_762x39mm_M67", "hlc_10rnd_12g_buck_S12", "hlc_10rnd_12g_slug_S12", "hlc_30Rnd_545x39_B_AK"];
						for "_i" from 1 to 1 + round random 9 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_AmmoCaseBlackA":
					{
						_items = ["30Rnd_762x39_Mag_F", "rhs_30Rnd_762x39mm", "rhs_30Rnd_545x39_7N6M_AK", "rhs_30Rnd_545x39_7N10_AK", "rhssaf_30Rnd_762x39mm_M67", "hlc_10rnd_12g_buck_S12", "hlc_10rnd_12g_slug_S12", "hlc_30Rnd_545x39_B_AK"];
						for "_i" from 1 to 1 + round random 9 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_AmmoCaseBlackB":
					{
						_items = ["30Rnd_762x39_Mag_F", "rhs_30Rnd_762x39mm", "rhs_30Rnd_545x39_7N6M_AK", "rhs_30Rnd_545x39_7N10_AK", "rhssaf_30Rnd_762x39mm_M67", "hlc_10rnd_12g_buck_S12", "hlc_10rnd_12g_slug_S12", "hlc_30Rnd_545x39_B_AK"];
						for "_i" from 1 to 1 + round random 9 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_AmmoCaseBlackC":
					{
						_items = ["30Rnd_762x39_Mag_F", "rhs_30Rnd_762x39mm", "rhs_30Rnd_545x39_7N6M_AK", "rhs_30Rnd_545x39_7N10_AK", "rhssaf_30Rnd_762x39mm_M67", "hlc_10rnd_12g_buck_S12", "hlc_10rnd_12g_slug_S12", "hlc_30Rnd_545x39_B_AK"];
						for "_i" from 1 to 1 + round random 9 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_AmmoCaseOliveA":
					{
						_items = ["30Rnd_762x39_Mag_F", "rhs_30Rnd_762x39mm", "rhs_30Rnd_545x39_7N6M_AK", "rhs_30Rnd_545x39_7N10_AK", "rhssaf_30Rnd_762x39mm_M67", "hlc_10rnd_12g_buck_S12", "hlc_10rnd_12g_slug_S12", "hlc_30Rnd_545x39_B_AK"];
						for "_i" from 1 to 1 + round random 9 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_AmmoCaseBlackB":
					{
						_items = ["30Rnd_762x39_Mag_F", "rhs_30Rnd_762x39mm", "rhs_30Rnd_545x39_7N6M_AK", "rhs_30Rnd_545x39_7N10_AK", "rhssaf_30Rnd_762x39mm_M67", "hlc_10rnd_12g_buck_S12", "hlc_10rnd_12g_slug_S12", "hlc_30Rnd_545x39_B_AK"];
						for "_i" from 1 to 1 + round random 9 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_AmmoCaseBlackC":
					{
						_items = ["30Rnd_762x39_Mag_F", "rhs_30Rnd_762x39mm", "rhs_30Rnd_545x39_7N6M_AK", "rhs_30Rnd_545x39_7N10_AK", "rhssaf_30Rnd_762x39mm_M67", "hlc_10rnd_12g_buck_S12", "hlc_10rnd_12g_slug_S12", "hlc_30Rnd_545x39_B_AK"];
						for "_i" from 1 to 1 + round random 9 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "Box_I_UAV_06_medical_F":
					{
						_items = ["FirstAidKits"];
						for "_i" from 1 to 1 + round random 4 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_FootlockerRed":
					{
						_items = ["FirstAidKits"];
						for "_i" from 1 to 1 + round random 4 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_BoxFoodSmallA":
					{
						_items = ["rvg_bacon", "rvg_beans", "rvg_rice", "rvg_milk", "rvg_plasticBottlePurified", "rvg_spirit", "rvg_franta"];
						for "_i" from 1 to 1 + round random 3 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_BoxFoodSmallB":
					{
						_items = ["rvg_bacon", "rvg_beans", "rvg_rice", "rvg_milk", "rvg_plasticBottlePurified", "rvg_spirit", "rvg_franta"];
						for "_i" from 1 to 1 + round random 3 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_BoxFoodSmallC":
					{
						_items = ["rvg_bacon", "rvg_beans", "rvg_rice", "rvg_milk", "rvg_plasticBottlePurified", "rvg_spirit", "rvg_franta"];
						for "_i" from 1 to 1 + round random 3 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_BoxFoodBigB":
					{
						_items = ["rvg_bacon", "rvg_beans", "rvg_rice", "rvg_milk", "rvg_plasticBottlePurified", "rvg_spirit", "rvg_franta"];
						for "_i" from 1 to 1 + round random 3 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_PlasticCoolerRed":
					{
						_items = ["rvg_bacon", "rvg_beans", "rvg_rice", "rvg_milk", "rvg_plasticBottlePurified", "rvg_spirit", "rvg_franta"];
						for "_i" from 1 to 1 + round random 3 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_PlasticCoolerBlue":
					{
						_items = ["rvg_bacon", "rvg_beans", "rvg_rice", "rvg_milk", "rvg_plasticBottlePurified", "rvg_spirit", "rvg_franta"];
						for "_i" from 1 to 1 + round random 3 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "Box_NATO_Support_F":
					{
						_items = ["rhs_acc_pbs1", "rhs_acc_pbs4", "rhs_acc_tgpa", "rhs_acc_dtk1", "rhs_acc_dtk2", "rhs_acc_dtk3", "rhs_acc_dtk4short", "rhs_acc_ekp8_02", "rhs_acc_ekp1", "rhs_acc_grip_rk2", "rhs_acc_grip_rk6", "rhs_acc_grip_ffg2", "rhs_acc_2dpZenit_ris", "rhs_acc_perst1ik_ris", "rhs_acc_perst3", "optic_Aco", "optic_Aco_smg", "optic_yorris", "acc_flashlight", "acc_pointer_IR", "Binocular","hlc_muzzle_762SUP_AK","hlc_muzzle_545SUP_AK","Item_ChemicalDetector_01_watch_F","Item_ChemicalDetector_01_black_F","Item_ChemicalDetector_01_olive_F","Item_ChemicalDetector_01_tan_F"];
						for "_i" from 1 to 1 + round random 7 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_FootlockerYellow":
					{
						_items = ["rvg_tire", "rvg_hose", "rvg_toolkit", "rvg_canisterFuel","Item_ChemicalDetector_01_watch_F","Item_ChemicalDetector_01_black_F","Item_ChemicalDetector_01_olive_F","Item_ChemicalDetector_01_tan_F"];
						for "_i" from 1 to 1 + round random 4 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_FootlockerGreen":
					{
						_items = ["rvg_tire", "rvg_hose", "rvg_toolkit", "rvg_canisterFuel","Item_ChemicalDetector_01_watch_F","Item_ChemicalDetector_01_black_F","Item_ChemicalDetector_01_olive_F","Item_ChemicalDetector_01_tan_F"];
						for "_i" from 1 to 1 + round random 4 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_ToolboxRedDirty":
					{
						_items = ["rvg_tire", "rvg_hose", "rvg_toolkit", "rvg_canisterFuel","Item_ChemicalDetector_01_watch_F","Item_ChemicalDetector_01_black_F","Item_ChemicalDetector_01_olive_F","Item_ChemicalDetector_01_tan_F"];
						for "_i" from 1 to 1 + round random 4 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ct_ToolboxBlackDirty":
					{
						_items = ["rvg_tire", "rvg_hose", "rvg_toolkit", "rvg_canisterFuel","Item_ChemicalDetector_01_watch_F","Item_ChemicalDetector_01_black_F","Item_ChemicalDetector_01_olive_F","Item_ChemicalDetector_01_tan_F"];
						for "_i" from 1 to 1 + round random 4 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
					case "plp_ctm_PlasticBoxGrey":
					{
						_items = ["rvg_tire", "rvg_hose", "rvg_toolkit", "rvg_canisterFuel","Item_ChemicalDetector_01_watch_F","Item_ChemicalDetector_01_black_F","Item_ChemicalDetector_01_olive_F","Item_ChemicalDetector_01_tan_F"];
						for "_i" from 1 to 1 + round random 5 do
						{
							_x addItemCargoGlobal [selectRandom _items,1];
						};
					};
				};

			} forEach allBoxes;
		};
        _spawn = selectRandom[
                "spawn1",
                "spawn2",
                "spawn3",
                "spawn4",
                "spawn5",
                "spawn6",
                "spawn7",
                "spawn8",
                "spawn9",
                "spawn10",
                "spawn11",
                "spawn12"
            ];
		{[3,15,3,"","Deploying...","",_x] remoteExec ["KEK_fnc_fade",0];} forEach units group _caller;
		sleep 5;
        _pos = getMarkerPos _spawn;
        {
            _x setPosATL [_pos select 0,_pos select 1,0];
            _x setDir markerDir _spawn;
			raidPlayerCount = raidPlayerCount + 1;
			publicVariable "raidPlayerCount";
			[_x,["inRaid",true]] remoteExecCall ["setVariable",0];
			[false, false] remoteExecCall ["enableEnvironment",owner _x];
        } forEach units group _caller;
    },                                                    // Code executed on completion
    {},                                                    // Code executed on interrupted
    [],                                                    // Arguments passed to the scripts as _this select 3
    2,                                                    // Action duration [s]
    100,                                                // Priority
    false,                                                // Remove on completion
    false                                                // Show in unconscious state
] call BIS_fnc_holdActionAdd;    // MP compatible implementation
[
    hub,                                            // Object the action is attached to
    "Go to stash",                                        // Title of the action
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",    // Idle icon shown on screen
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",    // Progress icon shown on screen
    "_this distance doorObj < 3.5",                        // Condition for the action to be shown
    "_caller distance doorObj < 3.5",                        // Condition for the action to progress
    {},                                                    // Code executed when action starts
    {},                                                    // Code executed on every progress tick
    {
		_caller setPosASL (getPosASL (_caller getVariable "stash") vectorAdd [0,0,0.2]);
    },                                                    // Code executed on completion
    {},                                                    // Code executed on interrupted
    [],                                                    // Arguments passed to the scripts as _this select 3
    2,                                                    // Action duration [s]
    100,                                                // Priority
    false,                                                // Remove on completion
    false                                                // Show in unconscious state
] call BIS_fnc_holdActionAdd;    // MP compatible implementation
{
	[
    _x,
    "Go to hub",
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",
    "\a3\ui_f\data\IGUI\Cfg\holdactions\holdAction_connect_ca.paa",
    "_this distance _target < 3.5",
    "_caller distance _target < 3.5",
    {},
    {},
    {
		_caller setPosASL (getPosASL (hubObj) vectorAdd [0,0,0.2]);
    },
    {},
    [],
    2,
    100,
    false,
    false
	] call BIS_fnc_holdActionAdd;

} forEach [stashHouse_0, stashHouse_1, stashHouse_2, stashHouse_3, stashHouse_4, stashHouse_5];
