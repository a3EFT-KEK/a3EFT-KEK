params ["_trader"];


rad_fnc_stashRefresh = {
	_menu = findDisplay 69421;
	_stash_player = _menu displayCtrl 101;
	lbClear _stash_player;
	_crate = (player getVariable "stashCrate");
	if (count (weaponCargo _crate + itemCargo _crate + magazineCargo _crate) > 0) then {
	{
	_itemName = "";
	_itemIcon = "";
	if (isClass (configFile >> "CfgWeapons" >> _x )) then 
	{
		_itemName =  getText (configFile >> "CfgWeapons" >> _x >> "displayName");
		_itemIcon =  getText (configFile >> "CfgWeapons" >> _x >> "picture");
	};
	if (isClass (configFile >> "CfgGlasses" >> _x )) then 
	{
		_itemName =  getText (configFile >> "CfgGlasses" >> _x >> "displayName");
		_itemIcon =  getText (configFile >> "CfgGlasses" >> _x >> "picture");
	};
		_stash_player lbAdd _itemName;
		_stash_player lbSetPicture [_foreachindex,_itemIcon];
		_stash_player lbSetPictureColor [_foreachindex, [1, 1, 1, 1]];
	} forEach (weaponCargo (player getVariable "stashCrate")) + (itemCargo (player getVariable "stashCrate"));
	{
		_mag = (_x select 0);
		_ammo = (_x select 1);
		_stash_player lbAdd format ["[%1] %2",_ammo, getText (configFile >> "CfgMagazines" >> _mag >> "displayName")];
		_stash_player lbSetPicture [_foreachindex + (count itemCargo (player getVariable "stashCrate")) + (count weaponCargo (player getVariable "stashCrate")),getText (configFile >> "CfgMagazines" >> _mag >> "picture")];
		_stash_player lbSetPictureColor [_foreachindex + (count itemCargo (player getVariable "stashCrate")) + (count weaponCargo (player getVariable "stashCrate")), [1, 1, 1, 1]];
	} forEach magazinesAmmoCargo (player getVariable "stashCrate");
	_stash_player lbSetCurSel 0;};
};
rad_fnc_stashRemove =
{
	params ["_toRemove"];
	_weapons = weaponsItems (player getVariable "stashCrate");
	_items = itemCargo (player getVariable "stashCrate");
	_magazines = magazinesAmmoCargo (player getVariable "stashCrate");
	if (_toRemove in _weapons) then {_weapons deleteAt (_weapons find _toRemove);};
	if (_toRemove in _items) then {_items deleteAt (_items find _toRemove);};
	if (_toRemove in _magazines) then {_magazines deleteAt (_magazines find _toRemove);};
	clearWeaponCargoGlobal (player getVariable "stashCrate");
	clearMagazineCargoGlobal (player getVariable "stashCrate");
	clearItemCargoGlobal (player getVariable "stashCrate");
	{
		(player getVariable "stashCrate") addWeaponWithAttachmentsCargoGlobal [_x,1];
	} forEach _weapons;
	{
		(player getVariable "stashCrate") addItemCargoGlobal [_x,1];
	} forEach _items;
	{
		(player getVariable "stashCrate") addMagazineAmmoCargo [_x select 0,1,_x select 1];
	} forEach _magazines;
	[] call rad_fnc_stashRefresh;
};


createDialog "trader";
_menu = findDisplay 69421;
_trader_pic = _menu displayCtrl 3;
_trader_name = _menu displayCtrl 4;
_player_name = _menu displayCtrl 5;
_funds = _menu displayCtrl 6;
_stash_trader = _menu displayCtrl 100;
_stash_player = _menu displayCtrl 101;
_player_name ctrlSetText name player;
_pics = 
	[
		"pictures\traders\traderPavlov.paa",
		"pictures\traders\traderSurgeon.paa",
		"pictures\traders\traderMechanic.paa",
		"pictures\traders\traderAdams.paa",
		"pictures\traders\traderBoris.paa",
		"pictures\traders\traderRagman.paa"
	];

