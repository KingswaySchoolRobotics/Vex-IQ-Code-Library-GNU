#pragma systemFile

bool TurnDegrees (float varTurnDegrees) { // turn PID function that returns true or false once finished
	static bool InProgressTask; // defines the static bool that keeps the function looping until it has completed the turn
	if (!InProgressTask) { // starts code while it hasn't completed the turn
		resetGyro(Main_Gyro); // resets the gyro
		if (varTurnDegrees>0) { // checks whether the setpoint (where we want to be) is greater than 0 so we turn right or if its less than 0 it turns Left
			setMotorSpeed(Left, 50); // turns Right
			setMotorSpeed(Right, -50);
			} else {
			setMotorSpeed(Left, -50); // turns Left
			setMotorSpeed(Right, 50);
		};
	};
	InProgressTask = true; // stops the above code
	if ((getGyroDegreesFloat(Main_Gyro)>varTurnDegrees && varTurnDegrees>0) || (getGyroDegreesFloat(Main_Gyro)<varTurnDegrees && varTurnDegrees<0)) { // if the robot has turned to the setpoint then stop the Motors
		InProgressTask = false; // starts above code again if it has overshot
		setMotorSpeed(Left, 0); // stops both motors
		setMotorSpeed(Right, 0);
		return true; // returns true if it has finished so that the sequence can move to the next command

	};
	return false; // returns false if it has not finished so that the sequence waits until it is finished
};

void GyroCustomCalibration(int count = 30) {
	startGyroCalibration( Main_Gyro, gyroCalibrateSamples512 );
	// delay so calibrate flag can be set internally to the gyro
	wait1Msec(100);

	// wait for calibration to finish or 2 seconds, whichever is longer
	while( getGyroCalibrationFlag(Main_Gyro) || (count-- > 0) ) {
		wait1Msec(100);
	} resetGyro(Main_Gyro);
};
