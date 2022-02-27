#include "methodimplementations.h"
#include "languageexception.h"
#include "chartplot.h"
#include "node.h"
#include <numbers>
#include <numeric>
#include <random>


ExpressionValue MethodAverage::interpret(const unsigned int tick) {

	// if any argument is a NAN return NAN
	if (!value1->value || !value2->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber((*value1->value + *value2->value) / 2);
}


ExpressionValue UnaryPlusOperator::interpret(const unsigned int tick) {
	// if arg is null return a null
	if (!value->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber(+*value->value);
}

ExpressionValue UnaryMinusOperator::interpret(const unsigned int tick) {
	// if arg is null return a null
	if (!value->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber(-*value->value);
}


ExpressionValue UnaryNotOperator::interpret(const unsigned int tick) {
	// if arg is null return a null
	if (!value->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(!*value->value);
}


ExpressionValue BinaryPlusOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber(*lhsValue->value + *rhsValue->value);
}

ExpressionValue BinaryStringConcat::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueString();
	}
	return NullableValueString(*lhsValue->value + *rhsValue->value);
}


ExpressionValue BinaryMinusOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber(*lhsValue->value - *rhsValue->value);
}

ExpressionValue BinaryDivideOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueNumber();
	}
	if (*rhsValue->value == 0) {
		throw LanguageException("Attempt to divide by 0", rhsNode);
	}
	return NullableValueNumber(*lhsValue->value / *rhsValue->value);
}


ExpressionValue BinaryMultiplyOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueNumber();
	}
	return NullableValueNumber(*lhsValue->value * *rhsValue->value);
}

ExpressionValue BinaryPowOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueNumber();
	}
	if (*rhsValue->value == 0) {
		throw LanguageException("Attempt to raise by power 0", rhsNode);
	}
	return NullableValueNumber(std::powf(*lhsValue->value, *rhsValue->value));
}



ExpressionValue BinaryModOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueNumber();
	}
	if (*rhsValue->value == 0) {
		throw LanguageException("Attempt to divide by 0", rhsNode);
	}
	return NullableValueNumber(std::fmod(*lhsValue->value, *rhsValue->value));
}




ExpressionValue BinaryLessOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value < *rhsValue->value);
}

ExpressionValue BinaryLessEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value <= *rhsValue->value);
}


ExpressionValue BinaryGreaterOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value > *rhsValue->value);
}


ExpressionValue BinaryGreaterEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value >= *rhsValue->value);
}


ExpressionValue BinaryAndOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value && *rhsValue->value);
}


ExpressionValue BinaryOrOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value || *rhsValue->value);
}


ExpressionValue BinaryBooleanEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value == *rhsValue->value);
}


ExpressionValue BinaryFloatEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value == *rhsValue->value);
}

ExpressionValue BinaryStringEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value == *rhsValue->value);
}


ExpressionValue BinaryBooleanNotEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value != *rhsValue->value);
}

ExpressionValue BinaryFloatNotEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value != *rhsValue->value);
}


ExpressionValue BinaryStringNotEqualOperator::interpret(const unsigned int tick) {
	// if any argument is a NAN return NAN
	if (!lhsValue->value || !rhsValue->value) {
		return NullableValueBoolean();
	}
	return NullableValueBoolean(*lhsValue->value != *rhsValue->value);
}


ExpressionValue GetTick::interpret(const unsigned int tick) {
	return NullableValueNumber(tick);
}


ExpressionValue Plot::interpret(const unsigned int tick) {


	// if null return a null value else extract the correct value
	float pushBackValue = value->value ? *value->value : std::numeric_limits<double>::quiet_NaN();
	plotdata->data[tick] = pushBackValue;

	return NullableValueBoolean(true);
}


ExpressionValue Mark::interpret(const unsigned int tick) {
	//if not null
	if (when->value) {

		// if positive
		if (*when->value) {

			float pushBackValue = value->value ? *value->value : std::numeric_limits<double>::quiet_NaN();
			plotdata->data[tick] = (pushBackValue);
		}
		else {
			plotdata->data[tick] = (std::numeric_limits<double>::quiet_NaN());
		}
	}
	else {
		plotdata->data[tick] = (std::numeric_limits<double>::quiet_NaN());
	}
	return NullableValueBoolean(true);
}


