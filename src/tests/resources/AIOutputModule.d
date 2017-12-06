FUNC VOID DIA_BanditGuard_EXIT_Info()
{
	AI_Output(hero, self, "Info_Mod_123"); //This line is valid.
	AI_Output(hero, self, "Info_Mod_123"); //
	AI_Output(hero, self, ""); //This line is valid.
	AI_Output(hero, self, ""); //
	ai_output(hero, self, "Info_Mod_123"); //Test.
	ai_output(hero, self, "Info_Mod_123"); //
	ai_output(hero, self, ""); //Test.
	ai_output(hero, self, ""); //
};