_inventory_pavlov = ["rhs_weap_akm","rhs_weap_akms","rhs_weap_akmn","rhs_weap_akms_gp25","rhs_30Rnd_762x39mm_bakelite","rhs_VOG25","rhs_weap_ak103","rhs_weap_ak104","rhs_weap_ak105","rhs_30Rnd_762x39mm_polymer","rhs_weap_ak74","rhs_weap_aks74u","rhs_weap_aks74un","rhs_weap_ak74m","rhs_weap_aks74","rhs_weap_aks74_2","rhs_weap_aks74n","rhs_weap_aks74n_2","rhs_weap_aks74_gp25","rhs_30Rnd_545x39_7N6M_AK","rhs_30Rnd_545x39_7N10_AK","rhs_30Rnd_545x39_7N10_2mag_AK","rhs_45Rnd_545X39_7N6_AK","rhs_45Rnd_545X39_7N6M_AK","rhs_60Rnd_545X39_7N22_AK","arifle_AK12_F","arifle_AK12U_F","30Rnd_762x39_AK12_Mag_F","arifle_AK12_arid_F","arifle_AK12U_arid_F","30rnd_762x39_AK12_Arid_Mag_F","arifle_AK12_lush_F","arifle_AK12U_lush_F","30rnd_762x39_AK12_Lush_Mag_F","arifle_AK12_GL_F","arifle_AK12_GL_arid_F","arifle_AK12_GL_lush_F","1Rnd_HE_Grenade_shell","arifle_RPK12_F","30Rnd_762x39_AK12_Mag_F","75rnd_762x39_AK12_Mag_F","arifle_RPK12_arid_F","30Rnd_762x39_AK12_Arid_Mag_F","75rnd_762x39_AK12_Arid_Mag_F","arifle_RPK12_lush_F","30Rnd_762x39_AK12_Lush_Mag_F","75rnd_762x39_AK12_Lush_Mag_F","rhs_VOG25","AGE_Vityaz","AGE_Vityaz_C","AGE_Vityaz_C_Grip","AGE_Vityaz_V","AGE_Vityaz_V_Grip","30Rnd_9x21_Mag_SMG_02","rhs_weap_pm63","rhs_30Rnd_762x39mm","rhs_weap_m70b1","rhs_weap_m70ab2","rhs_weap_m70b1n","rhs_weap_m70b3n","rhs_weap_m92","rhssaf_30Rnd_762x39mm_M67","rhs_weap_savz58p","rhs_weap_savz58v","rhs_30Rnd_762x39mm_Savz58","rhs_weap_m21a","rhs_weap_m21s","rhsgref_30rnd_556x45_m21","srifle_DMR_07_blk_F","20Rnd_650x39_Cased_Mag_F","sgun_HunterShotgun_01_F","sgun_HunterShotgun_01_sawedoff_F","2Rnd_12Gauge_Pellets","2Rnd_12Gauge_Slug","rhs_weap_Izh18","rhsgref_1Rnd_00Buck","rhsgref_1Rnd_Slug","hgun_Pistol_01_F","10Rnd_9x21_Mag","hgun_Pistol_heavy_02_F","6Rnd_45ACP_Cylinder"];
_prices_pavlov = [500,495,505,580,55,90,529,529,529,55,509,499,501,509,501,501,509,509,588,55,55,55,71,71,105,597,577,61,597,577,61,597,577,61,683,683,683,90,622,61,61,622,61,61,622,61,61,90,275,285,300,280,290,305,483,55,483,483,483,483,463,55,471,461,55,452,442,55,699,77,242,212,17,19,238,17,19,189,23,199,27];
_inventory_surgeon = ["FirstAidKit","Medikit","rvg_bacon","rvg_rice","rvg_beans","rvg_spirit","rvg_franta","rvg_milk","rvg_plasticBottlePurified","rvg_canteen","rvg_antiRad","rvg_canOpener","rvg_purificationTablets","rvg_ItemMap","ItemCompass","ItemRadio","ItemGPS","ChemicalDetector_01_watch_F"];
_prices_surgeon = [50,150,25,25,25,25,25,25,50,50,15,2,10,10,10,10,1250,500];
_inventory_dimitri = ["optic_Aco","optic_ACO_grn","optic_Aco_smg","optic_ACO_grn_smg","optic_Holosight_blk_F","optic_Holosight_smg_blk_F","optic_Holosight","optic_Holosight_smg","optic_Holosight_arid_F","optic_Holosight_lush_F","optic_Hamr","optic_Hamr_khk_F","optic_ERCO_blk_F","optic_ERCO_snd_F","optic_ERCO_khk_F","optic_Arco","optic_Arco_arid_F","optic_Arco_lush_F","optic_Arco_AK_blk_F","optic_Arco_AK_arid_F","optic_Arco_AK_lush_F","optic_KHS_blk","optic_KHS_tan","optic_DMS","optic_LRPS","optic_SOS","optic_MRCO","optic_Nightstalker","optic_NVS","optic_TWS","acc_flashlight","acc_pointer_IR","rhsusf_acc_M952V","rhsusf_acc_anpeq16a","rhsusf_acc_anpeq16a_top","rhsusf_acc_wmx","rhsusf_acc_wmx_bk","rhsusf_acc_anpeq15_wmx_light","rhsusf_acc_anpeq15_wmx","rhsusf_acc_anpeq15_bk_light","rhsusf_acc_anpeq15_bk","rhs_acc_2dpZenit","rhs_acc_2dpZenit_ris","rhs_acc_perst3_2dp_light_h","rhs_acc_perst3_2dp_h","AGE_PK0","AGE_PK1","AGE_PK2","muzzle_snds_H_MG_blk_F","AGE_Muzzle_FA556_Black","AGE_Muzzle_FA556AR_Black","muzzle_snds_M","muzzle_snds_m_snd_F","muzzle_snds_m_khk_F","muzzle_snds_H","muzzle_snds_H_khk_F","muzzle_snds_H_khk_F","muzzle_snds_65_TI_blk_F","bipod_01_F_blk","bipod_01_F_mtp","bipod_01_F_snd","bipod_01_F_khk","bipod_02_F_blk","bipod_02_F_arid","bipod_02_F_lush","bipod_03_F_blk","rhsusf_acc_ACOG2_USMC","rhsusf_acc_ACOG_USMC","rhsusf_acc_ACOG_RMR","rhsusf_acc_eotech_xps3","rhsusf_acc_EOTECH","rhsusf_acc_eotech_552","rhsusf_acc_g33_xps3","rhsusf_acc_g33_xps3_tan","rhs_acc_ekp1","rhs_acc_ekp8_02","rhs_acc_pso1m2","rhs_acc_pso1m21","rhsusf_acc_kac_grip","rhsusf_acc_rvg_blk","rhsusf_acc_rvg_de","rhsusf_acc_tdstubby_blk","rhsusf_acc_tdstubby_tan","rhsusf_acc_grip3","rhsusf_acc_grip3_tan","rhs_acc_grip_rk6","rhs_acc_grip_rk2","rhsusf_acc_SF3P556","rhsusf_acc_SFMB556","rhsusf_acc_nt4_black","rhsusf_acc_nt4_tan","rhsusf_acc_rotex5_grey","rhsusf_acc_rotex5_tan","rhs_acc_pbs1","rhs_acc_dtk4long","rhs_acc_dtk4screws","rhs_acc_dtk4short","rhs_acc_tgpa","rhs_acc_pbs4"];
_prices_dimitri = [150,150,150,150,180,180,180,180,185,185,181,181,220,220,220,210,210,210,210,215,215,250,250,250,250,400,220,850,850,850,75,95,75,115,115,75,75,115,115,115,115,75,75,75,75,100,100,100,1284,1284,1284,1284,1284,1284,1284,1284,1284,1284,65,65,65,65,65,65,65,65,200,250,150,150,150,185,185,150,150,225,250,250,100,100,100,100,100,100,100,100,100,284,284,284,284,284,284,284,284,284,284,284,284];
_inventory_adams = ["arifle_SPAR_01_blk_F","arifle_SPAR_01_GL_blk_F","30Rnd_556x45_Stanag","1Rnd_HE_Grenade_shell","arifle_SPAR_03_blk_F","20Rnd_762x51_Mag","arifle_MX_F","30Rnd_65x39_caseless_mag","arifle_MX_Black_F","30Rnd_65x39_caseless_black_mag","arifle_MXC_Black_F","30Rnd_65x39_caseless_black_mag","SMG_01_F","30Rnd_45ACP_Mag_SMG_01","SMG_02_F","SMG_05_F","30Rnd_9x21_Mag_SMG_02","rhs_weap_m4a1_carryhandle","rhs_weap_m4a1_carryhandle_m203S","rhs_weap_m4a1_carryhandle_mstock","rhs_weap_m4a1_blockII","rhs_weap_m4a1_blockII_bk","rhs_weap_m4a1_blockII_M203_bk","rhs_weap_m4a1_blockII_KAC_bk","rhs_mag_30Rnd_556x45_M855A1_Stanag","rhs_mag_M441_HE","rhs_mag_m576","srifle_EBR_F","20Rnd_762x51_Mag","rhs_weap_M590_8RD","rhs_weap_M590_5RD","rhsusf_8Rnd_00Buck","rhsusf_8Rnd_Slug","rhsusf_8Rnd_FRAG","hgun_P07_blk_F","hgun_P07_F","16Rnd_9x21_Mag"];
_prices_adams = [597,683,61,90,612,75,584,65,584,65,561,65,414,44,399,369,38,550,615,562,562,562,628,562,61,90,27,717,84,314,287,31,30,100,226,226,23];
_inventory_boris = ["H_Cap_blk","H_Cap_blk_ION","TRYK_H_headsetcap_blk","TRYK_H_headsetcap","rhsusf_bowman_cap","TRYK_H_woolhat","TRYK_H_woolhat_cu","TRYK_H_woolhat_tan","rhs_beanie_green","rhs_beanie","H_Watchcap_blk","H_Watchcap_cbr","H_Watchcap_camo","H_Watchcap_khk","H_HelmetB_light","H_HelmetB_light_black","H_HelmetB_light_desert","H_HelmetB_light_grass","H_HelmetB_light_sand","H_HelmetB_light_snakeskin","H_HelmetB","H_HelmetB_black","H_HelmetB_desert","H_HelmetB_grass","H_HelmetB_sand","H_HelmetB_snakeskin","H_HelmetSpecB","H_HelmetSpecB_blk","H_HelmetSpecB_paint2","H_HelmetSpecB_paint1","H_HelmetSpecB_sand","H_HelmetSpecB_snakeskin","H_HelmetHBK_F","H_HelmetHBK_headset_F","H_HelmetHBK_ear_F","AGE_Fast_Black","AGE_Fast_Black_A","AGE_Fast_Black_H","AGE_Fast_Black_H_A","AGE_Fast_Black_P","AGE_Fast_Black_P_A","AGE_Fast_Painted","AGE_Fast_Painted_A","AGE_Fast_Painted_H","AGE_Fast_Painted_H_A","AGE_Fast_Painted_P","AGE_Fast_Painted_P_A","AGE_Fast_Tan","AGE_Fast_Tan_A","AGE_Fast_Tan_H","AGE_Fast_Tan_H_A","AGE_Fast_Tan_P","AGE_Fast_Tan_P_A","rhsusf_opscore_bk_pelt","rhsusf_opscore_fg_pelt","rhsusf_opscore_ut_pelt","TRYK_H_PASGT_BLK","TRYK_H_PASGT_COYO","TRYK_H_PASGT_OD","H_HelmetB_TI_tna_F","H_HelmetB_TI_arid_F","rhs_6b26_green","rhs_6b26_bala_green","rhs_6b26_ess_bala_green","rhs_6b26_digi","rhs_6b26_digi_bala","rhs_6b26_digi_ess_bala","rhs_6b26","rhs_6b26_bala","rhs_6b26_ess_bala","rhs_6b27m_green","rhs_6b27m_green_bala","rhs_6b27m_green_ess_bala","rhs_6b27m_digi","rhs_6b27m_digi_bala","rhs_6b27m_digi_ess_bala","rhs_6b27m","rhs_6b27m_bala","rhs_6b27m_ess_bala","rhs_6b27m_ml","rhs_6b27m_ml_bala","rhs_6b27m_ML_ess_bala","rhs_6b28_green","rhs_6b28_green_bala","rhs_6b28_green_ess_bala","rhs_6b28","rhs_6b28_bala","rhs_6b28_ess_bala","rhs_6b28_flora","rhs_6b28_flora_bala","rhs_6b28_flora_ess_bala","rhs_6b47_bare","rhs_6b47","rhs_6b47_6m2_1","rhs_6b47_bala","rhs_6b7_1m","rhs_6b7_1m_bala1","rhs_6b7_1m_bala2","rhs_6b7_1m_ess_bala","rhs_6b7_1m_emr","rhs_6b7_1m_bala1_emr","rhs_6b7_1m_bala2_emr","rhs_6b7_1m_emr_ess_bala","rhs_6b7_1m_flora","rhs_6b7_1m_bala1_flora","rhs_6b7_1m_bala2_flora","rhs_6b7_1m_olive","rhs_6b7_1m_bala1_olive","rhs_6b7_1m_bala2_olive","rhs_altyn","rhs_altyn_bala","rhs_altyn_visordown","rhsusf_hgu56p_visor_mask_smiley","rhsusf_hgu56p_visor_mask_skull","rhsusf_hgu56p_visor_mask_pink","V_PlateCarrier1_rgr_noflag_F","V_PlateCarrier2_rgr_noflag_F","TRYK_V_ArmorVest_CBR","TRYK_V_ArmorVest_cbr2","TRYK_V_ArmorVest_Brown","TRYK_V_ArmorVest_Brown2","TRYK_V_ArmorVest_green","TRYK_V_ArmorVest_green2","TRYK_V_ArmorVest_coyo","TRYK_V_ArmorVest_coyo2","TRYK_V_ArmorVest_tan","TRYK_V_ArmorVest_tan2","V_Chestrig_blk","V_Chestrig_rgr","V_Chestrig_khk","V_Chestrig_oli","V_TacVestIR_blk","V_SmershVest_01_F","V_SmershVest_01_radio_F","V_CarrierRigKBT_01_Olive_F","V_CarrierRigKBT_01_EAF_F","V_CarrierRigKBT_01_light_Olive_F","V_CarrierRigKBT_01_light_EAF_F","V_CarrierRigKBT_01_heavy_Olive_F","V_CarrierRigKBT_01_heavy_EAF_F","V_TacVest_blk","V_TacVest_brn","V_TacVest_camo","V_TacVest_khk","V_TacVest_oli","V_I_G_resistanceLeader_F","V_BandollierB_blk","V_BandollierB_cbr","V_BandollierB_rgr","V_BandollierB_khk","V_BandollierB_oli","V_TacChestrig_cbr_F","V_TacChestrig_grn_F","V_TacChestrig_oli_F","AGE_TV110_AK_Black","AGE_TV110_AK_Holster_Black","AGE_TV110_SMG_Black","AGE_TV110_SMG_Holster_Black","AGE_TV110_AK_Coyote","AGE_TV110_AK_Holster_Coyote","AGE_TV110_SMG_Coyote","AGE_TV110_SMG_Holster_Coyote","AGE_TV110_AK_MultiCam","AGE_TV110_AK_Holster_MultiCam","AGE_TV110_SMG_MultiCam", "AGE_TV110_SMG_Holster_MultiCam","AGE_WAS_AK_MultiCam","AGE_WAS_Light_AK_MultiCam","AGE_WAS_Medium_AK_MultiCam","AGE_WAS_Heavy_AK_MultiCam","rhsusf_mbav","rhsusf_mbav_light","rhsusf_mbav_rifleman","V_EOD_coyote_F","V_EOD_olive_F","rhsgref_6b23_khaki_rifleman","rhs_6b2","rhs_6b3","rhs_6b5","rhs_6b5_khaki","rhs_6b43","rhs_6b45_light","rhs_6b45_rifleman","rhs_6b45_rifleman_2","rhs_6b13_Flora","rhs_6b13_Flora_6sh92","rhs_6b13_EMR","rhs_6b13_EMR_6sh92","rhs_6b23","rhs_6b23_6sh116_od","rhs_6b23_6sh116_od","rhs_6b23_digi","rhs_6b23_6sh116","rhs_6b23_digi_6sh92_spetsnaz2","rhs_6b23_6sh116_flora","rhs_6sh117_rifleman","B_AssaultPack_blk","B_AssaultPack_cbr","B_AssaultPack_rgr","B_AssaultPack_khk","B_AssaultPack_sgg","B_AssaultPack_mcamo","B_AssaultPack_tna_F","B_Kitbag_cbr","B_Kitbag_rgr","B_Kitbag_mcamo","B_Kitbag_sgg","B_Kitbag_tan","TRYK_B_Kitbag_blk","B_Carryall_cbr","B_Carryall_khk","B_Carryall_mcamo","B_Carryall_oli","B_Carryall_oucamo","TRYK_B_Carryall_blk","B_Bergen_mcamo_F","B_FieldPack_blk","B_FieldPack_cbr","B_FieldPack_khk","B_FieldPack_oli","TRYK_B_Coyotebackpack_BLK","TRYK_B_Coyotebackpack","TRYK_B_Coyotebackpack_OD","G_Aviator","G_Spectacles_Tinted","G_Sport_BlackRed","G_Tactical_Clear","G_Tactical_Black","rhs_googles_black","rhs_googles_clear","rhs_googles_orange","rhs_googles_yellow","G_Combat","G_Combat_Goggles_tna_F","rhs_ess_black","rhsusf_oakley_goggles_blk","rhsusf_oakley_goggles_clr","rhsusf_oakley_goggles_ylw","G_Balaclava_blk","G_Balaclava_oli","TRYK_kio_balaclava_BLK","TRYK_kio_balaclavas","TRYK_kio_balaclava_ear","TRYK_kio_balaclava_BLK_ear","rhs_balaclava","rhs_balaclava1_olive","G_Bandanna_blk","G_Bandanna_khk","G_Bandanna_oli","G_Bandanna_tan","G_Bandanna_beast","G_Bandanna_aviator","rhs_scarf","G_Balaclava_TI_blk_F","G_Balaclava_TI_G_blk_F","G_Balaclava_TI_tna_F","G_Balaclava_TI_G_tna_F","G_AirPurifyingRespirator_01_F","G_AirPurifyingRespirator_02_black_F","G_AirPurifyingRespirator_02_olive_F","G_AirPurifyingRespirator_02_sand_F","G_RegulatorMask_F","Mask_M40","Mask_M40_OD","TRYK_TAC_EARMUFF_Gs","rhs_facewear_6m2_1","TRYK_headset2_glasses","NVGoggles_OPFOR","NVGoggles","NVGoggles_INDEP","O_NVGoggles_grn_F","rvg_O_NVGoggles_grn_F","NVGogglesB_blk_F","NVGogglesB_grn_F","NVGogglesB_gry_F","rhsusf_ANPVS_14","rhsusf_ANPVS_15","rhs_1PN138"];
_prices_boris = [25,25,50,50,50,25,25,25,25,25,50,50,50,50,550,550,550,550,550,550,600,600,600,600,600,600,700,700,700,700,700,700,750,750,750,550,625,675,725,750,800,550,625,675,725,750,800,550,625,675,725,750,800,600,600,600,600,600,600,1600,1600,500,575,650,500,575,650,500,575,650,500,575,650,500,575,650,500,575,650,500,575,650,500,575,650,500,575,650,500,575,650,500,550,700,625,550,625,625,700,550,625,625,700,550,625,625,550,625,625,900,950,900,10000,10000,10000,913,1413,913,1413,913,1413,913,1413,913,1413,913,1413,194,194,194,194,350,226,246,1100,1100,1330,1330,1550,1550,279,279,279,279,279,279,205,103,103,103,103,103,201,201,201,887,917,887,917,887,917,887,917,887,917,887,917,887,917,1117,1317,3100,3100,3100,1250,1470,1470,870,1470,1470,3100,3100,3100,3100,3100,3100,3100,3100,3100,3100,3100,3100,3100,3100,3100,3100,3100,150,150,150,150,150,150,150,250,250,250,250,250,250,275,275,275,275,275,350,150,150,150,150,250,250,250,25,25,35,125,150,125,125,125,125,150,150,150,150,150,150,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,75,400,400,400,400,400,400,400,300,300,300,15000,15000,15000,15000,15000,30000,30000,30000,15000,15000,15000];
_inventory_ragman = ["U_B_CombatUniform_mcam_tshirt","U_B_CombatUniform_mcam","U_I_G_Story_Protagonist_F","TRYK_C_AOR2_T","U_B_CombatUniform_tshirt_mcam_wdL_f","U_B_CTRG_Soldier_2_Arid_F","U_B_CTRG_Soldier_Arid_F","U_B_CTRG_Soldier_3_Arid_F","U_B_GhillieSuit","U_B_FullGhillie_lsh","U_C_CBRN_Suit_01_White_F","U_C_CBRN_Suit_01_Blue_F","U_B_CBRN_Suit_01_MTP_F","U_B_CBRN_Suit_01_Wdl_F","U_I_E_CBRN_Suit_01_EAF_F","U_O_R_Gorka_01_F","U_O_R_Gorka_01_camo_F","U_O_R_Gorka_01_black_F","rhs_uniform_gorka_r_g","rhs_uniform_gorka_r_g_gloves","rhs_uniform_gorka_r_y","rhs_uniform_gorka_r_y_gloves","TRYK_U_pad_hood_Blod","TRYK_U_pad_hood_Cl_blk","TRYK_U_pad_hood_Blk","TRYK_U_pad_hood_tan","TRYK_U_pad_hood_odBK","TRYK_U_pad_hood_Cl","TRYK_U_hood_nc"];
_prices_ragman = [99,99,99,99,99,99,99,99,10000,15000,2500,2500,2500,2500,2500,99,99,99,99,99,99,99,99,99,99,99,99,99,99];


