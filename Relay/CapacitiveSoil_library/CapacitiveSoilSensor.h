/*
	CapacitiveSoilSensor.h - Library for the Capacitive Sensor code.
	by Edward Salcido derived from code by berinie Chen <bernie.chen@dfrobot.com>

	GNU Lesser General Public License.
	See <http://www.gnu.org/licenses/> for details.
	All above must be included in any redistribution

*/
#ifndef CapacitiveSoilSensor_h
#define CapacitiveSoilSensor_h


class CapacitiveSoilSensor
{
	public:
		CapacitiveSoilSensor(int _pin);
		// void setup();
		int getMoistureValue();
	private:
		int _pin;
		const int AirValue =0 ;
		const int WaterValue =0;
		int intervals;
		int soilMoistureValue;


};

#endif