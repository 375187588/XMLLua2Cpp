//��XML���õ�Lua����ҪLuaʹ�õ�CAPI��ɿ�ִ��Cpp����
//add by freeeyes

#include <stdio.h>
#include <stdlib.h>

#include "LuaFileCreate.h"
#include "CppFileCreate.h"
#include "ParseCAPIFile.h"

int main(int argc, char* argv[])
{
	_Project_Lua_Info obj_Project_Lua_Info;
	_Project_Cpp_Info obj_Project_Cpp_Info;
	_Test_API         obj_Test_API;
	_Base_Data_Group  obj_Base_Data_Group;

	//���Դ���
	//_File_Info obj_File_Info;
	//Parse_CAPI_H_File(".\\autotest\\LuaCppExec\\Exec_LuaAPI_Player.h", obj_File_Info);
	
	bool blRet = Read_Lua_File_XML("LuaFileInfo.xml", &obj_Project_Lua_Info);
	if(true != blRet)
	{
		printf("[Main]Read_Lua_File_XML is fail.\n");
		getchar();
		return 0;
	}

	blRet = Read_Cpp_File_XML("CppFileInfo.xml", &obj_Project_Cpp_Info);
	if(true != blRet)
	{
		printf("[Main]Read_Cpp_File_XML is fail.\n");
		getchar();
		return 0;
	}

	blRet = Read_Test_File_XML("TestAPIInfo.xml", &obj_Test_API);
	if(true != blRet)
	{
		printf("[Main]Read_Test_File_XML is fail.\n");
		getchar();
		return 0;
	}

	
	blRet = Read_StructData_File_XML("UserData.xml", &obj_Base_Data_Group);
	if(true != blRet)
	{
		printf("[Main]Read_StructData_File_XML is fail.\n");
		getchar();
		return 0;
	}


	//����Lua�ļ�
	Creat_Lua_Files(&obj_Project_Lua_Info);
	Create_Lua_Environment(&obj_Project_Lua_Info);
	printf("[Main]Create Project is OK.\n");

	//����H��Cpp�ļ�
	Create_User_Data_Interface_Head_Files(&obj_Base_Data_Group);

	//��ʱ��������
	//Create_User_Data_Interface_Cpp_Files(&obj_Base_Data_Group);
	Create_Cpp_API_Files(&obj_Project_Cpp_Info);
	Create_Cpp_Exec_File(&obj_Project_Cpp_Info);
	Create_Cpp_Test_Files(&obj_Project_Lua_Info, &obj_Project_Cpp_Info, &obj_Test_API);

	//����makefile�ļ�
	CreateMakefile(&obj_Project_Cpp_Info);

	return 0;
}

