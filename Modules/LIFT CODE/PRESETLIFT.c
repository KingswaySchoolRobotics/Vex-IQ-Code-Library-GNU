#pragma systemFile
#include "PRESET_LIB.h"
task main()
{
	while(true) {
	if (getJoystickValue(BtnLDown)==1 && IndexArmPressed==false) {  //gets the reading of LUP & LDOWN and turns it into a variable(ArmPresetValue)
			ArmPresetValue = (ArmPresetValue-1);
			ArmHeightMove();
			IndexArmPressed=true;
		}
		else {
			if (getJoystickValue(BtnLUp)==1 && IndexArmPressed==false) {
				ArmPresetValue = (ArmPresetValue+1);
				ArmHeightMove();
				IndexArmPressed=true;
			}
		};
		if (getJoystickValue(BtnLDown)==0 && getJoystickValue(BtnLUp)==0) {
			IndexArmPressed=false;
		};
		if (0>ArmPresetValue){
			ArmPresetValue = 0;
		}
		else {
			if (4<ArmPresetValue) {
				ArmPresetValue = 5;
			};
		}

			if (getJoystickValue(BtnRUp)) {
			setMotorSpeed(CubeClaw, 100);
			} else if (getJoystickValue(BtnRDown)) {
			setMotorSpeed(CubeClaw, -100);
			} else {
			setMotorSpeed(CubeClaw, 0);
		};

	};
}
