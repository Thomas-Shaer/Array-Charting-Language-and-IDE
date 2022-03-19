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
	plotdata->fdata[tick] = pushBackValue;

	return NullableValueBoolean(true);
}


ExpressionValue Mark::interpret(const unsigned int tick) {
	//if not null
	if (when->value) {

		// if positive
		if (*when->value) {

			float pushBackValue = value->value ? *value->value : std::numeric_limits<double>::quiet_NaN();
			plotdata->fdata[tick] = (pushBackValue);
		}
		else {
			plotdata->fdata[tick] = (std::numeric_limits<double>::quiet_NaN());
		}
	}
	else {
		plotdata->fdata[tick] = (std::numeric_limits<double>::quiet_NaN());
	}
	return NullableValueBoolean(true);
}


ExpressionValue Text::interpret(const unsigned int tick) {
	//if not null
	if (when->value) {

		// if positive
		if (*when->value) {

			float yValue = ylevel->value ? *ylevel->value : std::numeric_limits<double>::quiet_NaN();
			plotdata->fdata[tick] = (yValue);
			std::string stringValue = value->value ? *value->value : "";
			plotdata->sdata[tick] = (stringValue);

			float verticalFlag = vertical->value ? *vertical->value : false;
			plotdata->vstringdata[tick] = verticalFlag;
		}
		else {
			plotdata->fdata[tick] = (std::numeric_limits<double>::quiet_NaN());
			plotdata->sdata[tick] = "";
			plotdata->vstringdata[tick] = false;
		}
	}
	else {
		plotdata->fdata[tick] = (std::numeric_limits<double>::quiet_NaN());
		plotdata->sdata[tick] = "";
		plotdata->vstringdata[tick] = false;
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





ExpressionValue NumberNull::interpret(const unsigned int tick) {
	return NullableValueNumber();
}

ExpressionValue BooleanNull::interpret(const unsigned int tick) {
	return NullableValueBoolean();
}


ExpressionValue StringNull::interpret(const unsigned int tick) {
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

	buffer[tick] = (value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());


	int lookback;

	if (!bars_back->value) {
		return NullableValueNumber();
	}
	lookback = (int)*bars_back->value;

	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", minimum bars function must use positive non zero lookback.", barsBackNode);
	}

	if (lookback - 1 > tick) {
		return NullableValueNumber();
	}


	float min = std::numeric_limits<double>::quiet_NaN();

	for (int i = tick + 1 - lookback; i < tick + 1; i++) {

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


ExpressionValue Maximum::interpret(const unsigned int tick) {
	if (value->value) {
		if (*value->value > *maximumValue.value) {
			maximumValue = *value;
		}
	}

	return maximumValue;
}


ExpressionValue MaximumBars::interpret(const unsigned int tick) {


	buffer[tick] = (value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());


	int lookback;

	if (!bars_back->value) {
		return NullableValueNumber();
	}
	lookback = (int)*bars_back->value;

	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", max bars function must use positive non zero lookback.", barsBackNode);
	}

	if (lookback - 1 > tick) {
		return NullableValueNumber();
	}



	//if (buffer.size() >= lookback) {
		float max = std::numeric_limits<double>::quiet_NaN();

		for (int i = tick + 1 - lookback; i < tick + 1; i++) {

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
	//}
	//return NullableValueNumber();
}


ExpressionValue Sum::interpret(const unsigned int tick) {
	if (value->value) {
		sum += *value->value;
	}

	return NullableValueNumber(sum);
}



ExpressionValue SumBars::interpret(const unsigned int tick) {


	buffer[tick] = (value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());


	int lookback;

	if (!bars_back->value) {
		return NullableValueNumber();
	}
	lookback = (int)*bars_back->value;

	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", sum function must use positive non zero amount.", barsBackNode);
	}

	if (lookback - 1 > tick) {
		return NullableValueNumber();
	}


	float sum = 0;

	for (int i = tick + 1 - lookback; i < tick + 1; i++) {

		if (std::isnan(buffer[i])) {
			return NullableValueNumber();
		}
		sum += buffer[i];
	}
		
	return NullableValueNumber(sum);

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


