
#include <iostream>


#include "node.h"


#include "bison.tab.h"
#include "flex.flex.h"
#include "symboltable.h"
#include "languageexception.h"
#include <fstream>
#include <string>
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlabel.h>
#include <QtCore/qstring.h>
#include <QtCharts/qchart.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qscatterseries.h>
#include <QtCharts/chartsnamespace.h>
#include <QtCharts/qchartview.h>
#include <qtimer.h>
#include <qgraphicssceneevent.h>
void execute(const std::string& code) {



	BlockNode* input = nullptr;
	SymbolTable* symboltable = nullptr;
	try {
		yyscan_t scanner;

		yylex_init(&scanner);
		yy_scan_string(code.c_str(), scanner);
		std::string errorReturn = "";

		yy::parser parseengine(scanner, &input);
		int parseResult = parseengine.parse();
		if (parseResult != 0) {
			//std::cout << "error" << std::endl;
			throw LanguageException("Parsing Error");
		}

		yylex_destroy(scanner);

		std::cout << input->toString() << std::endl;

		symboltable = new SymbolTable();

		input->semanticAnalysis(symboltable);
		input->interpret(symboltable);
		std::cout << symboltable->toString() << std::endl;



	}
	catch (LanguageException langexception) {
		std::cout << langexception.message << std::endl;
	}

	if (input) {
		delete input;
	}

	if (symboltable) {
		delete symboltable;
	}
	std::cout << "_______________________________" << std::endl;
}


void execute(std::ifstream& myfile) {
	std::string code = "";
	std::string line;
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			code += line + "\n";
		}
		myfile.close();
	}

	BlockNode* input = nullptr;
	SymbolTable* symboltable = nullptr;
	try {
		yyscan_t scanner;

		yylex_init(&scanner);
		yy_scan_string(code.c_str(), scanner);
		std::string errorReturn = "";

		yy::parser parseengine(scanner, &input);
		int parseResult = parseengine.parse();
		if (parseResult != 0) {
			//std::cout << "error" << std::endl;
			throw LanguageException("Parsing Error");
		}

		yylex_destroy(scanner);


		symboltable = new SymbolTable();

		input->semanticAnalysis(symboltable);
		input->interpret(symboltable);



	}
	catch (LanguageException langexception) {
		std::cout << langexception.message << std::endl;
	}

	if (input) {
		delete input;
	}

	if (symboltable) {
		delete symboltable;
	}
}

/*
NOTE TO SELF. IF LINKER ERRORS HAPPEN.
FIND OUT WHAT GROUP IT BELONGS TO e.g. QString -> QCore

1. Add include of the specific folder e.g. QCore
2. Add additonally dendency for lib file e.g. QTCore.lib


NOTE FOR DISTRIBUTION
The .exe file must be stored with respective dll files found in QT/bin.
I have moved all these files to CodeBase/Debug so this shouldn't be a problem anyway (dont forget to include them).

C:\Qt\5.15.2\msvc2019\bin


TODO 

NOTE not sure exactly how .lib files are linked in but make sure additional dependencies (.lib files) are packaged with .exe somehow
Do the same for includes although thats more straight forward. At the moment these are included in the directories:

C:\Qt\5.15.2\msvc2019\include
C:\Qt\5.15.2\msvc2019\lib

*/




template<int amount>
class ChartView : public QChartView {
	qreal mFactor = 1.0;

public:
	QChart* chartA;
	QLineSeries* series;
	QScatterSeries* scatterseries;

	ChartView() : QChartView() {
		series = new QLineSeries();
		scatterseries = new QScatterSeries();
		for (int i = 0; i < amount; i++) {
			float y = i % 10;
			float x = i;
			if (y > 2 && y < 8) {
				x = std::numeric_limits<double>::quiet_NaN();
				y = std::numeric_limits<double>::quiet_NaN();
			}
			series->append(QPointF(x, y));
		}

		for (int i = 0; i < amount; i++) {
			scatterseries->append(QPointF(i, 12 + (i % 10)));
		}

		chartA = new QChart();
		chartA->addSeries(series);
		//chartA->addSeries(scatterseries);
		chartA->createDefaultAxes();

		setChart(chartA);
		resize(1300, 700);
		//setRubberBand(QChartView::HorizontalRubberBand);
	
	}

protected:
	void wheelEvent(QWheelEvent* event) Q_DECL_OVERRIDE
	{
		chart()->zoomReset();

		mFactor *= event->angleDelta().y() > 0 ? 0.5 : 2;

		QRectF rect = chart()->plotArea();
		QPointF c = chart()->plotArea().center();
		rect.setWidth(mFactor * rect.width());
		rect.moveCenter(c);
		chart()->zoomIn(rect);

		QChartView::wheelEvent(event);
	}

	//void mousePressEvent(QMouseEvent* event) Q_DECL_OVERRIDE
	//{
	//	//std::cout << "what" << std::endl;
	//	//chartA = new QChart();
	//	chartA->removeSeries(series);
	//	series->clear();
	//	for (int i = 0; i < amount; i++) {
	//		series->append(QPointF(i, 12 + (i % 10)));
	//	}
	//	chartA->addSeries(series);
	//	this->setChart(chartA);
	//	//this->chart()->removeSeries();
	//	/*QLineSeries* series = new QLineSeries();
	//	for (int i = 0; i < 1000; i++) {
	//		series->append(QPointF(i, 12 + (i % 10)));
	//	}

	//	chartA = new QChart();
	//	chartA->addSeries(series);
	//	chartA->createDefaultAxes();

	//	setChart(chartA);*/
	//	this->repaint();
	//}
};

int main(int argc, char* argv[]) {

	QApplication app(argc, argv);




	ChartView<1000>* chartView = new ChartView<1000>();

	chartView->show();

	//chart->addSeries(series);

	//chart->createDefaultAxes(); // Preparing the axis
	//chart->axisX()->setRange(0, 10);
	//chart->axisY()->setRange(0, 10);

	//// Same formatting
	//chart->setBackgroundVisible(false);
	//chart->setMargins(QMargins(0, 0, 0, 0));
	//chart->layout()->setContentsMargins(0, 0, 0, 0);
	//chart->legend()->hide();
	//chart->setPlotAreaBackgroundBrush(QBrush(Qt::black));
	//chart->setPlotAreaBackgroundVisible(true);
	//chartView = new QChartView(chart);

	//QPushButton hello("Hello world!", 0);
	//hello.resize(100, 30);

	//app.setactive
	//hello.show();
	app.exec();

	return 0;

	std::ifstream myfile("C:/Users/shaer/Desktop/Uni Work/Year 3/Project/Project/CodeBase/CodeBase/examplecode.txt");
	execute(myfile);


	return 0;

	//execute("x = 2 + 5 \
 //            y = 123 + 21 + 51 + 312 + x + q");


	//execute("z = true - false");

	//execute("false = 1.1231312 * 413 + 12");


	execute("a = 2 + 5 \
            b = 2 - 5 \
            c = 2 / 5 \
            d = 2 * 5 \
            e = 2 > 5 \
            f = 5 >= 5 \
            g = 5 < 2 \
            h = 1 <= 2 \
            i = false && false \
            i = false || false \
            k = 2 + 412 - 2");


	execute("a = +true");
	execute("a = true && false");
	execute("average(2, 3)");

	//execute("a = ! ! !false \
 //           b = + - - - - 2");


	/*execute("q = average(13, 12)");
	execute("q = average(13, 12, 13)");
	execute("q = average(13)");
	execute("q = average()");
	execute("q = average(true, 12)");*/
	//execute("x = -1");

}