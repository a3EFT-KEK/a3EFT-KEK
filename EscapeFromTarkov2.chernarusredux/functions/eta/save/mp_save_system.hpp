//PLAYER STASHES, MP_STASH, PLAYER_LOADOUTS
//Implement as .hpp file
//#include "functions\eta\tasks\mp_save_system.hpp"



//SETS BASE VALUES
mp_save_creation = {
  if (!isServer) exitWith {};
  if (!isClass(configfile >> "CfgPatches" >> "filext")) exitWith {};
  private _filename = "tarkov.save";
  private _playerstashes = [playerstash_0, playerstash_1, playerstash_2, playerstash_3, playerstash_4, playerstash_5];

  [_fileName] call filext_fnc_open;
  //SETS ALL LOADOUTS TO BE EMPTY
  [_fileName, format["loadouts"], str([["created"],["NULL"],[1000]])] call filext_fnc_set;

  //SAVES STASH
  [_fileName, "combined_storage_items", str(getItemCargo mp_stash)] call filext_fnc_set;
  [_fileName, "combined_storage_weapons", str(getWeaponCargo mp_stash)] call filext_fnc_set;

  [_fileName, "eta_save_player_stashes", str([["created"],["NULL"],["NULL"],["NULL"]])] call filext_fnc_set;

  [_fileName] call filext_fnc_write;
  [_fileName] call filext_fnc_close;

  "SAVE CREATED" remoteExec ["systemChat"];

  missionNamespace spawn mp_save;
};