ExpressionValue Boolean2NumberCast::interpret(const unsigned int tick) {

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



	buffer[tick] = (value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());


	int lookback;

	if (!bars_back->value) {
		return NullableValueNumber();
	}
	lookback = (int)*bars_back->value;

	if (lookback <= 1) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", sum function bars back must be > 1", barsBackNode);
	}

	if (lookback - 1 > tick) {
		return NullableValueNumber();
	}


	float sum = 0;

	for (int i = tick + 1 - lookback; i < tick + 1; i++) {

		if (std::isnan(buffer[i])) {
			return NullableValueNumber();
		}
		sum += buffer[i];
	}

	float mean = sum / lookback;
	float variance = 0;

	for (int i = tick + 1 - lookback; i < tick + 1; i++) {

		variance += (buffer[i] - mean) * (buffer[i] - mean);
	}
	variance = variance / (lookback - 1);


	return NullableValueNumber(variance);

}



ExpressionValue STD::interpret(const unsigned int tick) {


	buffer[tick] = (value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());


	int lookback;

	if (!bars_back->value) {
		return NullableValueNumber();
	}
	lookback = (int)*bars_back->value;

	if (lookback <= 1) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ",  std function bars back must be > 1", barsBackNode);
	}

	if (lookback - 1 > tick) {
		return NullableValueNumber();
	}


	float sum = 0;

	for (int i = tick + 1 - lookback; i < tick + 1; i++) {
		if (std::isnan(buffer[i])) {
			return NullableValueNumber();
		}
		sum += buffer[i];
	}

	float mean = sum / lookback;
	float variance = 0;

	for (int i = tick + 1 - lookback; i < tick + 1; i++) {
		variance += (buffer[i] - mean) * (buffer[i] - mean);
	}
	variance = variance / (lookback - 1);


	return NullableValueNumber(std::sqrt(variance));

}


ExpressionValue MA::interpret(const unsigned int tick) {



	buffer[tick] = (value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());

	int lookback;

	if (!amount->value) {
		return NullableValueNumber();
	}
	lookback = (int)*amount->value;

	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", moving average function must use positive non zero amount.", amountNode);
	}

	if (lookback - 1 > tick) {
		return NullableValueNumber();
	}



	
	float sum = 0;

	for (int i = tick + 1 - lookback; i < tick + 1; i++) {
		if (std::isnan(buffer[i])) {
			return NullableValueNumber();
		}
		sum += buffer[i];
	}
	float mean = sum / lookback;
	return NullableValueNumber(mean);

}

ExpressionValue IsNullN::interpret(const unsigned int tick) {
	return NullableValueBoolean((bool)!value->value);
}

ExpressionValue IsNullB::interpret(const unsigned int tick) {
	return NullableValueBoolean((bool)!value->value);
}


ExpressionValue IsNullS::interpret(const unsigned int tick) {
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


	buffer[tick] = (value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());

	int lookback;

	if (!bars_back->value) {
		return NullableValueBoolean();
	}
	lookback = (int)*bars_back->value;

	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", falling function must use positive non zero amount.", barsBackNode);
	}

	if (lookback - 1 > tick) {
		return NullableValueBoolean();
	}


	float lastvalue = std::numeric_limits<double>::quiet_NaN();

	for (int i = tick + 1 - lookback; i < tick + 1; i++) {

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


ExpressionValue Rising::interpret(const unsigned int tick) {

	buffer[tick] = (value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());


	int lookback;

	if (!bars_back->value) {
		return NullableValueBoolean();
	}
	lookback = (int)*bars_back->value;

	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", rising function must use positive non zero lookback.", barsBackNode);
	}

	if (lookback - 1 > tick) {
		return NullableValueBoolean();
	}


	float lastvalue = std::numeric_limits<double>::quiet_NaN();

	for (int i = tick + 1 - lookback; i < tick + 1; i++) {

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
ExpressionValue LinearRegressionAtTick::interpret(const unsigned int tick) {


	buffer[tick] = (value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());

	int lookback;

	if (!bars_back->value) {
		return NullableValueNumber();
	}
	lookback = (int)*bars_back->value;

	if (lookback <= 1) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", linreg function lookback must be > 1.", barsBackNode);
	}

	if (lookback - 1 > tick) {
		return NullableValueNumber();
	}


	if (!xvalue->value) {
		return NullableValueNumber();
	}

	float sumX = 0;
	float sumY = 0;

	for (int i = tick + 1 - lookback; i < tick + 1; i++) {

		if (std::isnan(buffer[i])) {
			return NullableValueNumber();
		}
		sumX += i;
		sumY += buffer[i];
	}

	float meanX = sumX / lookback;
	float meanY = sumY / lookback;

	float num = 0;
	float den = 0;

	for (int i = tick + 1 - lookback; i < tick + 1; i++) {

		num += (i - meanX) * (buffer[i] - meanY);
		den += std::pow(i - meanX, 2);
	}

	float m = num / den;
	float c = meanY - m * meanX;

	return NullableValueNumber((m * *xvalue->value) + c);

}



