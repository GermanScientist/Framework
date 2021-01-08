#include <myFramework/time.h>

//Constructor
Time::Time()
{

}

//Destructor
Time::~Time()
{

}

//Update delta time function
float Time::getDeltaTime() {

	//LastTime is initialised only the first time this function is called
	static double lastTime = glfwGetTime();

	//Get the current time
	double currentTime = glfwGetTime();

	//Compute time difference between current and last time
	float deltaTime = float(currentTime - lastTime);

	//For the next frame, the "last time" will be "now"
	lastTime = currentTime;
	
	//Return deltatime
	return deltaTime;
}