mp_save = {
  if (!isServer) exitWith {};
  private _playerstashes = [playerstash_0, playerstash_1, playerstash_2, playerstash_3, playerstash_4, playerstash_5];

  //checks if server has filext loaded
  if (!isClass(configfile >> "CfgPatches" >> "filext")) then {
    //LOADOUTS
    private _loadouts = profileNamespace getVariable ["eta_save_loadouts",[["created"],["NULL"],[1000]]];
    for [{private _i = 0},{_i < count allPlayers},{_i = _i + 1}] do {
      if (getPlayerUID (allPlayers select _i) in (_loadouts select 0)) then {
        private _index = _loadouts select 0 find getPlayerUID (allPlayers select _i);
        (_loadouts select 1) set [_index,getUnitLoadout (allPlayers select _i)];
        (_loadouts select 2) set [_index,((allPlayers select _i) getVariable ["money",1000])];
      }
      else
      {
        (_loadouts select 0) append [getPlayerUID (allPlayers select _i)];
        (_loadouts select 1) append [getUnitLoadout (allPlayers select _i)];
        (_loadouts select 2) append [1000];
      };
    };
    profileNamespace setVariable ["eta_save_loadouts", _loadouts];

    //STASHES
    profileNamespace setVariable ["eta_save_mp_stash_items", getItemCargo mp_stash];
    profileNamespace setVariable ["eta_save_mp_stash_weapons",getItemCargo mp_stash];

    private _stashes = profileNamespace getVariable ["eta_save_player_stashes",[["created"],["NULL"],["NULL"],["NULL"]]];
    for [{private _i = 0},{_i < playableSlotsNumber west},{_i = _i + 1}] do {
      private _player = missionNamespace getVariable [format["player_%1",_i],objNull];
      if !(_player isEqualTo objNull) then {
        _player = getPlayerUID _player;
        _current_stash = _playerstashes select _i;
        if (_player in (_stashes select 0)) then {
          private _index = _stashes select 0 find _player;
          (_stashes select 1) set [_index,getItemCargo _current_stash];
          (_stashes select 2) set [_index,getWeaponCargo _current_stash];
          (_stashes select 3) set [_index,getMagazineCargo _current_stash];
        }
        else
        {
          (_stashes select 0) append [_player];
          (_stashes select 1) append [getItemCargo _current_stash];
          (_stashes select 2) append [getWeaponCargo _current_stash];
          (_stashes select 3) append [getMagazineCargo _current_stash];
        };
      };
    };

    profileNamespace setVariable ["eta_save_player_stashes",_stashes];

    "SAVED IN PROFILENAMESPACE" remoteExec ["systemChat"];
    "profileNamespace is not a good place to store data, it has just been included for compatability, if you can please use FileXT" remoteExec ["systemChat"];
    if (true) exitWith {};
  };
  if (!isClass(configfile >> "CfgPatches" >> "filext")) exitWith {};
  private _filename = "tarkov.save";
  private _backup_file = "tarkov.backup";
  private _not_newgame = _fileName call filext_fnc_fileExists;

  //checks if savefile exists
  if (_not_newgame) then {
    [_fileName] call filext_fnc_open;
    [_fileName] call filext_fnc_read;

    //loading old file

    //LOADOUTS
    localNamespace setVariable [format["loadouts"], [_fileName, format["loadouts"]] call filext_fnc_get];

    //MP STASH
    private _mp_mission_storage_items = [_fileName, "combined_storage_items"] call filext_fnc_get;
    private _mp_mission_storage_weapons = [_fileName, "combined_storage_weapons"] call filext_fnc_get;

    //PLAYERSTASHES
    private _stashes = [_fileName, "eta_save_player_stashes"] call filext_fnc_get;

    //SAVING DATA FROM OLD FILE SINCE IT WILL BE OVERWRITTEN
    [_fileName, format["loadouts"], localNamespace getVariable format["loadouts"]] call filext_fnc_set;
    [_fileName, "eta_save_player_stashes", _stashes] call filext_fnc_set;

    //BACKUP, LOADS OLD DATA AND SAVES IT BEFORE DATA IS BEING ADJUSTED
    [_backup_file] call filext_fnc_open;
    [_backup_file] call filext_fnc_read;
    [_backup_file, format["loadouts"], localNamespace getVariable format["loadouts"]] call filext_fnc_set;
    [_backup_file, "eta_save_player_stashes", _stashes] call filext_fnc_set;

    [_backup_file, "combined_storage_items", _mp_mission_storage_items] call filext_fnc_set;
    [_backup_file, "combined_storage_weapons", _mp_mission_storage_weapons] call filext_fnc_set;
    {
      [_backup_file, format["%1_items",str(_x)], str(localNamespace getVariable [format["%1_items",str(_x)],""])] call filext_fnc_set;
      [_backup_file, format["%1_items",str(_x)], str(localNamespace getVariable [format["%1_weapons",str(_x)],""])] call filext_fnc_set;
    } forEach _playerstashes;
    [_backup_file] call filext_fnc_write;
    [_backup_file] call filext_fnc_close;

    //MP STASH NEW DATA
    [_fileName, "combined_storage_items", str(getItemCargo mp_stash)] call filext_fnc_set;
    [_fileName, "combined_storage_weapons", str(getWeaponCargo mp_stash)] call filext_fnc_set;

    //PLAYERSTASHES
    _stashes = parseSimpleArray _stashes;
    for [{private _i = 0},{_i < playableSlotsNumber west},{_i = _i + 1}] do {
      private _player = missionNamespace getVariable [format["player_%1",_i],objNull];
      if !(_player isEqualTo objNull)  then {
        _player = getPlayerUID _player;
        _current_stash = _playerstashes select _i;
        if (_player in (_stashes select 0)) then {
          private _index = _stashes select 0 find _player;
          (_stashes select 1) set [_index,getItemCargo _current_stash];
          (_stashes select 2) set [_index,getWeaponCargo _current_stash];
          (_stashes select 3) set [_index,getMagazineCargo _current_stash];
        }
        else
        {
          (_stashes select 0) append [_player];
          (_stashes select 1) append [getItemCargo _current_stash];
          (_stashes select 2) append [getWeaponCargo _current_stash];
          (_stashes select 3) append [getMagazineCargo _current_stash];
        };
      };
    };
    [_fileName, format["eta_save_player_stashes"], str(_stashes)] call filext_fnc_set;

    //PLAYER LOADOUTS
    private _loadouts = localNamespace getVariable ["loadouts",[[],[]]];
    _loadouts = parseSimpleArray _loadouts;

    for [{private _i = 0},{_i < count allPlayers},{_i = _i + 1}] do {
      if (getPlayerUID (allPlayers select _i) in (_loadouts select 0)) then {
        private _index = _loadouts select 0 find getPlayerUID (allPlayers select _i);
        (_loadouts select 1) set [_index,getUnitLoadout (allPlayers select _i)];
        (_loadouts select 2) set [_index,((allPlayers select _i) getVariable ["money",1000])];
      }
      else
      {
        (_loadouts select 0) append [getPlayerUID (allPlayers select _i)];
        (_loadouts select 1) append [getUnitLoadout (allPlayers select _i)];
        (_loadouts select 2) append [((allPlayers select _i) getVariable ["money",1000])];
      };
    };
    [_fileName, format["loadouts"], str(_loadouts)] call filext_fnc_set;


    [_fileName] call filext_fnc_write;
    [_fileName] call filext_fnc_close;

    "SAVED SUCCESSFULLY" remoteExec ["systemChat"];
  }
  else {
    "Calling save creation" remoteExec ["systemChat"];
    missionNamespace spawn mp_save_creation;
  };
};