ExpressionValue ValueWhenNumber::interpret(const unsigned int tick) {
	if (when->value) {
		if (*when->value) {
			currentValue = *value;
		}
	}
	return currentValue;
}

ExpressionValue ValueWhenBoolean::interpret(const unsigned int tick) {
	if (when->value) {
		if (*when->value) {
			currentValue = *value;
		}
	}
	return currentValue;
}


ExpressionValue ValueWhenString::interpret(const unsigned int tick) {
	if (when->value) {
		if (*when->value) {
			currentValue = *value;
		}
	}
	return currentValue;
}





ExpressionValue FloatNAN::interpret(const unsigned int tick) {
	return NullableValueNumber();
}

ExpressionValue BooleanNAN::interpret(const unsigned int tick) {
	return NullableValueBoolean();
}


ExpressionValue StringNAN::interpret(const unsigned int tick) {
	return NullableValueString();
}

ExpressionValue Minimum::interpret(const unsigned int tick) {
	if (value->value) {
		if (*value->value < *currentMinimum.value) {
			currentMinimum = *value;
		}
	}

	return currentMinimum;
}


ExpressionValue MinimumBars::interpret(const unsigned int tick) {
	int lookback = (int)*bars_back->value;
	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", moving average function must use positive non zero amount.", barsBackNode);
	}

	buffer.push_back(value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());


	if (buffer.size() >= lookback) {
		float min = std::numeric_limits<double>::quiet_NaN();

		for (int i = buffer.size() - lookback; i < buffer.size(); i++) {

			if (std::isnan(min)) {
				min = buffer[i];
			}

			if (buffer[i] < min) {
				min = buffer[i];
			}
		}
		if (std::isnan(min)) {
			return NullableValueNumber();
		}
		return NullableValueNumber(min);
	}
	return NullableValueNumber();
}


ExpressionValue Maximum::interpret(const unsigned int tick) {
	if (value->value) {
		if (*value->value > *maximumValue.value) {
			maximumValue = *value;
		}
	}

	return maximumValue;
}


ExpressionValue MaximumBars::interpret(const unsigned int tick) {

	int lookback = (int)*bars_back->value;
	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", moving average function must use positive non zero amount.", barsBackNode);
	}

	buffer.push_back(value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());


	if (buffer.size() >= lookback) {
		float max = std::numeric_limits<double>::quiet_NaN();

		for (int i = buffer.size() - lookback; i < buffer.size(); i++) {
			
			if (std::isnan(max)) {
				max = buffer[i];
			}

			if (buffer[i] > max) {
				max = buffer[i];
			}
		}
		if (std::isnan(max)) {
			return NullableValueNumber();
		}
		return NullableValueNumber(max);
	}
	return NullableValueNumber();
}


ExpressionValue Sum::interpret(const unsigned int tick) {
	if (value->value) {
		sum += *value->value;
	}

	return NullableValueNumber(sum);
}



ExpressionValue SumBars::interpret(const unsigned int tick) {

	int lookback = (int)*bars_back->value;
	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", sum function must use positive non zero amount.", barsBackNode);
	}

	buffer.push_back(value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());


	if (buffer.size() >= lookback) {
		float sum = 0;

		for (int i = buffer.size() - lookback; i < buffer.size(); i++) {

			if (std::isnan(buffer[i])) {
				return NullableValueNumber();
			}
			sum += buffer[i];
		}
		
		return NullableValueNumber(sum);
	}
	return NullableValueNumber();
}



ExpressionValue Mean::interpret(const unsigned int tick) {
	if (value->value) {
		amountSoFar++;
		sum += *value->value;
	}

	return NullableValueNumber(sum / amountSoFar);
}


ExpressionValue GetPi::interpret(const unsigned int tick) {
	return NullableValueNumber(std::numbers::pi_v<float>);
}


ExpressionValue GetE::interpret(const unsigned int tick) {
	return NullableValueNumber(std::numbers::e);
}



ExpressionValue Round::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueNumber(std::round(*value->value));
	}

	return NullableValueNumber();
}



