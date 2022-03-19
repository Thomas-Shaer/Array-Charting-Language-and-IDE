{
	"code": "// ATTEMPT TO PREDICT PEAK RAINFALL OVER 5 YEARS\n\nplot(east_of_england_rain, name=\"East England Annual Rainfall\",  chart_id = \"Attempt to find 5 year peak rainfall\")\n\nmoving_average_10 = ma(east_of_england_rain, 10)\n\nplot(moving_average_10, name=\"10 Year Moving Average\", chart_id = \"Attempt to find 5 year peak rainfall\")\n\npeak_event_cond_1 = east_of_england_rain > moving_average_10\n\npeak_event = false\n\n\n// if rainfall above moving average\nif (peak_event_cond_1) {\n    // if rainfall is rising for 3 years in a row, we have a peak event\n\tpeak_event = rising(east_of_england_rain, 3)\n\tmark(peak_event, east_of_england_rain, \"Peak?\", chart_id = \"Attempt to find 5 year peak rainfall\")\n\ttext(peak_event, \"Peak#\" + string(count(peak_event)), east_of_england_rain + 40, chart_id = \"Attempt to find 5 year peak rainfall\")\n}\n\npeak_level = valuewhen(peak_event, east_of_england_rain)\n\nplot(peak_level, \"Peak y level\", chart_id = \"Attempt to find 5 year peak rainfall\")\n\n\n// after a peak event, if rainfall exceeds the peak level, output fail\nif(prev(peak_event, 1) || prev(peak_event, 2) || prev(peak_event, 3) || prev(peak_event, 4) || prev(peak_event, 5)) {\n\tif(east_of_england_rain > peak_level) {\n\t\ttext(true, \"Fail\", east_of_england_rain + 40, chart_id = \"Attempt to find 5 year peak rainfall\")\n\t}\n}\n\n\n\n\n\n\n\n\n\n",
	"variables": [
		{
			"nullImportString": "NAN",
			"dataName": "﻿East of England",
			"falseImportString": "FALSE",
			"fileName": "east_england_rainfall.csv",
			"path": "C:\\Users\\shaer\\Desktop\\Uni Work\\Year 3\\Project\\Project\\Example Data\\east_england_rainfall.csv",
			"policy": "column-wise",
			"trueImportString": "TRUE",
			"variableName": "east_of_england_rain"
		}
	]
}