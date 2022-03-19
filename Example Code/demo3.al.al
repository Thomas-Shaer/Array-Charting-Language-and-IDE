{
	"code": "original_rainfall = east_england_rainfall\nthree_yr_moving_avg_rainfall = ma(east_england_rainfall, 3)\nrising_from_prev_year = east_england_rainfall > prev(east_england_rainfall, 1)\n\nplot(original_rainfall, \"original_rainfall\")\nplot(three_yr_moving_avg_rainfall, \"three_yr_moving_avg_rainfall\")\nmark(rising_from_prev_year, original_rainfall, \"rising_from_prev_year\")\n\n",
	"variables": [
		{
			"nullImportString": "NAN",
			"dataName": "﻿East of England",
			"falseImportString": "FALSE",
			"fileName": "east_england_rainfall.csv",
			"path": "C:\\Users\\shaer\\Desktop\\Uni Work\\Year 3\\Project\\Project\\Example Data\\east_england_rainfall.csv",
			"policy": "column-wise",
			"trueImportString": "TRUE",
			"variableName": "east_england_rainfall"
		},
		{
			"nullImportString": "NAN",
			"dataName": "﻿East Midlands",
			"falseImportString": "FALSE",
			"fileName": "east_midlands_rainfall.csv",
			"path": "C:\\Users\\shaer\\Desktop\\Uni Work\\Year 3\\Project\\Project\\Example Data\\east_midlands_rainfall.csv",
			"policy": "column-wise",
			"trueImportString": "TRUE",
			"variableName": "east_midlands_rainfall"
		}
	]
}