ExpressionValue Floor::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueNumber(std::floor(*value->value));
	}

	return NullableValueNumber();
}



ExpressionValue Ceil::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueNumber(std::ceil(*value->value));
	}

	return NullableValueNumber();
}


ExpressionValue MaxNumber::interpret(const unsigned int tick) {

	return NullableValueNumber((std::numeric_limits<float>::max)());
}


ExpressionValue MinNumber::interpret(const unsigned int tick) {

	return NullableValueNumber(-(std::numeric_limits<float>::max)());
}




ExpressionValue Count::interpret(const unsigned int tick) {

	if (value->value) {
		if (*value->value) {
			count++;
		}
	}

	return NullableValueNumber(count);
}


ExpressionValue Boolean2FloatCast::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueNumber(*value->value);
	}

	return NullableValueNumber();
}


ExpressionValue Float2BooleanCast::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueBoolean(*value->value);
	}

	return NullableValueBoolean();
}


ExpressionValue Float2StringCast::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueString(std::to_string(*value->value));
	}

	return NullableValueString();
}

ExpressionValue Boolean2StringCast::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueString(value->toString());
	}

	return NullableValueString();
}


ExpressionValue Absolute::interpret(const unsigned int tick) {

	if (value->value) {
		return NullableValueNumber(std::abs(*value->value));
	}

	return NullableValueNumber();
}



ExpressionValue LogE::interpret(const unsigned int tick) {

	if (value->value) {
		if (*value->value <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", log function must use positive non zero value.", valueNode);
		}
		return NullableValueNumber(std::log(*value->value));
	}

	return NullableValueNumber();
}


ExpressionValue LogBase::interpret(const unsigned int tick) {

	if (value->value) {
		if (*value->value <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", log function must use positive non zero value.", valueNode);
		}
	}
	if (base->value) {
		if (*base->value <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", log function must use positive non zero base.", baseNode);
		}
		return NullableValueNumber(log(*value->value) / log(*base->value));
	}

	return NullableValueNumber();
}



ExpressionValue SquareRoot::interpret(const unsigned int tick) {

	if (value->value) {
		if (*value->value < 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", log function must use positive zero value.", valueNode);
		}

		return NullableValueNumber(std::sqrt(*value->value));
	}

	return NullableValueNumber();
}


ExpressionValue LCM::interpret(const unsigned int tick) {

	if (value1->value && value2->value) {

		if (value1->value == 0) {
			throw LanguageException("LCM arg cannot be 0 ", value1Node);
		}

		if (value2->value == 0) {
			throw LanguageException("LCM arg cannot be 0 ", value2Node);
		}

		return NullableValueNumber(std::lcm((int)*value1->value, (int)*value2->value));
	}

	return NullableValueNumber();
}


ExpressionValue GCD::interpret(const unsigned int tick) {

	if (value1->value && value2->value) {

		if (value1->value == 0) {
			throw LanguageException("GCD arg cannot be 0 ", value1Node);
		}

		if (value2->value == 0) {
			throw LanguageException("GCD arg cannot be 0 ", value2Node);
		}
		return NullableValueNumber(std::gcd((int)*value1->value, (int)*value2->value));
	}

	return NullableValueNumber();
}



ExpressionValue Variance::interpret(const unsigned int tick) {
	if (amount->value) {
		int lookback = (int)*amount->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", variance function must use positive non zero amount.", amountNode);
		}

		if (value->value) {
			buffer.push_back(*value->value);

			if (buffer.size() < lookback) {
				return NullableValueNumber();
			}

			float sum = std::accumulate(buffer.begin(), buffer.end(), 0);
			float mean = sum / buffer.size();

			float variance = 0;
			for (int i = buffer.size() - 1; i >= 0; i--) {
				variance += std::pow(buffer[i] - mean, 2);
			}
			variance = variance / buffer.size();
			buffer.pop_front();
			return NullableValueNumber(variance);
		}
	}

	return NullableValueNumber();
}



