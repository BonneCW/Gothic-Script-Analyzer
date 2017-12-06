#include "gsa/library/modules/AIOutputModule.h"

#include "gsa/library/SeverityLevel.h"

#include "gsa/library/modules/Modules.h"

#include <QRegularExpression>

namespace gsa {
namespace library {

	AIOutputModule::AIOutputModule() : LineBasedModuleInterface(Module::AIOutput) {
	}

	CheckResult AIOutputModule::checkLine(QString line) {
		static QRegularExpression regex("(AI_Output)[\\s]*\\([^,]+,[^,]+,[^\"]*\"([^\"]*)\"[\\s]*\\)[\\s]*;[\\s]*//([^\\\n]*)\\\n", QRegularExpression::CaseInsensitiveOption);
		CheckResult result;
		result.module = getModule();
		line += '\n';
		if (line.contains(regex)) {
			QRegularExpressionMatch match = regex.match(line);
			Q_ASSERT(match.capturedLength() == 4);
			QString trimmedLine = match.captured(0).trimmed();
			QString aiOutput = match.captured(1);
			QString wavName = match.captured(2);
			QString subtitle = match.captured(3);

			if (aiOutput == "AI_Output") {
				if (wavName.isEmpty() && subtitle.isEmpty()) {
					result.errorString = "AI_Output without name and text: " + trimmedLine;
					result.level = SeverityLevel::Warning;
					result.success = false;
				} else if (wavName.isEmpty()) {
					result.errorString = "AI_Output without name: " + trimmedLine;
					result.level = SeverityLevel::Error;
					result.success = false;
				} else if (subtitle.isEmpty()) {
					result.errorString = "AI_Output without text: " + trimmedLine;
					result.level = SeverityLevel::Warning;
					result.success = false;
				} else {
					result.success = true;
				}
			} else {
				if (!wavName.isEmpty() && !subtitle.isEmpty()) {
					result.errorString = "AI_Output invalid: " + trimmedLine;
					result.level = SeverityLevel::Error;
					result.success = false;
				} else if (!wavName.isEmpty()) {
					result.errorString = "AI_Output ignored: " + trimmedLine;
					result.level = SeverityLevel::Warning;
					result.success = false;
				} else if (!subtitle.isEmpty()) {
					result.errorString = "AI_Output invalid: " + trimmedLine;
					result.level = SeverityLevel::Error;
					result.success = false;
				} else {
					result.success = true;
				}
			}
		} else {
			result.success = true;
		}
		return result;
	}

} /* namespace library */
} /* namespace gsa */
