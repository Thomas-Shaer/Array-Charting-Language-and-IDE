{
	"code": "\n\nplot(east_midlands_rainfall, \"East Midlands Annual Rainfall\", \"Raw data\")\nplot(east_england_rainfall, \"East England Annual Rainfall\", \"Raw data\")\nplot(corr(east_midlands_rainfall, east_england_rainfall, 3), \"3 year correlation\", \"Correlation\")\nplot(ma(east_midlands_rainfall, 10), \"East Midlands Rainfall MA(10)\", \"Moving average data\")\nplot(ma(east_england_rainfall, 10), \"East England Rainfall MA(10)\", \"Moving average data\")\n",
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