
class tradeMenu
{
	idd = 69420;
	movingEnable = false;
	
	class ControlsBackground
	{
		
	};
	class Controls
	{
		class background
		{
			type = 0;
			idc = 0;
			x = safeZoneX + safeZoneW * 0.09375;
			y = safeZoneY + safeZoneH * 0.00444445;
			w = safeZoneW * 0.8375;
			h = safeZoneH * 0.99;
			style = 2;
			text = "";
			colorBackground[] = {0,0,0,1};
			colorText[] = {0.0196,0.5137,0.4824,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class trader_1
		{
			type = 0;
			idc = 1;
			x = safeZoneX + safeZoneW * 0.175625;
			y = safeZoneY + safeZoneH * 0.17444445;
			w = safeZoneW * 0.131875;
			h = safeZoneH * 0.22555556;
			style = 0+48;
			text = "";
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class trader_2
		{
			type = 0;
			idc = 2;
			x = safeZoneX + safeZoneW * 0.44375;
			y = safeZoneY + safeZoneH * 0.17555556;
			w = safeZoneW * 0.1375;
			h = safeZoneH * 0.23222223;
			style = 0+48;
			text = "";
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class trader_3
		{
			type = 0;
			idc = 3;
			x = safeZoneX + safeZoneW * 0.71875;
			y = safeZoneY + safeZoneH * 0.17555556;
			w = safeZoneW * 0.1375;
			h = safeZoneH * 0.23222223;
			style = 0+48;
			text = "";
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class trader_4
		{
			type = 0;
			idc = 4;
			x = safeZoneX + safeZoneW * 0.16875;
			y = safeZoneY + safeZoneH * 0.59111112;
			w = safeZoneW * 0.1375;
			h = safeZoneH * 0.23222223;
			style = 0+48;
			text = "";
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class trader_5
		{
			type = 0;
			idc = 5;
			x = safeZoneX + safeZoneW * 0.44375;
			y = safeZoneY + safeZoneH * 0.59111112;
			w = safeZoneW * 0.1375;
			h = safeZoneH * 0.23222223;
			style = 0+48;
			text = "";
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class trader_6
		{
			type = 0;
			idc = 6;
			x = safeZoneX + safeZoneW * 0.71875;
			y = safeZoneY + safeZoneH * 0.59111112;
			w = safeZoneW * 0.1375;
			h = safeZoneH * 0.23222223;
			style = 0+48;
			text = "";
			colorBackground[] = {1,1,1,1};
			colorText[] = {1,1,1,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			
		};
		class Name_1
		{
			type = 0;
			idc = 11;
			x = safeZoneX + safeZoneW * 0.16875;
			y = safeZoneY + safeZoneH * 0.42;
			w = safeZoneW * 0.1375;
			h = safeZoneH * 0.06111112;
			style = 2;
			text = "Pavlov";
			colorBackground[] = {0.2824,0.8039,0.0157,0};
			colorText[] = {0.8,0.6824,0.4941,1};
			font = "PuristaBold";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 3);
			
		};
		class Name_2
		{
			type = 0;
			idc = 12;
			x = safeZoneX + safeZoneW * 0.44375;
			y = safeZoneY + safeZoneH * 0.42;
			w = safeZoneW * 0.1375;
			h = safeZoneH * 0.06111112;
			style = 2;
			text = "Surgeon";
			colorBackground[] = {0.2824,0.8039,0.0157,0};
			colorText[] = {0.8,0.6824,0.4941,1};
			font = "PuristaBold";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 3);
			
		};
		class Name_3
		{
			type = 0;
			idc = 13;
			x = safeZoneX + safeZoneW * 0.71875;
			y = safeZoneY + safeZoneH * 0.42;
			w = safeZoneW * 0.1375;
			h = safeZoneH * 0.06111112;
			style = 2;
			text = "Dimitri";
			colorBackground[] = {0.2824,0.8039,0.0157,0};
			colorText[] = {0.8,0.6824,0.4941,1};
			font = "PuristaBold";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 3);
			
		};
		class Name_4
		{
			type = 0;
			idc = 14;
			x = safeZoneX + safeZoneW * 0.16875;
			y = safeZoneY + safeZoneH * 0.83555556;
			w = safeZoneW * 0.1375;
			h = safeZoneH * 0.06111112;
			style = 2;
			text = "Adams";
			colorBackground[] = {0.2824,0.8039,0.0157,0};
			colorText[] = {0.8,0.6824,0.4941,1};
			font = "PuristaBold";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 3);
			
		};
		class Name_5
		{
			type = 0;
			idc = 15;
			x = safeZoneX + safeZoneW * 0.44375;
			y = safeZoneY + safeZoneH * 0.83555556;
			w = safeZoneW * 0.1375;
			h = safeZoneH * 0.06111112;
			style = 2;
			text = "Boris";
			colorBackground[] = {0.2824,0.8039,0.0157,0};
			colorText[] = {0.8,0.6824,0.4941,1};
			font = "PuristaBold";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 3);
			
		};
		class Name_6
		{
			type = 0;
			idc = 16;
			x = safeZoneX + safeZoneW * 0.71875;
			y = safeZoneY + safeZoneH * 0.83555556;
			w = safeZoneW * 0.1375;
			h = safeZoneH * 0.06111112;
			style = 2;
			text = "Ragman";
			colorBackground[] = {0.2824,0.8039,0.0157,0};
			colorText[] = {0.8,0.6824,0.4941,1};
			font = "PuristaBold";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 3);
			
		};
		class background_copy1
		{
			type = 0;
			idc = 7;
			x = safeZoneX + safeZoneW * 0.11875;
			y = safeZoneY + safeZoneH * 0.02888889;
			w = safeZoneW * 0.7875;
			h = safeZoneH * 0.94111112;
			style = 2+64;
			text = "Chernorussian Free Market";
			colorBackground[] = {0,0,0,1};
			colorText[] = {0.7992,0.6818,0.4946,1};
			font = "PuristaMedium";
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 3.5);
			
		};
		
	};
	
};
