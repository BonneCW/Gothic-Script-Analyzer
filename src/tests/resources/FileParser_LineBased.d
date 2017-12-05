INSTANCE DIA_Addon_BanditGuard_EXIT   (C_INFO)
{
	npc         = BDT_1064_Bandit_L;
	nr          = 999;
	condition   = DIA_BanditGuard_EXIT_Condition;
	information = DIA_BanditGuard_EXIT_Info;
	permanent   = TRUE;
	description = DIALOG_ENDE;
};
FUNC INT DIA_BanditGuard_EXIT_Condition()
{	
		return TRUE;
};
FUNC VOID DIA_BanditGuard_EXIT_Info()
{
	AI_StopProcessInfos (self);
};