ExpressionValue STD::interpret(const unsigned int tick) {


	if (amount->value) {
		int lookback = (int)*amount->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", variance function must use positive non zero amount.", amountNode);
		}

		if (value->value) {
			buffer.push_back(*value->value);

			if (buffer.size() < lookback) {
				return NullableValueNumber();
			}

			float sum = std::accumulate(buffer.begin(), buffer.end(), 0);
			float mean = sum / buffer.size();

			float variance = 0;
			for (int i = buffer.size() - 1; i >= 0; i--) {
				variance += std::pow(buffer[i] - mean, 2);
			}
			variance = variance / buffer.size();
			buffer.pop_front();
			return NullableValueNumber(std::sqrt(variance));
		}
	}

	return NullableValueNumber();
}


ExpressionValue MA::interpret(const unsigned int tick) {


	int lookback = (int)*amount->value;
	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", moving average function must use positive non zero amount.", amountNode);
	}

	buffer.push_back(value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());

	
	if (buffer.size() >= lookback) {
		float sum = 0;

		for (int i = buffer.size() - lookback; i < buffer.size(); i++) {
			if (std::isnan(buffer[i])) {
				return NullableValueNumber();
			}
			sum += buffer[i];
		}
		float mean = sum / lookback;
		return NullableValueNumber(mean);
	}
	return NullableValueNumber();
}

ExpressionValue IsNANF::interpret(const unsigned int tick) {
	return NullableValueBoolean((bool)!value->value);
}

ExpressionValue IsNANB::interpret(const unsigned int tick) {
	return NullableValueBoolean((bool)!value->value);
}


ExpressionValue IsNANS::interpret(const unsigned int tick) {
	return NullableValueBoolean((bool)!value->value);
}


ExpressionValue Random::interpret(const unsigned int tick) {
	if (!minvalue->value) {
		return NullableValueNumber();
	}
	if (!maxvalue->value) {
		return NullableValueNumber();
	}

	std::random_device seeder;
	std::mt19937 engine(seeder());
	std::uniform_int_distribution<int> dist((int)*minvalue->value > (int)*maxvalue->value ? (int)*maxvalue->value : (int)*minvalue->value,
											(int)*minvalue->value < (int)*maxvalue->value ? (int)*maxvalue->value : (int)*minvalue->value);
	int compGuess = dist(engine);

	return NullableValueNumber(compGuess);
}

ExpressionValue Falling::interpret(const unsigned int tick) {

	int lookback = (int)*bars_back->value;
	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", sum function must use positive non zero amount.", barsBackNode);
	}

	buffer.push_back(value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());


	if (buffer.size() >= lookback) {
		float lastvalue = std::numeric_limits<double>::quiet_NaN();

		for (int i = buffer.size() - lookback; i < buffer.size(); i++) {

			if (std::isnan(buffer[i])) {
				return NullableValueBoolean();
			}

			if (std::isnan(lastvalue)) {
				lastvalue = buffer[i];
			}
			else {
				if (buffer[i] > lastvalue) {
					return NullableValueBoolean(false);
				}
				else {
					lastvalue = buffer[i];
				}
			}
		}

		if (std::isnan(lastvalue)) {
			return NullableValueBoolean();
		}

		return NullableValueBoolean(true);
	}

	return NullableValueBoolean();
}


ExpressionValue Rising::interpret(const unsigned int tick) {
	int lookback = (int)*bars_back->value;
	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", sum function must use positive non zero amount.", barsBackNode);
	}

	buffer.push_back(value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());


	if (buffer.size() >= lookback) {
		float lastvalue = std::numeric_limits<double>::quiet_NaN();

		for (int i = buffer.size() - lookback; i < buffer.size(); i++) {

			if (std::isnan(buffer[i])) {
				return NullableValueBoolean();
			}

			if (std::isnan(lastvalue)) {
				lastvalue = buffer[i];
			}
			else {
				if (buffer[i] < lastvalue) {
					return NullableValueBoolean(false);
				}
				else {
					lastvalue = buffer[i];
				}
			}
		}

		if (std::isnan(lastvalue)) {
			return NullableValueBoolean();
		}

		return NullableValueBoolean(true);
	}

	return NullableValueBoolean();
}


ExpressionValue Cosine::interpret(const unsigned int tick) {
	if (radians->value) {
		return NullableValueNumber(std::cos(*radians->value));
	}

	return NullableValueNumber();
}