systemChat format ["%1:%2 - %3:%4 - %5:%6 - %7:%8 - %9:%10", count _inventory_pavlov,count _prices_pavlov, count _inventory_adams,count _prices_adams, count _inventory_boris,count _prices_boris, count _inventory_surgeon,count _prices_surgeon, count _inventory_dimitri,count _prices_dimitri];
_money = player getVariable ["money",1000];
_funds ctrlSetText (str _money + " KEK-Rubs");


traderItems = [];
traderPrices = [];
allItemsPool = ["B_AssaultPack_blk","B_AssaultPack_cbr","B_AssaultPack_rgr","B_AssaultPack_khk","B_AssaultPack_sgg","B_AssaultPack_mcamo","B_AssaultPack_tna_F","B_Kitbag_cbr","B_Kitbag_rgr","B_Kitbag_mcamo","B_Kitbag_sgg","B_Kitbag_tan","TRYK_B_Kitbag_blk","B_Carryall_cbr","B_Carryall_khk","B_Carryall_mcamo","B_Carryall_oli","B_Carryall_oucamo","TRYK_B_Carryall_blk","B_Bergen_mcamo_F","TRYK_B_Coyotebackpack_BLK","TRYK_B_Coyotebackpack","TRYK_B_Coyotebackpack_OD","B_FieldPack_blk","B_FieldPack_cbr","B_FieldPack_khk","B_FieldPack_oli"] + _inventory_adams + _inventory_boris + _inventory_dimitri + _inventory_pavlov + _inventory_ragman + _inventory_surgeon;
allPricesPool = [] + _prices_adams + _prices_boris + _prices_dimitri + _prices_pavlov + _prices_ragman + _prices_surgeon;

