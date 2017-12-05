#include "gsa/library/FileParser.h"

#include "gsa/library/modules/interfaces/LineBasedModuleInterface.h"

#include "gtest/gtest.h"

#include <QStringList>

using namespace gsa;
using namespace gsa::library;

namespace {
	class Test1LineBasedModule : public LineBasedModuleInterface {
	public:
		Test1LineBasedModule() : LineBasedModuleInterface(Module()), _lines() {
		}

		QStringList getLines() const {
			return _lines;
		}

	private:
		QStringList _lines;

		CheckResult checkLine(QString line) {
			_lines.append(line);
			return CheckResult();
		}
	};
}

TEST(FileParser, parseLines) {
	QStringList expectedResults = {
		"INSTANCE DIA_Addon_BanditGuard_EXIT   (C_INFO)",
		"{",
		"	npc         = BDT_1064_Bandit_L;",
		"	nr          = 999;",
		"	condition   = DIA_BanditGuard_EXIT_Condition;",
		"	information = DIA_BanditGuard_EXIT_Info;",
		"	permanent   = TRUE;",
		"	description = DIALOG_ENDE;",
		"};",
		"FUNC INT DIA_BanditGuard_EXIT_Condition()",
		"{	",
		"		return TRUE;",
		"};",
		"FUNC VOID DIA_BanditGuard_EXIT_Info()",
		"{",
		"	AI_StopProcessInfos (self);",
		"};"
	};
	Test1LineBasedModule testModule;

	FileParser fileParser({ &testModule });
	fileParser.parseFile("tests/FileParser_LineBased.d");

	EXPECT_EQ(expectedResults, testModule.getLines());
}
