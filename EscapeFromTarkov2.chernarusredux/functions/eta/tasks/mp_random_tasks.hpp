/*Random out of selection

Quest Rewards into shared storage (mp_stash)
Reward: 2 x Money_bunch

Task Ideas:
gather 3 random weapons from random weapon array, gather medical supplies (1-3 FAKs), chemical clearing, kill random HVT (spawn 3 FAKs on him)

Random Weapon Array:
["arifle_AKM_F","arifle_AKS_F","rhs_weap_ak103","rhs_weap_ak104","rhs_weap_ak105","rhs_weap_ak74","rhs_weap_aks74u","rhs_weap_aks74un","rhs_weap_ak74m","rhs_weap_ak74m_desert","rhs_weap_aks74","rhs_weap_aks74_2","rhs_weap_aks74n","rhs_weap_aks74n_2","rhs_weap_akm","rhs_weap_akms","rhs_weap_akmn","hlc_rifle_aek971worn","sgun_HunterShotgun_01_sawedoff_F","sgun_HunterShotgun_01_F","hgun_Pistol_heavy_02_F","hgun_Pistol_01_F","hgun_PDW2000_F","rhs_weapon_savz58v","rhs_weapon_savz58p","rhs_weap_m38","rhs_weap_m21a","rhs_weap_m21s","rhs_weap_Izh18","rhs_weap_m92","rhs_weap_pm63","rhs_weap_M590_5RD","rhs_weap_makarov_pm","rhs_weap_m70b1","rhs_weap_m70ab2","rhs_weap_m70b1n","rhs_weap_m70b3n","AGE_Vityaz","srifle_DMR_06_hunter_F","rhs_weap_asval_grip","rhs_weap_asval_npz","rhs_weap_pp2000","rhs_weap_vss_grip","rhs_weap_vss_grip_npz","arifle_SDAR_F"];
*/

//ARRAY CONTAINING THE RETURN BOXES, USED BY TASK_WEAPONS + TASK_MEDICINE
mp_return_storage_array = [mp_return_storage_0,mp_return_storage_1,mp_return_storage_2,mp_return_storage_3,mp_return_storage_4,mp_return_storage_5,mp_return_storage_6,mp_return_storage_7];

mp_random_task_weapons = {
  if (!isServer) exitWith {};
  private _common_weapons = ["arifle_AKM_F","arifle_AKS_F","rhs_weap_ak103","rhs_weap_ak104","rhs_weap_#ak105","rhs_weap_ak74","rhs_weap_aks74u","rhs_weap_aks74un","rhs_weap_ak74m","rhs_weap_ak74m_desert","rhs_weap_aks74","rhs_weap_aks74_2","rhs_weap_aks74n","rhs_weap_aks74n_2","rhs_weap_akm","rhs_weap_akms","rhs_weap_akmn","hlc_rifle_aek971worn","sgun_HunterShotgun_01_sawedoff_F","sgun_HunterShotgun_01_F","hgun_Pistol_heavy_02_F","hgun_Pistol_01_F","hgun_PDW2000_F","rhs_weapon_savz58v","rhs_weapon_savz58p","rhs_weap_m38","rhs_weap_m21a","rhs_weap_m21s","rhs_weap_Izh18","rhs_weap_m92","rhs_weap_pm63","rhs_weap_M590_5RD","rhs_weap_makarov_pm","rhs_weap_m70b1","rhs_weap_m70ab2","rhs_weap_m70b1n","rhs_weap_m70b3n","AGE_Vityaz","srifle_DMR_06_hunter_F","rhs_weap_asval_grip","rhs_weap_asval_npz","rhs_weap_pp2000","rhs_weap_vss_grip","rhs_weap_vss_grip_npz","arifle_SDAR_F"];
  random_selection_classnames = [];
  private _random_selection_names = [];
  private _weapon_count = 3;

  while {_weapon_count != 0} do
  {
    random_selection_classnames append [_common_weapons select random[0,count _common_weapons /2,count _common_weapons]];
    _weapon_count = _weapon_count - 1;
  };
  random_selection_classnames sort true;
  {_random_selection_names append [getText (configFile >> "CfgWeapons" >> _x >> "DisplayName")]} forEach random_selection_classnames;

  //Making sure all assigned weapons do have names (idk why but some don't seem to)
  while {"" in _random_selection_names} do {
    _random_selection_names = [];
    {_random_selection_names append [getText (configFile >> "CfgWeapons" >> _x >> "DisplayName")]} forEach random_selection_classnames;
  };

  [true, "mp_random_task_id", [format ["Deliver the following weapons to the drop-off crate:<br/>%1<br/>%2<br/>%3",_random_selection_names select 0, _random_selection_names select 1, _random_selection_names select 2],"Weapon Request","container"], objNull, "CREATED",-1,true,"box"] call BIS_fnc_taskCreate;

  mp_random_task_weapons_JIP = {
  mp_storage_action_id = player addAction ["Deliver Weapons",
  {
    private _mp_return_storage_inventory = getWeaponCargo cursorTarget;
    _mp_return_storage_inventory = _mp_return_storage_inventory select 0;
    if (random_selection_classnames select 0 in _mp_return_storage_inventory and random_selection_classnames select 1 in _mp_return_storage_inventory and random_selection_classnames select 2 in _mp_return_storage_inventory) then {
      ["mp_random_task_id","SUCCEEDED"] call BIS_fnc_taskSetState;
      mp_stash addItemCargo ["Money_Bunch", 2];
      {
          [cursorTarget, _x] call CBA_fnc_removeWeaponCargo;
      } forEach random_selection_classnames;
      player removeAction mp_storage_action_id;
      missionNamespace spawn {
        sleep 120;
        missionNamespace spawn mp_random_task_start;
      };
    }
    else
    {
        hint format["The weapons we requested ain't in the crate!"];
    };
  },
  "",
  10,
  true,
  true,
  "",
    "private _show = false;
    private _trg = cursorTarget;
    if (_trg in mp_return_storage_array) then {_show = true;};
    _show;"
  ];
  };
  remoteExecCall ["mp_random_task_weapons_JIP",0,true];
};