switch _trader do 
{
	case "Pavlov":
	{
		_trader_pic ctrlSetText (_pics select 0);
		_trader_name ctrlSetText _trader;
		
		traderItems = _inventory_pavlov;
		traderPrices = _prices_pavlov;
	};
	case "Surgeon":
	{
		_trader_pic ctrlSetText (_pics select 1);
		_trader_name ctrlSetText _trader;
		
		traderItems = _inventory_surgeon;
		traderPrices = _prices_surgeon;
	};
	case "Dimitri":
	{
		_trader_pic ctrlSetText (_pics select 2);
		_trader_name ctrlSetText _trader;
		
		traderItems = _inventory_dimitri;
		traderPrices = _prices_dimitri;
	};
	case "Adams":
	{
		_trader_pic ctrlSetText (_pics select 3);
		_trader_name ctrlSetText _trader;
		
		traderItems = _inventory_adams;
		traderPrices = _prices_adams;
	};
	case "Boris":
	{
		_trader_pic ctrlSetText (_pics select 4);
		_trader_name ctrlSetText _trader;
		
		traderItems = _inventory_boris;
		traderPrices = _prices_boris;
	};
	case "Ragman":
	{
		_trader_pic ctrlSetText (_pics select 5);
		_trader_name ctrlSetText _trader;
		
		traderItems = _inventory_ragman;
		traderPrices = _prices_ragman;
	};
};
{
	_itemName = "";
	_itemIcon = "";
	if (isClass (configFile >> "CfgWeapons" >> _x )) then 
	{
		_itemName =  getText (configFile >> "CfgWeapons" >> _x >> "displayName");
		_itemIcon =  getText (configFile >> "CfgWeapons" >> _x >> "picture");
	};
	if (isClass (configFile >> "CfgGlasses" >> _x )) then 
	{
		_itemName =  getText (configFile >> "CfgGlasses" >> _x >> "displayName");
		_itemIcon =  getText (configFile >> "CfgGlasses" >> _x >> "picture");
	};
	if (isClass (configFile >> "CfgMagazines" >> _x )) then 
	{
		_itemName =  getText (configFile >> "CfgMagazines" >> _x >> "displayName");
		_itemIcon =  getText (configFile >> "CfgMagazines" >> _x >> "picture");
	};
	if (isClass (configFile >> "CfgVehicles" >> _x ) && !isClass (configFile >> "CfgWeapons" >> _x )) then 
	{
		_itemName =  getText (configFile >> "CfgVehicles" >> _x >> "displayName");
		_itemIcon =  getText (configFile >> "CfgVehicles" >> _x >> "picture");
	};
	_stash_trader lbAdd _itemName;
	_stash_trader lbSetPicture [_foreachindex,_itemIcon];
	_stash_trader lbSetPictureColor [_foreachindex, [1, 1, 1, 1]];
} forEach traderItems;

