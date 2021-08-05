
class traders
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
			x = safeZoneX + safeZoneW * 0.06875;
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
			x = safeZoneX + safeZoneW * 0.150625;
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
			x = safeZoneX + safeZoneW * 0.41875;
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
			x = safeZoneX + safeZoneW * 0.69375;
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
			x = safeZoneX + safeZoneW * 0.14375;
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
			x = safeZoneX + safeZoneW * 0.41875;
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
			x = safeZoneX + safeZoneW * 0.69375;
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
			x = safeZoneX + safeZoneW * 0.14375;
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
			x = safeZoneX + safeZoneW * 0.41875;
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
			x = safeZoneX + safeZoneW * 0.69375;
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
			x = safeZoneX + safeZoneW * 0.14375;
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
			x = safeZoneX + safeZoneW * 0.41875;
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
			x = safeZoneX + safeZoneW * 0.69375;
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
			x = safeZoneX + safeZoneW * 0.09375;
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
		class Trader_B_1
		{
			type = 1;
			idc = 101;
			x = safeZoneX + safeZoneW * 0.14375;
			y = safeZoneY + safeZoneH * 0.15111112;
			w = safeZoneW * 0.148125;
			h = safeZoneH * 0.24555556;
			style = 0;
			text = "";
			borderSize = 0;
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			colorShadow[] = {0,0,0,0};
			colorText[] = {0,0,0,0};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			
		};
		class Trader_B_2
		{
			type = 1;
			idc = 102;
			x = safeZoneX + safeZoneW * 0.411875;
			y = safeZoneY + safeZoneH * 0.16444445;
			w = safeZoneW * 0.148125;
			h = safeZoneH * 0.24555556;
			style = 0;
			text = "";
			borderSize = 0;
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			colorShadow[] = {0,0,0,0};
			colorText[] = {0,0,0,0};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			
		};
		class Trader_B_3
		{
			type = 1;
			idc = 103;
			x = safeZoneX + safeZoneW * 0.690625;
			y = safeZoneY + safeZoneH * 0.16444445;
			w = safeZoneW * 0.148125;
			h = safeZoneH * 0.24555556;
			style = 0;
			text = "";
			borderSize = 0;
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			colorShadow[] = {0,0,0,0};
			colorText[] = {0,0,0,0};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			
		};
		class Trader_B_4
		{
			type = 1;
			idc = 104;
			x = safeZoneX + safeZoneW * 0.13375;
			y = safeZoneY + safeZoneH * 0.57777778;
			w = safeZoneW * 0.148125;
			h = safeZoneH * 0.24555556;
			style = 0;
			text = "";
			borderSize = 0;
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			colorShadow[] = {0,0,0,0};
			colorText[] = {0,0,0,0};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			
		};
		class Trader_B_5
		{
			type = 1;
			idc = 105;
			x = safeZoneX + safeZoneW * 0.411875;
			y = safeZoneY + safeZoneH * 0.59111112;
			w = safeZoneW * 0.148125;
			h = safeZoneH * 0.24555556;
			style = 0;
			text = "";
			borderSize = 0;
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			colorShadow[] = {0,0,0,0};
			colorText[] = {0,0,0,0};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			
		};
		class Trader_B_6
		{
			type = 1;
			idc = 106;
			x = safeZoneX + safeZoneW * 0.690625;
			y = safeZoneY + safeZoneH * 0.57777778;
			w = safeZoneW * 0.148125;
			h = safeZoneH * 0.24555556;
			style = 0;
			text = "";
			borderSize = 0;
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			colorShadow[] = {0,0,0,0};
			colorText[] = {0,0,0,0};
			font = "PuristaMedium";
			offsetPressedX = 0.01;
			offsetPressedY = 0.01;
			offsetX = 0.01;
			offsetY = 0.01;
			sizeEx = (((((safezoneW / safezoneH) min 1.2) / 1.2) / 25) * 1);
			soundClick[] = {"\A3\ui_f\data\sound\RscButton\soundClick",0.09,1.0};
			soundEnter[] = {"\A3\ui_f\data\sound\RscButton\soundEnter",0.09,1.0};
			soundEscape[] = {"\A3\ui_f\data\sound\RscButton\soundEscape",0.09,1.0};
			soundPush[] = {"\A3\ui_f\data\sound\RscButton\soundPush",0.09,1.0};
			
		};
		
	};
	
};