ExpressionValue Tangent::interpret(const unsigned int tick) {
	if (radians->value) {
		return NullableValueNumber(std::tan(*radians->value));
	}

	return NullableValueNumber();
}


ExpressionValue Sine::interpret(const unsigned int tick) {
	if (radians->value) {
		return NullableValueNumber(std::sin(*radians->value));
	}

	return NullableValueNumber();
}



ExpressionValue ArcCosine::interpret(const unsigned int tick) {
	if (radians->value) {
		if (*radians->value < -1 || *radians->value > 1) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", acos can only accept arg between -1 and 1", arg);
		}
		return NullableValueNumber(std::acos(*radians->value));
	}

	return NullableValueNumber();
}



ExpressionValue ArcTan::interpret(const unsigned int tick) {
	if (radians->value) {
		return NullableValueNumber(std::atan(*radians->value));
	}

	return NullableValueNumber();
}


ExpressionValue ArcSine::interpret(const unsigned int tick) {
	if (radians->value) {
		if (*radians->value < -1 || *radians->value > 1) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", asin can only accept arg between -1 and 1", arg);
		}
		return NullableValueNumber(std::asin(*radians->value));
	}

	return NullableValueNumber();
}



/*
WARNING. If look back changes value this will return the wrong value!
*/
ExpressionValue LinearRegression::interpret(const unsigned int tick) {
	if (bars->value) {
		int lookback = (int)*bars->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", linear regression function must use positive non zero amount.", barsNode);
		}


		if (data->value) {
			bufferX.push_back(tick);
			bufferY.push_back(*data->value);

			if (bufferX.size() < lookback) {
				return NullableValueNumber();
			}
		https://towardsdatascience.com/linear-regression-using-least-squares-a4c3456e8570

			float meanX = std::accumulate(bufferX.begin(), bufferX.end(), 0) / bufferX.size();
			float meanY = std::accumulate(bufferY.begin(), bufferY.end(), 0) / bufferY.size();

			float num = 0;
			float den = 0;
			for (int i = 0; i < bufferX.size(); i++) {

				num += (bufferX.at(i) - meanX) * (bufferY.at(i) - meanY);
				den += std::pow(bufferX.at(i) - meanX, 2);
			}
			float m = num / den;
			float c = meanY - m * meanX;

			bufferX.pop_front();
			bufferY.pop_front();
			return NullableValueNumber((m * tick) + c);
		}

	}

	return NullableValueNumber();
}



/*
WARNING. If look back changes value this will return the wrong value!
*/
ExpressionValue Correlation::interpret(const unsigned int tick) {
	if (length->value) {
		float lookback = (int)*length->value;
		if (lookback <= 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", linear regression function must use positive non zero amount.", lengthNode);
		}


		if (data1->value && data2->value) {
			values1.push_back(*data1->value);
			values2.push_back(*data2->value);

			if (values1.size() < lookback) {
				return NullableValueNumber();
			}
			//https://tutorialspoint.dev/algorithm/mathematical-algorithms/program-find-correlation-coefficient

			int sum_X = 0, sum_Y = 0, sum_XY = 0;
			int squareSum_X = 0, squareSum_Y = 0;

			for (int i = 0; i < lookback; i++)
			{
				// sum of elements of array X. 
				sum_X = sum_X + values1[i];

				// sum of elements of array Y. 
				sum_Y = sum_Y + values2[i];

				// sum of X[i] * Y[i]. 
				sum_XY = sum_XY + values1[i] * values2[i];

				// sum of square of array elements. 
				squareSum_X = squareSum_X + values1[i] * values1[i];
				squareSum_Y = squareSum_Y + values2[i] * values2[i];
			}

			// use formula for calculating correlation coefficient. 
			float corr = (float)((lookback * sum_XY) - (sum_X * sum_Y))
				/ sqrt((lookback * squareSum_X - sum_X * sum_X)
					* (lookback * squareSum_Y - sum_Y * sum_Y));
			values1.pop_front();
			values2.pop_front();
			return NullableValueNumber(corr);
		}

	}

	return NullableValueNumber();
}



