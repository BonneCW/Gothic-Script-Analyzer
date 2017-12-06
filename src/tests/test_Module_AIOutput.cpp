#include "gsa/library/FileParser.h"
#include "gsa/library/SeverityLevel.h"

#include "gsa/library/modules/AIOutputModule.h"
#include "gsa/library/modules/Modules.h"

#include "gtest/gtest.h"

using namespace gsa;
using namespace gsa::library;

TEST(AIOutputModule, basicTest) {
	QList<CheckResult> expectedResults;
	{
		CheckResult result;
		result.module = Module::AIOutput;
		result.success = false;
		result.errorString = "AI_Output without text: AI_Output(hero, self, \"Info_Mod_123\"); //";
		result.level = SeverityLevel::Warning;
		expectedResults << result;
	}
	{
		CheckResult result;
		result.module = Module::AIOutput;
		result.success = false;
		result.errorString = "AI_Output without name: AI_Output(hero, self, \"\"); //This line is valid.";
		result.level = SeverityLevel::Error;
		expectedResults << result;
	}
	{
		CheckResult result;
		result.module = Module::AIOutput;
		result.success = false;
		result.errorString = "AI_Output without name and text: AI_Output(hero, self, \"\"); //";
		result.level = SeverityLevel::Warning;
		expectedResults << result;
	}
	{
		CheckResult result;
		result.module = Module::AIOutput;
		result.success = false;
		result.errorString = "AI_Output invalid: ai_output(hero, self, \"Info_Mod_123\"); //Test.";
		result.level = SeverityLevel::Error;
		expectedResults << result;
	}
	{
		CheckResult result;
		result.module = Module::AIOutput;
		result.success = false;
		result.errorString = "AI_Output ignored: ai_output(hero, self, \"Info_Mod_123\"); //";
		result.level = SeverityLevel::Warning;
		expectedResults << result;
	}
	{
		CheckResult result;
		result.module = Module::AIOutput;
		result.success = false;
		result.errorString = "AI_Output invalid: ai_output(hero, self, \"\"); //Test.";
		result.level = SeverityLevel::Error;
		expectedResults << result;
	}
	AIOutputModule testModule;

	FileParser fileParser({ &testModule });
	auto checkResults = fileParser.parseFile("tests/AIOutputModule.d");

	EXPECT_EQ(expectedResults, checkResults);
}
