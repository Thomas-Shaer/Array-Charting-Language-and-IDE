#include "sourcelocation.h"
#include <sstream>

namespace yy {
	SourceLocation::SourceLocation() {
	}

	// Merges the locations
	SourceLocation SourceLocation::operator+(const SourceLocation& sl) {
		SourceLocation expandedLocation;
		expandedLocation.begin.line = begin.line < sl.begin.line ? begin.line : sl.begin.line;
		expandedLocation.begin.column = begin.column < sl.begin.column ? begin.column : sl.begin.column;
		expandedLocation.end.line = end.line > sl.end.line ? end.line : sl.end.line;
		expandedLocation.end.column = end.column > sl.end.column ? end.column : sl.end.column;
		return expandedLocation;
	}


	SourceLocation::SourceLocation(const SourceLocation& sl) {
		begin.line = sl.begin.line;
		begin.column = sl.begin.column;
		end.line = sl.end.line;
		end.column = sl.end.column;
	}

	std::ostream& operator<<(std::ostream& output, const SourceLocation& source) {
		output << "First line: " << source.begin.line << " Last Line: " << source.end.line << " First Column: " << source.begin.column << " Last Column: " << source.end.column << std::endl;
		return output;
	}

	std::string SourceLocation::highlightSourceLocation(const std::string& sourceCode) const {
		int lineno = 0;
		std::string output;
		std::istringstream stream(sourceCode);
		for (std::string line; std::getline(stream, line); )
		{
			// works fine
			if (lineno == begin.line && lineno == end.line) {
				return line + "\n" + std::string(begin.column, ' ') + std::string(end.column - begin.column, '^');
			}
			else if (lineno == begin.line) {
				output += line + "\n";
				output += std::string(begin.column, ' ') + std::string(line.length() - begin.column, '^') + "\n";
			}
			else if (lineno == end.line) {
				return output + line + "\n" + std::string(end.column, '^');
			}
			else if (lineno > begin.line && lineno < end.line) {
				output += line + "\n";
				output += std::string(line.length(), '^') + "\n";
			}
			lineno++;

		}

		return output;
	}
}
