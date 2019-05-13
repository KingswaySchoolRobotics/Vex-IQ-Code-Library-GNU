#pragma systemFile

void driveDistance(float distance) { // function that converts mm into rotations / degrees so the robot can then use the built in PIDcontroller to turn that ammount
	float MoveDistanceRotations=distance/200*360; //divides the input mm by 100 then times it by 360 to get the rotations / degrees
	moveMotorTarget(Left, MoveDistanceRotations, 100); // moves the motors according to the output variable from 'MoveDistanceRotations'
	moveMotorTarget(Right, MoveDistanceRotations, 100);
};
