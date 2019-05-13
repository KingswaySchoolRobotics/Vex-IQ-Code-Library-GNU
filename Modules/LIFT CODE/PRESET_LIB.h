#pragma systemFile
float Height0 = 0; //Floor
float Height1 = -100; //Place HighScored Hub and Move MultiPusher Over Field Lines
float Height2 = -200; //Position HighScored Hub
float Height3 = -300; //Static Height / Moving height for balance
float Height4 = -500; //Bonus Hub Position
float Height5 = -680; //Bonus Hub PickUp
int ArmPresetValue = 0; // the preset number that tells the preset code how high to move the arm

void ArmHeightMove() { //moves the arm to the defined positions (height 0, Height1, Height2, etc) based on the variable ArmPresetValue
	switch(ArmPresetValue) {  //moves the arm by reading the variable (ArmPresetValue)
	case 0://Floor
		setMotorTarget(ArmLeft, Height0, 100);
		setMotorTarget(ArmRight, Height0, 100);
		setTouchLEDColor(LED,colorOrange);
		break;

	case 1://
		setMotorTarget(ArmLeft, Height1, 100);
		setMotorTarget(ArmRight, Height1, 100);
		setTouchLEDColor(LED,colorOrange);
		break;

	case 2://
		setMotorTarget(ArmLeft, Height2, 100);
		setMotorTarget(ArmRight, Height2, 100);
		setTouchLEDColor(LED,colorOrange);
		break;

	case 3://Static Height / Moving height for balance
		setMotorTarget(ArmLeft, Height3, 100);
		setMotorTarget(ArmRight, Height3, 100);
		setTouchLEDColor(LED,colorOrange);
		break;

	case 4://
		setMotorTarget(ArmLeft, Height4, 100);
		setMotorTarget(ArmRight, Height4, 100);
		setTouchLEDColor(LED,colorOrange);
		break;

	case 5://
		setMotorTarget(ArmLeft, Height5, 100);
		setMotorTarget(ArmRight, Height5, 100);
		setTouchLEDColor(LED,colorOrange);
		break;

	};
};