[] call rad_fnc_stashRefresh;

buy_amount = 1;



_stash_trader ctrlAddEventHandler ["LBSelChanged",
{
	_menu = findDisplay 69421;
	_list = _menu displayCtrl 100;
	_price = _menu displayCtrl 201;
	_price ctrlSetText ("Price: " + str ((traderPrices select (lbCurSel _list)) * buy_amount));
}];
_stash_player ctrlAddEventHandler ["LBSelChanged",
{
	_menu = findDisplay 69421;
	_list = _menu displayCtrl 101;
	_price = _menu displayCtrl 202;
	_funds = _menu displayCtrl 6;
	_money = player getVariable ["money",1000];
	_inventory = (weaponsItems (player getVariable "stashCrate") + itemCargo (player getVariable "stashCrate") + magazinesAmmoCargo (player getVariable "stashCrate"));
	_totalPrice = 0;
	_crate = (player getVariable "stashCrate");
	if (count (weaponCargo _crate + itemCargo _crate + magazineCargo _crate) > 0) then {
	_toSell = (_inventory select (lbCurSel _list));
	if (typeName _toSell == "ARRAY") then
	{
		if (count _toSell > 2) then 
		{
			{
				_item = _x;
				if (typeName _item == "ARRAY") then //Check if it's a magazine
				{
					if (count _item > 0) then 
					{
						_item = _x select 0;
						_ammoMax = getNumber (configfile >> "CfgMagazines" >> _item >> "count");
						_ammo = _x select 1;
						if (_item in allItemsPool) then {_totalPrice = _totalPrice + round ((allPricesPool select (allItemsPool find _item)) * (_ammo / _ammoMax))} else {_totalPrice = _totalPrice + round (35 * (_ammo / _ammoMax))};
					};
				} else 
				{	
					if (_item != "") then 
					{
						if (_item in allItemsPool) then {_totalPrice = _totalPrice + (allPricesPool select (allItemsPool find _item))} else {if (_forEachIndex == 0) then {_totalPrice = _totalPrice + 550} else {_totalPrice = _totalPrice + 60}};
					};
				};
			} forEach _toSell;
		} else
		{
			if (count _toSell != 0) then 
			{
				_item = _toSell select 0;
				_ammoMax = getNumber (configfile >> "CfgMagazines" >> _item >> "count");
				_ammo = _toSell select 1;
				if (_item in allItemsPool) then {_totalPrice = _totalPrice + round ((allPricesPool select (allItemsPool find _item)) * (_ammo / _ammoMax))} else {_totalPrice = _totalPrice + round (35 * (_ammo / _ammoMax))};
			};
		};
	} else
	{
		_item = _toSell;
		if (_item in allItemsPool) then {_totalPrice = _totalPrice + (allPricesPool select (allItemsPool find _item))} else {_totalPrice = _totalPrice + 60};
	};};
	_price ctrlSetText ("Price: " + str _totalPrice);
}];