mp_random_task_medical_supply = {
  if (!isServer) exitWith {};
  FAK_request_count = [1, 3] call BIS_fnc_randomInt;
  [true, "mp_random_task_id", [format["Deliver %1 IFAKs to the drop-off crate",FAK_request_count],"Medicine Request","container"], objNull, "CREATED",-1,true,"box"] call BIS_fnc_taskCreate;

  mp_random_task_medical_supply_JIP = {
    mp_storage_action_id = player addAction ["Deliver Medicine",
    {
      private _mp_return_storage_inventory = getItemCargo cursorTarget;
      _mp_return_storage_inventory_amounts = _mp_return_storage_inventory select 1;
      _mp_return_storage_inventory = _mp_return_storage_inventory select 0;

      if ("FirstAidKit" in _mp_return_storage_inventory) then
      {
        private _FAK_index = _mp_return_storage_inventory find "FirstAidKit";
        if (_mp_return_storage_inventory_amounts select _FAK_index >= FAK_request_count) then
        {
          ["mp_random_task_id","SUCCEEDED"] call BIS_fnc_taskSetState;
          clearItemCargo cursorTarget;
          mp_stash addItemCargo ["Money_Bunch", 2];
          player removeAction mp_storage_action_id;
          missionNamespace spawn {
            sleep 120;
            missionNamespace spawn mp_random_task_start;
          };
        }
        else
        {
            hint "That ain't enough meds, go get more";
        };
      }
      else
      {
        hint "Come back when you have any meds to put in the crate";
      };
    },
    "",
    10,
    true,
    true,
    "",
      "private _show = false;
      private _trg = cursorTarget;
      if (_trg in mp_return_storage_array) then {_show = true;};
      _show;"
    ];
  };
  remoteExecCall ["mp_random_task_medical_supply_JIP",0,true];
};

mp_random_task_HVT = {
  if (!isServer) exitWith {};
  eta_task_HVT = "";
  private _player = (allPlayers call BIS_fnc_selectRandom);
  while {(eta_task_HVT in allPlayers) or (eta_task_HVT isEqualTo "")} do {
    eta_task_HVT = nearestObjects [_player, ["Man"], 3000] call BIS_fnc_selectRandom;
    sleep 1;
  };

  eta_task_HVT spawn {
        params ["_unit"];
        private _marker = "mp_random_task_marker";
        private _radius = 250;

        createMarker [_marker, [0, 0, 0]];
        _marker setMarkerShape "ELLIPSE";
        _marker setMarkerSize [_radius, _radius];
        _marker setMarkerColor "ColorRed";
        _marker setMarkerAlpha 0.8;

        private _randDir = random 360;
        private _randDist = random sqrt 1 * _radius;

        [true, "mp_random_task_id", [format["Kill %1, he stole from my medical storage<br/>Reward: 2 Money Bunches, all the medicine he stole",name _unit],"Kill HVT","mp_random_task_marker"], "mp_random_task_marker", "CREATED",-1,true,"kill"] call BIS_fnc_taskCreate;

        while {alive _unit} do {
            _marker setMarkerPos (_unit getPos [_randDist, _randDir]);
            sleep 1;
            ["mp_random_task_id","mp_random_task_marker"] call BIS_fnc_taskSetDestination;
        };
    };

  removeBackpack eta_task_HVT;
  eta_task_HVT addBackpack "rhs_medic_bag";
  eta_task_HVT addItemToBackpack "FirstAidKit";
  eta_task_HVT addItemToBackpack "FirstAidKit";
  eta_task_HVT addItemToBackpack "FirstAidKit";

  missionNamespace spawn {
    if (!hasInterface) exitWith {};
    eta_task_HVT addEventHandler ["Killed", {
      params ["_unit", "_killer", "_instigator", "_useEffects"];
      if (_killer in allPlayers) then {
    	  ["mp_random_task_id","SUCCEEDED"] call BIS_fnc_taskSetState;
        mp_stash addItemCargo ["Money_Bunch", 2];
        missionNamespace spawn {
          deleteMarker "mp_random_task_marker";
          sleep 120;
          missionNamespace spawn mp_random_task_start;
        };
      }
      else
      {
        ["mp_random_task_id","FAILED"] call BIS_fnc_taskSetState;
        missionNamespace spawn {
          sleep 120;
          missionNamespace spawn mp_random_task_start;
        };
      };
    }];
  };
};

