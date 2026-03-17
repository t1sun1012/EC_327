//Provided code
/**
 * This function determines if you have a new best time
 when you are runing a marathon. This function should 
 return true if your best time is reduced. False otherwise.
 Your best time improves (reduces) as follows:
 1. If not badWeather and you trained, your best time reduces by 20
 2. If there is badWeather and you trained, your best time reduces by 10
 3. Otherwise your best time does not change.
 

 * @param badWeather - true for badWeather, false for not badWeather 
 * @param trained - true for a trained, false otherwise
 * @param bestTime - your best time 
 */
 
 
//Put runAMarathon function here as described in raceCalc.h 
bool runAMarathon (double* bestTime, bool badWeather, bool trained)
 {
	 
	 if (!badWeather && trained)
	 {
		*bestTime -= 20.0;
		return true;
	 }
		 
	 else if (!trained)
	 {
		 return false;
	 }
		 
	 else if (badWeather && trained )
	 {
		 *bestTime -= 10.0;
		 return true;
	 }
	 else
		return false; 
 }
 
 