ExpressionValue PreviousNumberValue::interpret(const unsigned int tick) {

	// always record otherwise we will build up a offset
	values.push_back(*data->value);

	if (barsback->value) {
		int lookback = (int)*barsback->value;
		if (lookback < 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", previous function must not be negative.", barsbackNode);
		}


		if (values.size() > lookback) {
			return values.at(tick - lookback);
		}
		return NullableValueNumber();

	}

	return NullableValueNumber();
}


ExpressionValue PreviousStringValue::interpret(const unsigned int tick) {

	// always record otherwise we will build up a offset
	values.push_back(*data->value);

	if (barsback->value) {
		int lookback = (int)*barsback->value;
		if (lookback < 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", previous function must not be negative.", barsbackNode);
		}


		if (values.size() > lookback) {
			return values.at(tick - lookback);
		}
		return NullableValueString();

	}

	return NullableValueString();
}


ExpressionValue PreviousBooleanValue::interpret(const unsigned int tick) {

	// always record otherwise we will build up a offset
	values.push_back(*data->value);

	if (barsback->value) {
		int lookback = (int)*barsback->value;
		if (lookback < 0) {
			throw LanguageException("Run time error at tick " + std::to_string(tick) + ", previous function must not be negative.", barsbackNode);
		}


		if (values.size() > lookback) {
			return values.at(tick - lookback);
		}
		return NullableValueBoolean();

	}

	return NullableValueBoolean();
}



// https://stackoverflow.com/questions/15843525/how-do-you-insert-the-value-in-a-sorted-vector
template< typename T >
typename std::vector<T>::iterator
insert_sorted(std::vector<T>& vec, T const& item)
{
	return vec.insert
	(
		std::upper_bound(vec.begin(), vec.end(), item),
		item
	);
}



ExpressionValue Median::interpret(const unsigned int tick) {

	if (!data->value) {
		return NullableValueNumber();
	}

	insert_sorted(values, *data->value);

	if (values.size() % 2 == 0)
	{
		return NullableValueNumber((values[values.size() / 2 - 1] + values[values.size() / 2]) / 2);
	}

	return NullableValueNumber(values[values.size() / 2]);
}


ExpressionValue MedianBars::interpret(const unsigned int tick) {


	int lookback = (int)*bars_back->value;
	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", sum function must use positive non zero amount.", barsBackNode);
	}

	buffer.push_back(value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());


	if (buffer.size() >= lookback) {
		std::vector<float> new_vec;
		for (int i = buffer.size() - lookback; i < buffer.size(); i++) {

			if (std::isnan(buffer[i])) {
				return NullableValueNumber();
			}
			new_vec.push_back(buffer[i]);
		}

		std::sort(new_vec.begin(), new_vec.end());
		if (new_vec.size() % 2 == 0)
		{
			return NullableValueNumber((new_vec[new_vec.size() / 2 - 1] + new_vec[new_vec.size() / 2]) / 2);
		}

		return NullableValueNumber(new_vec[new_vec.size() / 2]);
	}

	return NullableValueNumber();
}




ExpressionValue IsPrime::interpret(const unsigned int tick) {

	if (!data->value) {
		return NullableValueBoolean();
	}

	int n = *data->value;

	//https://www.geeksforgeeks.org/c-program-to-check-prime-number/
	// Corner case
	if (n <= 2) {
		return NullableValueBoolean(false);
	}

	// Check from 2 to n-1
	for (int i = 2; i < n; i++)
		if (n % i == 0)
			return NullableValueBoolean(false);

	return NullableValueBoolean(true);
}

ExpressionValue IsTriangle::interpret(const unsigned int tick) {

	if (!data->value) {
		return NullableValueBoolean();
	}

	int n = *data->value;

	//https://stackoverflow.com/questions/2913215/fastest-method-to-define-whether-a-number-is-a-triangular-number

	if (n < 0)
		return NullableValueBoolean(false);

	if (n == 1)
		return NullableValueBoolean(true);

	for (int i = 0; i < n; i++) {
		if (i * (i + 1) / 2 == n) {
			return NullableValueBoolean(true);
		}
	}

	return NullableValueBoolean(false);
}