(_menu displayCtrl 103) ctrlAddEventHandler ["MouseButtonDown",
{
	if (buy_amount > 1) then 
	{
		_menu = findDisplay 69421;
		_list = _menu displayCtrl 100;
		_price = _menu displayCtrl 201;
		buy_amount = buy_amount - 1;
		(_menu displayCtrl 105) ctrlSetText ("Amount: " + str buy_amount);
		_price ctrlSetText ("Price: " + str ((traderPrices select (lbCurSel _list)) * buy_amount));
		
	};
}];
(_menu displayCtrl 104) ctrlAddEventHandler ["MouseButtonDown",
{
	_menu = findDisplay 69421;
	_list = _menu displayCtrl 100;
	_price = _menu displayCtrl 201;
	buy_amount = buy_amount + 1;
	(_menu displayCtrl 105) ctrlSetText ("Amount: " + str buy_amount);
	_price ctrlSetText ("Price: " + str ((traderPrices select (lbCurSel _list)) * buy_amount));
}];
(_menu displayCtrl 102) ctrlAddEventHandler ["MouseButtonClick",
{
	_menu = findDisplay 69421;
	_list = _menu displayCtrl 100;
	_funds = _menu displayCtrl 6;
	_totalPrice = (traderPrices select (lbCurSel _list)) * buy_amount;
	_money = player getVariable ["money",1000];
	if (_money >= _totalPrice) then 
	{
		if (isClass (configFile >> "CfgVehicles" >> (traderItems select (lbCurSel _list)))) then 
		{
			(player getVariable "stashCrate") addBackpackCargoGlobal [traderItems select (lbCurSel _list),buy_amount];
		} else {(player getVariable "stashCrate") addItemCargoGlobal [traderItems select (lbCurSel _list),buy_amount];};
		_money = _money - _totalPrice;
		_funds ctrlSetText (str _money + " KEK-Rubs");
		player setVariable ["money",_money];
		[] call rad_fnc_stashRefresh;
		hint "Item(s) Purchased!";
	} else {hint "Not enough funds!"};
}];
(_menu displayCtrl 106) ctrlAddEventHandler ["MouseButtonClick",
{
	_menu = findDisplay 69421;
	_list = _menu displayCtrl 101;
	_price = _menu displayCtrl 202;
	_funds = _menu displayCtrl 6;
	_money = player getVariable ["money",1000];
	_inventory = (weaponsItems (player getVariable "stashCrate") + itemCargo (player getVariable "stashCrate") + magazinesAmmoCargo (player getVariable "stashCrate"));
	_toSell = (_inventory select (lbCurSel _list));
	_totalPrice = 0;
	if (typeName _toSell == "ARRAY") then
	{
		if (count _toSell > 2) then 
		{
			{
				_item = _x;
				if (typeName _item == "ARRAY") then //Check if it's a magazine
				{
					if (count _item > 0) then 
					{
						_item = _x select 0;
						_ammoMax = getNumber (configfile >> "CfgMagazines" >> _item >> "count");
						_ammo = _x select 1;
						if (_item in allItemsPool) then {_totalPrice = _totalPrice + round ((allPricesPool select (allItemsPool find _item)) * (_ammo / _ammoMax))} else {_totalPrice = _totalPrice + round (35 * (_ammo / _ammoMax))};
					};
				} else 
				{	
					if (_item != "") then 
					{
						if (_item in allItemsPool) then {_totalPrice = _totalPrice + (allPricesPool select (allItemsPool find _item))} else {if (_forEachIndex == 0) then {_totalPrice = _totalPrice + 550} else {_totalPrice = _totalPrice + 60}};
					};
				};
			} forEach _toSell;
		} else
		{
			if (count _toSell != 0) then 
			{
				_item = _toSell select 0;
				_ammoMax = getNumber (configfile >> "CfgMagazines" >> _item >> "count");
				_ammo = _toSell select 1;
				if (_item in allItemsPool) then {_totalPrice = _totalPrice + round ((allPricesPool select (allItemsPool find _item)) * (_ammo / _ammoMax))} else {_totalPrice = _totalPrice + round (35 * (_ammo / _ammoMax))};
			};
		};
	} else
	{
		_item = _toSell;
		if (_item in allItemsPool) then {_totalPrice = _totalPrice + (allPricesPool select (allItemsPool find _item))} else {_totalPrice = _totalPrice + 60};
	};
	player setVariable ["money", _money + _totalPrice];
	_funds ctrlSetText (str (_money + _totalPrice) + " KEK-Rubs");
	[_toSell] call rad_fnc_stashRemove;
}];

_stash_trader lbSetCurSel 0;
_stash_player lbSetCurSel 0;