/*Convert the Temperature
You are given a non-negative floating point number rounded to two decimal places celsius, that denotes the temperature in Celsius.
You should convert Celsius into Kelvin and Fahrenheit and return it as an array ans = [kelvin, fahrenheit].
Kelvin = Celsius + 273.15
Fahrenheit = Celsius * 1.80 + 32.00*/
class Solution
{
public:
    vector<double> convertTemperature(double celsius)
    {
        return {celsius + 273.15, celsius * 1.80 + 32.00};
    }
};
// TC - O(1)  SC - O(1)