mp_load = {
  if (!isServer) exitWith {};
  private _playerstashes = [playerstash_0, playerstash_1, playerstash_2, playerstash_3, playerstash_4, playerstash_5];
  {
      clearItemCargoGlobal _x;
      clearWeaponCargoGlobal _x;
      clearMagazineCargoGlobal _x;
  } forEach _playerstashes;
  clearItemCargoGlobal mp_stash;
  clearWeaponCargoGlobal mp_stash;

  //NON FILEXT LOAD
  if (!isClass(configfile >> "CfgPatches" >> "filext")) then {

    private _loadouts = profileNamespace getVariable ["eta_save_loadouts",[["created"],["NULL"],[1000]]];

    private _mp_mission_storage_items = profileNamespace getVariable ["eta_save_mp_stash_items",getItemCargo mp_stash];
    private _mp_mission_storage_weapons = profileNamespace getVariable ["eta_save_mp_stash_weapons",getItemCargo mp_stash];

    private _stashes = profileNamespace getVariable ["eta_save_player_stashes",[["created"],["NULL"],["NULL"],["NULL"]]];

    //MP_STASH PERSISTENCY
    for [{private _i = 0}, {_i <= count (_mp_mission_storage_items select 0)}, {_i = _i + 1}] do
    {
      mp_stash addItemCargoGlobal [_mp_mission_storage_items select 0 select _i, _mp_mission_storage_items select 1 select _i];
    };
    for [{private _i = 0}, {_i <= count (_mp_mission_storage_weapons select 0)}, {_i = _i + 1}] do
    {
      mp_stash addWeaponCargoGlobal [_mp_mission_storage_weapons select 0 select _i, _mp_mission_storage_weapons select 1 select _i];
    };

    //PLAYERSTASHES PERSISTENCY
    for [{private _i = 0},{_i < playableSlotsNumber west},{_i = _i + 1}] do {
      _player = missionNamespace getVariable [format["player_%1",_i],objNull];
      if !(_player isEqualTo objNull)  then {
        _current_stash = _playerstashes select _i;
        if (getPlayerUID _player in (_stashes select 0)) then {
          private _index = _stashes select 0 find getPlayerUID _player;
          for [{private _ii = 0}, {_ii <= count (_stashes select 1 select _index select 0)},{_ii = _ii + 1}] do
          {
            _current_stash addItemCargoGlobal [_stashes select 1 select _index select 0 select _ii, _stashes select 1 select _index select 1 select _ii];
          };
          for [{private _ii = 0}, {_ii <= count (_stashes select 2 select _index select 0)},{_ii = _ii + 1}] do
          {
            _current_stash addWeaponCargoGlobal [_stashes select 2 select _index select 0 select _ii, _stashes select 2 select _index select 1 select _ii];
          };
          for [{private _ii = 0}, {_ii <= count (_stashes select 3 select _index select 0)},{_ii = _ii + 1}] do
          {
            _current_stash addMagazineCargoGlobal [_stashes select 3 select _index select 0 select _ii, _stashes select 3 select _index select 1 select _ii];
          };
        };
      };
    };

    //LOADOUTS
    for [{private _i = 0},{_i < count allPlayers},{_i = _i + 1}] do {
      if (getPlayerUID (allPlayers select _i) in (_loadouts select 0)) then {
        private _index = _loadouts select 0 find getPlayerUID (allPlayers select _i);
        allPlayers select _i setUnitLoadout [(_loadouts select 1 select _index), false];
        (allPlayers select _i) setVariable ["money", _loadouts select 2 select _index];
      };
    };
    "DATA LOADED FROM PROFILENAMESPACE" remoteExec ["systemChat"];
    "profileNamespace is not a good place to store data, it has just been included for compatability, if you can please use FileXT" remoteExec ["systemChat"];
    if (true) exitWith {};
  };
  if (!isClass(configfile >> "CfgPatches" >> "filext")) exitWith {};
  private _filename = "tarkov.save";
  private _not_newgame = _fileName call filext_fnc_fileExists;

  //CHECK IF SAFE EXISTS
  if (_not_newgame) then {
    [_fileName] call filext_fnc_open;
    [_fileName] call filext_fnc_read;

    //LOADING ALL INFORMATION FROM FILE

    _loadouts = [_fileName, format["loadouts"]] call filext_fnc_get;
    _stashes = [_fileName, "eta_save_player_stashes"] call filext_fnc_get;

    _mp_mission_storage_items = [_fileName, format["combined_storage_items"]] call filext_fnc_get;
    _mp_mission_storage_weapons = [_fileName, format["combined_storage_weapons"]] call filext_fnc_get;

    //REMOVING FILE FROM RAM
    [_fileName] call filext_fnc_close;

    //PARSING ALL INFORMATION
    _mp_mission_storage_items = parseSimpleArray _mp_mission_storage_items;
    _mp_mission_storage_weapons = parseSimpleArray _mp_mission_storage_weapons;
    _stashes = parseSimpleArray _stashes;
    _loadouts = parseSimpleArray _loadouts;

    //MP_STASH PERSISTENCY
    for [{private _i = 0}, {_i <= count (_mp_mission_storage_items select 0)}, {_i = _i + 1}] do
    {
      mp_stash addItemCargoGlobal [_mp_mission_storage_items select 0 select _i, _mp_mission_storage_items select 1 select _i];
    };
    for [{private _i = 0}, {_i <= count (_mp_mission_storage_weapons select 0)}, {_i = _i + 1}] do
    {
      mp_stash addWeaponCargoGlobal [_mp_mission_storage_weapons select 0 select _i, _mp_mission_storage_weapons select 1 select _i];
    };

    //PLAYERSTASHES PERSISTENCY
    for [{private _i = 0},{_i < playableSlotsNumber west},{_i = _i + 1}] do {
      _player = missionNamespace getVariable [format["player_%1",_i],objNull];
      if !(_player isEqualTo objNull)  then {
        _current_stash = _playerstashes select _i;
        if (getPlayerUID _player in (_stashes select 0)) then {
          private _index = _stashes select 0 find getPlayerUID _player;
          for [{private _ii = 0}, {_ii <= count (_stashes select 1 select _index select 0)},{_ii = _ii + 1}] do
          {
            _current_stash addItemCargoGlobal [_stashes select 1 select _index select 0 select _ii, _stashes select 1 select _index select 1 select _ii];
          };
          for [{private _ii = 0}, {_ii <= count (_stashes select 2 select _index select 0)},{_ii = _ii + 1}] do
          {
            _current_stash addWeaponCargoGlobal [_stashes select 2 select _index select 0 select _ii, _stashes select 2 select _index select 1 select _ii];
          };
          for [{private _ii = 0}, {_ii <= count (_stashes select 3 select _index select 0)},{_ii = _ii + 1}] do
          {
            _current_stash addMagazineCargoGlobal [_stashes select 3 select _index select 0 select _ii, _stashes select 3 select _index select 1 select _ii];
          };
        };
      };
    };

    //PLAYER LOADOUTS
    for [{private _i = 0},{_i < count allPlayers},{_i = _i + 1}] do {
      if (getPlayerUID (allPlayers select _i) in (_loadouts select 0)) then {
        private _index = _loadouts select 0 find getPlayerUID (allPlayers select _i);
        allPlayers select _i setUnitLoadout [(_loadouts select 1 select _index), false];
        allPlayers select _i setVariable ["money", _loadouts select 2 select _index];
      };
    };

    "SAVE LOADED" remoteExec ["systemChat"];
  }
  else {
    missionNamespace spawn mp_save_creation;
  };
};