/*
WARNING. If look back changes value this will return the wrong value!
*/
ExpressionValue Correlation::interpret(const unsigned int tick) {

	

	buffer1[tick] = (data1->value ? *data1->value : std::numeric_limits<double>::quiet_NaN());
	buffer2[tick] = (data2->value ? *data2->value : std::numeric_limits<double>::quiet_NaN());


	int lookback;

	if (!bars_back->value) {
		return NullableValueNumber();
	}
	lookback = (int)*bars_back->value;

	if (lookback <= 1) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", correlation function must be > 1.", barsBackNode);
	}

	//https://tutorialspoint.dev/algorithm/mathematical-algorithms/program-find-correlation-coefficient

	float sum_X = 0, sum_Y = 0, sum_XY = 0;
	float squareSum_X = 0, squareSum_Y = 0;

	if (lookback - 1 > tick) {
		return NullableValueNumber();
	}


	for (int i = tick + 1 - lookback; i < tick+1; i++)
	{

		if (std::isnan(buffer1[i])) {
			return NullableValueNumber();
		}
		if (std::isnan(buffer2[i])) {
			return NullableValueNumber();
		}

		// sum of elements of array X. 
		sum_X = sum_X + buffer1[i];

		// sum of elements of array Y. 
		sum_Y = sum_Y + buffer2[i];

		// sum of X[i] * Y[i]. 
		sum_XY = sum_XY + buffer1[i] * buffer2[i];

		// sum of square of array elements. 
		squareSum_X = squareSum_X + buffer1[i] * buffer1[i];
		squareSum_Y = squareSum_Y + buffer2[i] * buffer2[i];
	}

	float corr = ((float)lookback * sum_XY - sum_X * sum_Y) / sqrt((lookback * squareSum_X - sum_X * sum_X) * (lookback * squareSum_Y - sum_Y * sum_Y));
	return NullableValueNumber(corr);

}



ExpressionValue PreviousNumberValue::interpret(const unsigned int tick) {

	buffer[tick].value = data->value;
	
	int lookback;

	if (!barsback->value) {

		return NullableValueNumber();
	}
	lookback = (int)*barsback->value;

	if (lookback < 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", previous function must not be negative.", barsbackNode);
	}


	if (lookback - 1 > tick) {
		return NullableValueNumber();
	}


	if ((int)tick - lookback < 0) {
		return NullableValueNumber();
	}

	return buffer.at((int)tick - lookback);

}


ExpressionValue PreviousStringValue::interpret(const unsigned int tick) {

	buffer[tick].value = data->value;

	int lookback;

	if (!barsback->value) {
		return NullableValueString();
	}
	lookback = (int)*barsback->value;

	if (lookback < 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", previous function must not be negative.", barsbackNode);
	}


	if (lookback - 1 > tick) {
		return NullableValueString();
	}


	if ((int)tick - lookback < 0) {
		return NullableValueString();
	}

	return buffer.at((int)tick - lookback);
}


ExpressionValue PreviousBooleanValue::interpret(const unsigned int tick) {

	buffer[tick].value = data->value;

	int lookback;

	if (!barsback->value) {

		return NullableValueBoolean();
	}
	lookback = (int)*barsback->value;

	if (lookback < 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", previous function must not be negative.", barsbackNode);
	}


	if (lookback - 1 > tick) {
		return NullableValueBoolean();
	}


	if ((int)tick - lookback < 0) {
		return NullableValueBoolean();
	}

	return buffer.at((int)tick - lookback);
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



	buffer[tick] = (value->value ? *value->value : std::numeric_limits<double>::quiet_NaN());

	int lookback;

	if (!bars_back->value) {
		return NullableValueNumber();
	}
	lookback = (int)*bars_back->value;

	if (lookback <= 0) {
		throw LanguageException("Run time error at tick " + std::to_string(tick) + ", median bars function lookback must use positive non zero.", barsBackNode);
	}

	if (lookback - 1 > tick) {
		return NullableValueNumber();
	}



	//if (buffer.size() >= lookback) {
		std::vector<float> new_vec;
		for (int i = tick + 1 - lookback; i < tick + 1; i++) {

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
	//}

	//return NullableValueNumber();
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