mp_random_task_radioactive = {
  if (!isServer) exitWith {};

  private _player = (allPlayers call BIS_fnc_selectRandom);
  radioactive_source_pos = [_player, 3000, 5000, 3, 0, 0.1, 0] call BIS_fnc_findSafePos;
  eta_radioactive_source = "plp_cts_BarrelRadioactiveSide" createVehicle radioactive_source_pos;
  private _marker = "mp_random_task_marker";

  [eta_radioactive_source,_marker] spawn {
    params ["_unit","_marker"];

    private _radius = 1000;

    createMarker [_marker, [0, 0, 0]];
    _marker setMarkerShape "ELLIPSE";
    _marker setMarkerSize [_radius, _radius];
    _marker setMarkerColor "ColorRed";
    _marker setMarkerAlpha 0.8;

    private _randDir = random 360;
    private _randDist = random sqrt 1 * _radius;

    _marker setMarkerPos (_unit getPos [_randDist, _randDir]);

    [true, "mp_random_task_id", [format["Some radioactive material seems to be leaking, find and mark it<br/>If you have a chemical detector it should be able to detect it as well"],"Find radiation source","mp_random_task_marker"], "mp_random_task_marker", "CREATED",-1,true,"search"] call BIS_fnc_taskCreate;
    };

    missionNamespace spawn {
      if (!hasInterface) exitWith {};
      ["itemAdd", ["chem_distance", {
        private _threat_distance = player distance2D radioactive_source_pos;
        if (_threat_distance < 1000 and "ChemicalDetector_01_watch_F" in (assignedItems player)) then {
          player say "watchbeep_single";
          _threat_actual = abs((_threat_distance - 1000) / 100);

          "ChemDetector" cutRsc ["RscWeaponChemicalDetector", "PLAIN", 1, false];
          private _chem_ui = uiNamespace getVariable "RscWeaponChemicalDetector";
          private _chem_obj_ctrl = _chem_ui displayCtrl 101;
          _chem_obj_ctrl ctrlAnimateModel ["Threat_Level_Source", _threat_actual, true];
        }
        else {
        "ChemDetector" cutRsc ["RscWeaponChemicalDetector", "PLAIN", 1, false];
        private _chem_ui = uiNamespace getVariable "RscWeaponChemicalDetector";
        private _chem_obj_ctrl = _chem_ui displayCtrl 101;
        _chem_obj_ctrl ctrlAnimateModel ["Threat_Level_Source", 0, true];
      };
      }, 5]] call BIS_fnc_loop;

      [
      	eta_radioactive_source,
      	"Mark Radiation Source",
      	"\a3\missions_f_oldman\data\img\holdactions\holdAction_box_ca.paa",
      	"\a3\missions_f_oldman\data\img\holdactions\holdAction_box_ca.paa",
      	"_this distance _target < 3",
      	"_caller distance _target < 3",
      	{},
      	{},
      	{
          ["mp_random_task_id","SUCCEEDED"] call BIS_fnc_taskSetState;
          mp_stash addItemCargo ["Money_Bunch", 2];
          ["itemRemove", ["chem_distance"]] call BIS_fnc_loop;
          _target spawn {
            deleteMarker "mp_random_task_marker";
            sleep 120;
            deleteVehicle _this;
            missionNamespace spawn mp_random_task_start;
          };
        },
      	{},
      	[],
      	10,
      	0,
      	true,
      	false
      ] remoteExec ["BIS_fnc_holdActionAdd", 0, eta_radioactive_source];
    };
};

mp_random_task_start = {
  //Tasklist
  //mp_random_task_HVT,mp_random_task_medical_supply,mp_random_task_weapons,mp_random_task_radioactive
  if (!isServer) exitWith {};
  private _task_array = [mp_random_task_HVT,mp_random_task_medical_supply,mp_random_task_weapons,mp_random_task_radioactive];
  private _spawn_random_task = _task_array call BIS_fnc_selectRandom;
  missionNamespace spawn _spawn_random_task;
};

//DEBUG
//missionNamespace spawn mp_random_task_medical_supply;