mp_load_player = {
  //WIP MAKE SURE LOADOUT IS EMPTY IF PLAYER IS DEAD
  //WIP IMPLEMENT UID BASED STASH
  //WIP IMPLEMENT MONEY (money = player getVariable ["money",1000];)
  if (!isServer) exitWith {};  
  params ["_unit"];
  private _playerstashes = [playerstash_0, playerstash_1, playerstash_2, playerstash_3, playerstash_4, playerstash_5];

  //PROFILENAMESPACE SAVE
  if (!isClass(configfile >> "CfgPatches" >> "filext")) then {

  //LOADOUT
  private _loadouts = profileNamespace getVariable ["eta_save_loadouts",[["created"],["NULL"],[1000]]];
  private _index = _loadouts select 0 find getPlayerUID _unit;
  _unit setUnitLoadout [(_loadouts select 1 select _index), false];
  if (!alive _unit) then {
    _unit setUnitLoadout (configFile >> "EmptyLoadout");
  };
  _unit setVariable ["money", _loadouts select 2 select _index];

  //STASH

  private _stashes = profileNamespace getVariable ["eta_save_player_stashes",[["created"],["NULL"],["NULL"]]];
  _playernumber = (parseNumber(str(_unit) select [7, 1]));
  _current_stash = _playerstashes select (_playernumber);
  clearItemCargoGlobal _current_stash;
  clearWeaponCargoGlobal _current_stash;
  clearMagazineCargoGlobal _current_stash;
  if (getPlayerUID _unit in (_stashes select 0)) then {
    private _index = _stashes select 0 find getPlayerUID _unit;
    for [{private _ii = 0}, {_ii <= count (_stashes select 1 select _index select 0)},{_ii = _ii + 1}] do
    {
      _current_stash addItemCargoGlobal [_stashes select 1 select _index select 0 select _ii, _stashes select 1 select _index select 1 select _ii];
    };
    for [{private _ii = 0}, {_ii <= count (_stashes select 2 select _index select 0)},{_ii = _ii + 1}] do
    {
      _current_stash addWeaponCargoGlobal [_stashes select 2 select _index select 0 select _ii, _stashes select 2 select _index select 1 select _ii];
    };
    for [{private _ii = 0}, {_ii <= count (_stashes select 3 select _index select 0)},{_ii = _ii + 1}] do
    {
      _current_stash addMagazineCargoGlobal [_stashes select 3 select _index select 0 select _ii, _stashes select 3 select _index select 1 select _ii];
    };
  };

  }
  //FILEXT SAVE
  else {
    private _filename = "tarkov.save";
    [_fileName] call filext_fnc_open;
    [_fileName] call filext_fnc_read;
    private _loadouts = [_fileName, format["loadouts"]] call filext_fnc_get;
    private _stashes = [_fileName,"eta_save_player_stashes"] call filext_fnc_get;
    [_fileName] call filext_fnc_close;

    _loadouts = parseSimpleArray _loadouts;
    _stashes = parseSimpleArray _stashes;

    //LOADOUTS
    private _index = _loadouts select 0 find getPlayerUID _unit;
    _unit setUnitLoadout [(_loadouts select 1 select _index), false];
    if (!alive _unit) then {
      _unit setUnitLoadout (configFile >> "EmptyLoadout");
    };
    _unit setVariable ["money", _loadouts select 2 select _index];

    //STASHES
    _playernumber = (parseNumber(str(_unit) select [7, 1]));
    _current_stash = _playerstashes select (_playernumber);
    clearItemCargoGlobal _current_stash;
    clearWeaponCargoGlobal _current_stash;
    clearMagazineCargoGlobal _current_stash;
    if (getPlayerUID _unit in (_stashes select 0)) then {
      private _index = _stashes select 0 find getPlayerUID _unit;
      for [{private _ii = 0}, {_ii <= count (_stashes select 1 select _index select 0)},{_ii = _ii + 1}] do
      {
        _current_stash addItemCargoGlobal [_stashes select 1 select _index select 0 select _ii, _stashes select 1 select _index select 1 select _ii];
      };
      for [{private _ii = 0}, {_ii <= count (_stashes select 2 select _index select 0)},{_ii = _ii + 1}] do
      {
        _current_stash addWeaponCargoGlobal [_stashes select 2 select _index select 0 select _ii, _stashes select 2 select _index select 1 select _ii];
      };
      for [{private _ii = 0}, {_ii <= count (_stashes select 3 select _index select 0)},{_ii = _ii + 1}] do
      {
        _current_stash addMagazineCargoGlobal [_stashes select 3 select _index select 0 select _ii, _stashes select 3 select _index select 1 select _ii];
      };
    };
  };
};


//needs param _unit (whatever unit you want to load stuff from)

//DEBUG
//PUT THIS IN INIT
/*
#include "functions\eta\save\mp_save_system.hpp"
debug_console addAction ["Create new Save",
{
  remoteExec ["mp_save_creation"];
}];

debug_console addAction ["Save",
{
  remoteExec ["mp_save"];
}];

debug_console addAction ["Load",
{
  remoteExec ["mp_load"];
}];

debug_console addAction ["Load PLAYER",
{
  [player_0] remoteExec ["mp_load_player"];
}];
*/
